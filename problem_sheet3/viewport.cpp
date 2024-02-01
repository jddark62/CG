#include <GL/glut.h>

int screenWidth, screenHeight;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw first viewport
    glViewport(0, 0, screenWidth / 2, screenHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();
    
    // Draw second viewport
    glViewport(screenWidth / 2, 0, screenWidth / 2, screenHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    // Get screen resolution
    screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Two Viewports");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

// run with: g++ viewport.cpp -lglut -lGL -lGLU -o viewport