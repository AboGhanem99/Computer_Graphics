
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"

GLuint VBO; // Create a new VBO

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);       // it clears buffers to preset values..

    glEnableVertexAttribArray(0);// Enable attribute index 0 as being used
    //Bind our first VBO as being the active buffer and storing vertex attributes (coordinates)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);  
    // Specify that our coordinate data is going into attribute index 0, and contains 3 floats per vertex
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);  
   
    glDrawArrays(GL_TRIANGLES, 0, 3); // Start drawing geometric shapes (draw a dots).

    glDisableVertexAttribArray(0); // cleanup work, undoing some of the setup that was done for the purposes of rendering.

    glutSwapBuffers();
}

static void CreateVertexBuffer()
{
    Vector3f Vertices[3];
    glColor3f(0.0f, 0.0f, 1.0f);
    Vertices[0] = Vector3f(-1.f, -1.f, 0.0f); // bottom left
    Vertices[1] = Vector3f(01.f, -1.f, 0.0f);  // bottom right
    Vertices[2] = Vector3f(0.0f, 01.f, 0.0f);   // top
   
    glGenBuffers(1, &VBO); 
    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

int main(int argc, char** argv)
{

    int Width = 800;
    int Height = 400;
    int x = 500;
    int y = 250;
    GLclampf Red = 1.1f, Greeen = 0.1f, Blue = 0.1f, Alpha = 0.0f;


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 

    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(x, y);
    glClearColor(Red, Greeen, Blue, Alpha);
    glutCreateWindow("First triangle");

    glutDisplayFunc(RenderSceneCB); 

    //Check if GLEW is ready 
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cout << "glewInit failed: " << glewGetErrorString(err) << std::endl;
        exit(1);
    }

  
    CreateVertexBuffer(); // Create a vertex buffer

    glutMainLoop();  // Run the inner GLUT loop

    return 0;
}
