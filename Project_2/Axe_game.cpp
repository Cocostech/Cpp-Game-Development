#include "raylib.h"
#include <stdio.h>

int main() {

    // Window dimensions
    int width{1280};
    int height{720};
    
    InitWindow(width, height, "Robert's Axe Game");
    SetTargetFPS(60);  // Limit to 60 FPS

    printf("Window initialized with dimensions: %dx%d\n", width, height);

    // Circle dimensions
    int circle_x = width / 2;
    int circle_y = height / 2;
    int circle_radius = 50;

    int axe_x = width / 2;
    int axe_y = 0;
    int axe_speed = 10;

    while (WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logic begins here
        DrawCircle(circle_x, circle_y, circle_radius, BLUE); // Draw a blue circle in the center
        DrawRectangle(axe_x, axe_y, 50, 50, RED); // Draw ground

        axe_y += axe_speed;
        if (axe_y > height || axe_y <= -25) {
            axe_speed = -axe_speed;
        }
        
        if (IsKeyDown(KEY_D) && circle_x < width) 
        {
            circle_x += 10;
        }

        if (IsKeyDown(KEY_A) && circle_x > 0) 
        {
            circle_x -= 10;
        }

        // Game logic ends here
        EndDrawing();
    }
    
}