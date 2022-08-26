//Triangle Translation
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

float x,y,x0,y0,x1,y1,x2,y2,tx,ty;
int i;

cout<<"Enter the value of first point (x0,y0): ";
cin>>x0>>y0;
cout<<"Enter the value of second point (x1,y1): ";
cin>>x1>>y1;
cout<<"Enter the value of third point (x2,y2): ";
cin>>x2>>y2;
cout<<"Enter the value of translation factor (tx,ty): ";
cin>>tx>>ty;

//line before translation
setcolor(2);

line(x0,y0,x1,y1);
line(x1,y1,x2,y2);
line(x2,y2,x0,y0);

//calculating the translated coordinates
x0=x0+tx;
y0=y0+ty;
x1=x1+tx;
y1=y1+ty;
x2=x2+tx;
y2=y2+ty;

setcolor(3);
line(x0,y0,x1,y1);
line(x1,y1,x2,y2);
line(x2,y2,x0,y0);


getch();
closegraph();
}