#include<GL/glut.h>
#include<stdio.h>
void display1()
{ 
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0,0.0,1.0,1.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_TRIANGLES);
glVertex2f(0.5,0.5);
glVertex2f(-0.5,0.5);
glVertex2f(-0.5,-0.5);
glColor3f(0.0,1.0,0.0);
glVertex2f(0.5,-0.5);
glEnd();
glFlush();
}
void init()
{
glViewport(300,400,100,100);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-1,1,-1,1);
}
void main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(100,100);
glutInitWindowSize(500,500);
glutCreateWindow("SQUARE");
glutReshapeFunc(init);
glutDisplayFunc(display1);
glutMainLoop();
}
