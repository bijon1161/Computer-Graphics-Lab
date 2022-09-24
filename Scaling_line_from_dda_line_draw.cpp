//DDA Line draw
//scaling with scaling factor
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
			setcolor(MAGENTA);
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
	for(int i=screenWidth/2;i>=0;i=i-25)
	{
		for(int j=screenHeight/2;j>=0;j=j-25)
		{
			setcolor(MAGENTA);
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
	//plotting origin axes
	setcolor(WHITE);
	line(0,screenHeight/2,screenWidth,screenHeight/2);
	line(screenWidth/2,0,screenWidth/2,screenHeight);
}
int main(){
	
	float x,y,x0,y0,x1,y1,dx,dy,XIncrement,YIncrement,step,sx,sy;
	
	//graphics driver
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	
	//window size measurement and initialization
	DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",-3,-3);
	
	//graph plotting function call
	plotgraph(screenWidth,screenHeight);
	
	//dda algorithm
	
	
	cout<<"Enter the starting point (x0,y0): ";
	cin>>x0>>y0;
	cout<<"Enter the ending point (x1,y1): ";
	cin>>x1>>y1;
	cout<<"Enter the value of scaling factor (sx,sy): ";
	cin>>sx>>sy;
	
	dx=abs(x1-x0);
	dy=abs(y1-y0);
	
	if(dx>dy)
	{
		step=dx;
	}
	else
	{
		step=dy;
	}
	
	XIncrement = (x1-x0)/step;
	YIncrement = (y1-y0)/step;
	
	x=x0;
	y=y0;
	
//	cout<<"x\ty"<<endl;	
    
    for(int i=0;i<=step;i++)
    {
    
        putpixel((screenWidth/2)+((int) (x+0.5)),(screenHeight/2)-((int)(y+0.5)),GREEN);
        outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "original line");
        
        setcolor(BLUE);
        putpixel((screenWidth/2)+((int) (x*sx+0.5)),(screenHeight/2)-((int)(y*sy+0.5)),BLUE);
        outtextxy((screenWidth/2)+x1*sx+10,(screenHeight/2)-y1*sy-10, "scaled line");
        outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");

    	x=x+XIncrement;
    	y=y+YIncrement;
	}
    
	getch();
	closegraph();
	

}