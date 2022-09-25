//midpoint ellipse draw
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

//window size measurement and initialization
DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);


void plotgraph(int screenWidth,int screenHeight)
{
	//plotting grids
	for(int i=screenWidth/2;i<=screenWidth;i=i+50)
	{
		for(int j=screenHeight/2;j<=screenHeight;j=j+50)
		{
			setcolor(WHITE);
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
	for(int i=screenWidth/2;i>=0;i=i-50)
	{
		for(int j=screenHeight/2;j>=0;j=j-50)
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

void midpoint_ellipse_draw(int rx, int ry, int xc, int yc){
	
	initwindow(screenWidth-20,screenHeight-20,"",-3,-3);
	plotgraph(screenWidth,screenHeight);
	
	int x,y,p1,p2,dx,dy,i;
	
	//for center=origin (x,y)=(0,ry)
	x=0;
	y=ry;


	//REGION 1

	p1=(ry*ry)-(rx*rx*ry)+(0.25*rx*rx);

	dx=2*(ry*ry)*x;
	dy=2*(rx*rx)*y;
	
	while(dx < dy)
	{
    
    	putpixel((screenWidth/2)+(xc+x),(screenHeight/2)-(yc+y),YELLOW);
    	putpixel((screenWidth/2)+(xc+x),(screenHeight/2)-(yc-y),YELLOW);
    	putpixel((screenWidth/2)+(xc-x),(screenHeight/2)-(yc+y),YELLOW);
    	putpixel((screenWidth/2)+(xc-x),(screenHeight/2)-(yc-y),YELLOW);
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

	while(y>=0)
	{ 
    	putpixel((screenWidth/2)+(xc+x),(screenHeight/2)-(yc+y),YELLOW);
    	putpixel((screenWidth/2)+(xc+x),(screenHeight/2)-(yc-y),YELLOW);
    	putpixel((screenWidth/2)+(xc-x),(screenHeight/2)-(yc+y),YELLOW);
    	putpixel((screenWidth/2)+(xc-x),(screenHeight/2)-(yc-y),YELLOW);
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
}

int main(){


	int rx,ry,xc,yc;

	cout<<"Enter the value of rx and ry: ";
	cin>>rx>>ry;
	cout<<"Enter the value of center point (xc,yc): ";
	cin>>xc>>yc;
	
	midpoint_ellipse_draw(rx, ry, xc, yc);
	
	getch();
	closegraph();
}
