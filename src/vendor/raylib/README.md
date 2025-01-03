Debloated repo of [Raylib 5.0](https://github/raysan5/raylib) for
Windows with Visual Studio solution and simplfied CMake.

## Things removed

Documentation, zig build and examples.

## Things not removed

Non-Windows platform implementations in `src/platforms`.

## Things added

- Raygui
- JPEG compile flag is enabled by default
- [core_basic_window](https://www.raylib.com/examples/core/loader.html?name=core_basic_window)
  example in C++ without comments and congrats text.
- Renamed CloseWindow to RCloseWindow (prevents linker error)

Intended for internal usage at
[Doomhowl Interactive](https://doomhowl-interactive.com), but could turn out
useful for someone.

Comes with absolutely no warranty.<br>All credit belongs to raysan5 and Raylib
contributors.

> Original snippet of Raylib readme

<img align="left" style="width:260px" src="https://github.com/raysan5/raylib/blob/master/logo/raylib_logo_animation.gif" width="288px">

**raylib is a simple and easy-to-use library to enjoy videogames programming.**

raylib is highly inspired by Borland BGI graphics lib and by XNA framework and
it's especially well suited for prototyping, tooling, graphical applications,
embedded systems and education.

_NOTE for ADVENTURERS: raylib is a programming library to enjoy videogames
programming; no fancy interface, no visual helpers, no debug button... just
coding in the most pure spartan-programmers way._
