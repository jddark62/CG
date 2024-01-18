#include <GL/glut.h>

void drawHouse() {
  // Draw house body
  glBegin(GL_QUADS);
  glColor3f(0.8f, 0.6f, 0.4f); // Brown color
  glVertex2f(-0.5f, -0.5f);
  glVertex2f(0.5f, -0.5f);
  glVertex2f(0.5f, 0.5f);
  glVertex2f(-0.5f, 0.5f);
  glEnd();

  // Draw roof
  glBegin(GL_TRIANGLES);
  glColor3f(0.9f, 0.2f, 0.2f); // Red color
  glVertex2f(-0.6f, 0.5f);
  glVertex2f(0.6f, 0.5f);
  glVertex2f(0.0f, 1.0f);
  glEnd();

  // Draw windows
  glBegin(GL_QUADS);
  glColor3f(0.9f, 0.9f, 0.9f); // White color
  glVertex2f(-0.3f, -0.2f);
  glVertex2f(-0.1f, -0.2f);
  glVertex2f(-0.1f, 0.0f);
  glVertex2f(-0.3f, 0.0f);

  glVertex2f(0.1f, -0.2f);
  glVertex2f(0.3f, -0.2f);
  glVertex2f(0.3f, 0.0f);
  glVertex2f(0.1f, 0.0f);
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  // Set up orthographic projection
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

  // Draw the house
  drawHouse();

  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 600); // Set the window size here
  glutCreateWindow("House");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
