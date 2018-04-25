#include<iostream>
#include<windows.h>
#include<vector>
#include<string>
#include<cstring>
#include<iomanip>
//#include "func.h"
using namespace std;

	
void shownamegame(int sx,int sy){
	int n=11,pcolor[n+1]={17,34,85,102,119,153,170,187,204,221,238,255},rcolor=rand()%n;
		// Road //
		{
	
			// R //
			{
			colorit(pcolor[rcolor]);
			gotoxy(sx,sy);
			cout<<"666666";
			gotoxy(sx,sy+2);
			cout<<"rrrr";
				for(int ro=sy+1;ro < sy+5;ro++){
				gotoxy(sx,ro);
				cout<<"..";
				gotoxy(sx+4,ro);
				cout<<"..";
												}
			colorit(0);
			gotoxy(sx+5,sy+2);
			cout<<"r";
			gotoxy(sx+5,sy);
			cout<<"r";
			}
			// O //
			sx+=8;
			{
				rcolor=rand()%n;
			colorit(pcolor[rcolor]);
			gotoxy(sx,sy);
			cout<<"ooooo";
			gotoxy(sx,sy+4);
			cout<<"ooooo";
				for(int ro=sy+1;ro < sy+5;ro++){
				gotoxy(sx,ro);
				cout<<"  ";
				gotoxy(sx+4,ro);
				cout<<"  ";
			}
			colorit(0);
			gotoxy(sx,sy+4);
			cout<<"r";
			gotoxy(sx,sy);
			cout<<"r";
			gotoxy(sx+5,sy+4);
			cout<<"r";
		}
			// A //
			sx+=8; 
			{
				rcolor=rand()%n;
			colorit(pcolor[rcolor]);
			gotoxy(sx+1,sy);
			cout<<"rroa";
			gotoxy(sx,sy+2);
			cout<<"rroaar";
				for(int ro=sy+1;ro < sy+5;ro++){
				gotoxy(sx,ro);
				cout<<"  ";
				gotoxy(sx+4,ro);
				cout<<"  ";
			}
			colorit(0);
			gotoxy(sx,sy);
			cout<<"a";
		}
			//  D //
				sx+=8;
			{
			rcolor=rand()%n;
			colorit(pcolor[rcolor]);
			gotoxy(sx,sy);
			cout<<"rrord";
			gotoxy(sx,sy+4);
			cout<<"rrord";
			for(int ro=sy+1;ro < sy+5;ro++){
				gotoxy(sx,ro);
				cout<<"  ";
				gotoxy(sx+4,ro);
				cout<<"  ";
			}
			colorit(0);
			gotoxy(sx+5,sy+4);
			cout<<"r";
		}	
	}	
		// To //
		{
		rcolor=rand()%n;
			//  T //
			sx += 10;
			{
			colorit(pcolor[rcolor]);
			gotoxy(sx,sy);
			cout<<"ttttttt";
			
			for(int ro=sy;ro < sy+5;ro++){
				gotoxy(sx+2,ro);
				cout<<"0.4";
			}
		
			
			}
			//  o //
			sx=sx+8;
		{
				rcolor=rand()%n;
			colorit(pcolor[rcolor]);
			gotoxy(sx,sy);
			cout<<"ooooo";
			gotoxy(sx,sy+4);
			cout<<"ooooo";
			for(int ro=sy+1;ro < sy+5;ro++)
			{
				gotoxy(sx,ro);
				cout<<"  ";
				gotoxy(sx+4,ro);
				cout<<"  ";
			}
			colorit(0);
			gotoxy(sx,sy+4);
			cout<<"r";
			gotoxy(sx,sy);
			cout<<"r";
			gotoxy(sx+5,sy+4);
			cout<<"r";
		}
	}		
		// The //
		{
			rcolor=rand()%n;
			// T //
			sx+=11;
		{
			colorit(pcolor[rcolor]);
			gotoxy(sx,sy);
			cout<<"       ";
			
			for(int ro=sy+1;ro < sy+5;ro++)
			{
				gotoxy(sx+2,ro);
				cout<<"   ";
			}
		}
			// H //
			sx += 8;
		
			{
			rcolor=rand()%n;	
			colorit(pcolor[rcolor]);
			gotoxy(sx,sy+2);
			cout<<"       ";
		for(int ro=sy;ro < sy+5;ro++){
		
				gotoxy(sx,ro);
				cout<<"  ";
				gotoxy(sx+5,ro);
				cout<<"  ";
			}	
			
			}
			
			// E //
			sx += 9;
			{
				rcolor=rand()%n;
			colorit(pcolor[rcolor]);
			gotoxy(sx,sy+2);
			cout<<"ttttt";
			gotoxy(sx,sy);
			cout<<"ttttt";
			gotoxy(sx,sy+4);
			cout<<"ttttt";
			for(int ro=sy;ro < sy+5;ro++){
				gotoxy(sx-1,ro);
				cout<<". ";
			}		
		
			}			
		}
		
		// SKY //
		{
			rcolor=rand()%n;
			//  S // 
			sx+=10;
			{
				colorit(pcolor[7]);
				gotoxy(sx,sy);
				cout<<"555555";
				gotoxy(sx,sy+1);
				cout<<"55";
				gotoxy(sx,sy+2);
				cout<<"555555";
				gotoxy(sx+4,sy+3);
				cout<<"55";
				gotoxy(sx,sy+4);
				cout<<"555555";
				}	
			// K //
			sx+=8;
			{
				for(int i=sy;i< sy+5;i++)
				{
				colorit(pcolor[7]);
				gotoxy(sx,i);
				cout<<"55";
				}
				gotoxy(sx+6,sy);
				cout<<"55";
				gotoxy(sx+4,sy+1);
				cout<<"55";
				gotoxy(sx+2,sy+2);
				cout<<"55";
				gotoxy(sx+4,sy+3);
				cout<<"55";
				gotoxy(sx+6,sy+4);
				cout<<"55";
			}
			// Y //
			sx+=10;
			{
				colorit(pcolor[7]);
				gotoxy(sx,sy);
				cout<<"55";
				gotoxy(sx+8,sy);
				cout<<"55";
				gotoxy(sx+2,sy+2);
				cout<<"55";
				gotoxy(sx+6,sy+2);
				cout<<"55";
				gotoxy(sx,sy+1);
				cout<<"55";
				gotoxy(sx+8,sy+1);
				cout<<"55";
				gotoxy(sx+4,sy+3);
				cout<<"55";
				gotoxy(sx+4,sy+4);
				cout<<"55";
				
			}			
		}
		colorit(15);
}

