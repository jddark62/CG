#include <GL/glut.h>
#include <cmath>

// Windmill parameters
const float bladeLength = 0.4f;
const float bladeWidth = 0.05f;
const float towerHeight = 0.6f;
const float towerWidth = 0.1f;

// Rotation angle and speed
float angle = 0.0f;
const float rotationSpeed = 360.0f; // One rotation per second

// Function to draw a windmill blade
void drawBlade() {
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(bladeLength, bladeWidth / 2);
    glVertex2f(bladeLength, -bladeWidth / 2);
    glEnd();
}

// Function to draw the windmill
void drawWindmill() {
    // Draw tower
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-towerWidth / 2, 0.0f);
    glVertex2f(towerWidth / 2, 0.0f);
    glVertex2f(towerWidth / 2, towerHeight);
    glVertex2f(-towerWidth / 2, towerHeight);
    glEnd();

    // Draw blades
    glColor3f(0.8f, 0.8f, 0.8f);
    glPushMatrix();
    glTranslatef(0.0f, towerHeight, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    drawBlade();
    glRotatef(120.0f, 0.0f, 0.0f, 1.0f);
    drawBlade();
    glRotatef(120.0f, 0.0f, 0.0f, 1.0f);
    drawBlade();
    glPopMatrix();
}

// Function to update the rotation angle
void updateAngle(int value) {
    angle += rotationSpeed / 60.0f; // 60 frames per second
    if (angle > 360.0f) {
        angle -= 360.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, updateAngle, 0);
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    gluOrtho2D(-screenWidth / 1000.0, screenWidth / 1000.0, -screenHeight / 1000.0, screenHeight / 1000.0);
    drawWindmill();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Windmill Animation");
    glutDisplayFunc(display);
    glutTimerFunc(0, updateAngle, 0);
    glutMainLoop();
    return 0;
}
