//midpoint ellipse draw
#include<bits/stdc++.h>
#include<graphics.h>
#include<dos.h>
using namespace std;

void plotgraph(int screenWidth,int screenHeight)
{
	//plotting grids
	for(int i=screenWidth/2;i<=screenWidth;i=i+25)
	{
		for(int j=screenHeight/2;j<=screenHeight;j=j+25)
		{
			setcolor(WHITE);
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
	for(int i=screenWidth/2;i>=0;i=i-25)
	{
		for(int j=screenHeight/2;j>=0;j=j-25)
		{
			setcolor(WHITE);
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
	//plotting origin axes
	setcolor(YELLOW);
	line(0,screenHeight/2,screenWidth,screenHeight/2);
	line(screenWidth/2,0,screenWidth/2,screenHeight);
}

int main(){

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	setbkcolor(WHITE);


	//window size measurement and initialization
	DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",-3,-3);
	
	//graph plotting function call
	plotgraph(screenWidth,screenHeight);

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
    
    	putpixel((screenWidth/2)+(xc+x),(screenHeight)-(yc+y),RED);
    	putpixel((screenWidth/2)+(xc+x),(screenHeight)-(yc-y),RED);
    	putpixel((screenWidth/2)+(xc-x),(screenHeight)-(yc+y),RED);
    	putpixel((screenWidth/2)+(xc-x),(screenHeight)-(yc-y),RED);
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
    
    	putpixel((screenWidth/2)+(xc+x),(screenHeight)-(yc+y),RED);
    	putpixel((screenWidth/2)+(xc+x),(screenHeight)-(yc-y),RED);
    	putpixel((screenWidth/2)+(xc-x),(screenHeight)-(yc+y),RED);
    	putpixel((screenWidth/2)+(xc-x),(screenHeight)-(yc-y),RED);
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
	
    //outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "Starting point");
    //outtextxy((screenWidth/2)+x1+10,(screenHeight/2)-y1-10, "Ending point");
    //outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");
	getch();
	closegraph();
}