#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"
#include <stdio.h>
#include <math.h>

using namespace std;

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& same_side_normal,int recursion_depth,bool is_exiting) const 
{
    vec3 color;
    vec3 ambient = color_ambient * world.ambient_intensity * world.ambient_color;
    vec3 diffuse, specular, r;
    color = ambient;
    for(unsigned i = 0; i < world.lights.size(); i++){
        vec3 l = world.lights[i]->position - intersection_point;
        double square_light = dot(-l, -l);
        if(world.enable_shadows){
            Ray ray2(intersection_point, l.normalized());
            Hit hit;
            Object *obj = world.Closest_Intersection(ray2, hit);
            if(obj){
                if(hit.t < sqrt(square_light)){
                    continue;
                }
            }
        }
        vec3 L = world.lights[i]->Emitted_Light(ray) / square_light;
        diffuse = color_diffuse * L * max(0.0, dot(l.normalized(), same_side_normal));
        r = (2 * dot(l.normalized(), same_side_normal) * same_side_normal) - l.normalized();
        specular = color_specular * pow( max(0.0, dot(-ray.direction.normalized(), r.normalized())), specular_power) * L;
        color += diffuse + specular;
    }
    return color;
}


































// if(world.enable_shadows){
        //     Ray ray2(intersection_point, l.normalized());
        //     Hit hit;
        //     Object* obj = world.Closest_Intersection(ray2, hit);
        //     if(obj){
        //         if(hit.t > sqrt(square_light)){
        //             continue;
        //         }
        //         else{
        //             vec3 diffuse_light = (world.lights[i]->Emitted_Light(ray)) / square_light;
        //             diffuse = color_diffuse * diffuse_light * max(0.0, dot(l, same_side_normal));
        //             r = (2 * dot(l, same_side_normal) * same_side_normal) - l;
        //             specular = color_specular * pow( max(0.0, dot(r.normalized(), -ray.direction.normalized())), specular_power) * diffuse_light;
        //             color = ambient + diffuse + specular;
        //         }
        //     }
        // }
