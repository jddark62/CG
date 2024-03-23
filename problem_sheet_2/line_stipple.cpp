#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set the line stipple pattern
    glEnable(GL_LINE_STIPPLE);
    // 0xAAAA is the pattern for a dashed line
    glLineStipple(1, 0xAAAA);
    
    // Draw a line
    glBegin(GL_LINES);
    glVertex2f(-0.5, 0.0);
    glVertex2f(0.5, 0.0);
    glEnd();
    
    // Set the polygon stipple pattern
    glEnable(GL_POLYGON_STIPPLE);
    GLubyte pattern[] = {
        0xFF, 0x00, 0xFF, 0x00,
        0x00, 0xFF, 0x00, 0xFF,
        0xFF, 0x00, 0xFF, 0x00,
        0x00, 0xFF, 0x00, 0xFF
    };
    glPolygonStipple(pattern);
    
    // Draw a polygon
    glBegin(GL_POLYGON);
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
    glutInitWindowSize(400, 400);
    glutCreateWindow("Line and Polygon Stipple");
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
