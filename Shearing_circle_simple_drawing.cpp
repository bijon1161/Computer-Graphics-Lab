#include<bits/stdc++.h>
#include<graphics.h>
#include<dos.h>
using namespace std;

int main(){

int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(WHITE);

float r,x,y,x0,y0,pk,xc,yc,tx,ty,sh,xn1,yn1,r1;
int i;


cout<<"Enter the value of r: ";
cin>>r;
cout<<"Enter the value of center point (xc,yc): ";
cin>>xc>>yc;
cout<<"Enter shearing value (0-1): ";
cin>>sh;


//simple circle
setcolor(RED);
circle(xc,yc,r);

//shearing circle x-axis
setcolor(GREEN);
//circle((xc+sh*yc),yc,r);
xn1=xc+sh*yc;
yn1=yc;
r1=r+sh*xc;
ellipse(xn1,yn1,0,360,r,r1);

getch();
closegraph();
}