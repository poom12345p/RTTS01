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
	for(int i=1;i<7;i++)
	{
	gotoxy(6*i+2,4);
   	cout <<i;
   	gotoxy(6*i,5);
	if(i%2==0) psq (32,3);
	else psq (203,3);	
	}
	
	while(c !=32)
	{
		gotoxy(6+(R%35),5);
		psq(245,0.5);
		if (_kbhit()==1)
	    {	
			c=getch();
	    	gotoxy(6+(R%35),5);
	    	psq(245,0.5);
			dice.push_back((R%35)/6+1);
	        break;
	    }	        
	    Sleep(20);
	    gotoxy(6+(R%35),5);
		if((1+(R%35)/6)%2==0) psq (32,0.5);
		else psq (203,0.5);
	    R++;
	}
	
	gotoxy(6,7);
	cout<< dice[rand()%7+1];
}

