//Digital clock
#include <bits/stdc++.h>
#include <time.h>
#include <graphics.h>

int main()
{
	int gd = DETECT, gm;
	long current_time;
    // char timeStr[256];
    std::string timeStr;
    std::string tstatus="AM";
    int midx, midy;
	// Initialize of gdriver
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	
    /* mid pixel in horizontal and vertical axis */
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;
    
    /* Get Current epoch time in seconds */
    time_t t = time(NULL);
    tm *timePtr = localtime(&t); // stores the local time of the computer.

    int seconds = (timePtr->tm_sec);
    int minutes = (timePtr->tm_min);
    int hrs = (timePtr->tm_hour);

    while (!kbhit()) {
    	
        cleardevice();
        setcolor(WHITE);
        setfillstyle(HATCH_FILL, BLUE);
	    rectangle(midx - 250, midy - 40, midx + 250, midy + 40);
        floodfill(midx,midy,WHITE);
        
        
        setfillstyle(LTSLASH_FILL, BROWN);
        // Clock inner Outline
	    rectangle((midx - 250)+5, (midy - 40)+5,(midx + 250)-5, (midy + 40)-5);
        //floodfill(midx, midy, BROWN);
     
        
        setcolor(RED);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
 
        moveto(midx, midy+10);
        
        //print current time
        timeStr=std::to_string(hrs)+":"+std::to_string(minutes)+":"+std::to_string(seconds)+" "+tstatus;
        outtext((char*)timeStr.c_str());
        
        //increment sec min and hours
        seconds++;
        if (seconds >= 60)
        {
            seconds = 1;
            minutes++;
        }
        // This increases the minutes
        if (minutes >= 60)
        {
            minutes = 0;
            hrs++;
        }
        // This increases the hours
        if (hrs > 24)
        {
            hrs = 00;
        }
        if(hrs>12)
        {
        	hrs=hrs-12;
        	tstatus="PM";
		}

       //Add delay of 1000 milliseconds(1 second)
        delay(1000);
    }

	// Hold the screen for a while
	getch();

	// Close the initialized gdriver
	closegraph();
}
