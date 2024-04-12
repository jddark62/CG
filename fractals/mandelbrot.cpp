#include <GL/glut.h>

const int WIDTH = 800;
const int HEIGHT = 800;
const double X_MIN = -2.0;
const double X_MAX = 1.0;
const double Y_MIN = -1.5;
const double Y_MAX = 1.5;
const int MAX_ITERATIONS = 100;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_POINTS);

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            double zx = 0;
            double zy = 0;
            double cx = X_MIN + (x / (double)WIDTH) * (X_MAX - X_MIN);
            double cy = Y_MIN + (y / (double)HEIGHT) * (Y_MAX - Y_MIN);

            int iterations = 0;
            while (zx * zx + zy * zy < 4 && iterations < MAX_ITERATIONS)
            {
                double xtemp = zx * zx - zy * zy + cx;
                zy = 2 * zx * zy + cy;
                zx = xtemp;
                iterations++;
            }

            if (iterations == MAX_ITERATIONS)
            {
                glColor3f(0, 0, 0); // Black
            }
            else
            {
                float t = iterations / (float)MAX_ITERATIONS;
                glColor3f(t, t, t); // Shades of gray
            }

            glVertex2i(x, y);
        }
    }

    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Mandelbrot Fractal");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

