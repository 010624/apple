#include <stdio.h>
#include <GL/glut.h>

int pntX1, pntY1, r;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x + pntX1, y + pntY1);
    glEnd();
}

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void midPointCircleAlgo()
{
    int x = 0;
    int y = r;
    float decision = 5 / 4 - r;
    plot(x, y);
    while (y > x)
    {
        if (decision < 0)
        {
            x++;
            decision += 2 * x + 1;
        }
        else
        {
            y--;
            x++;
            decision += 2 * (x - y) + 1;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);
    midPointCircleAlgo();
    glFlush();
}

int main(int argc, char **argv)
{   
    printf("Enter radius : ");
    scanf("%d", &r);
    printf("Give Center: ");
    scanf("%d%d", &pntX1, &pntY1);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Midpoint_Circle_Drawing_Alogrithms");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}
