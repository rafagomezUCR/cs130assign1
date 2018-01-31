#include "sphere.h"
#include "ray.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;


// Determine if the ray intersects with the sphere
bool Sphere::Intersection(const Ray& ray, std::vector<Hit>& hits) const
{
    // TODO
    
    // vec3 center double radius vec3 endpoint vec3 direction
    vec3 p = ray.endpoint - center;
    double a = dot(ray.direction,p);
    double b = dot(p,p);
    double delta = (4*a*a) - (4*(b- radius*radius));
    if(delta > 0){
        double t1 = ((-2*a) - sqrt(delta)) / 2;
        double t2 = ((-2*a) + sqrt(delta)) / 2;
        if(t1 > 0){
            Hit hit1;
            hit1.object = this;
            hit1.t = t1;
            hit1.ray_exiting = false;
            hits.push_back(hit1);
        }
        Hit hit2;
        hit2.object = this;
        hit2.t = t2;
        hit2.ray_exiting = true;
        hits.push_back(hit2);
        return true;
    }
    
    return false;
}

vec3 Sphere::Normal(const vec3& point) const
{
    vec3 normal;
    // TODO: set the normal
    normal = point - center;
    return normal.normalized();
}
