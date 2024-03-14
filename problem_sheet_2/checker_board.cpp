#include <GL/glut.h>

int windowWidth = 640;
int windowHeight = 480;
int squareSize = 40;
int numSquaresX = windowWidth / squareSize;
int numSquaresY = windowHeight / squareSize;
bool isWhite = true;

void drawSquare(int x, int y) {
    if (isWhite) {
        glColor3f(1.0, 1.0, 1.0); // White color
    } else {
        glColor3f(0.0, 0.0, 0.0); // Black color
    }

    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + squareSize, y);
    glVertex2f(x + squareSize, y + squareSize);
    glVertex2f(x, y + squareSize);
    glEnd();

    isWhite = !isWhite;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    for (int i = 0; i < numSquaresX; i++) {
        for (int j = 0; j < numSquaresY; j++) {
            drawSquare(i * squareSize, j * squareSize);
        }
        isWhite = !isWhite;
    }

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int squareX = (x / squareSize) * squareSize;
        int squareY = (y / squareSize) * squareSize;
        drawSquare(squareX, squareY);
        glutPostRedisplay();
    }

    // Draw the entire checkerboard again
        for (int i = 0; i < numSquaresX; i++) {
            for (int j = 0; j < numSquaresY; j++) {
                drawSquare(i * squareSize, j * squareSize);
            }
            isWhite = !isWhite;
        }
        
        glFlush();
    }

    


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Checkerboard");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseClick);
    glutMainLoop();
    return 0;
}


