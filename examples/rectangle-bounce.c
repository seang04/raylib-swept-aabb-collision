#include "../raylib/include/raylib.h"
#include "../raylib/include/raymath.h"
#include "../src/rect-collision.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_DYNAMICS 256

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Collision between rectangles");

    SetTargetFPS(60);

    Rectangle wall = (Rectangle){700, 20, 50, 410};

    DynamicRectangle dynamics[MAX_DYNAMICS];
    int num_dynamics = 0;
    const Vector2 start_pos = {125, 225};

    while(!WindowShouldClose())
    {
        Vector2 direction = Vector2Subtract(GetMousePosition(), (Vector2){125, 225});
        direction = Vector2Normalize(direction);

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if(num_dynamics < MAX_DYNAMICS)
            {
                dynamics[num_dynamics % MAX_DYNAMICS].rectangle = (Rectangle){start_pos.x - 25, start_pos.y - 25, 50, 50};
                dynamics[num_dynamics % MAX_DYNAMICS].velocity = Vector2Scale(direction, 400);
                num_dynamics++;
            }
        }
        for(int i = 0; i < num_dynamics; i++)
        {
            collision_data collision = collision_dynamic_rectangle(dynamics[i], wall);
            if(collision.collision)
            {
                if(collision.t_hit_near <= 0)
                {
                    Vector2 vel = dynamics[i].velocity;
                    float dot = Vector2DotProduct(vel, collision.contact_normal);
                    dynamics[i].velocity = Vector2Subtract(vel, Vector2Scale(collision.contact_normal, 2 * dot));
                }
                else
                {
                    dynamics[i].velocity.x += collision.contact_normal.x * fabs(dynamics[i].velocity.x) * (1 - collision.t_hit_near);
                    dynamics[i].velocity.y += collision.contact_normal.y * fabs(dynamics[i].velocity.y) * (1 - collision.t_hit_near);
                }

            }

            dynamics[i].rectangle.x += dynamics[i].velocity.x * GetFrameTime();
            dynamics[i].rectangle.y += dynamics[i].velocity.y * GetFrameTime();

            if(dynamics[i].rectangle.x > 900 || dynamics[i].rectangle.x < -100 || dynamics[i].rectangle.y > 550 || dynamics[i].rectangle.y < -100)
            {
                dynamics[i] = dynamics[num_dynamics - 1];
                num_dynamics--;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawLineEx(start_pos, Vector2Add(start_pos, Vector2Scale(direction, 50)), 5, RED);
        for(int i = 0; i < num_dynamics; i++)
        {
            DrawRectangleLinesEx(dynamics[i].rectangle, 10, BLACK);
        }
        DrawRectangleLinesEx(wall, 10, BLACK);
        EndDrawing();

    }
    return EXIT_SUCCESS;

}
