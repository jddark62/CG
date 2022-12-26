/*
In main(), try the following.
1. change the window size and run it again.
2. change the window position and run it again.
3. change the window title and run it again.
*/

#include <iostream>
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello World");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

