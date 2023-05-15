#include "../raylib/include/raylib.h"

typedef struct col_data_struct
{
    int collison;
    Vector2 contact_point;
    Vector2 contact_normal;
    float t_hit_near;

} collision_data;

typedef struct dyanmic_rect_struct
{
    Rectangle rectangle;
    Vector2 velocity;
} DynamicRectangle;

collision_data collision_ray_rect(Vector2 ray_origin, Vector2 ray_dir, Rectangle target);

collision_data collision_rectangle(Rectangle source, Vector2 src_velocity, Rectangle target);

collision_data collision_dynamic_rectangle(DynamicRectangle source, Rectangle target);
