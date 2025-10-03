#include "render.h"

#include <iostream>
#include <cstdio>

#define SCR_WIDTH 800
#define SCR_HEIGHT 600


int main(){
    // fg_utils::CreateDebugConsole();
    auto window = fg_window::Window(L"Game", SCR_WIDTH, SCR_HEIGHT);

    fg_gl::ShaderProgram program("./assets/shaders/v.glsl", "./assets/shaders/f.glsl");


    float vertices[] = {
        // first triangle
        -0.9f, -0.5f, 0.0f,  // left 
        -0.0f, -0.5f, 0.0f,  // right
        -0.45f, 0.5f, 0.0f,  // top 
        // second triangle
         0.0f, -0.5f, 0.0f,  // left
         0.9f, -0.5f, 0.0f,  // right
         0.45f, 0.5f, 0.0f   // top 
    }; 

    fg_gl::VAO vao;
    fg_gl::VBO<float> vbo(vertices, 3, 6, GL_FLOAT, GL_STATIC_DRAW, 0);

    vbo.SetAttr(3, GL_FALSE);
    vao.UnBind();
    vbo.UnBind();


    fg_interact::Event event;
    while(true){
        if(fg_interact::PollEvent(&event)){
            std::cout << "Main Loop Get Event: "
                    << event.type << std::endl;
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        program.Use();
        vao.Bind();
        glDrawArrays(GL_TRIANGLES, 0, 6); // set the count to 6 since we're drawing 6 vertices now (2 triangles); not 3!

        window.SwapBuffer();

    }
}