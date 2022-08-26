//Rotation of line from a pivot point

#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main()
{
int gd=DETECT,gm;
float x,y,x0,y0,x1,y1,pivot_x,pivot_y;
double angle,radian;

initgraph(&gd,&gm,"C://TURBOC3//BGI");
cleardevice();

int rotated_point_x,rotated_point_y;

cout<<"Enter the value of starting point (x0,y0): ";
cin>>x0>>y0;
cout<<"Enter the value of ending point (x1,y1): ";
cin>>x1>>y1;
cout<<"Enter Rotation Angle(a): ";
cin>>angle;
cout<<"Enter the value of pivot point (x_pivot,y_pivot): ";
cin>>pivot_x>>pivot_y;

setcolor(GREEN);
line(x0,y0,x1,y1);

radian=angle*3.14/180;

rotated_point_x=(int)(pivot_x +((x1-pivot_x)*cos(radian)-(y1-pivot_y)*sin(radian)));
rotated_point_y=(int)(pivot_y +((x1-pivot_x)*sin(radian)+(y1-pivot_y)*cos(radian)));

setcolor(RED);
line(pivot_x,pivot_y,rotated_point_x,rotated_point_y);
getch();
closegraph();
}