#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <ctime>
#include <vector>
#include "func.h"
using namespace std;

void print(int);

int main()
{
	print(10);
	char input;
	int y=10;
	while(input!=13)
	{
		//cout << y;
		input=getch();
		
		if(input=='a')
		{
			if(y<=10) y=40;
			else y-=10;
		}
		
		if(input=='d')
		{
			if(y>=40) y=10;
			else y+=10;
		}
		
		print(y);
	}
	
	
	
}

void print(int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(10,4);
	psq(252,3.5);
	gotoxy(10,5);
	psq(252,0.5);
	if(y==10) colorit(233);
	else colorit(252);
	gotoxy(11,5);
	cout<< "Small";
	psq(252,0.5);
	//SetConsoleTextAttribute(hConsole,15);
	gotoxy(10,6);
	psq(252,3.5);
	
	gotoxy(20,4);
	psq(252,4);
	gotoxy(20,5);
	psq(252,0.5);
	//SetConsoleTextAttribute(hConsole,252);
	gotoxy(21,5);
	if(y==20) colorit(233);
	else colorit(252);
	cout<< "Medium";
	psq(252,0.5);
	//SetConsoleTextAttribute(hConsole,15);
	gotoxy(20,6);
	psq(252,4);
	
	gotoxy(31,4);
	psq(252,3.5);
	gotoxy(31,5);
	psq(252,0.5);
	//SetConsoleTextAttribute(hConsole,252);
	gotoxy(32,5);
	if(y==30) colorit(233);
	else colorit(252);
	cout<< "Large";
	psq(252,0.5);
	//SetConsoleTextAttribute(hConsole,15);
	gotoxy(31,6);
	psq(252,3.5);
	
	gotoxy(41,3);
	psq(252,6);
	gotoxy(41,4);
	psq(252,0.5);
	gotoxy(42,4);
	if(y==40)colorit(233);
	else colorit(252);
	cout<< "Creat Your";
	psq(252,0.5);
	gotoxy(41,5);
	psq(252,0.5);
	if(y==40) colorit(233);
	else colorit(252);
	cout<<" New Map";
	psq(252,1.5);
	gotoxy(41,6);
	psq(252,6);
}

/*map cremap(){
	int max,ppl,li,rd;
	do{
	cout<<"input [maxpad] [pad per lv] [number of ladder] [number of randompad] \n";
	cin>>max;
	cin>>ppl;
	cin>>li;
	cin>>rd;
	}while(max-2 < li*4 || max-2-(li*4) < rd || ppl > 12 || max<19);
	system("cls");
	SetWindow(250,(max/ppl)*7+30);
	return map(max,ppl,li,rd);
}*/
