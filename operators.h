// OPERATORS
inline vec3 operator*(vec3 a, vec3 b) { return vec3(a.x * b.x, a.y * b.y, a.z * b.z); }
inline vec3 operator/(vec3 a, vec3 b) { return vec3(a.x / b.x, a.y / b.y, a.z / b.z); }
inline vec3 operator+(vec3 a, vec3 b) { return vec3(a.x + b.x, a.y + b.y, a.z + b.z); }
inline vec3 operator-(vec3 a, vec3 b) { return vec3(a.x - b.x, a.y - b.y, a.z - b.z); }

inline vec3 &operator*=(vec3& a, vec3 b) { a = a * b; return a; }
inline vec3 &operator/=(vec3& a, vec3 b) { a = a * b; return a; }
inline vec3 &operator+=(vec3& a, vec3 b) { a = a * b; return a; }
inline vec3 &operator-=(vec3& a, vec3 b) { a = a * b; return a; }


inline vec3 operator*(vec3 v, float f) { return vec3(v.x * f, v.y * f, v.z * f); }
inline vec3 operator/(vec3 v, float f) { return vec3(v.x / f, v.y / f, v.z / f); }

inline vec3& operator*=(vec3& v, float f) { v = v * f; return v; }
inline vec3& operator/=(vec3& v, float f) { v = v * f; return v; }



// CONSTANSTS INITIALIZATION
const vec3::vec3 one = vec3(1, 1, 1);
const vec3::vec3 left = vec3(-1, 0, 0);
const vec3::vec3 right = vec3(1, 0, 0);
const vec3::vec3 up = vec3(0, 1, 0);
const vec3::vec3 down = vec3(0, -1, 0);
const vec3::vec3 forwards = vec3(0, 0, 1);
const vec3::vec3 back = vec3(0, 0, -1);
