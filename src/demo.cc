#include "file_reader.hh"
#include "file_reloader.hh"
#include "local_file_reader.hh"

#include <iostream>
#include <memory>
#include <raylib.h>

namespace observer {

class DemoScene final {

public:
    DemoScene(int width, int height)
        : mFileReader(std::make_unique<LocalFileReader>())
        , mFileReloader(std::make_unique<FileReloader>(*mFileReader))
    {
        InitWindow(width, height, "raylib [core] example - basic window");
        SetTargetFPS(60);
    }

    ~DemoScene()
    {
        RCloseWindow();
    }

    void render()
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Change shapes.ini to modify the shapes!", 50, 50, 36, GRAY);

        EndDrawing();
    }

    bool shouldClose() const
    {
        return WindowShouldClose();
    }

private:
    std::unique_ptr<IFileReader> mFileReader;
    std::unique_ptr<IFileReloader> mFileReloader;
};

}

int main(int arc, char** argv)
{
    observer::DemoScene scene(1280, 720);
    while (!scene.shouldClose()) {
        scene.render();
    }
    return EXIT_SUCCESS;
}
