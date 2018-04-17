#include <iostream>
#include<windows.h>
using namespace std;

void SetWindow(int Width, int Height)//don,t care//set window size
    {
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Width-1;
    Rect.Right = Height-1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
    }


void psq(int c,float i,char p=0){//draw pixel i block,color code c
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,c); 
	for(int j=0;j <i*2 ;j++)
	{
		if(p!=0)cout <<p;
		else cout<<" ";
	}
	SetConsoleTextAttribute(hConsole,15); 
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void colorit(int col){//12=red, 15=white---------------->this.colorit(12);  this.colorit(15);
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), col );
}
 
