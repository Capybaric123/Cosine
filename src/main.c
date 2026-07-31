#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "log.h"
#include "fbSizeCallback.h"
#include "processInput.h"

int main()
{
    log_trace("Logger initialized successfully!");

    if(!glfwInit())
    {
        log_error("Failed to initialize GLFW!");
        return -1;
    }
    log_trace("GLFW initialized successfully!");
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    log_trace("Set GLFW version context!");
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    log_trace("Set GLFW openGL profile!");

    GLFWwindow* window = glfwCreateWindow(640, 480, "Cosine", NULL, NULL);
    if(window == NULL)
    {
        log_error("Failed to create GLFW window!");
        glfwTerminate();
        return -1;
    }
    log_trace("Successfully created GLFW window!");
    glfwMakeContextCurrent(window);
    log_trace("Set openGL window context!");

    int version = gladLoadGL(glfwGetProcAddress);
    if(version == 0)
    {
        log_error("Failed to initialize GLAD!");
        glfwTerminate();
        return -1;
    }
    log_info("Loaded OpenGL %d.%d",
             GLAD_VERSION_MAJOR(version),
             GLAD_VERSION_MINOR(version));
    glViewport(0, 0, 640, 480);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        processInput(window);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
