/*#include<bits/stdc++.h>
#include<graphics.h>
 using namespace std;
void drawline(int x0, int y0, int x1, int y1)
{
int dx, dy, p, x, y;
 
dx=x1-x0;
dy=y1-y0;
 
x=x0;
y=y0;
 
p=2*dy-dx;
 
while(x<x1)
{
if(p>=0)
{
putpixel(x,y,7);
y=y+1;
p=p+2*dy-2*dx;
}
else
{
putpixel(x,y,7);
p=p+2*dy;
}
x=x+1;
}
}
 
int main()
{
int gdriver=DETECT, gmode, error, x0, y0, x1, y1;
initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
 
cout<<"Enter co-ordinates of first point: ";
cin>>x0>>y0;
 
cout<<"Enter co-ordinates of second point: ";
cin>>x1>>y1;
drawline(x0, y0, x1, y1);
 getch();
return 0;
}*/

#include<bits/stdc++.h>
#include<graphics.h>
 using namespace std;
void get_driver()
{
//clrscr(); //clear screen
int gDriver=DETECT,gMode;
initgraph(&gDriver,&gMode,"C:\\TC\\BGI");
}

int main()
{
get_driver(); //initialize graphics
int dx, dy, p, end;
float x1, x2, y1, y2, x, y;
x1=x2=y1=y2=x=y=p=end=dx=dy=0;
cout<<"Enter the x1 value : ";
cin>>x1;
cout<<"Enter the y1 value : ";
cin>>y1;
cout<<"Enter the x2 value : ";
cin>>x2;
cout<<"Enter the y2 value : ";
cin>>y2;
cleardevice(); //clear Screen for graphics
setbkcolor(15);//set background white
dx = abs(x1 - x2);
dy = abs(y1 - y2);
p = 2 * dy - dx;
if(x1 > x2)
{
x = x2;
y = y2;
end = x1;
}
else
{
x = x1;
y = y1;
end = x2;
}
putpixel(x, y, RED); //put first pixel
while(x < end)
{
x = x + 1;
if(p < 0)
{
p = p + 2 * dy;
}
else
{
y = y + 1;
p = p + 2 * (dy - dx);
}
putpixel(x,y,RED); //put pixel in loop
}
getch();
}