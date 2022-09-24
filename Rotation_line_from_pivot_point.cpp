//Rotation Line from pivot point draw
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
	
	float x,y,x0,y0,x1,y1,xr,yr,xa,xb,ya,yb,angle,radian;
	
	//graphics driver
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	
	//window size measurement and initialization
	DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",-3,-3);
	
	//graph plotting function call
	plotgraph(screenWidth,screenHeight);
	

	
	cout<<"Enter the starting point (x0,y0): ";
	cin>>x0>>y0;
	cout<<"Enter the ending point (x1,y1): ";
	cin>>x1>>y1;
	cout<<"Enter the pivot point (xr,yr): ";
	cin>>xr>>yr;
	cout<<"Enter the rotation angle a: ";
	cin>>angle;
	
	radian=3.14/180;
	
	//before rotation
	setcolor(BLUE);
	line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
	outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "Before rotation");
    
    //after rotation
    xa=xr+(x0-xr)*cos(angle*radian)-(y0-yr)*sin(angle*radian);
    ya=yr+(x0-xr)*sin(angle*radian)+(y0-yr)*cos(angle*radian);
    xb=xr+(x1-xr)*cos(angle*radian)-(y1-yr)*sin(angle*radian);
    yb=yr+(x1-xr)*sin(angle*radian)+(y1-yr)*cos(angle*radian);
    
    setcolor(GREEN);
	line((screenWidth/2)+xa,(screenHeight/2)-ya,(screenWidth/2)+xb,(screenHeight/2)-yb);    
    outtextxy((screenWidth/2)+xb+10,(screenHeight/2)-yb-10, "After rotation");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");
    
    //drawing the pivot point as circle for visualization
    setcolor(YELLOW);
    circle((screenWidth/2)+xr,(screenHeight/2)-yr,3);
    
    //drawing the pivot point as filled circle for visualization
    setfillstyle(SOLID_FILL,YELLOW);
    setcolor(YELLOW);
    circle((screenWidth/2)+xr,(screenHeight/2)-yr,3);
    outtextxy((screenWidth/2)+xr+5,(screenHeight/2)-yr+5, "pivot");
    floodfill((screenWidth/2)+xr,(screenHeight/2)-yr,YELLOW);
    
	getch();
	closegraph();
	

}