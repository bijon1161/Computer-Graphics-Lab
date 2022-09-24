#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);

void countm(int co_mo,int inc) // co_mo : count move
{
    inc+=5;
    settextstyle(0,HORIZ_DIR,0);
    setcolor(14);
//    outtextxy(515,198,"MOVE");
//    char arr[50];
//    sprintf(arr,"%d",*co_mo);
//    setcolor(3);
//    outtextxy(520,215,arr);
    co_mo=co_mo+1;

}

//void moving_obstruction(int left, int top, int right, int bottom)
//{
//	for(int i=1;i<150;i++)
//	{
//		top = top+i;
//		bottom = bottom+i;
//		rectangle(left, top, right, bottom);
//		cout<<top+i<<"\n";
//    	floodfill(left+10,top+10,RED);
//		delay(50);
//		cleardevice();
//	}
//}

void body() //figure
{
    setcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    
    //Border
    rectangle(0,0,640,20);
    floodfill(10,10,RED);
    
    rectangle(0,460,640,480);
    floodfill(10,470,RED);
    
    rectangle(0,0,20,480);
    floodfill(10,30,RED);
    
    rectangle(620,0,640,480);
    floodfill(630,430,RED);
    
    //Obstructions
    setcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    
    rectangle (100,150,125,250);
    floodfill(110,160,RED);
    
    rectangle (200,50,225,150);
    floodfill(210,100,RED);
    
    rectangle (300,250,325,350);
    floodfill(310,300,RED);
    
    rectangle (400,100,425,200);
    floodfill(410,150,RED);
    
    rectangle (500,175,525,275);
    floodfill(510,200,RED);
    
    rectangle (140,275,170,305);
    floodfill(141,276,RED);
    
    //Triangle
    setfillstyle(SOLID_FILL,BLUE);
    
    line(220, 480, 320, 480);
    line(220, 480, 270, 400);
    line(320, 480, 270, 400);
    floodfill(271,410,RED);
    
    //Circle
    setfillstyle(SOLID_FILL,MAGENTA);
    
    circle(560, 60, 25);
    floodfill(561,61,RED);
    
    setcolor(WHITE);
}
int ball(int j,int k,int l)   //ball
{
	setcolor(GREEN);
    circle(j,k,l);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(j+1,k+1,GREEN);
}
void condition(int *j,int *k, int *chk)
{
	if(*j<=30 || *j>=610 || *k<=30 || *k>=450)
	{
		*chk = 0;
	}
	if(*j>=130 && *k>=265)
	{
		if(*j<=180 && *k<=315){
			*chk = 0;
		}
	}
    if(*j>=90 && *j<=135)
    {
        if(*k>135 && *k<265) {
            *chk = 0;
        }
    }
    
    if(*j>=190 && *j<=235)
    {
        if(*k>35 && *k<165) {
            *chk = 0;
        }
    }
    
    if(*j>=290 && *j<=335)
    {
        if(*k>235 && *k<365) {
            *chk = 0;
        }
    }
    
    if(*j>=390 && *j<=435)
    {
        if(*k>85 && *k<215) {
            *chk = 0;
        }
    }
    
    if(*j>=490 && *j<=535)
    {
        if(*k>160 && *k<290) {
            *chk = 0;
        }
    }
    if(round(sqrt((*j - 560) * (*j - 560) + (*k - 60) * (*k - 60))) == 35)
    {
    	*chk = 0;
	}
	

}

int start(int *p)
{
    int i,j=50,k=250,l=10,m=10,co_mo=0,inc=0, chk=1111;
    char c;
    cleardevice();
    body();          //draw the figure
    ball(j,k,l);     //draw the  ball

    countm(&co_mo,&inc);
    for(i=0; i<m++; i++)
    {
        condition(&j,&k,&chk); //cheacking condition
        if(chk == 0) {
        	setcolor(CYAN);
        	settextstyle(10,HORIZ_DIR,5);
        	outtextxy(220,240,"GAME OVER");
        	delay(3000);
        	settextstyle(0,HORIZ_DIR,0);
        	cleardevice();
        	char arr[50];
        	sprintf(arr,"%d",co_mo);
    		setcolor(14);
    		outtextxy(240,240,"Your Score is: ");
    		setcolor(3);
    		outtextxy(320,270,arr);
            delay(5000);
			return 0;
		}
        countm(&co_mo,&inc);
        c=getch();
        cleardevice();
        if(c==75||c=='a') j-=5;
        if(c==80||c=='s') k+=5;
        if(c==77||c=='d') j+=5;
        if(c==72||c=='w') k-=5;
        if(c==' ') return 0;
        *p=co_mo;
        body();        //draw the figure
        ball(j,k,l);   //draw the ball
        // if(j>=500) return 1;
    }

    return 9999;
}
int main()
{
    int d=DETECT,g;
    int flag,point=0;
    initgraph(&d,&g,"");

    flag=start(&point);

    getch();
    closegraph();
    return flag;
}
