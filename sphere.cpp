// =====================================================================
// Author: Tristen Woodruff
// Date: May 4th, 2022 (may the fourth be with u)
// 
// Creates a sphere on the screen.
// Has some color on the poles and around it.
// Provides different ways of drawing the sphere as there exists several different ways.
// Maybe add some spinning once done.
// Basic algo:
// 1. Create a triangle (vertex shader, fragment shader, vertices, indices, colors)
// 2. Tesselate it (any degree of precision)  
// 3. Change normals to point away from the center (map into a sphere)
// 4. Gonna need some 3D projection with MVP (model, view, projection, GLM library, basic camera, won't need a class)
// (Optional) 5. Rotate it
// (Optional) 6. Change color
// (Optional) 8. Add textures
// (Optional) 7. Translate it around (move the center)
// (Optional) 8. Dynamic radius (non-const)
// (Optional) 9. Sphere class -> list of sphere objects -> draw them
// (Optional) 10. Light object to light spheres and stuff (light object, light position, light color, fragment shader)
// 
// Look into sphere drawing algos (the one used above is the first I found). What about fibonacci way?
// Theres also the one that normalizes a cube after tesselation into a sphere (more complex)

// =====================================================================

#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// ========================
// Global vars
// ========================
const GLuint width                  = 640,
       height                       = 480;
constexpr GLfloat aspect_ratio      = (GLfloat)(width / height);
const GLfloat radius                = 1.0f;
const GLfloat diameter              = (2.0f) * radius;
const GLfloat pi                    = 3.14159f;


// ========================
// Triangle
// X, Y, Z, R, G, B
// 3 Vertices
// ========================
static const struct {
    GLfloat x, y, z, 
            r, g, b;
} basic_triangle[3] = {
    {-1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f},
    {-1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f},
    {1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f}
};

// ========================
// Function declarations
// ========================
void input_callback(GLFWwindow* handle, int key, int s, int action, int mods);
void reshape_callback(GLFWwindow* handle, int width, int height);
void draw();
void destroy(GLFWwindow* handle, int exitcode = EXIT_SUCCESS);

void input_callback(GLFWwindow* handle, int key, int s, int action, int mods) {
    switch (key) {
    case GLFW_KEY_ESCAPE:
        destroy(handle);
        break;
    }
}

void reshape_callback(GLFWwindow* handle, int width, int height) {
    // Set the viewport to the entire window when resized
    glViewport(0, 0, width, height);
}

// =========================
// Draw elements to the screen
// Mostly the sphere and setting the colors
// =========================
void draw() { 

}

// ==========================
// Destroys the program
// ==========================
void destroy(GLFWwindow* handle, int exitcode) {
    glfwDestroyWindow(handle);
    glfwTerminate();
    exit(exitcode);
}

// ==========================
// Main method
// Instantiates window, main loop
// ==========================
int main() {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }

    // Set the window hints (version, GL profile, window)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create the window that returns a GLFWwindow pointer
    static GLFWwindow * const handle = glfwCreateWindow(width, height, "Sphere", NULL, NULL);
    if (!handle) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Set the callbacks for keyboard, window resizing
    glfwSetFramebufferSizeCallback(handle, reshape_callback);
    glfwSetKeyCallback(handle, input_callback);

    // Make GLFW use our window, make glad load GL from GLFW, and set the swap interval to every frame
    glfwMakeContextCurrent(handle);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSwapInterval(1);

    // Main loop (will run when window is opened)
    while (!glfwWindowShouldClose(handle)) {
        // FPS counter?

        // Colored background and clear the buffer
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draws to the screen
        // draw();

        // Animates based on ingame time (glfwGetTime())
        // animate();


        // Swap the buffer and poll any events that occur (calls to keyboard and mouse and window)
        glfwSwapBuffers(handle);
        glfwPollEvents(); 

    }

    // End the program
    destroy(handle);
}