//Rotation of line after drwaing using DDA algorithm
//DDA Line draw
//line rotation
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
	
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(WHITE); 

float x,y,x0,y0,x1,y1,step,xIncrement,yIncrement,dx,dy,angle,c,s,firstpoint_x,firstpoint_y,lastpoint_x,lastpoint_y;
int i;

cout<<"Enter the value of starting point (x0,y0): ";
cin>>x0>>y0;
cout<<"Enter the value of ending point (x1,y1): ";
cin>>x1>>y1;
cout<<"Enter Rotation Angle(a): ";
cin>>angle;

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

 
c=cos(angle*3.14/180);
s=sin(angle*3.14/180);

cout<<"x\ty"<<endl;

for(i=0;i<=step;i++){
    cout<<(int)(x+0.5)<<"\t"<<(int)(y+0.5)<<endl;//round=(int)(a+0.5)
    
    putpixel((int)(x+0.5),(int)(y+0.5),RED);
    putpixel(abs(floor(((int)(x+0.5))*c+((int)(y+0.5))*s)),abs(floor((-(int)(x+0.5))*s+((int)(y+0.5))*c),GREEN)); //rotation //shouldn't use abs(),but for some negative value 
  //no output is generating so used abs() here
  //putpixel(abs(floor(x*c+y*s)),abs(floor(-x*s+y*c)),GREEN); //shouldn't use abs(),but for some negative value no output is generating so used abs() here

    x=x+xIncrement;
    y=y+yIncrement;


}



/*

firstpoint_x=abs(floor(x0*c+y0*s));    //shouldn't use abs(),but for some negative value no output is generating so used abs() here
firstpoint_y=abs(floor(-x0*s+y0*c));
lastpoint_x=abs(floor(x1*c+y1*s));
lastpoint_y=abs(floor(-x1*s+y1*c));

cout<< firstpoint_x<<firstpoint_y<<lastpoint_x<<lastpoint_y;
setcolor(BLUE);
line(firstpoint_x,firstpoint_y,lastpoint_x,lastpoint_y);
*/

getch();
closegraph();
}