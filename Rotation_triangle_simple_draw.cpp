//Rotation of triangle
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()  
{  
    int gd=0,gm,x1,y1,x2,y2,x3,y3;  
    double s,c, angle;  
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");  
    setcolor(RED);  
    cout<<"Enter the value of  point (x1,y1): ";
    cin>>x1>>y1;
    cout<<"Enter the value of  point (x2,y2): ";
    cin>>x2>>y2;
    cout<<"Enter the value of  point (x3,y3): ";
    cin>>x3>>y3;
    cout<<"Enter Rotation Angle(a): ";
    cin>>angle; 
    
   
    setcolor(GREEN);
    line(x1,y1,x2,y2);  
    line(x2,y2, x3,y3);  
    line(x3, y3, x1, y1);  
   
      
     
  
    c = cos(angle *M_PI/180);  
    s = sin(angle *M_PI/180);  
    
    x1 = abs(floor(x1 * c + y1 * s));  //shouldn't use abs(),but for some negative value no output is generating so used abs() here
    y1 = abs(floor(-x1 * s + y1 * c));  
    x2 = abs(floor(x2 * c + y2 * s));  
    y2 = abs(floor(-x2 * s + y2 * c));  
    x3 = abs(floor(x3 * c + y3 * s));  
    y3 = abs(floor(-x3 * s + y3 * c));  
     
    setcolor(RED);
    line(x1, y1 ,x2, y2);  
    line(x2,y2, x3,y3);  
    line(x3, y3, x1, y1);  
    
    getch();  
    closegraph();  
 
}  