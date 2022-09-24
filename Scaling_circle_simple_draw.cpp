//scaling of circle from simple circle drawing
//scaling
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
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");

	//window size measurement and initialization
	DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",-3,-3);
	
	//graph plotting function call
	plotgraph(screenWidth,screenHeight);
	float r,xc,yc,sx,sy;
	int i;

	cout<<"Enter the value of radius r : ";
	cin>>r;
	cout<<"Enter the value of center point (xc,yc): ";
	cin>>xc>>yc;
	cout<<"Enter the value of scaling factor (sx): ";
	cin>>sx;

	//circle before scaling
	setcolor(BLUE);
	circle((screenWidth/2)+xc,(screenHeight/2)-yc,r);
	
	
    outtextxy((screenWidth/2)+xc,(screenHeight/2)-yc+10, "Before scaling");
	//calculating the scaled coordinates
	//xc=xc*sx;
	//yc=yc*sy;
      r=r*sx;
	setcolor(GREEN);
	circle((screenWidth/2)+xc,(screenHeight/2)-yc,r);
	
    outtextxy((screenWidth/2)+xc+60,(screenHeight/2)-yc-10, "After scaling");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");

	getch();
	closegraph();
}