#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
int n=0;
void display()
{
GLfloat vertices[3][3]={{0.0,0.0,0.0},{25.0,50,0.0},{50.0,0.0,0.0}};
GLfloat p[3]={7.5,5.0,0.0};
glClear(GL_COLOR_BUFFER_BIT);
int j, k;
 int rand();
glBegin(GL_POINTS);
   for(k=0;k<n;k++)
{		
j=rand()%3;
p[0]=(p[0]+vertices[j][0])/2;
p[1]=(p[1]+vertices[j][1])/2;
glVertex2fv(p);
}
glEnd();
glFlush();
}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 60.0, -15.0, 60.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor (1.0, 1.0,1.0,1.0);
    glColor3f(0.0,0.0,0.0);
}
int main(int argc, char **argv)
{
   printf("Enter the number of divisions\n");
	 scanf("%d",&n);
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutCreateWindow("2D Gasket");
   glutDisplayFunc(display);
	 myinit();
   glutMainLoop();
}
