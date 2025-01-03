#include "raylib.h"

int main(void)
{
	InitWindow(1280, 720, "window");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawFPS(10, 10);
		EndDrawing();
	}

	RCloseWindow();
	return 0;
}