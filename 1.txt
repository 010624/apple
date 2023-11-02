#include<stdio.h>
#include<GL/glut.h>
void display()
{
glClear(GL_COLOR_BUFFER_BIT); //To Clear the buffer
glColor3f(0.0, 0.5, 1.0); // To change the color of the object
glClearColor(1,1, 1, 1); // To change the background color
glLineWidth(8);
glBegin(GL_LINES); //OpenGL Basic Primitives to draw a line
glVertex2f(0.0, 0.0); //Coordinates of starting vertex
glVertex2f(0.0, 0.5); //Coordinates of starting vertex
glEnd(); //To delimit the vertices of primitive
glFlush(); //Empties the buffer and forces other commands to execute
}
int main(int argc, char** argv)
{
glutInit(&argc, argv); //To initialize GLUT library
glutInitWindowSize(1000,650);
glutInitWindowPosition(200,200);
glutCreateWindow("Basic_Primitives"); //To name the Output window
glutDisplayFunc(display); //To set the display callback to current window
glutMainLoop(); //To call the display in Loop
}
