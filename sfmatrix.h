#ifndef SF_MATRIX_H
#define SF_MATRIX_H

typedef float mat4[4][4];

void mat4_zero(mat4 m) {
    m[0][0] = 0.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
    m[1][0] = 0.0f; m[1][1] = 0.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
    m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 0.0f; m[2][3] = 0.0f;
    m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 0.0f;
}

void mat4_identity(mat4 m) {
	mat4_zero(m);
    m[0][0] = 1.0f;
    m[1][1] = 1.0f;
    m[2][2] = 1.0f;
    m[3][3] = 1.0f;
}

void mat4_transpose(mat4 m) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i != j) {
				int temp = m[i][j];
				m[i][j] = m[j][i];
				m[j][i] = temp;
			}
		}
	}
}

void mat4_multiply(mat4 m1, mat4 m2, mat4 ans) {
    ans[0][0] = (m1[0][0] * m2[0][0]) + (m1[0][1] * m2[1][0]) + (m1[0][2] * m2[2][0]) + (m1[0][3] * m2[3][0]);
    ans[0][1] = (m1[0][0] * m2[0][1]) + (m1[0][1] * m2[1][1]) + (m1[0][2] * m2[2][1]) + (m1[0][3] * m2[3][1]);
    ans[0][2] = (m1[0][0] * m2[0][2]) + (m1[0][1] * m2[1][2]) + (m1[0][2] * m2[2][2]) + (m1[0][3] * m2[3][2]);
    ans[0][3] = (m1[0][0] * m2[0][3]) + (m1[0][1] * m2[1][3]) + (m1[0][2] * m2[2][3]) + (m1[0][3] * m2[3][3]);
    
    ans[1][0] = (m1[1][0] * m2[0][0]) + (m1[1][1] * m2[1][0]) + (m1[1][2] * m2[2][0]) + (m1[1][3] * m2[3][0]);
    ans[1][1] = (m1[1][0] * m2[0][1]) + (m1[1][1] * m2[1][1]) + (m1[1][2] * m2[2][1]) + (m1[1][3] * m2[3][1]);
    ans[1][2] = (m1[1][0] * m2[0][2]) + (m1[1][1] * m2[1][2]) + (m1[1][2] * m2[2][2]) + (m1[1][3] * m2[3][2]);
    ans[1][3] = (m1[1][0] * m2[0][3]) + (m1[1][1] * m2[1][3]) + (m1[1][2] * m2[2][3]) + (m1[1][3] * m2[3][3]);
    
    ans[2][0] = (m1[2][0] * m2[0][0]) + (m1[2][1] * m2[1][0]) + (m1[2][2] * m2[2][0]) + (m1[2][3] * m2[3][0]);
    ans[2][1] = (m1[2][0] * m2[0][1]) + (m1[2][1] * m2[1][1]) + (m1[2][2] * m2[2][1]) + (m1[2][3] * m2[3][1]);
    ans[2][2] = (m1[2][0] * m2[0][2]) + (m1[2][1] * m2[1][2]) + (m1[2][2] * m2[2][2]) + (m1[2][3] * m2[3][2]);
    ans[2][3] = (m1[2][0] * m2[0][3]) + (m1[2][1] * m2[1][3]) + (m1[2][2] * m2[2][3]) + (m1[2][3] * m2[3][3]);
    
    ans[3][0] = (m1[3][0] * m2[0][0]) + (m1[3][1] * m2[1][0]) + (m1[3][2] * m2[2][0]) + (m1[3][3] * m2[3][0]);
    ans[3][1] = (m1[3][0] * m2[0][1]) + (m1[3][1] * m2[1][1]) + (m1[3][2] * m2[2][1]) + (m1[3][3] * m2[3][1]);
    ans[3][2] = (m1[3][0] * m2[0][2]) + (m1[3][1] * m2[1][2]) + (m1[3][2] * m2[2][2]) + (m1[3][3] * m2[3][2]);
    ans[3][3] = (m1[3][0] * m2[0][3]) + (m1[3][1] * m2[1][3]) + (m1[3][2] * m2[2][3]) + (m1[3][3] * m2[3][3]);
}

void mat4_mult_vec(mat4 m, vec4f32 v, vec4f32 *ans) {
	ans->x = (m[0][0] * v.x) + (m[0][1] * v.y) + (m[0][2] * v.z) + (m[0][3] * v.w);
	ans->y = (m[1][0] * v.x) + (m[1][1] * v.y) + (m[1][2] * v.z) + (m[1][3] * v.w);
	ans->z = (m[2][0] * v.x) + (m[2][1] * v.y) + (m[2][2] * v.z) + (m[2][3] * v.w);
	ans->w = (m[3][0] * v.x) + (m[3][1] * v.y) + (m[3][2] * v.z) + (m[3][3] * v.w);
}

float mat4_mult_vec3(mat4 m, vec3f32 v, vec3f32 *ans, float w) {
	float w_result = 1.0f;
	ans->x = (m[0][0] * v.x) + (m[0][1] * v.y) + (m[0][2] * v.z) + (m[0][3] * w);
	ans->y = (m[1][0] * v.x) + (m[1][1] * v.y) + (m[1][2] * v.z) + (m[1][3] * w);
	ans->z = (m[2][0] * v.x) + (m[2][1] * v.y) + (m[2][2] * v.z) + (m[2][3] * w);
	w_result = (m[3][0] * v.x) + (m[3][1] * v.y) + (m[3][2] * v.z) + (m[3][3] * w);
	
	return w_result;
}

void mat4_translate(mat4 m, vec3f32 *position)
{
	mat4_identity(m);
	m[0][3] = position->x;
	m[1][3] = position->y;
	m[2][3] = position->z;
}

void mat4_scale(mat4 m, vec3f32 *scale)
{
	mat4_identity(m);
	m[0][0] = scale->x;
	m[1][1] = scale->y;
	m[2][2] = scale->z;
}

void mat4_gen_lookat(vec3f32 camera_target, vec3f32 camera_up,
					 vec3f32 camera_pos, mat4 m)
{
	vec3f32 camera_z_axis = {
		.x = 0.0f,
		.y = 0.0f,
		.z = 0.0f,
	};
	vec3f32 camera_x_axis = {
		.x = 0.0f,
		.y = 0.0f,
		.z = 0.0f,
	};
	vec3f32 camera_y_axis = {
		.x = 0.0f,
		.y = 0.0f,
		.z = 0.0f,
	};

	vec3_subtract(&camera_pos, &camera_target, &camera_z_axis);
	vec3_normalize(&camera_z_axis, &camera_z_axis);

	vec3_cross(&camera_up, &camera_z_axis, &camera_x_axis);
	vec3_normalize(&camera_x_axis, &camera_x_axis);

	// no need to normalize y_axis since x and z are unit vectors
	// and they are orthonormal to each other. So the cross product
	// result is also a unit vector.

	vec3_cross(&camera_z_axis, &camera_x_axis, &camera_y_axis);
    
    m[0][0] = camera_x_axis.x; m[0][1] = camera_x_axis.y;
	m[0][2] = camera_x_axis.z; m[0][3] = -vec3_dot(&camera_x_axis, &camera_pos);

    m[1][0] = camera_y_axis.x; m[1][1] = camera_y_axis.y;
	m[1][2] = camera_y_axis.z; m[1][3] = -vec3_dot(&camera_y_axis, &camera_pos);

    m[2][0] = camera_z_axis.x; m[2][1] = camera_z_axis.y;
	m[2][2] = camera_z_axis.z; m[2][3] = -vec3_dot(&camera_z_axis, &camera_pos);

    m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
}

void mat4_gen_orthographic_proj(float right, float left,
								float top, float bottom,
								float far_val, float near_val, mat4 m)
{
	float ortho_length = near_val - far_val;
	float ortho_height = top - bottom;
	float ortho_width = right - left;

	// set this to -ve so that we can move the projection
	// to the center;
	vec3f32 ortho_center = {
		.x = -ortho_width,
		.y = -ortho_height,
		.z = -ortho_length,
	};

	mat4 tm;
	mat4_translate(tm, &ortho_center);

	vec3f32 scale = {
		.x = 2.0f / ortho_width,
		.y = 2.0f / ortho_height,
		.z = 2.0f / ortho_length,
	};

	mat4 sm;
	mat4_scale(sm, &scale);

	mat4_multiply(sm, tm, m);
}

void mat4_gen_perspective_proj(float near_val, float far_val, float fov,
							   float aspect_ratio, mat4 m)
{
	float top = tanf(fov / 2) * near_val;
	float bottom = -top;
	float right = top * aspect_ratio;
	float left = -top * aspect_ratio;

	m[0][0] = (2 * near_val)/(right - left);
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;

	m[1][0] = 0.0f;
	m[1][1] = (2 * near_val) / (top - bottom);
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;

	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = -((far_val + near_val) / (far_val - near_val));
	m[2][3] = -(2 * far_val * near_val) / (far_val - near_val);

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = -1.0f;
	m[3][3] = 0.0f;
}

#endif //mat4_H
