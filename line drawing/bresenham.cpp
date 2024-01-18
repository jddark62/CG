#include <GL/glut.h>
#include <iostream>

// Window size
int windowWidth = 640;
int windowHeight = 480;

// Line coordinates
int x1, y1, x2, y2;

// Algorithm choice
int algorithmChoice = 1; // 1 for Bresenham's algorithm, 2 for DDA algorithm

// Function to draw a line using Bresenham's algorithm
void drawLineBresenham() {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x = x1;
    int y = y1;

    int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
    if (dx < 0) {
        dx1 = -1;
        dx2 = -1;
    } else if (dx > 0) {
        dx1 = 1;
        dx2 = 1;
    }

    if (dy < 0) {
        dy1 = -1;
    } else if (dy > 0) {
        dy1 = 1;
    }

    int longest = abs(dx);
    int shortest = abs(dy);

    if (!(longest > shortest)) {
        longest = abs(dy);
        shortest = abs(dx);
        if (dy < 0) {
            dy2 = -1;
        } else if (dy > 0) {
            dy2 = 1;
        }
        dx2 = 0;
    }

    int numerator = longest >> 1;
    for (int i = 0; i <= longest; i++) {
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        numerator += shortest;
        if (!(numerator < longest)) {
            numerator -= longest;
            x += dx1;
            y += dy1;
        } else {
            x += dx2;
            y += dy2;
        }
    }
}

// Function to draw a line using DDA algorithm
void drawLineDDA() {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = (float)dx / (float)steps;
    float yIncrement = (float)dy / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        x += xIncrement;
        y += yIncrement;
    }
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    if (algorithmChoice == 1) {
        drawLineBresenham();
    } else if (algorithmChoice == 2) {
        drawLineDDA();
    }

    glFlush();
}

// Menu callback function
void menu(int choice) {
    algorithmChoice = choice;
    glutPostRedisplay();
}

// Mouse callback function
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x1 == -1) {
            x1 = x;
            y1 = windowHeight - y;
        } else {
            x2 = x;
            y2 = windowHeight - y;
            glutPostRedisplay();
        }
    }
}

// Initialize OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Line Drawing");

    // Initialize line coordinates
    x1 = -1;
    y1 = -1;
    x2 = -1;
    y2 = -1;

    // Create menu
    glutCreateMenu(menu);
    glutAddMenuEntry("Bresenham's Algorithm", 1);
    glutAddMenuEntry("DDA Algorithm", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    // Register callback functions
    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    // Initialize OpenGL
    init();

    // Start the main loop
    glutMainLoop();

    return 0;
}

