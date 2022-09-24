
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;


void plotgraph(int screenWidth,int screenHeight)
{
	//plotting grids
	/*
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

int main(){
	//clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");

	//window size measurement and initialization
	DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"Window",1,1);
	
	//graph plotting function call
    plotgraph(screenWidth,screenHeight);
	float r,xc,yc,tx,ty,sx0,sy0,sx1,sy1;
	int i,x=0,y=0;

	cout<<"Enter the value of radius r : ";
	cin>>r;
	cout<<"Enter the value of center point (xc,yc): ";
	cin>>xc>>yc;
	cout<<"Enter the coordinates of straight line (sx0,sy0) and (sx1,sy1): ";
	cin>>sx0>>sy0>>sx1>>sy1;

	//line before translation
	setcolor(GREEN);
	setlinestyle(0,0,2);
	circle((screenWidth/2)+xc,(screenHeight/2)-yc,r);
	
	
 //   outtextxy((screenWidth/2)+xc,(screenHeight/2)-yc+10, "Before translation");
	//calculating the translated coordinates
    

    x=sx0;
    y=sy0;
	while(1){
		
		plotgraph(screenWidth,screenHeight);
		
		if(x>=sx1 || y>=sy1)
		 { 
		  cleardevice();
		  break;
	    }
	    
		x=x+20;
		y=y+20;
	    setcolor(WHITE);
	    setlinestyle(0,0,2);
	    line((screenWidth/2)+sx0,(screenHeight/2)-sy0,(screenWidth/2)+sx1,(screenHeight/2)-sy1);
		xc=x;
		yc=y;
		
		setcolor(GREEN);
		circle((screenWidth/2)+xc,(screenHeight/2)-yc,r);
		delay(1000);
		cleardevice();
		

    }
        setcolor(WHITE);
	    setlinestyle(0,0,2);
	    line((screenWidth/2)+sx0,(screenHeight/2)-sy0,(screenWidth/2)+sx1,(screenHeight/2)-sy1);
		xc=sx1;
		yc=sy1;
		
		setcolor(GREEN);
		circle((screenWidth/2)+xc,(screenHeight/2)-yc,r);
        plotgraph(screenWidth,screenHeight);
   
    //outtextxy((screenWidth/2)+xc+60,(screenHeight/2)-yc-10, "After translation");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");

	getch();
	closegraph();
}