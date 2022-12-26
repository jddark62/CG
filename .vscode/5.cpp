// draw a house with a door and a window

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

void init(void) {
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

int main
