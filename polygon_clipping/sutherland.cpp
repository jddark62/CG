//Polygon clipping using Sutherland-Hodgman algorithm
// openGL
// get window coordinates from user using mouse clicks (diagonal points of window)
// get polygon coordinates from user using mouse clicks
// clip the polygon using Sutherland-Hodgman algorithm
// display the original and clipped polygon
// draw the clipped window and original polygon before clipping

#include <iostream>
#include <GL/glut.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
    int x, y;
};

vector<Point> polygon;
vector<Point> window;
vector<Point> clipped_polygon;

bool inside(Point p, Point q, Point r)
{
    int x1 = q.x - p.x;
    int y1 = q.y - p.y;
    int x2 = r.x - q.x;
    int y2 = r.y - q.y;
    int cross_product = x1 * y2 - x2 * y1;
    return cross_product >= 0;
}

Point intersection(Point p1, Point q1, Point p2, Point q2)
{
    Point intersection_point;
    float m1, m2, c1, c2;
    if (p1.x != q1.x)
    {
        m1 = (float)(q1.y - p1.y) / (q1.x - p1.x);
        c1 = p1.y - m1 * p1.x;
    }
    else
    {
        m1 = INFINITY;
        c1 = p1.x;
    }
    if (p2.x != q2.x)
    {
        m2 = (float)(q2.y - p2.y) / (q2.x - p2.x);
        c2 = p2.y - m2 * p2.x;
    }
    else
    {
        m2 = INFINITY;
        c2 = p2.x;
    }
    if (m1 == m2)
    {
        intersection_point.x = INFINITY;
        intersection_point.y = INFINITY;
    }
    else if (m1 == INFINITY)
    {
        intersection_point.x = c1;
        intersection_point.y = m2 * intersection_point.x + c2;
    }
    else if (m2 == INFINITY)
    {
        intersection_point.x = c2;
        intersection_point.y = m1 * intersection_point.x + c1;
    }
    else
    {
        intersection_point.x = (c2 - c1) / (m1 - m2);
        intersection_point.y = m1 * intersection_point.x + c1;
    }
    return intersection_point;
}

void sutherland_hodgman()
{
    for (int i = 0; i < 4; i++)
    {
        vector<Point> input_polygon = clipped_polygon;
        clipped_polygon.clear();
        int n = input_polygon.size();
        for (int j = 0; j < n; j++)
        {
            Point p1 = input_polygon[j];
            Point p2 = input_polygon[(j + 1) % n];
            if (inside(window[i], window[(i + 1) % 4], p1))
            {
                if (!inside(window[i], window[(i + 1) % 4], p2))
                {
                    Point intersection_point = intersection(p1, p2, window[i], window[(i + 1) % 4]);
                    clipped_polygon.push_back(intersection_point);
                }
                clipped_polygon.push_back(p2);
            }
            else if (inside(window[i], window[(i + 1) % 4], p2))
            {
                Point intersection_point = intersection(p1, p2, window[i], window[(i + 1) % 4]);
                clipped_polygon.push_back(intersection_point);
            }
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (auto point : polygon)
    {
        glVertex2i(point.x, point.y);
    }
    glEnd();
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (auto point : clipped_polygon)
    {
        glVertex2i(point.x, point.y);
    }
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    for (auto point : window)
    {
        glVertex2i(point.x, point.y);
    }
    glEnd();
    glFlush();
}

void myinit()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        Point p;
        p.x = x;
        p.y = 500 - y;
        polygon.push_back(p);
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        Point p;
        p.x = x;
        p.y = 500 - y;
        window.push_back(p);
        if (window.size() == 2)
        {
            // Create the window using diagonal points
            Point p1 = window[0];
            Point p2 = window[1];
            window.clear();
            window.push_back(p1);
            window.push_back({p1.x, p2.y});
            window.push_back(p2);
            window.push_back({p2.x, p1.y});
        }
    }
    if (window.size() == 4)
    {
        sutherland_hodgman();
        glutDisplayFunc(display);
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Sutherland-Hodgman");
    myinit();
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

