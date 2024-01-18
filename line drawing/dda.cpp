// Implement the DDA algorithm for line drawing.
// Get the input from the user.
// Input: two points using mouse input from the user
// Output: line joining the two points
// Resolution of screen is 640x480
// Adjust mouse coordinates to fit the screen resolution
// Use openGL

#include <iostream>
#include <GL/glut.h>
using namespace std;

float x1, y1, x2, y2;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // set display-window color to black
    glMatrixMode(GL_PROJECTION); // set projection parameters
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void lineDDA(void) {
    float dx = x2 - x1, dy = y2 - y1, steps, xIncrement, yIncrement, x = x1, y = y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xIncrement = dx / steps;
    yIncrement = dy / steps;

    glClear(GL_COLOR_BUFFER_BIT); // clear display window

    glBegin(GL_POINTS); // plot the points
    glVertex2i(x, y); // plot first point

    for (int i = 0; i < steps; i++) {
        x += xIncrement;
        y += yIncrement;
        glVertex2i(x, y); // plot intermediate points
    }

    glEnd();
    glFlush();
}

void mouse(int button, int state, int mousex, int mousey) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        x1 = mousex;
        y1 = 480 - mousey;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        x2 = mousex;
        y2 = 480 - mousey;
        lineDDA();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
    glutInitWindowPosition(50, 100); // set top-left display-window position
    glutInitWindowSize(640, 480); // set display-window width and height
    glutCreateWindow("DDA Line Drawing Algorithm"); // create display window

    init(); // execute initialization procedure
    glutDisplayFunc(lineDDA); // send graphics to display window
    glutMouseFunc(mouse); // call mouse function
    glutMainLoop(); // display everything
    return 0;
}