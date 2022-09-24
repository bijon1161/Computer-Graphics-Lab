//reflection of line using line starting and ending points
//transformation
//reflection
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


//line before translation
setcolor(2);
line(x0,y0,x1,y1);


//reflection x-axis 
setcolor(3);
line(x0+180,y0,x1+180,y1);

//reflection y-axis 
setcolor(4);
line(x0,y0+180,x1,y1+180);

getch();
closegraph();
}