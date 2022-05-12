// =======================================
// VERTEX SHADER
// Tesselation occurs after
// =======================================
#version core 330

layout (location = 0) in vec3 xyz; // Position xyz
layout (location = 1) in vec3 rgb // Color rgb

out vec3 outcolor;

int main() {
    gl_Position = vec4(xyz, 1.0);
    outcolor = rgb;
}