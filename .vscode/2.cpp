/*
Comment out the following and write the feedback ; Uncomment it when you are
done.
1. The call to glutInit() and then run the program to see what happens.
2. The call to glutInitDisplayMode() and then run the program to see what happens.
3. The call to glutInitWindowSize() and then run the program to see what happens.
4. The call to glutInitWindowPosition() and then run the program to see what
happens.
5. The call to glutCreateWindow() and then run the program to see what happens.
We should always make these five function calls, even if it seemed to make no
difference in this experiment.*/

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