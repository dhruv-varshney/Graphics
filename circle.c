[10:52] Dr. J. Girija
    
#include <GL/glut.h>
#include <stdio.h>
int xc,yc, rad;

void myInit()
{​​​​​
glClearColor(0.0, 0.0, 0.0, 1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-50, 50, -50, 50);
}​​​​​
void draw_pixel(int x, int y)
{​​​​​ glColor3f(0,1,0);
glPointSize(4);
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
}​​​​​

void draw_quadrant_pixel(int x, int y)
{​​​​​
draw_pixel(x,y);
draw_pixel(y,x);
draw_pixel(-x,y);
draw_pixel(-y,x);
draw_pixel(-x,-y);
draw_pixel(-y,-x);
draw_pixel(x,-y);
draw_pixel(y,-x);
}​​​​​

void draw_circle (int r)
{​​​​​
int d,x=0,y=r;
d = 1-r;
draw_quadrant_pixel(x,y);
while(x<=y)
{​​​​​
if (d<0)
d+=2*x +3;
else
{​​​​​d+=2*(x-y)+5;
y--;
}​​​​​
x++;
draw_quadrant_pixel(x,y);
}​​​​​
}​​​​​
void myDisplay()
{​​​​​
glClear(GL_COLOR_BUFFER_BIT);
draw_circle(rad);
glFlush();
}​​​​​
int main(int argc, char **argv)
{​​​​​
printf("Enter radius of the circle \n");
scanf("%d", &rad);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(0, 0);
glutCreateWindow("Midpoint circle algorithm");
myInit();
glutDisplayFunc(myDisplay);
glutMainLoop();
return 0;
}​​​​​
