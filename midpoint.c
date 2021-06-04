#include<stdio.h>
#include<GL/glut.h>

int r;

void myInit(){
// glCLearColor(1.0,1.0,1.0,1.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-200,200,-200,200);
}

void setPixel(int x, int y){
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
}

void drawPixel(int x, int y){
 setPixel(x,y);
 setPixel(-x,y);
 setPixel(x,-y);
 setPixel(-x,-y);
 setPixel(y,x);
 setPixel(-y,x);
 setPixel(y,-x);
 setPixel(-y,-x);
}

void drawCircle(int r){
 int d,x,y;
 x=0;
 y=r;
 d=1-r;
 drawPixel(x,y);
 while(x<=y){
        if(d<0)
                d+=2*x+3;
        else
        {
                d+=2*(x-y)+5;
                y--;
        }
        x++;
        drawPixel(x,y);
 }
}

void myDisplay(){
 glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
 drawCircle(r);
 glFlush();
}

int main(int argc, char**argv){
 printf("Enter the radius r:\n");
 scanf("%d",&r);
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
 glutInitWindowPosition(0,0);
 glutInitWindowSize(500,500);
 glutCreateWindow("midpoint circle");
 glutDisplayFunc(myDisplay);
 myInit();
 glutMainLoop();
 return 0;
}
