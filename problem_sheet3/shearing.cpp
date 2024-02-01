#include <GL/glut.h>


int windowWidth = 400;
int windowHeight = 400;

void display() {
    glViewport(0, 0, windowWidth, windowHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1, 0, 1, -1, 1);
    
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Draw the original polygon
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(0.25f, 0.25f);
    glVertex2f(0.75f, 0.25f);
    glVertex2f(0.75f, 0.75f);
    glVertex2f(0.25f, 0.75f);
    glEnd();
    
    // Apply shear transformation
    float shearX = 0.5f; // Shear in X direction
    float shearY = 0.2f; // Shear in Y direction
    
    glTranslatef(0.5f, 0.5f, 0.0f); // Translate to the center of the square
    
    float shearMatrix[16] = {
        1.0f, shearY, 0.0f, 0.0f,
        shearX, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    
    glMultMatrixf(shearMatrix); // Apply shear transformation matrix
    
    glTranslatef(-0.5f, -0.5f, 0.0f); // Translate back to the original position
    
    // Draw the unit square
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glVertex2f(0.25f, 0.25f);
    glVertex2f(0.75f, 0.25f);
    glVertex2f(0.75f, 0.75f);
    glVertex2f(0.25f, 0.75f);
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Shear Transformation");
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}

// run using g++ -std=c++11 shear.cpp -lGL -lGLU -lglut