#include <GL/glut.h> 
#include <stdio.h> 
#include <math.h> 
int X1,Y1,X2,Y2; 
void Line() 
{ 
int x,y; 
int dx,dy; 
int p,k; 
glColor3f(1,0,0); 
glClear(GL_COLOR_BUFFER_BIT); 
glBegin(GL_POINTS); 
glVertex2f(X1,Y1); 
dx=X2-X1; 
dy=Y2-Y1; 
p=2*dy-dx; 
x=X1; 
y=Y1; 
for(k=0;k<dx;k++) 
{ 
if(p<0) 
{ 
p=p+2*dy; 
} 
else 
{ 
p=p+2*dy-2*dx; 
y++; 
} 
x++; 
glVertex2f(x,y); 
} 
glEnd(); 
glFlush(); 
} 
int main(int argc, char** argv) 
{ 
glutInit(&argc,argv); 
printf("Give values: "); 
scanf("%d%d",&X1,&Y1); 
printf("Give values: "); 
scanf("%d%d",&X2,&Y2);
//glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); 
glutInitWindowPosition(150,150); 
glutInitWindowSize(780,640); 
glutCreateWindow("BRESENHAM_LINE_ALGORITHM"); 
glClearColor(1.0,1.0,1.0,0.0); 
glOrtho(0,640,0,480,0,480); 
glutDisplayFunc(Line); 
glutMainLoop(); 
return 0; 
} 


