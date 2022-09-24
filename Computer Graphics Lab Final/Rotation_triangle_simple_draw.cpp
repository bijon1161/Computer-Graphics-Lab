//Rotation triangle draw
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
	
	float x,y,x0,y0,x1,y1,x2,y2,xa,xb,xc,ya,yb,yc,angle,radian;
	
	//graphics driver
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	
	//window size measurement and initialization
	DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",-3,-3);
	
	//graph plotting function call
	plotgraph(screenWidth,screenHeight);
	
	
	
	cout<<"Enter the value of first point (x0,y0): ";
	cin>>x0>>y0;
	cout<<"Enter the value of second point (x1,y1): ";
	cin>>x1>>y1;
	cout<<"Enter the value of third point (x2,y2): ";
	cin>>x2>>y2;;
	cout<<"Enter the rotation angle a: ";
	cin>>angle;
	
	radian=3.14/180;
	
	//before rotation
	setcolor(BLUE);
	line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
	line((screenWidth/2)+x1,(screenHeight/2)-y1,(screenWidth/2)+x2,(screenHeight/2)-y2);
	line((screenWidth/2)+x2,(screenHeight/2)-y2,(screenWidth/2)+x0,(screenHeight/2)-y0);
	outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "Before rotation");
    
    //after rotation
    xa=x0*cos(angle*radian)-y0*sin(angle*radian);
    ya=x0*sin(angle*radian)+y0*cos(angle*radian);
    xb=x1*cos(angle*radian)-y1*sin(angle*radian);
    yb=x1*sin(angle*radian)+y1*cos(angle*radian);
    xc=x2*cos(angle*radian)-y2*sin(angle*radian);
    yc=x2*sin(angle*radian)+y2*cos(angle*radian);
    
    setcolor(GREEN);
	line((screenWidth/2)+xa,(screenHeight/2)-ya,(screenWidth/2)+xb,(screenHeight/2)-yb);
	line((screenWidth/2)+xb,(screenHeight/2)-yb,(screenWidth/2)+xc,(screenHeight/2)-yc);
	line((screenWidth/2)+xc,(screenHeight/2)-yc,(screenWidth/2)+xa,(screenHeight/2)-ya);   
    outtextxy((screenWidth/2)+xb+10,(screenHeight/2)-yb-10, "After rotation");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");

	getch();
	closegraph();
	

}