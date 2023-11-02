#include<GL/glut.h>
#include<math.h>
double parr[8];
void init()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glClearColor(1,1,1,1);
 glColor3f(1,0,1);
 gluOrtho2D(-500,500,-500,500);

 parr[0] = 10; //x
 parr[1] = 10; //y

 parr[2] = 200;
 parr[3] = 10;

 parr[4] = 200;
 parr[5] = 200;

 parr[6] = 10;
 parr[7] = 200;
}
double degreeToRad(double deg)
{
 return 3.14*(deg/180);
}
void polygon()
{
 glColor3f(1,0,0);
 glBegin(GL_LINE_LOOP);
 glVertex2f(parr[0],parr[1]);
 glVertex2f(parr[2],parr[3]);

 glVertex2f(parr[4],parr[5]);
 glVertex2f(parr[6],parr[7]);
 glEnd();

 glFlush();
}
void drawCorodinates()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,0,0);
 glPointSize(4);

 glBegin(GL_LINES);
 glVertex2f(-500,0);
 glVertex2f(500,0);
 
 glVertex2f(0,500);
 glVertex2f(0,-500);
 glEnd();

 glColor3f(1,0,0);

 glBegin(GL_POINTS);
 glVertex2f(0,0);
 glEnd();

 glFlush();
}
// Translation
void translate2d()
{
 // 40px in x
 // 50px in y

 int i = 0;
 int x = 40, y = 50;

 for(i= 0;i<7;i=i+2)
 {
 parr[i] = parr[i] + x;
 }

 for(i = 1;i<7;i=i+2)
 {
 parr[i] = parr[i] + y;
 }

 polygon();
}
// Rotation
void rotation()
{
 double angle = 180,rad,x,y;
 rad = degreeToRad(angle);

 for(int i=0;i<8;i=i+2)
 {
 x = parr[i]*cos(rad) - parr[i+1]*sin(rad);
 y = parr[i]*sin(rad) + parr[i+1]*cos(rad);

 parr[i] = x;
 parr[i+1] = y;
 }

 polygon();
}
// Scaling
void scaling2d()
{
 // 2 unit in x
 // 2 unit in y

 int i = 0;
 double x = 0.5, y = 0.5;

 for(i= 0;i<7;i=i+2)
 {
 parr[i] = parr[i] * x;
 parr[i+1] = parr[i+1] * y;
 }


 polygon();
}
void menu(int ch)
{
 drawCorodinates();
 switch(ch)
 {
 case 1: polygon();
 break;

 case 2: translate2d();
 break;
 case 3: scaling2d();
 break;
 case 4: rotation();
 break;
 }
}
int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(100,100);

 glutCreateWindow("2D Transformation");
 init();
 glutDisplayFunc(drawCorodinates);

 glutCreateMenu(menu);
 glutAddMenuEntry("1 Display Polygon",1);
 glutAddMenuEntry("2 Translate",2);
 glutAddMenuEntry("3 Scaling",3);
 glutAddMenuEntry("4 Rotation",4);
 glutAttachMenu(GLUT_LEFT_BUTTON);

 glutMainLoop();
 return 0;
}
