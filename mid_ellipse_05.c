#include<stdio.h>
#include<GL/glut.h>
const float PI=3.14;

int rx,ry;
int xCenter,yCenter;
void myinit(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}
void setPixel(GLint x,GLint y)
{
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}

void ellipseMidPoint()
{
float x = 0;
float y = ry;//(0,ry) ---
float p1 = ry * ry - (rx * rx)* ry + (rx * rx) * (0.25) ;
//slope
float dx = 2 * (ry * ry) * x;
float dy = 2 * (rx * rx) * y;
while(dx < dy)
{
//plot (x,y)
setPixel(xCenter + x , yCenter+y);
setPixel( xCenter - x, yCenter + y);
setPixel( xCenter + x , yCenter - y );
setPixel( xCenter - x , yCenter - y);

if(p1 < 0)
{
x = x + 1;
dx = 2 * (ry * ry) * x;
p1 = p1 + dx + (ry * ry);
}
else
{
x = x + 1;
y = y - 1;
dx = 2 * (ry * ry) * x;
dy = 2 * (rx * rx) * y;
p1 = p1 + dx - dy +(ry * ry);
}
}

float p2 = (ry * ry )* ( x + 0.5) * ( x + 0.5) + ( rx * rx) * ( y - 1) * ( y - 1) - (rx * rx )* (ry * ry);

while(y > 0)
{
//plot (x,y)
setPixel(xCenter + x , yCenter+y);
setPixel( xCenter - x, yCenter + y);
setPixel( xCenter + x , yCenter - y );
setPixel( xCenter - x , yCenter - y); //glEnd();
if(p2 > 0)
{
x = x;
y = y - 1;
dy = 2 * (rx * rx) * y;
//dy = 2 * rx * rx *y;
p2 = p2 - dy + (rx * rx);
}
else
{
x = x + 1;
y = y - 1;
dy = dy - 2 * (rx * rx) ;
dx = dx + 2 * (ry * ry) ;
p2 = p2 + dx -
dy + (rx * rx);
}
}

}
void display()
{
glClear(GL_COLOR_BUFFER_BIT); // clear the screen
glColor3f(1.0,0.0,0.0); // red foreground
glPointSize(2.0); // size of points to be drawin (in pixel)

//establish a coordinate system for the image

ellipseMidPoint();
glFlush(); // send all output to the display
}
int main(int argc, char** argv){
printf("Enter value of rx and ry");
scanf("%d%d",&rx,&ry);
printf("Enter value of xcenter and ycenter");
scanf("%d%d",&xCenter,&yCenter);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(100,150);
glutCreateWindow("Midpoint_Ellipse_Drawing");
glutDisplayFunc(display);
myinit();
glutMainLoop();
return 0;
}
