#pragma once
#include <core/Common.h>

template<typename T>
struct basic_vec2 {
	union {
		struct { T i; T j; };
		struct { T x; T y; };
		struct { T r; T g; };
		struct { T s; T t; };
	};

	[[nodiscard]] constexpr inline friend bool operator==(const basic_vec2& lhs, const basic_vec2& rhs) {
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}
};

template<typename T>
struct basic_vec3 {
	union {
		struct { T i; T j; T k; };
		struct { T x; T y; T z; };
		struct { T r; T g; T b; };
		struct { T s; T t; T p; };
	};

	constexpr friend bool operator==(const basic_vec3& lhs, const basic_vec3& rhs) {
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
	}

};

template<typename T>
struct basic_vec4 {
	union {
		struct { T i; T j; T k; T l; };
		struct { T x; T y; T z; T w; };
		struct { T r; T g; T b; T a; };
		struct { T s; T t; T p; T q; };
	};

	constexpr friend bool operator==(const basic_vec4& lhs, const basic_vec4& rhs) {
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
	}

};

using vec2i = basic_vec2<int>;
using vec3i = basic_vec3<int>;
using vec4i = basic_vec4<int>;

using vec2li = basic_vec2<long long int>;
using vec3li = basic_vec3<long long int>;
using vec4li = basic_vec4<long long int>;

using vec2u = basic_vec2<unsigned int>;
using vec3u = basic_vec3<unsigned int>;
using vec4u = basic_vec4<unsigned int>;

using vec2ul = basic_vec2<unsigned long long int>;
using vec3ul = basic_vec3<unsigned long long int>;
using vec4ul = basic_vec4<unsigned long long int>;

using vec2f = basic_vec2<float>;
using vec3f = basic_vec3<float>;
using vec4f = basic_vec4<float>;

using vec2d = basic_vec2<double>;
using vec3d = basic_vec3<double>;
using vec4d = basic_vec4<double>;