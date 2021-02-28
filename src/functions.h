// STATIC FUNCTIONS

float lengthSqr(vec2 v) { return v.x * v.x + v.y * v.y; }
float lengthSqr(vec3 v) { return v.x * v.x + v.y * v.y + v.z * v.z; }
float lengthSqr(vec4 v) { return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w; }

float length(vec2 v) { return sqrt(v.x * v.x + v.y * v.y); }
float length(vec3 v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }
float length(vec4 v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w); }


float distance(vec2 a, vec2 b) { return length(a - b); }
float distance(vec3 a, vec3 b) { return length(a - b); }
float distance(vec4 a, vec4 b) { return length(a - b); }

float distanceSqr(vec2 a, vec2 b) { return lengthSqr(a - b); }
float distanceSqr(vec3 a, vec3 b) { return lengthSqr(a - b); }
float distanceSqr(vec4 a, vec4 b) { return lengthSqr(a - b); }

vec2 normalize(vec2 v) { return v / length(v); }
vec3 normalize(vec3 v) { return v / length(v); }
vec4 normalize(vec4 v) { return v / length(v); }

float dot(vec2 a, vec2 b) { return a.x * b.x + a.y * b.y; }
float dot(vec3 a, vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
float dot(vec4 a, vec4 b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.z; }



vec3 cross(vec3 a, vec3 b) { return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }


