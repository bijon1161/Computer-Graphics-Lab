//shearing of line using line starting and ending points
//transformation
//shearing
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
	
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(WHITE); 

float x,y,x0,y0,x1,y1,sh;
int i;

cout<<"Enter the value of starting point (x0,y0): ";
cin>>x0>>y0;
cout<<"Enter the value of ending point (x1,y1): ";
cin>>x1>>y1;
cout<<"Enter the value of shearing factor (sh): ";
cin>>sh;

//line before translation
setcolor(2);
line(x0,y0,x1,y1);

//calculating the coordinates
x0=x0+y0*sh;
y0=y0;
x1=x1+y1*sh;
y1=y1;

setcolor(3);
line(x0,y0,x1,y1);

getch();
closegraph();
}