#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
static int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8,xl,xh,yl,yh;
void plotgraph(int screenWidth,int screenHeight)
{
	setcolor(MAGENTA);
	
	for(int i=screenWidth/2;i<=screenWidth;i=i+25)
	{
		for(int j=screenHeight/2;j<=screenHeight;j=j+25)
		{
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
		for(int i=screenWidth/2;i>=0;i=i-25)
	{
		for(int j=screenHeight/2;j>=0;j=j-25)
		{
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
	setcolor(WHITE);
	line(0,screenHeight/2,screenWidth,screenHeight/2);
	line(screenWidth/2,0,screenWidth/2,screenHeight);
}
int getcode(int x,int y)
{
	int code=0;
    if(x<xl)code=code | LEFT;
	if(x>xh)code=code | RIGHT;
	if(y<yl)code=code | BOTTOM;
	if(y>yh)code=code | TOP;
	
	return code;	
}
int main()
{
	int gd=DETECT,gm;
	
	//window initialization and size measurements
	int screenWidth=GetSystemMetrics(SM_CXSCREEN);
	int screenHeight=GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"Line Clipping",-3,-3);
	
	plotgraph(screenWidth,screenHeight);
	
	float x1,y1,x2,y2;
	setcolor(YELLOW);
	cout<<"Enter bottom-left and upper-right coordinates of the window: ";
	cin>>xl>>yl>>xh>>yh;
	cout<<"Enter coordinates of the line: ";
	cin>>x1>>y1>>x2>>y2;	
		
	int code1=getcode(x1,y1);
	int code2=getcode(x2,y2);
	
	setlinestyle(0,0,2);
	rectangle((screenWidth/2)+xl,(screenHeight/2)-yl,(screenWidth/2)+xh,(screenHeight/2)-yh);
	
	setcolor(GREEN);
	setlinestyle(0,0,2);
	line((screenWidth/2)+x1,(screenHeight/2)-y1,(screenWidth/2)+x2,(screenHeight/2)-y2);
	
	int accept=0;
	while(1){
		float m=(float) (y2-y1)/(x2-x1);
		if(code1==0 && code2==0)
		{
	    	accept=1;
	    	break;
		}
		else if((code1 & code2)!=0)
		{
			outtextxy(screenWidth/2+x1,screenHeight/2-y1,"Not a clipping case");
			break;
		}
		else
		{
			int x,y;
			int temp;
			
			if(code1==0)
			{
				temp=code2;
			}
			else
			{
				temp=code1;
			}
			
			if(temp & TOP)
			{
				x=	x1+(yh-y1)/m;
				y=  yh;
			}
			else if(temp & BOTTOM)
			{
				x=	x1+(yl-y1)/m;
				y=  yl;
			}
			else if(temp & LEFT)
			{
				x=	xl;
				y=  yl+(xl-x1)*m;
			}
			else if(temp & RIGHT)
			{
				x=	xh;
				y=  y1+(xh-x1)*m;
			}
			
			if(code1==temp)
			{
				x1=x;
				y1=y;
				code1=getcode(x1,y1);
				
			}
			else
			{
				x2=x;
				y2=y;
				code2=getcode(x2,y2);	
			}
				
		}
    	}
	setcolor(WHITE);
	
	if(accept==1)
	{
		setlinestyle(0,0,2);  //line thickness increase
		line((screenWidth/2)+x1,(screenHeight/2)-y1,(screenWidth/2)+x2,(screenHeight/2)-y2);
		outtextxy((screenWidth/2)+x2+100,(screenHeight/2)-y2-30,"After clipping: white ");
		getch();
	}
	getch();
	closegraph();
	
	
	return 0;
}