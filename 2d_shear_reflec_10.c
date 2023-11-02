#include <stdio.h>
#include <stdlib.h>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <ctype.h>

float xd[10], yd[10], X1[10], Y1[10];
int vertex;
float shx, shy;
float WXMax = 600, WXMin = 100, WYMax = 600, WYMin = 100;
float VXMax = 800, VXMin = 600, VYMax = 800, VYMin = 200, VX[10], VY[10], VX1[10], VY1[10];

int operationType = 0;  // 0: Shearing, 1: Reflection

void initt() {
    glClearColor(0, 0, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1000, 1000, -1000, 1000);
}

void shearX() {
    int i;
    for (i = 0; i < vertex; i++) {
        X1[i] = xd[i] + shx * yd[i];
        Y1[i] = yd[i];
    }
}

void shearY() {
    int i;
    for (i = 0; i < vertex; i++) {
        Y1[i] = yd[i] + shy * xd[i];
        X1[i] = xd[i];
    }
}

void reflectionX() {
    int i;
    for (i = 0; i < vertex; i++) {
        Y1[i] = -yd[i];
        X1[i] = xd[i];
    }
}

void reflectionY() {
    int i;
    for (i = 0; i < vertex; i++) {
        X1[i] = -xd[i];
        Y1[i] = yd[i];
    }
}

void worldWindow() {
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    if (vertex == 2) {
        glBegin(GL_LINES);
        for (i = 0; i < vertex; i++) {
            glVertex2f(xd[i], yd[i]);
        }
    } else {
        glBegin(GL_POLYGON);
        for (i = 0; i < vertex; i++) {
            glVertex2f(xd[i], yd[i]);
        }
    }
    glEnd();
    glColor3f(1.0, 0.0, 1.0);
    if (vertex == 2) {
        glBegin(GL_LINES);
        for (i = 0; i < vertex; i++) {
            glVertex2f(X1[i], Y1[i]);
        }
    } else {
        glBegin(GL_POLYGON);
        for (i = 0; i < vertex; i++) {
            glVertex2f(X1[i], Y1[i]);
        }
    }
    glEnd();
    glutSwapBuffers();
    glFlush();
}

void viewPort() {
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    if (vertex == 2) {
        glBegin(GL_LINES);
        for (i = 0; i < vertex; i++) {
            glVertex2f(VX[i], VY[i]);
        }
    } else {
        glBegin(GL_POLYGON);
        for (i = 0; i < vertex; i++) {
            glVertex2f(VX[i], VY[i]);
        }
    }
    glEnd();
    glColor3f(1.0, 0.0, 1.0);
    if (vertex == 2) {
        glBegin(GL_LINES);
        for (i = 0; i < vertex; i++) {
            glVertex2f(VX1[i], VY1[i]);
        }
    } else {
        glBegin(GL_POLYGON);
        for (i = 0; i < vertex; i++) {
            glVertex2f(VX1[i], VY1[i]);
        }
    }
    glEnd();
    glutSwapBuffers();
    glFlush();
}

void performOperation() {
    if (operationType == 0) {
        // Prompt for shearing factors
        printf("Enter shearing factors (shx and shy) as floating-point values:\n");
        scanf("%f %f", &shx, &shy);
        shearX();
    } else if (operationType == 1) {
        reflectionX();
    }
}

void operation(GLubyte key, GLint x, GLint y) {
    switch (key) {
        case 's':
            operationType = 0;  // Shearing
            performOperation();
            break;
        case 'r':
            operationType = 1;  // Reflection
            performOperation();
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    int i;
    printf("ENTER NO. OF VERTICES (max=10):-\n");
    scanf("%d", &vertex);
    
    if (vertex < 2 || vertex > 10) {
        printf("Invalid Input. Exiting...\n");
        exit(0);
    }
    
    for (i = 0; i < vertex; i++) {
        printf("Enter coordinates (x, y):-\n");
        scanf("%f %f", &xd[i], &yd[i]);
    }
    
    printf("Press 's' to apply shearing or 'r' to apply reflection.\n");
    
    // Calculate viewport coordinates
    for (i = 0; i < vertex; i++) {
        VX[i] = (xd[i] - WXMin) * (VXMax - VXMin) / (WXMax - WXMin) + VXMin;
        VY[i] = (yd[i] - WYMin) * (VYMax - VYMin) / (WYMax - WYMin) + VYMin;
    }
    
    // Initialize viewport transformation
    for (i = 0; i < vertex; i++) {
        VX1[i] = VX[i];
        VY1[i] = VY[i];
    }
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WXMax - WXMin, WYMax - WYMin);
    glutInitWindowPosition(WXMin, WYMin);
    glutCreateWindow("2D TRANSFORMATION");
    initt();
    glutDisplayFunc(worldWindow);
    glutKeyboardFunc(operation);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(VXMax - VXMin, VYMax - VYMin);
    glutInitWindowPosition(VXMin, VYMin);
    glutCreateWindow("OpenGL - View Port");
    initt();
    glutDisplayFunc(viewPort);
    glutMainLoop();
    
    return 0;
}

