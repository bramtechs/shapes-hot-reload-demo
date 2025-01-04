/*
 * Copyright (c) 2025. Doomhowl Interactive - All Rights Reserved
 * Redistribution and use in source and binary forms, with or without modification are not permitted
 * without the prior written permission of Doomhowl Interactive.
 *
 * File created on: 03-01-2025
 */

#include "file_reloader.hh"
#include "file_reader.hh"

namespace demo
{

FileReloader::FileReloader(IFileReader& reader, long pollIntervalMillis)
    : mReader(reader)
    , mThread(std::bind(&FileReloader::threadedChecker, this, std::placeholders::_1, pollIntervalMillis))
{
}

void FileReloader::trackFile(const std::string& fileName)
{
    std::lock_guard<std::mutex> guard(mWriteTimesMutex);
    if (mWriteTimes.find(fileName) == mWriteTimes.end()) {
        mWriteTimes[fileName] = mReader.getFileUpdateTime(fileName);
    }
}

void FileReloader::poll()
{
    std::lock_guard<std::mutex> guard(mQueuedChangesMutex);

    for (const std::string& fname : mQueuedChanges) {
        notifyListeners(fname);
    }

    mQueuedChanges.clear();
}

void FileReloader::threadedChecker(std::stop_token stopToken, long pollIntervalMillis)
{
    using namespace std::chrono_literals;

    while (!stopToken.stop_requested()) {
        {
            std::lock_guard<std::mutex> guard(mWriteTimesMutex);
            for (auto& [fname, lastWrite] : mWriteTimes) {
                std::size_t updateTime = mReader.getFileUpdateTime(fname);
                if (lastWrite != updateTime) {
                    printf("Script %s changed, requesting hot-reload: %zu != %zu\n", fname.c_str(), lastWrite, updateTime);
                    std::lock_guard<std::mutex> guard2(mQueuedChangesMutex);
                    mQueuedChanges.emplace_back(fname);
                    lastWrite = updateTime;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(pollIntervalMillis));
    }
}

void FileReloader::notifyListeners(const std::string& path) const
{
    for (auto& listener : mListeners) {
        listener.get().onFileReloaded(path);
    }
}

}
