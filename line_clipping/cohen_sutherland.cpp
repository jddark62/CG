#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

const int window_width = 640;
const int window_height = 480;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

double Xmin, Ymin, Xmax, Ymax;
double x0, y0, x1, y1;

int computeOutCode(double x, double y)
{
    int code = INSIDE;

    if (x < Xmin)
        code |= LEFT;
    else if (x > Xmax)
        code |= RIGHT;
    if (y < Ymin)
        code |= BOTTOM;
    else if (y > Ymax)
        code |= TOP;

    return code;
}

void clipLine()
{
    int outcode0, outcode1;
    bool accept = false, done = false;

    outcode0 = computeOutCode(x0, y0);
    outcode1 = computeOutCode(x1, y1);

    do
    {
        if (!(outcode0 | outcode1))
        {
            accept = true;
            done = true;
        }
        else if (outcode0 & outcode1)
        {
            done = true;
        }
        else
        {
            double x, y;

            int outcodeOut = outcode0 ? outcode0 : outcode1;

            if (outcodeOut & TOP)
            {
                x = x0 + (x1 - x0) * (Ymax - y0) / (y1 - y0);
                y = Ymax;
            }
            else if (outcodeOut & BOTTOM)
            {
                x = x0 + (x1 - x0) * (Ymin - y0) / (y1 - y0);
                y = Ymin;
            }
            else if (outcodeOut & RIGHT)
            {
                y = y0 + (y1 - y0) * (Xmax - x0) / (x1 - x0);
                x = Xmax;
            }
            else
            {
                y = y0 + (y1 - y0) * (Xmin - x0) / (x1 - x0);
                x = Xmin;
            }

            if (outcodeOut == outcode0)
            {
                x0 = x;
                y0 = y;
                outcode0 = computeOutCode(x0, y0);
            }
            else
            {
                x1 = x;
                y1 = y;
                outcode1 = computeOutCode(x1, y1);
            }
        }
    } while (!done);

    if (accept)
    {
        glColor3f(0, 1, 0); // Green color for clipped line
        glBegin(GL_LINES);
        glVertex2f(x0, y0);
        glVertex2f(x1, y1);
        glEnd();
    }
    else
    {
        glColor3f(1, 0, 0); // Red color for outside lines
        glBegin(GL_LINES);
        glVertex2f(x0, y0);
        glVertex2f(x1, y1);
        glEnd();
    }
}

void display()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1); // White color for clipping window
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-window_width / 2, window_width / 2, -window_height / 2, window_height / 2);

    glBegin(GL_LINE_LOOP);
    glVertex2f(Xmin, Ymin);
    glVertex2f(Xmax, Ymin);
    glVertex2f(Xmax, Ymax);
    glVertex2f(Xmin, Ymax);
    glEnd();

    clipLine();

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (x0 == 0 && y0 == 0)
        {
            x0 = (x - window_width / 2);
            y0 = (window_height / 2 - y);
        }
        else
        {
            x1 = (x - window_width / 2);
            y1 = (window_height / 2 - y);
        }

        if (x1 != 0 && y1 != 0)
        {
            display();
            x0 = 0;
            y0 = 0;
        }
    }
}

int main(int argc, char **argv)
{
    Xmin = -100;
    Ymin = -100;
    Xmax = 100;
    Ymax = 100;

    x0 = x1 = y0 = y1 = 0;

    glutInit(&argc, argv);
    glutInitWindowSize(window_width, window_height);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Cohen Sutherland Line Clipping");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}
