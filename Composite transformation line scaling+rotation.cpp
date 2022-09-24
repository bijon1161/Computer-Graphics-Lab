//scaling of line using line starting and ending points
//transformation
//scaling
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
	
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(WHITE); 

float x,y,x0,y0,x1,y1,sx,sy,angle,s,c,firstpoint_x,firstpoint_y,lastpoint_x,lastpoint_y;
int i;

cout<<"Enter the value of starting point (x0,y0): ";
cin>>x0>>y0;
cout<<"Enter the value of ending point (x1,y1): ";
cin>>x1>>y1;
cout<<"Enter the value of scaling factor (sx,sy): ";
cin>>sx>>sy;
cout<<"Enter Rotation Angle(a): ";
cin>>angle;
//line before scaling
setcolor(RED);
line(x0,y0,x1,y1);

//calculating the  coordinates
x0=x0*sx;
y0=y0*sy;
x1=x1*sx;
y1=y1*sy;

//line after scaling
//setcolor(3);
//line(x0,y0,x1,y1);

//rotation

c=cos(angle*3.14/180);
s=sin(angle*3.14/180);

firstpoint_x=abs(floor(x0*c+y0*s));   //shouldn't use abs(),but for some negative value no output is generating so used abs() here
firstpoint_y=abs(floor(-x0*s+y0*c));
lastpoint_x=abs(floor(x1*c+y1*s));
lastpoint_y=abs(floor(-x1*s+y1*c));

//after rotation

setcolor(GREEN);
line(firstpoint_x,firstpoint_y,lastpoint_x,lastpoint_y);


getch();
closegraph();
}