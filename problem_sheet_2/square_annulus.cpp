#include <GL/glut.h>

int windowWidth = 640;
int windowHeight = 480;

bool isMouseInputComplete = false;
int cornerPoints[4][2];

void drawCheckerboard() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the checkerboard
    int squareSize = 50;
    int numRows = windowHeight / squareSize;
    int numCols = windowWidth / squareSize;

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if ((row + col) % 2 == 0) {
                glColor3f(1.0, 1.0, 1.0); // White
            } else {
                glColor3f(0.0, 0.0, 0.0); // Black
            }

            int x = col * squareSize;
            int y = row * squareSize;

            glBegin(GL_QUADS);
            glVertex2i(x, y);
            glVertex2i(x + squareSize, y);
            glVertex2i(x + squareSize, y + squareSize);
            glVertex2i(x, y + squareSize);
            glEnd();
        }
    }

    glFlush();
}

void handleMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (!isMouseInputComplete) {
            cornerPoints[0][0] = x;
            cornerPoints[0][1] = windowHeight - y;

            isMouseInputComplete = true;
        }
    }
}

void handleMouseMotion(int x, int y) {
    if (isMouseInputComplete) {
        cornerPoints[1][0] = x;
        cornerPoints[1][1] = windowHeight - y;

        cornerPoints[2][0] = cornerPoints[0][0];
        cornerPoints[2][1] = cornerPoints[1][1];

        cornerPoints[3][0] = cornerPoints[1][0];
        cornerPoints[3][1] = cornerPoints[0][1];

        glutPostRedisplay();
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Checkerboard");

    init();
    glutDisplayFunc(drawCheckerboard);
    glutMouseFunc(handleMouseClick);
    glutMotionFunc(handleMouseMotion);

    glutMainLoop();
    return 0;
}
