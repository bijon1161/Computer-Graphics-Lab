//scaling circle after drawing from midpoint algorithm
#include<bits/stdc++.h>
#include<graphics.h>
#include<dos.h>
using namespace std;

int main(){

int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(WHITE);

float r,x,y,x0,y0,pk,xc,yc,sx,sy;
int i;

cout<<"Enter the value of r: ";
cin>>r;
cout<<"Enter the value of center point (xc,yc): ";
cin>>xc>>yc;
cout<<"Enter the value of scaling factor (sx): ";
cin>>sx;

//simple circle
setcolor(RED);
circle(xc,yc,r);

//scaled circle
setcolor(GREEN);
circle(xc,yc,r*sx);
getch();
closegraph();
}