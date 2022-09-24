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
cout<<"Enter Rotation Angle(a): ";
cin>>angle;

radian=angle*3.14/180;
//simple circle
setcolor(RED);
circle(xc,yc,r);

//translated circle
setcolor(GREEN);
circle(xc*cos(radian)-yc*sin(radian),xc*sin(radian)+yc*cos(radian),r);

getch();
closegraph();
}