//Reflection Line simple draw
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
	
	float x,y,x0,y0,x1,y1,x2,x3,x4,x5,y2,y3,y4,y5;
	
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

	
	//before reflection
	setcolor(BLUE);
	line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
	outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "Before reflection");
    
    //reflection on x-axis
    x2=x0;
    y2=-y0;
    x3=x1;
    y3=-y1;
    
    setcolor(GREEN);
	line((screenWidth/2)+x2,(screenHeight/2)-y2,(screenWidth/2)+x3,(screenHeight/2)-y3);    
    outtextxy((screenWidth/2)+x3+10,(screenHeight/2)-y3-10, "x-axis reflection");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");

    //reflection on y-axis
    x4=-x0;
    y4=y0;
    x5=-x1;
    y5=y1;
    
    setcolor(GREEN);
	line((screenWidth/2)+x4,(screenHeight/2)-y4,(screenWidth/2)+x5,(screenHeight/2)-y5);    
    outtextxy((screenWidth/2)+x5+10,(screenHeight/2)-y5-10, "y-axis reflection");
	getch();
	closegraph();
	

}