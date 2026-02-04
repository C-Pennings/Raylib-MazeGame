#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - Moving Rectangle");
    SetTargetFPS(60);  // Limit to 60 FPS for smooth, consistent movement across machines

    // Rectangle properties (your "player" or entity)
    Rectangle playerRect = { 50.0f, 50.0f, 50.0f, 50.0f };  // x, y, width, height
    float playerSpeed = 200.0f;  // Pixels per second — adjust for feel
    Color playerColor = MAROON;   // Nice red color

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())  // Handles ESC or close button
    {
        float deltaTime = GetFrameTime();  // Time since last frame (key for smooth movement)

        // Update: Handle input and move rectangle
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))    playerRect.y -= playerSpeed * deltaTime;
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))  playerRect.y += playerSpeed * deltaTime;
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  playerRect.x -= playerSpeed * deltaTime;
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) playerRect.x += playerSpeed * deltaTime;

        // Optional: Clamp to screen edges (prevents going off-screen)
        if (playerRect.x < 0) playerRect.x = 0;
        if (playerRect.x + playerRect.width > screenWidth) playerRect.x = screenWidth - playerRect.width;
        if (playerRect.y < 0) playerRect.y = 0;
        if (playerRect.y + playerRect.height > screenHeight) playerRect.y = screenHeight - playerRect.height;
        //----------------------------------------------------------------------------------

        // Draw everything
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);  // White background

        // Draw your moving rectangle
        DrawRectangleRec(playerRect, playerColor);

        // UI helpers (remove later for polish)
        DrawRectangleLinesEx(playerRect, 2.0f, Fade(BLACK, 0.5f));  // Border
        DrawFPS(10, 10);  // FPS counter (top-left)
        DrawText("WASD or Arrow Keys to Move", 10, 40, 20, DARKGRAY);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();  // Cleanup
    return 0;
}