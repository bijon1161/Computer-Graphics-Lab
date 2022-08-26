#include<bits/stdc++.h>
#include<graphics.h>
#include<dos.h>
using namespace std;

int main(){

int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(WHITE);

float r,x,y,x0,y0,pk,xc,yc,tx,ty;
int i;
double angle,radian;

cout<<"Enter the value of r: ";
cin>>r;
cout<<"Enter the value of center point (xc,yc): ";
cin>>xc>>yc;


//radian=angle*3.14/180;
//simple circle
setcolor(RED);
circle(xc,yc,r);

//reflection about x-axis circle
setcolor(GREEN);
circle(xc+180,yc,r);
//reflection about y-axis circle
setcolor(BLUE);
circle(xc,yc+180,r);
//reflection about xy-axis circle
setcolor(WHITE);
circle(xc+180,yc+180,r);
getch();
closegraph();
}