/* date = February 16th 2024 2:25 pm */

#ifndef VECTOR_H
#define VECTOR_H

union vec3i32 {
	struct {
		int x;
		int y;
		int z;
	};
    
	int v[3];
};

typedef union vec3i32 vec3i32;

union vec4i32 {
	struct {
		int x;
		int y;
		int z;
		int w;
	};

	int v[4];
};

typedef union vec4i32 vec4i32;

union vec3f32 {
	struct {
		float x;
		float y;
		float z;
	};
    
	float v[3];
};

typedef union vec3f32 vec3f32;

union vec4f32 {
	struct {
		float x;
		float y;
		float z;
		float w;
	};

	float v[4];
};

typedef union vec4f32 vec4f32;

void vec3_normalize(vec3f32 *v, vec3f32 *ans) {
	float magnitude = sqrtf((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	ans->x = v->x / magnitude;
	ans->y = v->y / magnitude;
	ans->z = v->z / magnitude;
}

void vec3_cross(vec3f32 *v1, vec3f32 *v2, vec3f32 *ans) {
	ans->x = (v1->y * v2->z) - (v1->z * v2->y);
	ans->y = (v1->z * v2->x) - (v1->x * v2->z);
	ans->z = (v1->x * v2->y) - (v1->y * v2->x);
}

void vec3_subtract(vec3f32 *v1, vec3f32 *v2, vec3f32 *ans) {
	ans->x = v1->x - v2->x;
	ans->y = v1->y - v2->y;
	ans->z = v1->z - v2->z;
}

float vec3_dot(vec3f32 *v1, vec3f32 *v2) {
	return (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
}

#endif //VECTOR_H
