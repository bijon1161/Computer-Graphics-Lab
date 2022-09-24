//reflection circle simple draw
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
	
	float r,xc,yc;
	
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
	
	//before reflection
	setcolor(BLUE);
	circle((screenWidth/2)+xc,(screenHeight/2)-yc,r);
	outtextxy((screenWidth/2)+xc,(screenHeight/2)-yc+10, "Before reflection");
    
    //x-axis reflection
    xc=xc;
    yc=-yc;
    
    setcolor(GREEN);
	circle((screenWidth/2)+xc,(screenHeight/2)-yc,r);    
    outtextxy((screenWidth/2)+xc+10,(screenHeight/2)-yc-10, "x-axis reflection");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");
    
    /*
    //y-axis reflection
    xc=-xc;
    yc=yc;
    
    setcolor(RED);
	circle((screenWidth/2)+xc,(screenHeight/2)-yc,r);    
    outtextxy((screenWidth/2)+xc+10,(screenHeight/2)-yc-10, "y-axis reflection");
   */
	getch();
	closegraph();
	

}