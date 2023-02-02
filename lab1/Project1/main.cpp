#include <GL/freeglut.h>
#include <stdio.h>


static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    int Width = 800;
    int Height = 400;
    int x = 500;
    int y = 250;

    glutInit(&argc, argv); //initializes GLUT.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 


    glutInitWindowSize(Width, Height); 

    glutInitWindowPosition(x, y);
    glutCreateWindow ("My Window");


    GLclampf Red = 0.0f, Greeen = 0.0f, Blue = 0.0f, Alpha = 0.0f;
    glClearColor(Red, Greeen, Blue, Alpha);

    glutDisplayFunc(RenderSceneCB);

    glutMainLoop();

    return 0;
}