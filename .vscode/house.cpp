/*
Draw a house using openGL with defined windows and different gradient filling*/

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void init(void) {
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

void drawHouse(void) {
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
    glVertex2i(-5, 5);
    glVertex2i(-5, 10);
    glVertex2i(5, 10);
    glVertex2i(5, 5);
  glEnd();
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_POLYGON);
    glVertex2i(-2, 5);
    glVertex2i(-2, 7);
    glVertex2i(2, 7);
    glVertex2i(2, 5);
  glEnd();
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_POLYGON);
    glVertex2i(-1, 7);
    glVertex2i(-1, 10);
    glVertex2i(1, 10);
    glVertex2i(1, 7);
  glEnd();
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  drawHouse();
  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("House");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}