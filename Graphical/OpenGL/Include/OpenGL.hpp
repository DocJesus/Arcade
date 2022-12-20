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

        void InitScreen();

        void CloseScreen();

		void Render();

		void DrawShape();

};