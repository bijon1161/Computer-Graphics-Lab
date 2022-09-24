//Translation of line after line draw using DDA algorithm
//DDA Line draw
//translation
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
	
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(WHITE); 

float x,y,x0,y0,x1,y1,step,xIncrement,yIncrement,dx,dy,tx,ty;
int i;

cout<<"Enter the value of starting point (x0,y0): ";
cin>>x0>>y0;
cout<<"Enter the value of ending point (x1,y1): ";
cin>>x1>>y1;
cout<<"Enter the value of translation factor (tx,ty): ";
cin>>tx>>ty;

dx=abs(x1-x0);
dy=abs(y1-y0);

if(dx>dy)
    step=dx;
else
    step=dy;

xIncrement=(x1-x0)/step;
yIncrement=(y1-y0)/step;

x=x0;
y=y0;

cout<<"x\ty"<<endl;

for(i=0;i<=step;i++){
  //  cout<<(int)(x+0.5)<<"\t"<<(int)(y+0.5)<<endl;//round=(int)(a+0.5)
    
    putpixel((int)(x+0.5),(int)(y+0.5),RED);
    putpixel((int)(x+tx+0.5),(int)(y+ty+0.5),RED); //translation with translation factor

    x=x+xIncrement;
    y=y+yIncrement;


}
getch();
closegraph();
}