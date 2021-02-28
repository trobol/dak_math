
// VEC2

inline vec2 operator*(vec2 a, vec2 b) { return vec2(a.x * b.x, a.y * b.y); }
inline vec2 operator/(vec2 a, vec2 b) { return vec2(a.x / b.x, a.y / b.y); }
inline vec2 operator+(vec2 a, vec2 b) { return vec2(a.x + b.x, a.y + b.y); }
inline vec2 operator-(vec2 a, vec2 b) { return vec2(a.x - b.x, a.y - b.y); }

inline vec2 &operator*=(vec2& a, vec2 b) { a = a * b; return a; }
inline vec2 &operator/=(vec2& a, vec2 b) { a = a * b; return a; }
inline vec2 &operator+=(vec2& a, vec2 b) { a = a * b; return a; }
inline vec2 &operator-=(vec2& a, vec2 b) { a = a * b; return a; }


inline vec2 operator*(vec2 v, float f) { return vec2(v.x * f, v.y * f); }
inline vec2 operator/(vec2 v, float f) { return vec2(v.x / f, v.y / f); }

inline vec2 operator*(float f, vec2 v) { return vec2(v.x * f, v.y * f); }
inline vec2 operator/(float f, vec2 v) { return vec2(v.x / f, v.y / f); }


inline vec2& operator*=(vec2& v, float f) { v = v * f; return v; }
inline vec2& operator/=(vec2& v, float f) { v = v * f; return v; }




// VEC3
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

inline vec3 operator*(float f, vec3 v) { return vec3(v.x * f, v.y * f, v.z * f); }
inline vec3 operator/(float f, vec3 v) { return vec3(v.x / f, v.y / f, v.z / f); }

inline vec3& operator*=(vec3& v, float f) { v = v * f; return v; }
inline vec3& operator/=(vec3& v, float f) { v = v * f; return v; }


// VEC4
inline vec4 operator*(vec4 a, vec4 b) { return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
inline vec4 operator/(vec4 a, vec4 b) { return vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
inline vec4 operator+(vec4 a, vec4 b) { return vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
inline vec4 operator-(vec4 a, vec4 b) { return vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }

inline vec4 &operator*=(vec4& a, vec4 b) { a = a * b; return a; }
inline vec4 &operator/=(vec4& a, vec4 b) { a = a * b; return a; }
inline vec4 &operator+=(vec4& a, vec4 b) { a = a * b; return a; }
inline vec4 &operator-=(vec4& a, vec4 b) { a = a * b; return a; }


inline vec4 operator*(vec4 v, float f) { return vec4(v.x * f, v.y * f, v.z * f, v.w * f); }
inline vec4 operator/(vec4 v, float f) { return vec4(v.x / f, v.y / f, v.z / f, v.w / f); }

inline vec4 operator*(float f, vec4 v) { return v * f; }
inline vec4 operator/(float f, vec4 v) { return vec4(f / v.x, f / v.y, f / v.z, f / v.w); }

inline vec4& operator*=(vec4& v, float f) { v = v * f; return v; }
inline vec4& operator/=(vec4& v, float f) { v = v * f; return v; }