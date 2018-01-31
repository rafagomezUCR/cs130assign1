#include "reflective_shader.h"
#include "ray.h"
#include "render_world.h"
#include "light.h"

vec3 Reflective_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& same_side_normal,int recursion_depth,bool is_exiting) const
{
    vec3 color;
    // vec3 reflected_color;
    // // TODO: determine the color
    // //Calculating the reflective vector
    // vec3 r = (2 * dot(ray.direction.normalized(), same_side_normal) * same_side_normal) - ray.direction.normalized();
    // //Making the reflective ray
    // Ray ray2(intersection_point, r);
    // //Getting the reflected color
    // recursion_depth++;
    // //reflected_color = world.Cast_Ray(ray2, recursion_depth);
    // //increasing the recursion depth after casting the ray
    // //calculating the shader color
    // vec3 shader_color = Shade_Surface(ray2, intersection_point, same_side_normal, recursion_depth, is_exiting);
    // //calculating the color
    // color = (reflectivity * reflected_color) + ((1 - reflectivity) * shader_color);
    
    return color;
}
