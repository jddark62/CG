#include <GL/glut.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int MAX_POINTS = 100;

int numPoints = 0;
int points[MAX_POINTS][2];
int lineColorIndex = 0;
GLfloat lineColors[][3] = {
    {1.0, 0.0, 0.0}, // Red
    {0.0, 1.0, 0.0}, // Green
    {0.0, 0.0, 1.0}, // Blue
    {1.0, 1.0, 0.0}, // Yellow
    {1.0, 0.0, 1.0}, // Magenta
    {0.0, 1.0, 1.0}  // Cyan
};

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    for (int i = 0; i < numPoints - 1; i++) {
        glColor3fv(lineColors[i % 6]);
        glBegin(GL_LINES);
        glVertex2i(points[i][0], points[i][1]);
        glVertex2i(points[i + 1][0], points[i + 1][1]);
        glEnd();
    }
    
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (numPoints >= MAX_POINTS) {
            numPoints = 0; // Reset points array if maximum number of points reached
        }
        
        points[numPoints][0] = x;
        points[numPoints][1] = SCREEN_HEIGHT - y; // Invert y-coordinate to match OpenGL coordinate system
        numPoints++;
        
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    
    return 0;
}
