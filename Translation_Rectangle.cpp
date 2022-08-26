//Translation Rectangle
//Translation of line using line starting and ending points
//DDA Line draw
//translation
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
	
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(WHITE); 

float x,y,x0,y0,x1,y1,tx,ty;
int i;

cout<<"Enter the value of starting point (x0,y0): ";
cin>>x0>>y0;
cout<<"Enter the value of ending point (x1,y1): ";
cin>>x1>>y1;
cout<<"Enter the value of translation factor (tx,ty): ";
cin>>tx>>ty;

//line before translation
setcolor(2);
//setfillstyle(SOLID_FILL,2);  //filling with color
rectangle(x0,y0,x1,y1);
//floodfill(x0-1,y0-1,2);     //filling with color
//calculating the translated coordinates
x0=x0+tx;
y0=y0+ty;
x1=x1+tx;
y1=y1+ty;

setcolor(3);
//setfillstyle(SOLID_FILL,3);
rectangle(x0,y0,x1,y1);
//floodfill(x0-1,y0-1,3);

getch();
closegraph();
}