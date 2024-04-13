#include <GL/glut.h>

float angle = 0.0f; // Angle for rotating the objects

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set up the perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    
    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0,  // Camera position
              0.0, 0.0, 0.0,  // Look-at point
              0.0, 1.0, 0.0); // Up vector
    
    // Rotate the objects
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    
    // Draw sample objects
    glColor3f(1.0, 0.0, 0.0); // Red color
    glutWireCube(1.0);        // Draw a wireframe cube
    
    glColor3f(0.0, 1.0, 0.0); // Green color
    glTranslatef(2.0, 0.0, 0.0); // Translate to the right
    glutSolidSphere(1.0, 20, 20); // Draw a solid sphere
    
    glFlush();
}

void update(int value) {
    angle += 1.0f; // Increment the rotation angle
    glutPostRedisplay(); // Mark the window for redisplay
    glutTimerFunc(16, update, 0); // Call update() after 16 milliseconds
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Perspective Projection");
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0); // Call update() initially
    glutMainLoop();
    return 0;
}