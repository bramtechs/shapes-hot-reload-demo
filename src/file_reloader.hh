#pragma once
#include <cassert>
#include <chrono>
#include <functional>
#include <memory>
#include <mutex>
#include <stop_token>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

namespace demo {

class IFileReader;

class IFileReloaderListener {
public:
    virtual ~IFileReloaderListener() = default;
    virtual void onFileReloaded(const std::string& file) = 0;
};

class IFileReloader {
public:
    virtual ~IFileReloader() = default;

    virtual void trackFile(const std::string& fileName) = 0;

    virtual void poll() = 0;

    /// Registers a listener that triggers with the name of the file reloaded.
    virtual void registerReloadListener(IFileReloaderListener& listener) = 0;
};

class FileReloader : public IFileReloader {
public:
    FileReloader(IFileReader& reader, long pollIntervalMillis = 1000);

    void trackFile(const std::string& fileName) override;

    void poll() override;

    /// Registers a listener that triggers with the name of the file reloaded.
    void registerReloadListener(IFileReloaderListener& listener) override
    {
        mListeners.emplace_back(listener);
    }

private:
    void notifyListeners(const std::string& path) const;

    void threadedChecker(std::stop_token stopToken, long pollIntervalMillis);

    IFileReader& mReader;

    std::mutex mWriteTimesMutex {};
    std::mutex mQueuedChangesMutex {};

    std::vector<std::reference_wrapper<IFileReloaderListener>> mListeners {};
    std::vector<std::string> mQueuedChanges {};
    std::unordered_map<std::string, std::size_t> mWriteTimes {};

    std::jthread mThread;
};

}
