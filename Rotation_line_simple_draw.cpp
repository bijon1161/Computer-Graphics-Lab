//Rotation of line after drwaing using simple draw

//line rotation
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
	
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(WHITE);

float x,y,x0,y0,x1,y1,angle,c,s,firstpoint_x,firstpoint_y,lastpoint_x,lastpoint_y;
int i;

cout<<"Enter the value of starting point (x0,y0): ";
cin>>x0>>y0;
cout<<"Enter the value of ending point (x1,y1): ";
cin>>x1>>y1;
cout<<"Enter Rotation Angle(a): ";
cin>>angle;


//before rotation
setcolor(RED);   
line(x0,y0,x1,y1);


c=cos(angle*3.14/180);
s=sin(angle*3.14/180);

firstpoint_x=abs(floor(x0*c+y0*s));   //shouldn't use abs(),but for some negative value no output is generating so used abs() here
firstpoint_y=abs(floor(-x0*s+y0*c));
lastpoint_x=abs(floor(x1*c+y1*s));
lastpoint_y=abs(floor(-x1*s+y1*c));

//after rotation
cout<< firstpoint_x<<firstpoint_y<<lastpoint_x<<lastpoint_y;
setcolor(GREEN);
line(firstpoint_x,firstpoint_y,lastpoint_x,lastpoint_y);



getch();
closegraph();
}