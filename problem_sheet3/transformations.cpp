#include <GL/glut.h>
#include <iostream>
#include <cmath>

// Screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Polygon vertices
float polygonVertices[4][2];
int numVertices = 0;

// Transformation variables
float rotationAngle = 0.0f;
float scalingFactor = 1.0f;
float translationX = 0.0f;
float translationY = 0.0f;

// Function to draw the polygon
void drawPolygon() {
    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; i++) {
        glVertex2f(polygonVertices[i][0], polygonVertices[i][1]);
    }
    glEnd();
}

// Function to perform rotation transformation
void rotatePolygon() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(translationX, translationY, 0.0f);
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-translationX, -translationY, 0.0f);
}

// Function to perform scaling transformation
void scalePolygon() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(translationX, translationY, 0.0f);
    glScalef(scalingFactor, scalingFactor, 1.0f);
    glTranslatef(-translationX, -translationY, 0.0f);
}

// Function to perform translation transformation
void translatePolygon() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(translationX, translationY, 0.0f);
}

// Mouse click event handler
void onMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (numVertices < 4) {
            polygonVertices[numVertices][0] = (float)x / SCREEN_WIDTH;
            polygonVertices[numVertices][1] = 1.0f - (float)y / SCREEN_HEIGHT;
            numVertices++;
        }
    }
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    // Draw the polygon
    drawPolygon();

    // Apply transformations based on user input
    if (rotationAngle != 0.0f) {
        rotatePolygon();
    } else if (scalingFactor != 1.0f) {
        scalePolygon();
    } else if (translationX != 0.0f || translationY != 0.0f) {
        translatePolygon();
    }

    // Draw the transformed polygon
    glColor3f(0.0f, 1.0f, 0.0f);
    drawPolygon();

    glFlush();
}

// Menu callback function
void menu(int choice) {
    switch (choice) {
        case 1:
            std::cout << "Enter rotation angle (in degrees): ";
            std::cin >> rotationAngle;
            break;
        case 2:
            std::cout << "Enter scaling factor: ";
            std::cin >> scalingFactor;
            break;
        case 3:
            std::cout << "Enter translation in X direction: ";
            std::cin >> translationX;
            std::cout << "Enter translation in Y direction: ";
            std::cin >> translationY;
            break;
        case 4:
            rotationAngle = 0.0f;
            scalingFactor = 1.0f;
            translationX = 0.0f;
            translationY = 0.0f;
            break;
        case 5:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Transformations");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);

    glutDisplayFunc(display);
    glutMouseFunc(onMouseClick);

    // Create menu
    glutCreateMenu(menu);
    glutAddMenuEntry("Rotate", 1);
    glutAddMenuEntry("Scale", 2);
    glutAddMenuEntry("Translate", 3);
    glutAddMenuEntry("Reset", 4);
    glutAddMenuEntry("Exit", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
