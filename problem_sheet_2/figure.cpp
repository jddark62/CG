#include <GL/glut.h>

// Function to display the graphics
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set up the coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, numMonths, -1000, 8000);
    
    // Plot the sales data
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < numMonths; i++)
    {
        glVertex2f(i, sales[i]);
    }
    glEnd();
    
    // Display the month names
    glColor3f(0.0, 0.0, 0.0); // Black color
    glRasterPos2f(-0.1, -200);
    for (int i = 0; i < numMonths; i++)
    {
        for (const char* c = months[i]; *c != '\0'; c++)
        {
            glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
        }
        glRasterPos2f(i + 0.5, -200);
    }
    
    // Display the x-axis label
    glColor3f(0.0, 0.0, 0.0); // Black color
    glRasterPos2f(numMonths / 2.0, -500);
    const char* xLabel = "Month";
    for (const char* c = xLabel; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    
    // Display the y-axis label
    glColor3f(0.0, 0.0, 0.0); // Black color
    glRasterPos2f(-0.5, 4000);
    const char* yLabel = "Sales Value";
    for (const char* c = yLabel; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    
    glFlush();
}

int main(int argc, char** argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Sales Data");
    
    // Set the display function
    glutDisplayFunc(display);
    
    // Enter the main loop
    glutMainLoop();
    
    return 0;
}
