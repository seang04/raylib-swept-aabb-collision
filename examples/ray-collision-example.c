#include "../raylib/include/raylib.h"
#include "../src/rect-collision.h"
#include <stdio.h>


int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(screenWidth, screenHeight, "Ray collision with a rectangle");

    SetTargetFPS(60);

    Rectangle rect;

    collision_data collision;
    char contact_point[256];
    char contact_normal[256];
    char t_hit_near[256];

    while (!WindowShouldClose())
    {
        float screen_scale_x = GetScreenWidth() / (float)screenWidth;
        float screen_scale_y = GetScreenHeight() / (float)screenHeight;

        rect.width = 100 * (screen_scale_x);
        rect.height = 100 * (screen_scale_y );
        rect.x = (GetScreenWidth() / 2.0) - (rect.width / 2);
        rect.y = (GetScreenHeight() / 2.0) - (rect.height / 2);

        collision = collision_ray_rect((Vector2){0, 0}, GetMousePosition(), rect);

        sprintf(contact_point, "contact point: <%.4f, %.4f>", collision.contact_point.x, collision.contact_point.y);
        sprintf(contact_normal, "contact normal: <%.4f, %.4f>", collision.contact_normal.x, collision.contact_normal.y);
        sprintf(t_hit_near, "t hit near: %.4f", collision.t_hit_near);

        DrawLineEx((Vector2){0, 0}, GetMousePosition(), 2.5 * (screen_scale_x), BLACK);
        BeginDrawing();
        if(collision.collison)
        {
            DrawRectangleRec(rect, DARKGREEN);
            DrawCircleV(collision.contact_point, 10 * screen_scale_x, RED);
            DrawText(contact_point, 5, GetScreenHeight() - 100 * (screen_scale_x), (15 * (screen_scale_x)), BLACK);
            DrawText(contact_normal, 5, GetScreenHeight() - 75 * (screen_scale_x), (15 * (screen_scale_x)), BLACK);
        }
        else
        {
            DrawRectangleRec(rect, BLACK);
            DrawText("contact point:", 5, GetScreenHeight() - 100 * (screen_scale_x), (15 * (screen_scale_x)), BLACK);
            DrawText("contact normal:", 5, GetScreenHeight() - 75 * (screen_scale_x), (15 * (screen_scale_x)), BLACK);
        }

        DrawText(t_hit_near, 5, GetScreenHeight() - 50 * (screen_scale_x), (15 * (screen_scale_x)), BLACK);

        ClearBackground(RAYWHITE);
        EndDrawing();
    }
}
