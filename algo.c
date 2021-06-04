#include <GL/glut.h>
#include <stdio.h>
int x1, y1, x2, y2;
void myInit()
{
 glClearColor(0.0, 0.0, 0.0, 1.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0, 500, 0, 500);
}
void draw_pixel(int x, int y)
{
 glBegin(GL_POINTS);
 glVertex2i(x, y);
 glEnd();
}
void draw_line(int x1, int x2, int y1, int y2)
{
 int dx, dy, i, e;
 int incx, incy, inc1, inc2;
 int x,y;
 dx = x2-x1;
 dy = y2-y1;
 if (dx < 0) dx = -dx;
 if (dy < 0) dy = -dy;
 incx = 1;
 if (x2 < x1) incx = -1;
 incy = 1;
 if (y2 < y1) incy = -1;
 x = x1; y = y1;
 if (dx > dy)
 {
 draw_pixel(x, y);
 e = 2 * dy-dx;
 inc1 = 2*(dy-dx);
 inc2 = 2*dy;
 for (i=0; i<dx; i++)
{
 if (e >= 0)
{
y += incy;e += inc1;
}
 else
 e += inc2;
 x += incx;
 draw_pixel(x, y);
 }
 }
 else
 {
 draw_pixel(x, y);
 e = 2*dx-dy;
 inc1 = 2*(dx-dy);
 inc2 = 2*dx;
 for (i=0; i<dy; i++)
 {
 if (e >= 0)
 {
x+= incx;
 e += inc1;
}
else
 e += inc2;
 y += incy;
 draw_pixel(x, y);
 }
 }
}
void draw_text( float x, float y, float z, char* s)
{
glRasterPos3f(x,y,z);
int i;
for(i=0;s[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
}
void myDisplay()
{
glClear(GL_COLOR_BUFFER_BIT);
draw_line(x1, x2, y1, y2);
draw_text(0.00,0.0,0.0,"Dhruv Varshney 1BI18CS050");
 glFlush();
}
int main(int argc, char **argv)
{
 printf( "Enter end points of the Line (x1, y1, x2, y2)\n");
 scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutInitWindowPosition(0, 0);
 glutCreateWindow("Bresenham's Line Drawing");
 myInit();
 glutDisplayFunc(myDisplay);
 glutMainLoop();
 return 0;
}
