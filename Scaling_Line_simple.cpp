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

float x,y,x0,y0,x1,y1,sx,sy;
int i;

cout<<"Enter the value of starting point (x0,y0): ";
cin>>x0>>y0;
cout<<"Enter the value of ending point (x1,y1): ";
cin>>x1>>y1;
cout<<"Enter the value of scaling factor (sx,sy): ";
cin>>sx>>sy;

//line before scaling
setcolor(2);
line(x0,y0,x1,y1);

//calculating the  coordinates
x0=x0*sx;
y0=y0*sy;
x1=x1*sx;
y1=y1*sy;

setcolor(3);
line(x0,y0,x1,y1);

getch();
closegraph();
}