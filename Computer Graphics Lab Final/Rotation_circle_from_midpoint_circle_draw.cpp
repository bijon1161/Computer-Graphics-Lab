//midpoint circle draw
//rotation 
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
	
	float x,y,r,xc,yc,x1,y1,dx,dy,pk,radian,angle;
	
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
	cout<<"Enter the rotation angle a: ";
	cin>>angle;
	
	radian=angle*3.14/180;
	
	
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
        setcolor(GREEN);
        putpixel((screenWidth/2)+(xc+x),(screenHeight/2)-(yc+y),GREEN);
        putpixel((screenWidth/2)+(xc+x),(screenHeight/2)-(yc-y),GREEN);
        putpixel((screenWidth/2)+(xc-x),(screenHeight/2)-(yc+y),GREEN);
        putpixel((screenWidth/2)+(xc-x),(screenHeight/2)-(yc-y),GREEN);
        putpixel((screenWidth/2)+(xc+y),(screenHeight/2)-(yc+x),GREEN);  
        putpixel((screenWidth/2)+(xc+y),(screenHeight/2)-(yc-x),GREEN);
        putpixel((screenWidth/2)+(xc-y),(screenHeight/2)-(yc+x),GREEN);
        putpixel((screenWidth/2)+(xc-y),(screenHeight/2)-(yc-x),GREEN);
        
        //rotation
        //there's something wrong ***************************************************
        /*
        putpixel((screenWidth/2)+(xc+x)*cos(radian)-(yc+y)*sin(radian),(screenHeight/2)-(xc+x)*sin(radian)+(yc+y)*cos(radian),BLUE);
        putpixel((screenWidth/2)+(xc+x)*cos(radian)-(yc-y)*sin(radian),(screenHeight/2)-(xc+x)*sin(radian)+(yc-y)*cos(radian),BLUE);
        putpixel((screenWidth/2)+(xc-x)*cos(radian)-(yc+y)*sin(radian),(screenHeight/2)-(xc-x)*sin(radian)+(yc+y)*cos(radian),BLUE);
        putpixel((screenWidth/2)+(xc-x)*cos(radian)-(yc-y)*sin(radian),(screenHeight/2)-(xc-x)*sin(radian)+(yc-y)*cos(radian),BLUE);
        putpixel((screenWidth/2)+(xc+y)*cos(radian)-(yc+x)*sin(radian),(screenHeight/2)-(xc+y)*sin(radian)+(yc+x)*cos(radian),BLUE);
        putpixel((screenWidth/2)+(xc+y)*cos(radian)-(yc-x)*sin(radian),(screenHeight/2)-(xc+y)*sin(radian)+(yc-x)*cos(radian),BLUE);
        putpixel((screenWidth/2)+(xc-y)*cos(radian)-(yc+x)*sin(radian),(screenHeight/2)-(xc-y)*sin(radian)+(yc+x)*cos(radian),BLUE);
        putpixel((screenWidth/2)+(xc-y)*cos(radian)-(yc-x)*sin(radian),(screenHeight/2)-(xc-y)*sin(radian)+(yc-x)*cos(radian),BLUE);
        */
        
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
	
    outtextxy((screenWidth/2)+xc,(screenHeight/2)-yc+10, "before rotation");
   
    
    setcolor(BLUE);
    outtextxy((screenWidth/2)+(xc+x)*cos(radian)-(yc+y)*sin(radian)+10,(screenHeight/2)-(xc+x)*sin(radian)+(yc+y)*cos(radian)-10, "after rotation");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");
	getch();
	closegraph();
	

}