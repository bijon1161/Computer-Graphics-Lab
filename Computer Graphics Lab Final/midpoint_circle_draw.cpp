//midpoint circle draw
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
	
	float x,y,r,xc,yc,x1,y1,dx,dy,pk;
	
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
	
	
	x=0;
	y=r;
	
	if(r- (int)r==0.0)
	{
		pk=1-r;          //initial value of decision parameter pk
	}
	else
	{
		pk=(5.0/4.0-r);
	}
	
	
//	cout<<"x\ty"<<endl;	
    
    while(x<=y)
    {
    
        putpixel((screenWidth/2)+(xc+x),(screenHeight/2)-(yc+y),GREEN);
        putpixel((screenWidth/2)+(xc+x),(screenHeight/2)-(yc-y),GREEN);
        putpixel((screenWidth/2)+(xc-x),(screenHeight/2)-(yc+y),GREEN);
        putpixel((screenWidth/2)+(xc-x),(screenHeight/2)-(yc-y),GREEN);
        putpixel((screenWidth/2)+(xc+y),(screenHeight/2)-(yc+x),GREEN);  
        putpixel((screenWidth/2)+(xc+y),(screenHeight/2)-(yc-x),GREEN);
        putpixel((screenWidth/2)+(xc-y),(screenHeight/2)-(yc+x),GREEN);
        putpixel((screenWidth/2)+(xc-y),(screenHeight/2)-(yc-x),GREEN);
        
        if(pk<0)
        {
        	x=x+1;
        	y=y;
        	pk=pk+2*x+1;
		}
		else
		{
			x=x+1;
        	y=y-1;
        	pk=pk+2*x+1-2*y;
		}
	
	}
	
    //outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "Starting point");
    //outtextxy((screenWidth/2)+x1+10,(screenHeight/2)-y1-10, "Ending point");
    //outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");
	getch();
	closegraph();
	

}