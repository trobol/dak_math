// STATIC FUNCTIONS

inline float lengthSqr(vec2 v) { return v.x * v.x + v.y * v.y; }
inline float lengthSqr(vec3 v) { return v.x * v.x + v.y * v.y + v.z * v.z; }
inline float lengthSqr(vec4 v) { return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w; }

inline float length(vec2 v) { return sqrt(v.x * v.x + v.y * v.y); }
inline float length(vec3 v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }
inline float length(vec4 v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w); }


inline float distance(vec2 a, vec2 b) { return length(a - b); }
inline float distance(vec3 a, vec3 b) { return length(a - b); }
inline float distance(vec4 a, vec4 b) { return length(a - b); }

inline float distanceSqr(vec2 a, vec2 b) { return lengthSqr(a - b); }
inline float distanceSqr(vec3 a, vec3 b) { return lengthSqr(a - b); }
inline float distanceSqr(vec4 a, vec4 b) { return lengthSqr(a - b); }

inline vec2 normalize(vec2 v) { return v / length(v); }
inline vec3 normalize(vec3 v) { return v / length(v); }
inline vec4 normalize(vec4 v) { return v / length(v); }

inline float dot(vec2 a, vec2 b) { return a.x * b.x + a.y * b.y; }
inline float dot(vec3 a, vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
inline float dot(vec4 a, vec4 b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.z; }



inline vec3 cross(vec3 a, vec3 b) { return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }


