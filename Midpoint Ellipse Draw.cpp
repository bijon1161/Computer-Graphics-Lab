#include<bits/stdc++.h>
#include<graphics.h>
#include<dos.h>
using namespace std;

int main(){

int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(WHITE);

float rx,ry,x,y,x0,y0,p1,p2,xc,yc,dx,dy;
int i;

cout<<"Enter the value of rx and ry: ";
cin>>rx>>ry;
cout<<"Enter the value of center point (xc,yc): ";
cin>>xc>>yc;

//for center=origin (x,y)=(0,ry)
x=0;
y=ry;


//REGION 1

p1=(ry*ry)-(rx*rx*ry)+(0.25*rx*rx);

dx=2*(ry*ry)*x;
dy=2*(rx*rx)*y;
cout<<"p1\t"<<"x\ty"<<endl;
while(dx < dy)
{
    cout<<p1<<"\t"<<(int) xc+x<<"\t"<<(int) yc+y<<endl;
    
    putpixel(xc+x,yc+y,RED);
    putpixel(xc-x,yc+y,RED);
    putpixel(xc+x,yc-y,RED);
    putpixel(xc-x,yc-y,RED);
    if(p1<0){
    	x=x+1;
        y=y;
        dx=dx+(2*ry*ry);
        p1=p1+dx+(ry*ry);
    }
    else{
        x=x+1;
        y=y-1;
        dx = dx + (2 * ry * ry);
        dy = dy - (2 * rx * rx);
        p1=p1+dx-dy+(ry*ry);
        
        
    }
      
}

//REGION 2  
p2=(ry*ry)*(x+0.5)*(x+0.5)+(rx*rx)*(y-1)*(y-1)-(rx*rx*ry*ry); 

cout<<"p2\t"<<"x2\ty2"<<endl;
while(y>=0)
{
    cout<<p1<<"\t"<<(int) xc+x<<"\t"<<(int) yc+y<<endl;
    
    putpixel(xc+x,yc+y,RED);
    putpixel(xc-x,yc+y,RED);
    putpixel(xc+x,yc-y,RED);
    putpixel(xc-x,yc-y,RED);
    if(p2>0){
        x=x;
        y=y-1;
        
        dy = dy - (2 * rx * rx);
        p2=p2-dy+(rx*rx);
    }
    else{
        x=x+1;
        y=y-1;
        dx = dx + (2 * ry * ry);
        dy = dy - (2 * rx * rx);
        p2=p2+dx-dy+(rx*rx);
    }
    

}
 
getch();
closegraph();
}