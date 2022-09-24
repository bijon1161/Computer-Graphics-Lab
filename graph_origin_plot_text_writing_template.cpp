
//transformation

#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void plotgraph(int screenWidth,int screenHeight){
	
    //plotting graph grids
	for(int i=screenWidth/2;i<=screenWidth;i=i+25){
      	for(int j=screenHeight/2;j<=screenHeight;j=j+25){
      		setcolor(WHITE);
      		line(0,j,screenWidth,j);
        	line(i,0,i,screenHeight);
	  	}	
	}
	for(int i=screenWidth/2;i>=0;i=i-25){
      	for(int j=screenHeight/2;j>=0;j=j-25){
      		setcolor(WHITE);
        	line(0,j,screenWidth,j);
        	line(i,0,i,screenHeight);
	  	}	
	}
	
	//plotting origin lines
    setcolor(YELLOW);
    line(0,screenHeight/2,screenWidth,screenHeight/2);
    line(screenWidth/2,0,screenWidth/2,screenHeight);	
	
}

int main(){
    
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    setbkcolor(WHITE);
    //window size measurement and initialization
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth, screenHeight, "", -3, -3);
	
	plotgraph(screenWidth,screenHeight); //calling graph plotting function
    
    float x,y,x0,y0,x1,y1,sx,sy;
    
    
    
    cout<<"Enter value of stating point x0,y0: ";
    cin>>x0>>y0;
    cout<<"Enter the value of ending point (x1,y1): ";
    cin>>x1>>y1;
    
    //line drawing with respect to plotted origin
    setcolor(GREEN);
    line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
    //text writing
    outtextxy((screenWidth/2)+x0,(screenHeight/2)-y0+10, "Starting point");
    outtextxy((screenWidth/2)+x1+10,(screenHeight/2)-y1-10, "Ending point");
    outtextxy((screenWidth/2)+5,(screenHeight/2)+5, "(0,0)");
    
	delay(500);
    getch();
    closegraph();
}