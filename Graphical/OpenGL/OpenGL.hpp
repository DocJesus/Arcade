#include "AGraphic.hpp"
#include "Error.hpp"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Common/shader.hpp>

#define WIDTH 120
#define HEIGHT 40 

struct triangle
{
	float botLeft_x;
	float botLeft_y;
	float botLeft_z;
	float botRight_x;
	float botRight_y;
	float botRight_z;
	float up_x;
	float up_y;
	float up_z;

};

class OpenGL
{
    private:
        GLFWwindow* window;
		GLuint VertexArrayID;
		GLuint programID;
		GLuint vertexbuffer;

    public:
        OpenGL()
        {}
        virtual ~OpenGL()
        {
			this->CloseScreen();
		}

        void InitScreen()
        {
			// Initialise GLFW
			if( !glfwInit() )
			{
				throw Error("Failed to initialize GLFW\n");
				return;
			}

			glfwWindowHint(GLFW_SAMPLES, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			// Open a window and create its OpenGL context
			// todo use the currenct window
			this->window = glfwCreateWindow( 1024, 768, "Tutorial 02 - Red triangle", NULL, NULL);

			if(this->window == NULL ){
				throw Error("Failed to open GLFW window.\n" );
				getchar();
				glfwTerminate();
				return;
			}
			glfwMakeContextCurrent(this->window);

			// Initialize GLEW
			glewExperimental = true; // Needed for core profile
			if (glewInit() != GLEW_OK) {
				throw Error("Failed to initialize GLEW\n");
				getchar();
				glfwTerminate();
				return;
			}

			// Ensure we can capture the escape key being pressed below
			// todo : this will change for sure
			glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);


			// Dark blue background
			glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

			// create a Vertex Array Object -> use for ????
			glGenVertexArrays(1, &this->VertexArrayID);
			glBindVertexArray(this->VertexArrayID);

        }

        void CloseScreen()
		{
			// Cleanup VBO
			glDeleteBuffers(1, &this->vertexbuffer);
			glDeleteVertexArrays(1, &this->VertexArrayID);
			glDeleteProgram(this->programID);

			// Close OpenGL window and terminate GLFW
			glfwTerminate();
		}

		void Render()
		{
			this->DrawShape();

			// Clear the screen
			glClear( GL_COLOR_BUFFER_BIT );
			// Use our shader
			glUseProgram(programID);
			// 1rst attribute buffer : vertices
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			glVertexAttribPointer(
				0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
				3,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				(void*)0            // array buffer offset
			);

			// Draw the triangle !
			glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
			glDisableVertexAttribArray(0);

			// Swap buffers
			glfwSwapBuffers(this->window);
			glfwPollEvents();

			while( glfwGetKey(this->window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
				glfwWindowShouldClose(this->window) == 0 );

		}

		void DrawShape()
		{
			this->programID = LoadShaders( "Graphical/Shaders/SimpleVertexShader.vertexshader", "Graphical/Shaders/SimpleFragmentShader.fragmentshader" );

			static const GLfloat g_vertex_buffer_data[] = { 
				-1.0f, -1.0f, 0.0f,
				1.0f, -1.0f, 0.0f,
				0.0f,  1.0f, 0.0f,
			};

			glGenBuffers(1, &this->vertexbuffer);
			glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
			glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
		}

};