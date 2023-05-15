#include "../raylib/include/raylib.h"
#include "../src/rect-collision.h"


int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Ray collision with a rectangle");

    SetTargetFPS(60);

    Rectangle rect;
    rect.width = 100;
    rect.height = 100;
    rect.x = screenWidth - (rect.width / 2);
    rect.y = screenHeight - (rect.height / 2);
    collision_data collision;


    while (!WindowShouldClose())
    {
        collision = collision_ray_rect((Vector2){0, 0}, GetMousePosition(), rect);


        BeginDrawing();
        if(collision.collison)
        {
            DrawRectangleRec(rect, DARKGREEN);
            DrawCircleV(collision.contact_point, 10, RED);
        }
        else
        {
            DrawRectangleRec(rect, BLACK);
        }
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
}
