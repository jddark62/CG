/*
Divide the entire screen into 4 quadrants, by drawing the coordinate axes.
a. Draw a green triangle.
b. Draw a blue quadrilateral.
*/

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void init(void) {
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

void drawTriangle(void) {
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_LINE_LOOP);
    glVertex2i(0, 0);
    glVertex2i(5, 5);
    glVertex2i(5, 0);
  glEnd();
}

void drawQuadrilateral(void) {
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_LINE_LOOP);
    glVertex2i(0, 0);
    glVertex2i(0, -5);
    glVertex2i(5, -5);
    glVertex2i(5, 0);
  glEnd();
}

// Draw a quadrilateral with alternating red and blue vertices. 
// Should be drawn in the lower left quadrant.
void drawQuadrilateral2(void) {
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_LINE_LOOP);
    glVertex2i(-5, -5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(-5, -10);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(0, -10);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(0, -5);
  glEnd();
}

// draw an octagon with vertices of different colors 
// should be filled in the upper left quadrant
// should be drawn in the upper left quadrant
void drawOctagon(void) {
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
    glVertex2i(-5, 5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(-5, 10);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(0, 10);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2i(5, 5);
    glColor3f(1.0, 0.0, 1.0);
    glVertex2i(5, 0);
    glColor3f(0.0, 1.0, 1.0);
    glVertex2i(0, -5);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(-5, 0);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(-5, 5);
  glEnd();
}