//successive Translation of line using line starting and ending points
//composite translation
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
	float x,y,x0,y0,x1,y1,tx1,ty1,tx2,ty2;
	int i;

	cout<<"Enter the value of starting point (x0,y0): ";
	cin>>x0>>y0;
	cout<<"Enter the value of ending point (x1,y1): ";
	cin>>x1>>y1;
	cout<<"Enter the value of translation factor (tx1,ty1): ";
	cin>>tx1>>ty1;
	cout<<"Enter the value of translation factor (tx2,ty2): ";
	cin>>tx2>>ty2;
	//line before translation
	setcolor(BLUE);
	line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
	
    outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "Before translation");
	//calculating the translated coordinates
	x0=x0+(tx1+tx2);
	y0=y0+(ty1+ty2);
	x1=x1+(tx1+tx2);
	y1=y1+(ty1+ty2);

	setcolor(GREEN);
	line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
	
    outtextxy((screenWidth/2)+x1+10,(screenHeight/2)-y1-10, "After translation");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");

	getch();
	closegraph();
}