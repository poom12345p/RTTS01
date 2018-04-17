#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <ctime>
#include <vector>
#include "func.h"
using namespace std;
void Dice(int d);
int main()
{
	srand(time(0));
	while(getch() !=32)
	{
	}
	Sleep(100);
	char c='0';
	vector<int> dice;
	int R=0;
	for(int i=1; i<7 ; i++)
	{
		dice.push_back(i);	
	}
	
	while(c !=32)
	{
		Dice(1+(R%6));
		if (_kbhit()==1)
	    {	
			c=getch();
			dice.push_back((R%35)/6+1);
	        break;
	    }	        
	    Sleep(20);
	    R++;
	}
	Dice(dice[rand()%7+1]);
}

void Dice(int d)
{
	switch (d)
	{
		case 1:
		for(int i=0; i<25 ;i++)
		{
			for(int j=0; j<50;j++)
			{
				gotoxy(j+5,i+5);
				if(i>4&&i<21)
				{
					if(j>9&&j<41) psq(192,1);
					else psq(123,1);
				}
				else psq(123,1);	
			}
		
		} break;
		case 2:
			for(int i=0; i<25 ;i++)
			{
				for(int j=0; j<50;j++)
				{
					gotoxy(j+5,i+5);
					if((i>4&&i<11)||(i>14&&i<21))
					{
						if((j>9&&j<21)||(j>29&&j<41)) psq(192,1);
						else psq(123,1);
					}
					else psq(123,1);	
				}
		
			}break;
		case 3:
			for(int i=0; i<25 ;i++)
			{
				for(int j=0; j<50;j++)
				{
					gotoxy(j+5,i+5);
					if((i>4&&i<11)&&(j>4&&j<16))		psq(192,1);
					if((i>9&&i<16)&&(j>19&&j<31))	psq(192,1);
					if((i>14&&i<21)&&(j>34&&j<46))	psq(192,1);
					else psq(123,1);	
				}
			}break;
		case 4:
			for(int i=0; i<25 ;i++)
			{
				for(int j=0; j<50;j++)
				{
					gotoxy(j+5,i+5);
					if((i>4&&i<11)||(i>14&&i<21))
					{
						if((j>9&&j<21)||(j>29&&j<41)) psq(192,1);
						else psq(123,1);
					}
					else psq(123,1);	
				}
			}break;
		case 5:
			for(int i=0; i<25 ;i++)
			{
				for(int j=0; j<50;j++)
				{
					gotoxy(j+5,i+5);
					if((i>2&&i<9)&&(j>7&&j<19))	psq(192,1);
					if((i>2&&i<9)&&(j>31&&j<43))	psq(192,1);
					if((i>9&&i<16)&&(j>19&&j<31))	psq(192,1);
					if((i>16&&i<23)&&(j>7&&j<19))	psq(192,1);
					if((i>16&&i<23)&&(j>31&&j<43))	psq(192,1);
					else psq(123,1);	
				}
			}break;
		case 6:
			for(int i=0; i<25 ;i++)
			{
				for(int j=0; j<50;j++)
				{
					gotoxy(j+5,i+5);
					if((i>4&&i<11)||(i>14&&i<21))
					{
						if((j>4&&j<16)||(j>19&&j<31)||(j>34&&j<46)) psq(192,1);
						else psq(123,1);
					}
					else psq(123,1);	
				}
			}break;	
	}
	
}


