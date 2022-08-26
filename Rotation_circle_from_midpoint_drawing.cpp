//rotation circle after drawing from midpoint algorithm
#include<bits/stdc++.h>
#include<graphics.h>
#include<dos.h>
using namespace std;

int main(){

int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(WHITE);

float r,x,y,x0,y0,pk,xc,yc,tx,ty;
double angle,radian;
int i;

cout<<"Enter the value of r: ";
cin>>r;
cout<<"Enter the value of center point (xc,yc): ";
cin>>xc>>yc;
cout<<"Enter Rotation Angle(a): ";
cin>>angle;

//for center=origin (x,y)=(0,r)
x=0;
y=r;

radian=angle*3.14/180;

if(r-(int) r== 0.0)
    pk=1-r; //initial value of decision parameter pk
else
    pk=(5.0/4.0)-r;


cout<<"pk\t"<<"x\ty"<<endl;
while(x<=y)
{
    cout<<pk<<"\t"<<(int) xc+x<<"\t"<<(int) yc+y<<endl;
    
    putpixel(xc+x,yc+y,RED);
    putpixel(xc+y,yc+x,RED);
    putpixel(xc-x,yc+y,RED);
    putpixel(xc+x,yc-y,RED);
    putpixel(xc-x,yc-y,RED);
    putpixel(xc+y,yc-x,RED);
    putpixel(xc-y,yc+x,RED);
    putpixel(xc-y,yc-x,RED);
    
    //translation
    putpixel((xc+x)*cos(radian)-(yc+x)*sin(radian),(xc+y)*sin(radian)+(yc+y)*cos(radian),GREEN);
    putpixel((xc+y)*cos(radian)-(yc+y)*sin(radian),(xc+x)*sin(radian)+(yc+x)*cos(radian),GREEN);
    putpixel((xc-x)*cos(radian)-(yc-x)*sin(radian),(xc+y)*sin(radian)+(yc+y)*cos(radian),GREEN);
    putpixel((xc+x)*cos(radian)-(yc+x)*sin(radian),(xc-y)*sin(radian)+(yc-y)*cos(radian),GREEN);
    putpixel((xc-x)*cos(radian)-(yc-x)*sin(radian),(xc-y)*sin(radian)+(yc-y)*cos(radian),GREEN);
    putpixel((xc+y)*cos(radian)-(yc+y)*sin(radian),(xc-x)*sin(radian)+(yc-x)*cos(radian),GREEN);
    putpixel((xc-y)*cos(radian)-(yc-y)*sin(radian),(xc+x)*sin(radian)+(yc+x)*cos(radian),GREEN);
    putpixel((xc-y)*cos(radian)-(yc-y)*sin(radian),(xc-x)*sin(radian)+(yc-x)*cos(radian),GREEN);
    
    if(pk<0){
        x=x+1;
        y=y;
        pk=pk+(2*x)+1;
    }
    else{
        x=x+1;
        y=y-1;
        pk=pk+(2*x)+1-(2*y);
    }

}
getch();
closegraph();
}