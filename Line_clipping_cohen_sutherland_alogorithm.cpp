
//Program to implement Cohen-Sutherland Line Clipping Algorithm in C++

#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

static int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8,xl,yl,xh,yh;

void plotgraph(int screenWidth,int screenHeight)
{
	/*
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
	*/
	//plotting origin axes
	setcolor(YELLOW);
	line(0,screenHeight/2,screenWidth,screenHeight/2);
	line(screenWidth/2,0,screenWidth/2,screenHeight);
}
int getcode(int x,int y){
	int code = 0;
	//Perform Bitwise OR to get outcode
	if(y > yh) code =code | TOP;
	if(y < yl) code =code | BOTTOM;
	if(x < xl) code =code | LEFT;
	if(x > xh) code =code | RIGHT;
	return code;
}

int main()
{
		
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
		
	//window size measurement and initialization
	DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",-3,-3);
	
	//graph plotting function call
	plotgraph(screenWidth,screenHeight);

	setcolor(BLUE);
	cout<<"Enter bottom left and top right co-ordinates of window: ";
	cin>>xl>>yl>>xh>>yh;
	rectangle((screenWidth/2)+xl,(screenHeight/2)-yl,(screenWidth/2)+xh,(screenHeight/2)-yh);
	int x1,y1,x2,y2;
	cout<<"Enter the endpoints of the line: ";
	cin>>x1>>y1>>x2>>y2;
	line((screenWidth/2)+x1,(screenHeight/2)-y1,(screenWidth/2)+x2,(screenHeight/2)-y2);
	//getch();

	int outcode1=getcode(x1,y1), outcode2=getcode(x2,y2);
	int accept = 0; 	//decides if line is to be drawn
	while(1){
		float m =(float)(y2-y1)/(x2-x1);
		//Both points inside. Accept line
		if(outcode1==0 && outcode2==0){ 

			accept = 1;
			break;
		}
		//AND of both codes != 0.Line is outside. Reject line
		else if((outcode1 & outcode2)!=0){
			cout<<"NOT A CLIPPING CASE ";
		    outtextxy(x2+10,y2-10,"NOT A CLIPPING CASE");
			break;
		}
		else{
			int x,y;
			int temp;
			//Decide if point1 is inside, if not, calculate intersection
			if(outcode1==0) 
				temp = outcode2;
			else 
				temp = outcode1;
			//Line clips top edge
			if(temp & TOP){
				x = x1+ (yh-y1)/m;
				y = yh;
			}
			else if(temp & BOTTOM){ 	//Line clips bottom edge
				x = x1+ (yl-y1)/m;
				y = yl;
			}else if(temp & LEFT){ 	//Line clips left edge
				x = xl;
				y = y1+ m*(xl-x1);
			}else if(temp & RIGHT){ 	//Line clips right edge
				x = xh;
				y = y1+ m*(xh-x1);
			}
			//Check which point we had selected earlier as temp, and replace its co-ordinates
			if(temp == outcode1){ 
				x1 = x;
				y1 = y;
				outcode1 = getcode(x1,y1);
			}else{
				x2 = x;
				y2 = y;
				outcode2 = getcode(x2,y2);
			}
		}
	}
	setcolor(WHITE);
	outtextxy((screenWidth/2)+x2+100,(screenHeight/2)-y2-30,"After clipping: white ");
	if(accept){
		line((screenWidth/2)+x1,(screenHeight/2)-y1,(screenWidth/2)+x2,(screenHeight/2)-y2);
		getch();
	}
	getch();
	closegraph();
}