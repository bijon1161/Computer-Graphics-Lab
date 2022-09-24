#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void plotgraph(int screenWidth,int screenHeight)
{
	int i,j;
	
/*	for(i=screenWidth/2;i<=screenWidth;i=i+10)
	{
		for(j=screenHeight/2;j<=screenHeight;j=j+10)
		{
			setcolor(MAGENTA);
			line(i,0,i,screenHeight);
			line(0,j,screenWidth,j);
		}
	}
		for(i=screenWidth/2;i>=0;i=i-10)
	{
		for(j=screenHeight/2;j>=0;j=j-10)
		{
			setcolor(MAGENTA);
			line(i,0,i,screenHeight);
			line(0,j,screenWidth,j);
		}
	}
	*/
	setcolor(YELLOW);
	line(0,screenHeight/2,screenWidth,screenHeight/2);
	line(screenWidth/2,0,screenWidth/2,screenHeight);
}

int main()
{
	int gd=DETECT,gm,i;
	float xc,yc,r;
	char c;
	int lr=0,ud=0;
	
	int screenWidth=GetSystemMetrics(SM_CXSCREEN);
	int screenHeight=GetSystemMetrics(SM_CYSCREEN);
	
	initwindow(screenWidth,screenHeight,"window",2,2);
	plotgraph(screenWidth,screenHeight);
	
//	cout<<"enter the radius of thre circle r:";
//	cin>>r;
//	cout<<"enter the center of thre circle (xc,yc):";
//	cin>>xc>>yc;
    int centerX=screenWidth/2;
    int centerY=screenHeight/2;
    r=40;
    xc=50;
    yc=50;
    
    setcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
	circle((centerX)+xc,centerY-yc,r);
	floodfill(centerX+xc+1,centerY-yc+1,GREEN);
	
	while(1)
	{
		if(kbhit){
		
		c=getch();
		cleardevice();
		if(c=='a' || c==75)lr=lr-5;
		if(c=='s' || c==80)ud=ud+5;
		if(c=='d' || c==77)lr=lr+5;
		if(c=='w' || c==72)ud=ud-5;
		
		cout<<xc+lr<<" "<<yc+ud<<endl;
		setcolor(GREEN);
        setfillstyle(SOLID_FILL,GREEN);
	    circle((centerX)+xc+lr,centerY-yc+ud,r);
	    floodfill(centerX+xc+1+lr,centerY-yc+1+ud,GREEN);
	    plotgraph(screenWidth,screenHeight);
	   // delay(10);
	    
	}
		
	}
	
	getch();
	closegraph();
}