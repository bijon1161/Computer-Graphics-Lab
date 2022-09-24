//Shearing of line using line starting and ending points

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
	float x,y,x0,y0,x1,y1,shx,shy;
	int i;

	cout<<"Enter the value of starting point (x0,y0): ";
	cin>>x0>>y0;
	cout<<"Enter the value of ending point (x1,y1): ";
	cin>>x1>>y1;
	cout<<"Enter the value of shearing parameter (shx,shy): ";
	cin>>shx>>shy;

	//line before shearing
	setcolor(BLUE);
	line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
	
    outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "Before shearing");
    
    //shearing on x-axis
	//calculating the sheared coordinates
	x0=x0+shx*y0;
	y0=y0;
	x1=x1+shx*y1;
	y1=y1;

	setcolor(GREEN);
	line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
	
    outtextxy((screenWidth/2)+x1+10,(screenHeight/2)-y1-10, "After shearing(x-axis)");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");
    
    /*
    //shearing on y-axis
	//calculating the sheared coordinates
	x0=x0;
	y0=y0+shy*x0;
	x1=x1;
	y1=y1+shy*x1;

	setcolor(RED);
	line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
    outtextxy((screenWidth/2)+x1+10,(screenHeight/2)-y1-10, "After shearing(y-axis)");
    */
	getch();
	closegraph();
}