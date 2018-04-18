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
//int main()
{
{
//	int d=0;
//	cin>>d;
	switch (d)
	{
			case 1:
				for(int i=0;i<10;i++)
					{
						for(int j=0;j<5;j++)
						{
							gotoxy(i,j);
							if(j==2&&(i==4||i==5))
								psq(192,0.5);
							else psq(123,0.5);			
						}
					}break;
			case 2:
				for(int i=0;i<10;i++)
					{
						for(int j=0;j<5;j++)
						{
							gotoxy(i,j);
							if(j==2&&(i%4==2||i%4==3))
								psq(192,0.5);
							else psq(123,0.5);			
						}
					}break;
			case 3:
				for(int i=0;i<10;i++)
					{
						for(int j=0;j<5;j++)
						{
							gotoxy(i,j);
							if(j>0&&j<4&&(i/2==j))
								psq(192,0.5);
							else psq(123,0.5);			
						}
					}break;
			case 4:
				for(int i=0;i<10;i++)
					{
						for(int j=0;j<5;j++)
						{
							gotoxy(i,j);
							if((j==1||j==3)&&(i%4==2||i%4==3))
								psq(192,0.5);
							else psq(123,0.5);			
						}
					}break;
			case 5:
				for(int i=0;i<10;i++)
					{
						for(int j=0;j<5;j++)
						{
							gotoxy(i,j);
							if(j>0&&j<4)
							{
								if((j%2==1)&&(i%6==1||i%6==2))
									psq(192,0.5);
								else if(j%2==0&&(i%6==4||i%6==5))
									psq(192,0.5);
								else psq(123,0.5);				
							}
							else psq(123,0.5);
						}
					}break;
			case 6:
				for(int i=0;i<10;i++)
					{
						for(int j=0;j<5;j++)
						{
							gotoxy(i,j);
							if((j==1||j==3)&&(i==1||i==2||i==4||i==5||i==7||i==8))
								psq(192,0.5);
							else psq(123,0.5);			
						}
					}break;
	}
}	
}


