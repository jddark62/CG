// Use openGL to draw a circle using midpoint algorithm
// Menu driven program to draw a circle using midpoint algorithm
// Menu should have options to change the center and radius of the circle
// Centre and radius will be taken as input from the user after selecting the option from the menu
// Redraw the circle after every change in the center or radius


#include <iostream>
#include <GL/glut.h>

int centerX, centerY, radius;
bool redrawCircle = false;

void drawCircle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    int deltaE = 3;
    int deltaSE = -2 * radius + 5;
    glVertex2i(centerX + x, centerY + y);
    glVertex2i(centerX + x, centerY - y);
    glVertex2i(centerX - x, centerY + y);
    glVertex2i(centerX - x, centerY - y);
    while (y > x) {
        if (d < 0) {
            d += deltaE;
            deltaE += 2;
            deltaSE += 2;
        } else {
            d += deltaSE;
            deltaE += 2;
            deltaSE += 4;
            y--;
        }
        x++;
        glVertex2i(centerX + x, centerY + y);
        glVertex2i(centerX + x, centerY - y);
        glVertex2i(centerX - x, centerY + y);
        glVertex2i(centerX - x, centerY - y);
        glVertex2i(centerX + y, centerY + x);
        glVertex2i(centerX + y, centerY - x);
        glVertex2i(centerX - y, centerY + x);
        glVertex2i(centerX - y, centerY - x);
    }
    glEnd();
    glFlush();
    redrawCircle = false;
}

void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    if (redrawCircle) {
        drawCircle();
    }
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

void menu(int choice) {
    switch (choice) {
        case 1:
            std::cout << "Enter the center X coordinate: ";
            std::cin >> centerX;
            std::cout << "Enter the center Y coordinate: ";
            std::cin >> centerY;
            redrawCircle = true;
            break;
        case 2:
            std::cout << "Enter the radius: ";
            std::cin >> radius;
            redrawCircle = true;
            break;
        case 3:
            redrawCircle = true;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle Drawing");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutCreateMenu(menu);
    glutAddMenuEntry("Change Center", 1);
    glutAddMenuEntry("Change Radius", 2);
    glutAddMenuEntry("Redraw Circle", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}

// g++ circle.cpp -lGL -lGLU -lglut -o circle
// ./circle

