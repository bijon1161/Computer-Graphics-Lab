#include <graphics.h>
#include <conio.h>
main()
{
   int gd = DETECT, gm;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   setcolor(RED);
   setfillstyle(HATCH_FILL, BLUE);
   circle(100,100,50);
   floodfill(100,100,RED);
   
   getch();
   closegraph();
   return 0;
}