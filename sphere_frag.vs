// =======================================
// FRAGMENT SHADER
// Colors the sphere
// =======================================
#version core 330

in vec3 outcolor;
out vec4 FragColor;

int main() {
    FragColor = vec4(outcolor, 1.0);
}