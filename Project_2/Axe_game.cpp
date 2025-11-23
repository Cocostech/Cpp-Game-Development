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
    int circle_radius = 25;
    // Circle edges
    int r_circle_x = circle_x + circle_radius;
    int l_circle_x = circle_x - circle_radius;
    int u_circle_y = circle_y - circle_radius;
    int b_circle_y = circle_y + circle_radius;

    // Axe dimensions
    int axe_x = width / 2;
    int axe_y = 0;
    int axe_length = 50;
    int axe_speed = 10;
    // Axe edges
    int r_axe_x = axe_x + axe_length;
    int l_axe_x = axe_x;
    int u_axe_y = axe_y;
    int b_axe_y = axe_y + axe_length;

    bool collision_with_axe = (b_circle_y >= u_axe_y) && (u_circle_y <= b_axe_y) && (r_circle_x >= l_axe_x) && (l_circle_x <= r_axe_x);

    while (WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if ( collision_with_axe )
        {
            DrawText("Game Over!", width/2 - 120, height/2-20, 40, RED);
        }
        else
        {   
            // Update edges
            r_circle_x = circle_x + circle_radius;
            l_circle_x = circle_x - circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            r_axe_x = axe_x + axe_length;
            l_axe_x = axe_x;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;
            // Check collision
            collision_with_axe = (b_circle_y >= u_axe_y) && (u_circle_y <= b_axe_y) && (r_circle_x >= l_axe_x) && (l_circle_x <= r_axe_x);
            
            // Game logic begins here
            DrawCircle(circle_x, circle_y, circle_radius, BLUE); // Draw a blue circle in the center
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED); // Draw ground

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
        }
        
        EndDrawing();
    }
    
}