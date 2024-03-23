#include <GL/glut.h>
#include<bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include<iostream>
#include<vector>

using namespace std;


class Point{
    public :
    int x, y;
};

struct Color {
    float r,g,b;
};
vector<Point> points;
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,1);
    //glPointSize(5.0);
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glBegin(GL_LINES);
        glVertex2f(0,0);
        glVertex2f(130.0,0);

    glEnd();
    glFlush();
}
void Init()
{
  glClearColor(1.0,1.0,1.0,0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0 , 640 , 0 , 480);
}

void drawPolygon()
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<points.size();i++)
    {
        glVertex2f(points[i].x,points[i].y);
    }
    glEnd();
    glFlush();

}

void yx() 
{
    for(int y = 0; y <=480 ; y++)
    {      // For each scan line
        vector<int> intersections;
        int n = points.size();

        for(int i = 0, j = 1; i < n; i++, j = (++j) % n) 
        {      // For each edge

            int y1 = points[i].y;
            int y2 = points[j].y;

            if(y1 < y2) 
            {
                if(y >= y1 && y < y2) 
                {
                    int x = (y - y1) * (points[j].x - points[i].x) / (y2 - y1) + points[i].x;
                    intersections.push_back(x);
                }
            } 
            else 
            {
                if (y >= y2 && y < y1) 
                {
                    int x = (y - y1) * (points[j].x - points[i].x) / (y2 - y1) + points[i].x;
                    intersections.push_back(x);
                }
            }
        }

        sort(intersections.begin(), intersections.end());
        int m = intersections.size();

        glColor3f(0, 1, 0);
        for(int i = 0; i < m; i += 2) 
        {
            int x1 = intersections[i];
            int x2 = intersections[i + 1];
            for (int i=x1;i<=x2;i++)
            {
                glBegin(GL_POINTS);
                    glVertex2i(i,y);
                glEnd();
                glFlush();
            }
        }
    }

    cout<<"Finished filling!\n";



}




void handleMouse(int button,int state , int x_loc,int y_loc)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        int x = x_loc;
        int y = 480 - y_loc;
        points.push_back({x,y});
        glPointSize(1);
        glBegin(GL_POINTS);
            glVertex2f(x,y);
        glEnd();
        glFlush();
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        int x = x_loc;
        int y = 480 - y_loc;
        drawPolygon();

        struct Color old_col={1.0,0.0,0.0};
        struct Color new_col={1.0,1.0,0.0};
        int x_start =0;
        int y_start =0;
        for(int i=0;i<points.size();i++)
        {
            x_start+=points[i].x;
            y_start+=points[i].y;
        }
        x_start= x_start/points.size();
        y_start = y_start/points.size();
        //flood(x_start,y_start,old_col,new_col);
        yx();
        //boundary_fill(x_start,y_start,new_col,old_col);
    }
}


int main(int argc, char **argv)
{

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640, 480);
glutInitWindowPosition(10, 10);
glutCreateWindow("Flood fill");
Init();
glutDisplayFunc(display);
glutMouseFunc(handleMouse);

glutMainLoop();
}