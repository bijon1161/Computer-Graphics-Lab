//bresenham Line draw
#include<bits/stdc++.h>
#include<graphics.h>
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
	
	float x,y,x0,y0,x1,y1,dx,dy,pk;
	
	//graphics driver
	int gd=DETECT,gm,step;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	
	//window size measurement and initialization
	DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"window",-3,-3);
	
	//graph plotting function call
	plotgraph(screenWidth,screenHeight);
	
	
	cout<<"Enter the starting point (x0,y0): ";
	cin>>x0>>y0;
	cout<<"Enter the ending point (x1,y1): ";
	cin>>x1>>y1;
	
	dx=abs(x1-x0);
	dy=abs(y1-y0);
	
	

	if(x0>x1)
	  {
	  	x=x1;
	  	y=y1;
	  	step=x0;
	  }
	else
	{
		x=x0;
		y=y0;
		step=x1;
	}
	
//	x = (dy/dx > 1) ? y : x;
//	y = (dy/dx > 1) ? x : y;
	
	pk=2*dy-dx;
	
//	cout<<"x\ty"<<endl;	
    
    for(int i=0;i<step;i++)
    {
    //	cout<<(int)(x)<<"\t"<<(int)(y)<<endl;
    //	cout<<(screenWidth/2)+((int) (x))<<"\t"<<(screenWidth/2)-((int)(y))<<endl;
        putpixel((screenWidth/2)+x,(screenHeight/2)-y,GREEN);
        
        if(pk<0)
        {
        	x=x+1;
        	y=y;
        	pk=pk+2*dy;
		}
		else
		{
			x=x+1;
        	y=y+1;
        	pk=pk+2*dy-2*dx;
		}
        
        outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "Starting point");
        outtextxy((screenWidth/2)+x1+10,(screenHeight/2)-y1-10, "Ending point");
        outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");

    	
	}
    
	getch();
	closegraph();
	

}