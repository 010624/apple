#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
int i;
void init(void)
{
 glClearColor(1.0, 1.0, 1.0, 1.0);
}
void drawBitmapText(char* string, float x, float y, float z)
{
 char* c;
 glRasterPos2f(x, y);
 for (c = string; *c != '\0'; c++)
 {
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
 }
}
void draw(GLfloat ctrlpoints[4][3])
{
 glShadeModel(GL_FLAT);
 glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4,&ctrlpoints[0][0]);
 glEnable(GL_MAP1_VERTEX_3);
 glColor3f(1.0, 1.0, 1.0);
 glBegin(GL_LINE_STRIP);
 for (i = 0; i <= 30; i++)
 {
 glEvalCoord1f((GLfloat)i / 30.0);
 }
 glEnd();
 glFlush();
}
void display(void)
{
int i;
 GLfloat ctrlpoints[4][3]= { { -0.00, 2.00, 0.0 },
 { -2.00, 2.00, 0.0 },
 { -2.00, -1.00, 0.0 },
 { -0.00, -1.00, 0.0 } };
draw(ctrlpoints);
GLfloat ctrlpoints2[4][3]= { { 0.0, -1.00, 0.0 },
 { 0.55, -0.65, 0.0 },
 { 0.65, -0.25, 0.0 },
 { 0.00, 0.70, 0.0 } };
 draw(ctrlpoints2);

 GLfloat ctrlpoints3[4][3]= { { 0.0, 0.70, 0.0 },
 { 0.15, 0.70, 0.0 },
 { 0.25, 0.70, 0.0 },
 { 0.65, 0.700, 0.0 } };
 draw(ctrlpoints3);
 
 GLfloat ctrlpoints4[4][3]= { { 0.65, 0.70, 0.0 },
 { 0.65, -0.90, 0.0 },
 { 0.65, -0.70, 0.0 },
 { 0.65, -1.00, 0.0 } };
 draw(ctrlpoints4);

 GLfloat ctrlpoints5[4][3]= { { 1.00, -1.00, 0.0 },
 { 1.00, -0.5, 0.0 },
 { 1.00, -0.20, 0.0 },
 { 1.00, 1.35, 0.0 } };
 draw(ctrlpoints5);
 GLfloat ctrlpoints6[4][3]= { { 1.00, 1.35 },
 { 1.10, 1.35, 0.0 },
 { 1.10, 1.35, 0.0 },
{ 1.90, 1.35, 0.0 } };
 draw(ctrlpoints6);
 GLfloat ctrlpoints7[4][3]= { { 1.00, 0.50, 0.0 },
 { 1.10, 0.5, 0.0 },
 { 1.10, 0.5, 0.0 },
 { 1.90, 0.5, 0.0 } };
 draw(ctrlpoints7);
 GLfloat ctrlpoints8[4][3]= { { 3.50, 2.00, 0.0 },
 { 1.50, 2.00, 0.0 },
 { 1.50, -1.00, 0.0 },
 { 3.50, -1.00, 0.0 } };
 draw(ctrlpoints8);
 GLfloat ctrlpoints9[4][3]= { { 3.50, -1.00, 0.0 },
 { 4.05, -0.65, 0.0 },
 { 4.15, -0.25, 0.0 },
 { 3.50, 0.70, 0.0 } };
 draw(ctrlpoints9);
 GLfloat ctrlpoints10[4][3]= { { 3.50, 0.70, 0.0 },
 { 3.65, 0.70, 0.0 },
 { 3.75, 0.70, 0.0 },
 { 4.15, 0.700, 0.0 } };
draw(ctrlpoints10);
 GLfloat ctrlpoints11[4][3]= { { 4.15, 0.70, 0.0 },
 { 4.15, -0.90, 0.0 },
 { 4.15, -0.70, 0.0 },
 { 4.15, -1.00, 0.0 } };
 draw(ctrlpoints11);
 GLfloat ctrlpoints12[4][3]= { { -2.0, 2.50, 0.0 },
 { 2.05, 2.50, 0.0 },
 { 3.15, 2.50, 0.0 },
 { 4.65, 2.50, 0.0 } };
 draw(ctrlpoints12);
 GLfloat ctrlpoints13[4][3]= { { -2.0, -1.80, 0.0 },
 { 2.05, -1.80, 0.0 },
 { 3.15, -1.80, 0.0 },
 { 4.65, -1.80, 0.0 } };
 draw(ctrlpoints13);
 GLfloat ctrlpoints14[4][3]= { { -2.0, -1.80, 0.0 },
 { -2.0, 1.80, 0.0 },
 { -2.0, 1.90, 0.0 },
 { -2.0, 2.50, 0.0 } };
 draw(ctrlpoints14);
 GLfloat ctrlpoints15[4][3]= { { 4.650, -1.80, 0.0 },
 { 4.65, 1.80, 0.0 },
 { 4.65, 1.90, 0.0 },
 { 4.65, 2.50, 0.0 } };
draw(ctrlpoints15);
 glColor3f(1, 0, 0);
 drawBitmapText("Bezier Curves Implementation",-1.00, -3.0, 0);
 glFlush();
}
void reshape(int w, int h)
{
 glViewport(0, 0, (GLsizei)w,(GLsizei)h);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 if (w <= h)
 glOrtho(-5.0, 5.0, -5.0* (GLfloat)h / (GLfloat)w,5.0 * (GLfloat)h / (GLfloat)w, -5.0, 5.0);
 else
 glOrtho(-5.0 * (GLfloat)w / (GLfloat)h,5.0 * (GLfloat)w / (GLfloat)h,-5.0, 5.0,-5.0, 5.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
}
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow(argv[0]);
 glutSetWindowTitle("Bezier curve");
init();
glutDisplayFunc(display);
 glutReshapeFunc(reshape);
 glutMainLoop();
 return 0;
}
