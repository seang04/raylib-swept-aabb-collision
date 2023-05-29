///rect-collision.h
///provides functions for an implementation of swept AABB collision detection
///for use with raylib.
///Also provides simple dynamic rectangle struct which is just a raylib
///rectangle with a velocity.
///@author Sean Gaines

#include "../raylib/include/raylib.h"
#include <stdbool.h>

typedef struct col_data_struct
{
    bool collision;
    Vector2 contact_point;
    Vector2 contact_normal;
    float t_hit_near;

} collision_data;

typedef struct dyanmic_rect_struct
{
    Rectangle rectangle;
    Vector2 velocity;
} DynamicRectangle;

/**
 * Checks the collision of a ray, defined by a start position and a vector,
 * against a rectangle target.
 *
 * @param ray_origin, the starting point of the ray.
 * @param ray_dir, the vector representing the ray from the origin.
 * @param target, the target rectangle to check collision with.
 * @return collision_data, information about the collision with the target.
 **/
collision_data collision_ray_rect(Vector2 ray_origin, Vector2 ray_dir, Rectangle target);


/**
 * Checks the collision of a rectangle with a velocity against a stationary
 * rectangle target.
 *
 * @param souce, the moving rectangle
 * @param src_velocity, the velocity of the moving rectangle
 * @param target, the target rectangle to check collision against
 * */
collision_data collision_rectangle(Rectangle source, Vector2 src_velocity, Rectangle target);

/**
 *Checks the collision of a moving rectangle against a stationary one using the
 *provided dynamic rectangle type.
 *
 *@param source, dynamic rectangle to check collision with
 *@param target, stationary target rectangle to check collision against
 **/
collision_data collision_dynamic_rectangle(DynamicRectangle source, Rectangle target);
