#include "../raylib/include/raylib.h"
#include "../raylib/include/raymath.h"
#include "../src/rect-collision.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_STATICS 10
#define SPEED 300


typedef struct pair
{
    int index;
    float t_hit_near;
} pair;

int cmp_collision (const void * a, const void * b)
{
    pair* first = (pair*)a;
    pair* second = (pair*)b;
    return (first->t_hit_near > second->t_hit_near) - (first->t_hit_near < second->t_hit_near);
}


int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Collision between rectangles");

    SetTargetFPS(60);

    DynamicRectangle dynamic;
    dynamic.rectangle = (Rectangle){100, 100, 50, 50};
    dynamic.velocity = (Vector2){0, 0};

    Rectangle statics[NUM_STATICS];
    statics[0] = (Rectangle){200, 200, 100, 50};
    statics[1] = (Rectangle){280, 150, 20, 50};
    statics[2] = (Rectangle){355, 150, 50, 100};
    for(int i = 0; i < 7; i++)
    {
        statics[i + 3] = (Rectangle){150 + (50 * i), 350, 50, 50};
    }

    pair collisions[NUM_STATICS];
    RenderTexture screen = LoadRenderTexture(screenWidth, screenHeight);

    while(!WindowShouldClose())
    {
        if(IsKeyDown(KEY_W))
        {
            dynamic.velocity.y += -SPEED;
        }
        if(IsKeyDown(KEY_D))
        {
            dynamic.velocity.x += SPEED;
        }
        if(IsKeyDown(KEY_S))
        {
            dynamic.velocity.y += SPEED;
        }
        if(IsKeyDown(KEY_A))
        {
            dynamic.velocity.x += -SPEED;
        }
        dynamic.velocity = Vector2ClampValue(dynamic.velocity, 0, SPEED);


        int num_collisions = 0;
        for(int i = 0; i < NUM_STATICS; i++)
        {
            collision_data collision = collision_dynamic_rectangle(dynamic, statics[i]);
            if(collision.collision)
            {
                collisions[num_collisions].index = i;
                collisions[num_collisions].t_hit_near = collision.t_hit_near;
                num_collisions++;
            }
        }
        qsort(collisions, num_collisions, sizeof(pair), cmp_collision);

        for(int i = 0; i < num_collisions; i++)
        {
            collision_data collision = collision_dynamic_rectangle(dynamic, statics[collisions[i].index]);
            if(collision.collision)
            {
                dynamic.velocity.x += collision.contact_normal.x * fabs(dynamic.velocity.x) * (1 - collision.t_hit_near);
                dynamic.velocity.y += collision.contact_normal.y * fabs(dynamic.velocity.y) * (1 - collision.t_hit_near);
            }
        }

        dynamic.rectangle.x += dynamic.velocity.x * GetFrameTime();
        dynamic.rectangle.y += dynamic.velocity.y * GetFrameTime();


        if(dynamic.rectangle.x > 900 || dynamic.rectangle.y > 550 || dynamic.rectangle.x < -100 || dynamic.rectangle.y < -100)
        {
            dynamic.rectangle.x = 100;
            dynamic.rectangle.y = 100;
        }

        dynamic.velocity = Vector2Zero();

        BeginTextureMode(screen);
        ClearBackground(RAYWHITE);
        for(int i = 0; i < NUM_STATICS; i++)
        {
            DrawRectangleLinesEx(statics[i], 5, BLACK);
        }
        DrawRectangleRec(dynamic.rectangle, RED);

        //Draw control instructions
        DrawText("Movement:\n left/right - a/d\n up/down - w/s", 600, 10, 20, BLACK);

        EndTextureMode();
        BeginDrawing();
        DrawTexturePro(screen.texture, (Rectangle){0, 0, screen.texture.width, -screen.texture.height}, (Rectangle){0, 0, GetScreenWidth(), GetScreenHeight()}, (Vector2){0, 0}, 0.0, WHITE);
        EndDrawing();
    }

}
