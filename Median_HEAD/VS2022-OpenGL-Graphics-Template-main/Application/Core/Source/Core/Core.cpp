#include "Core.h"

// std includes
#include <iostream>

// window and opengl bindings
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// GUI
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

// maths
#include <glm\glm.hpp>

// image reading
#include <stb_image.h>


// Vertex shader source code
const char* vertexShaderSource = R"(
#version 330 core
layout(location = 0) in vec3 aPos;
void main()
{
    gl_Position = vec4(aPos, 1.0);
}
)";

// Fragment shader source code
const char* fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;
void main()
{
    FragColor = vec4(1.0, 0.5, 0.2, 1.0);
}
)";


namespace Core 
{
    

	void PrintHelloWorld()
	{
        std::cout << "Hello World!\n" << std::endl;;
	}
    
    
    void DoGraphicsSomething() 
    {
        
        // Initialize GLFW
        if (!glfwInit()) 
        {
            std::cerr << "Failed to initialize GLFW" << std::endl;
        }

        // Create a windowed mode window and its OpenGL context
        GLFWwindow* window = glfwCreateWindow(1280, 960, "App-Core Graphics Template", NULL, NULL);

        if (!window) 
        {
            glfwTerminate();
            std::cerr << "Failed to create GLFW window" << std::endl;
            return;
        }

        // Make the window's context current
        glfwMakeContextCurrent(window);

        // Initialize GLEW
        if (glewInit() != GLEW_OK) 
        {
            std::cerr << "Failed to initialize GLEW" << std::endl;
            return;
        }

        // Setup ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;

        // Setup ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsClassic();

        // Setup Platform/Renderer bindings
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 130");



        // Define the vertex data for a triangle
        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f
        };

        // Create a vertex buffer object (VBO)
        GLuint VBO;
        glGenBuffers(1, &VBO);

        // Create a vertex array object (VAO)
        GLuint VAO;
        glGenVertexArrays(1, &VAO);

        // Bind the VAO
        glBindVertexArray(VAO);

        // Bind the VBO
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // Define the vertex attributes
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Create and compile the vertex shader
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);

        // Check for shader compile errors
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        // Create and compile the fragment shader
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);

        // Check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        // Link shaders to create a shader program
        GLuint shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        // Check for linking errors
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }

        // Clean up shaders as they're no longer needed
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);



        // Main loop
        while (!glfwWindowShouldClose(window)) 
        {
            // Poll for and process events
            glfwPollEvents();

            // Render here
            glClear(GL_COLOR_BUFFER_BIT);

            // Start the ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            // Create a simple ImGui window
            ImGui::Begin("Hello, world!");
            ImGui::Text("Bla bla bla bla bla. ^^;");
            ImGui::End();

            // Show demo window
            ImGui::ShowDemoWindow();

            // Rendering
            ImGui::Render();
            glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Render the triangle
            glUseProgram(shaderProgram);
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);

            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            // Swap front and back buffers
            glfwSwapBuffers(window);
        }

        // Cleanup ImGui
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();


        // Cleanup glfw
        glfwDestroyWindow(window);
        glfwTerminate();

        // Cleanup OpenGL resources
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteProgram(shaderProgram);
        
    }
    
}