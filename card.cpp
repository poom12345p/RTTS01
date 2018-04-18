#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <ctime>
#include <vector>
#include "func.h"
using namespace std;
void card(int,int);
bool selected(int);
int main()
{
	srand(time(0));
	for(int a=0; a<4;a++)
	{
		for(int i=0;i<15;i++)
		{
			for(int j=0;j<11;j++)
			{
				gotoxy(i+(a*20),j);
				if((j==2)&&(i>2&&i<13))
					psq(153,1);
				else if((j>2&&j<6)&&(i==12||i==11))
					psq(153,1);
				else if((j==6)&&(i>4&&i<13))
					psq(153,1);
				else if((j==6||j==7||j==9)&&(i==5||i==6))
					psq(153,1);			
				else psq(127,1);		
		}
		}
	}
	Sleep(100);
	int R=0;
	int c='0';
	bool havecard=true;
	vector<bool>cards;
	for(int i=0;i<4;i++)
		cards.push_back(false);
	vector<int>number;
		for(int i=0;i<4;i++)
			number.push_back(i+1);
	while(havecard)
	{
		gotoxy(0,14);
		cin>> c;
		if(c>0&&c<5)
		{
			while(cards[c-1]==true)
			{	
				gotoxy(0,13);
				cout<<"Select new card"<<endl;
				cin>> c;
			}
			cards.at(c-1)=selected(c);
			R=rand()%number.size();
			card(number[R],c-1);
			number.erase(number.begin()+R);
			if(cards[0]==true&&cards[1]==true&&cards[2]==true&&cards[3]==true) havecard=false;
		}
		else
		{
			gotoxy(0,13);
			cout<<"Please select 1-4";	
		}
	}
}
bool selected(int R)
{
	switch(R)
	{
		case 1:return 1;
		case 2:return 1;
		case 3:return 1;
		case 4:return 1;
	}
}
void card(int R,int a)
{
	switch (R)
	{
			case 1:
				for(int i=0;i<15;i++)
				{
					for(int j=0;j<11;j++)
					{
						gotoxy(i+a*20,j);
						if((j==3||j==2)&&(i==5||i==6))
							psq(153,1);
						else if((j>1&&j<9)&&(i==7||i==8||i==9))
							psq(153,1);			
						else psq(127,1);		
					}
				}break;
			case 2:
				for(int i=0;i<15;i++)
				{
					for(int j=0;j<11;j++)
					{
						gotoxy(i+a*20,j);
						if((j==3||j==2||(j>4&&j<9))&&(i==5||i==4||i==3))
							psq(153,1);
						else if((j==8||j==9||(j>1&&j<7))&&(i==10||i==11||i==12))
							psq(153,1);
						else if((j==2||j==3||j==5||j==6||j==8||j==9)&&(i>2&&i<13))
							psq(153,1);			
						else psq(127,1);		
					}
				}break;
			case 3:
				for(int i=0;i<15;i++)
				{
					for(int j=0;j<11;j++)
					{
						gotoxy(i+a*20,j);
						if((j>1&&j<10)&&(i==10||i==11||i==12))
							psq(153,1);
						else if((j==2||j==3||j==5||j==6||j==8||j==9)&&(i>2&&i<13))
							psq(153,1);			
						else psq(127,1);		
					}
				}break;
			case 4:
				for(int i=0;i<15;i++)
				{
					for(int j=0;j<11;j++)
					{
						gotoxy(i+a*20,j);
						if((i>2&&i<6)&&(j>1&&j<7))
							psq(153,1);
						else if((i>5&&i<10)&&(j==5||j==6))
							psq(153,1);			
						else if((i>9&&i<13)&&(j>1&&j<10))
							psq(153,1);
						else psq(127,1);		
					}
				}break;
	}
}
	 
