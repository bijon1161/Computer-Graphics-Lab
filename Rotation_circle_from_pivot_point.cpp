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
	
	float r,xc,yc,xr,yr,xa,ya,angle,radian;
	
	//graphics driver
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	
	//window size measurement and initialization
	DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",-3,-3);
	
	//graph plotting function call
	plotgraph(screenWidth,screenHeight);
	
		
	cout<<"Enter the value of radius r : ";
	cin>>r;
	cout<<"Enter the value of center point (xc,yc): ";
	cin>>xc>>yc;
	cout<<"Enter the pivot point (xr,yr): ";
	cin>>xr>>yr;
	cout<<"Enter the rotation angle a: ";
	cin>>angle;
	
	radian=3.14/180;
	
	//before rotation
	setcolor(BLUE);
	circle((screenWidth/2)+xc,(screenHeight/2)-yc,r);
	outtextxy((screenWidth/2)+xc,(screenHeight/2)-yc+10, "Before rotation");
    
    //after rotation
    xa=xr+(xc-xr)*cos(angle*radian)-(yc-yr)*sin(angle*radian);
    ya=yr+(xc-xr)*sin(angle*radian)+(yc-yr)*cos(angle*radian);
    
    setcolor(GREEN);
	circle((screenWidth/2)+xa,(screenHeight/2)-ya,r);    
    outtextxy((screenWidth/2)+xa+10,(screenHeight/2)-ya-10, "After rotation");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");

    //drawing the pivot point as filled circle for visualization
    setfillstyle(SOLID_FILL,YELLOW);
    setcolor(YELLOW);
    circle((screenWidth/2)+xr,(screenHeight/2)-yr,3);
    outtextxy((screenWidth/2)+xr+5,(screenHeight/2)-yr+5, "pivot");
    floodfill((screenWidth/2)+xr,(screenHeight/2)-yr,YELLOW);
    
	getch();
	closegraph();
	

}