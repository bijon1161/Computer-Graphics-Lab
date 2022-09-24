#include <iostream>

#include <graphics.h>

#include <math.h>

#include <conio.h>

using namespace std;

void draw_wave()
{
	int x,y;
	line(0,300,getmaxx(),300);

    line(400,0,400,getmaxy());

    float pi = 3.14;
	for(int i = -360; i < 360 ; i++)

    {

        x = (int) 400+i;

        y = (int) 300 - cos(i*pi/180)*25;

        putpixel(x,y,WHITE);

    }
}
int main()

{

    initwindow(800,600);
	int x,y;
	float pi = 3.14;
	
    draw_wave();

	for(int i = -360; i < 360 ; i=i+5)

    {

        x = (int) 400+i;

        y = (int) 300 - 25*cos(i*3.141/180);
        
        circle(x,y,20);
        
        delay(200);
        cleardevice();
        draw_wave();
		

    }
    
    getch();

    closegraph();

    return 0;

}