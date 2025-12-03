#include <raylib.h>

int main() {
    // Initialize the window
    const int window_withdth = 1280;
    const int window_height = 720;
    InitWindow(window_withdth, window_height, "Dapper Dasher!");
    SetTargetFPS(60);

    const int rect_width = 50;
    const int rect_height = 80;
    int rect_y = window_height-rect_height;
    int velocity_y = 0;

    // Main game loop
    while (!WindowShouldClose()) { 
        BeginDrawing();
        
        ClearBackground(WHITE);
        
        rect_y += velocity_y;
        DrawRectangle(window_withdth/2 - rect_width/2, rect_y, rect_width, rect_height, BLUE);
        
        if (IsKeyPressed(KEY_SPACE)) {
            velocity_y = -5; // Move up
        }
        
        
        
        EndDrawing();
    }
    
    CloseWindow(); // Close window and OpenGL context
}