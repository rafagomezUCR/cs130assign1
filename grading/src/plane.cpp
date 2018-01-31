#include "plane.h"
#include "ray.h"
#include <cfloat>

using namespace std;

// Intersect with the half space defined by the plane.  The plane's normal
// points outside.  If the ray starts on the "inside" side of the plane, be sure
// to record a hit with t=0 as the first entry in hits.
bool Plane::Intersection(const Ray& ray, vector<Hit>& hits) const
{
    // TODO
    Hit h;
    h.object = this;
    vec3 a = x1 - ray.endpoint;
    double b = dot(normal, a);
    double c = dot(normal, ray.direction);
    double t = b/c;
    h.t = t;
    if(c > 0){
        h.ray_exiting = true;
    }
    else{
        h.ray_exiting = false;
    }
    hits.push_back(h);
    return true;
}

vec3 Plane::Normal(const vec3& point) const
{
    return normal;
}
