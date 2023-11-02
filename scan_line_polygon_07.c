#include <GL/glut.h>
#include<math.h>
#include <stdio.h>
int h, k, r;
void scanline(int, int);
void circle(void);
void Axes(void);
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (1.0, 0.0, 0.0);
glBegin(GL_POINTS);
circle();
glEnd();
glFlush();
}
void scanline(int ax, int by)
{
int varx;
for(varx=h+ax; varx>=(h-ax); varx--)
glVertex2s(varx, by);
}
void circle(void)
{
double XEnd, J;
int i, j;
XEnd=(r/1.414);
for(i=0; i<=XEnd; i++)
{
J=sqrt(r*r - i*i);
j=(int)(J);
scanline(i, j);
scanline(j, i);
scanline(j, -i);
scanline(i, -j);
}
Axes();
glVertex3s(h, k, -25);
}
void Axes(void)
{
int i;
glColor3f(1.0, 1.0, 1.0);
for(i=-100; i<=100; i++)
{
glVertex2s(i, 0);
glVertex2s(0, i);
}
for(i=-2; i<=2; i++)
{
glVertex2s(4+i, 95+i);
glVertex2s(4-i, 95+i);

glVertex2s(4, 95-i);
}
}
void init(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
printf("Enter values for h, k, r: ");
scanf("%d %d %d",&h, &k, &r);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640, 480);
glutInitWindowPosition(100, 150);
glutCreateWindow("Polygon_Filling_Algorithm");
glutDisplayFunc(display);
init();
glutMainLoop();
return 0;
}
