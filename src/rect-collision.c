#include "rect-collision.h"
#include <math.h>
#include <stdlib.h>
#include "../raylib/include/raymath.h"

collision_data collision_ray_rect(Vector2 ray_origin, Vector2 ray_dir, Rectangle target)
{
    collision_data out;
    out.collison = false;

    float t_near_x = (target.x - ray_origin.x) / ray_dir.x;
    float t_far_x = (target.x + target.width - ray_origin.x) / ray_dir.x;
    float t_near_y = (target.x - ray_origin.y) / ray_dir.y;
    float t_far_y = (target.y + target.height - ray_origin.y) / ray_dir.y;

    if (isnan(t_far_y) || isnan(t_far_x)) return out;

    if (isnan(t_near_y) || isnan(t_near_x)) return out;

    if (t_near_x > t_far_x)
    {
        float tmp = t_near_x;
        t_near_x = t_far_x;
        t_far_x = tmp;
    }
    if (t_near_y > t_far_y)
    {
        float tmp = t_near_y;
        t_near_y = t_far_y;
        t_far_y = tmp;
    }

    if (t_near_x > t_far_y || t_near_y > t_far_x) return out;

    out.t_hit_near = fmax(t_near_x, t_near_y);
    if(out.t_hit_near > 1) return out;

    float t_hit_far = fmin(t_far_x, t_far_y);
    if(t_hit_far < 0) return out;

    out.contact_point = Vector2Add(ray_origin, Vector2Scale(ray_dir, out.t_hit_near));

    if (t_near_x > t_near_y)
    {
        if (ray_dir.x < 0)
        {
            out.contact_normal = (Vector2){1, 0};
        }
        else
        {
            out.contact_normal = (Vector2){-1, 0};
        }
    }
    else if(t_near_x < t_near_y)
    {
        if(ray_dir.y < 0)
        {
            out.contact_normal = (Vector2){0, 1};
        }
        else
        {
            out.contact_normal = (Vector2){0, -1};
        }
    }

    out.collison = true;
    return out;
}
