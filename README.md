# Shapes Hot Reload Demo

Quick visual demo of config file hot-reloading, implemented with the **observer, state** and **factory** pattern.

File loading module extracted from my work-in-progress proprietary
game engine. Demo presented with the [Raylib](https://www.raylib.com/)
library.

<video controls src="./misc/demo.mp4"></video>

## Build instructions (Windows)

Ensure `Desktop Development with C++` is installed for Visual Studio 2022.

Run with `Developer Command Prompt for VS 2022`:

```cmd
cmake --preset windows
```

Open the Visual Studio solution in the build folder or run:

```cmd
cmake --build build --parallel
call build\Debug\shapes-hot-reload.exe
```

## Credits

- [multini library (by me)](https://github.com/bramtechs/multini)

- [Raylib library](https://www.raylib.com/)
