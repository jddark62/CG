#include <GL/glut.h>
#include <iostream>

// Screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Clipping window coordinates
int clipXMin, clipYMin, clipXMax, clipYMax;

// Line to be clipped
int lineX1, lineY1, lineX2, lineY2;

void drawClippingWindow() {
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(clipXMin, clipYMin);
        glVertex2i(clipXMax, clipYMin);
        glVertex2i(clipXMax, clipYMax);
        glVertex2i(clipXMin, clipYMax);
    glEnd();
    glFlush();
}

void drawClippedLine() {
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex2i(lineX1, lineY1);
        glVertex2i(lineX2, lineY2);
    glEnd();
    glFlush();
}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Store the clipping window coordinates
        if (clipXMin == -1) {
            clipXMin = x;
            clipYMin = SCREEN_HEIGHT - y;
        } else if (clipXMax == -1) {
            clipXMax = x;
            clipYMax = SCREEN_HEIGHT - y;
        } else {
            // Store the line coordinates
            if (lineX1 == -1) {
                lineX1 = x;
                lineY1 = SCREEN_HEIGHT - y;
            } else if (lineX2 == -1) {
                lineX2 = x;
                lineY2 = SCREEN_HEIGHT - y;
                drawClippingWindow();
                drawClippedLine();
            }
        }
    }
}

int main(int argc, char** argv) {
    clipXMin = -1;
    clipYMin = -1;
    clipXMax = -1;
    clipYMax = -1;

    lineX1 = -1;
    lineY1 = -1;
    lineX2 = -1;
    lineY2 = -1;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Liang-Barsky Line Clipping");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(drawClippingWindow);
    glutMouseFunc(mouseClick);
    glutMainLoop();

    return 0;
}
