#include "file_reader.hh"
#include "file_reloader.hh"
#include "local_file_reader.hh"
#include "shape_importer.hh"

#include <iostream>
#include <memory>
#include <raylib.h>

namespace demo {

class DemoScene final : public IFileReloaderListener {

public:
    DemoScene(int width, int height, const std::string& shapesFile = "shapes.ini")
        : mImporter(shapesFile)
        , mFileReader(std::make_unique<LocalFileReader>())
        , mFileReloader(std::make_unique<FileReloader>(*mFileReader))
    {
        InitWindow(width, height, "File Reloader Observer Demo");
        SetTargetFPS(60);

        mFileReloader->trackFile(shapesFile);
        reloadShapes();
    }

    ~DemoScene()
    {
        RCloseWindow();
    }

    void render()
    {
        // poll file reloader for new events
        mFileReloader.poll();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (const std::unique_ptr<IShape>& shape : mShapes) {
            shape->draw();
        }

        DrawText("Change shapes.ini to modify the shapes!", 50, 50, 36, GRAY);

        EndDrawing();
    }

    bool shouldClose() const
    {
        return WindowShouldClose();
    }

    void onFileReloaded(const std::string& file)
    {
        if (file == "shapes.ini") {
            reloadShapes();
        }
    }

private:
    void reloadShapes()
    {
        std::cout << "Reloading shapes.ini" << std::endl;
        mImporter.open();
        mShapes = mImporter.readShapes();
        mImporter.close();
    }

    ShapeImporter mImporter;
    std::vector<std::unique_ptr<IShape>> mShapes;
    std::unique_ptr<IFileReader> mFileReader;
    std::unique_ptr<IFileReloader> mFileReloader;
};

}

int main(int arc, char** argv)
{
    demo::DemoScene scene(1280, 720);
    while (!scene.shouldClose()) {
        scene.render();
    }
    return EXIT_SUCCESS;
}
