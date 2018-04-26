#include<iostream>
#include<windows.h>
#include<vector>
#include<string>
#include<cstring>
#include<iomanip>
//#include "func.h"
using namespace std;

	
void  shownamegame(int sx,int sy){
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
			cout<<"ttttttt";
			
			for(int ro=sy+1;ro < sy+5;ro++)
			{
				gotoxy(sx+2,ro);
				cout<<"0.4";
			}
		}
			// H //
			sx += 8;
		
			{
			rcolor=rand()%n;	
			colorit(pcolor[rcolor]);
			gotoxy(sx,sy+2);
			cout<<"ttthhtt";
		for(int ro=sy;ro < sy+5;ro++){
		
				gotoxy(sx,ro);
				cout<<". ";
				gotoxy(sx+5,ro);
				cout<<". ";
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
		
		
		
		
			}
	
		
	void showkrop(int sx,int sy,int ex,int ey){sx-=5;
	int n=11,pcolor[n+1]={17,34,85,102,119,153,170,187,204,221,238,255},color[2],i=0,j=0;
		color[0]=rand()%n;
		color[1]=rand()%n;
		
		while( i < 8 ){
		
		if(color[0] == color[1]){
			color[1]=rand()%n;
		}else{
			i=15;
		}
		}					
			gotoxy(sx,sy);
			for(int i=sy;i <= ey;i++){
				gotoxy(sx,i);
				colorit(pcolor[color[j]]);
				cout<<" ";j++;j=j%2;colorit(pcolor[color[j]]);cout<<" ";				
			}
			gotoxy(ex,sy);
			for(int i=sy;i <= ey;i++){
				gotoxy(ex,i);
			colorit(pcolor[color[j]]);
				cout<<" ";j++;j=j%2;colorit(pcolor[color[j]]);cout<<" ";
				
			}
			gotoxy(sx,ey);
			for(int i=sx-1;i <= ex;i++){
				colorit(pcolor[color[j]]);
				cout<<" ";
				j++;
				j=j%2;
			}
		gotoxy(sx,sy);
			for(int i=sx-1;i <= ex;i++){
				colorit(pcolor[color[j]]);
				cout<<" ";
				j++;
				j=j%2;
			}
	}
	
	

void htp()
{
	SetWindow(231,81);
	int x=100,y=3;
	gotoxy(x,y);
	cout<<"[RULES]";
	gotoxy(x-20,++y);
	cout<<"1.Go to last pad and win this game.";
	gotoxy(x-20,++y);
	cout<<"2.Think Carefully and watch your step.";
	gotoxy(x-20,++y);
	cout<<"3.Using item for support your self and block the enemy way.";
	y+=3;
	gotoxy(x-2,y);
	cout<<"[Pads type]";
	x=10;
	////draw normal pads
	gotoxy(x+5,y+7);
	psq(32,9);
	gotoxy(x+1+5,y-1+7);
	psq(32,3.5);
	colorit(47);
	cout<<"48";
	psq(32,3.5);//-------
	gotoxy(x+5+18,y+7);
	psq(151,9);
	gotoxy(x+1+5+18,y-1+7);
	psq(151,3.5);
	colorit(151);
	cout<<"69";
	psq(151,3.5);
	/////////////////ladder
	gotoxy(x+5+55,y+7);
	psq(32,9);
	gotoxy(x+61,y-1+7);
	psq(32,3.5);
	colorit(47);
	cout<<"20";
	psq(32,3.5);
	gotoxy(x+5+62,y+7);
	colorit(97);
	cout<<"->48";
	/////////////////snake///
	gotoxy(x+5+90,y+7);
	psq(32,9);
	gotoxy(x+96,y-1+7);
	psq(32,3.5);
	colorit(47);
	cout<<"40";
	psq(32,3.5);
	gotoxy(x+5+97,y+7);
	colorit(207);
	cout<<"16<-";
	/////////////////////rand dom
	gotoxy(x+5+130,y+7);
	psq(151,9);
	gotoxy(x+6+130,y-1+7);
	psq(151,3.5);
	colorit(151);
	cout<<"24";
	psq(151,3.5);
	gotoxy(x+11+130,y+7);
	colorit(112);
	cout<<"RANDOM";
	colorit(15);
	///////last pad
	gotoxy(x+5+165,y+7);
	psq(236,9);
	gotoxy(x+6+165,y-1+7);
	psq(236,3.5);
	colorit(236);
	cout<<"100";
	psq(236,3);
	gotoxy(x+5+165+7,y+7);
	drawstar(position(x+5+165,y+7));
	////////////
	y+=8;
	gotoxy(x+15,y);
	cout<<"[Normal pad]";
	gotoxy(x+62,y);
	cout<<"[Ladder pad]";
	gotoxy(x+99,y);
	cout<<"[Snake pad]";
	gotoxy(x+137,y);
	cout<<"[Random pad]";
	gotoxy(x+175,y);
	cout<<"[Win pad]";
	//////////////////////
	y+=2;
	x+=5;
	gotoxy(x,y);
	cout<<"-Items will spawn at this pad.";
	gotoxy(x,y+1);
	cout<<"-You can set trap here.";
	//
	x+=47;
	gotoxy(x,y);
	cout<<"-if you are on at this pad,";
	gotoxy(x,y+1);
	cout<<" you will gotopad further pad";
	//
	x+=37;
	gotoxy(x,y);
	cout<<"-if you are on at this pad,";
	gotoxy(x,y+1);
	cout<<" you will be sent away from win pad";
	//
	x+=42;
	gotoxy(x,y);
	cout<<"-if you are on at this pad,";
	gotoxy(x,y+1);
	cout<<" you will get random event";
	//
	x+=34;
	gotoxy(x,y);
	cout<<"-if you are on at this pad,you will win";
	gotoxy(x,y+1);
	cout<<"-But if your steps go futher,you will step back";
	//////////////////////////////////////////////////////
	y+=5;
	gotoxy(100,y);
	cout<<"[Item]";
	y+=2;
	x=85;
	gotoxy(x,y);
	//////////
	psq(176,0.5);
		colorit(11);
		cout<<"S";
		colorit(15);
		psq(176,0.5);
		cout<<setw(14)<<left<<" \"Sheild\"";
		cout<<": Protect your from being targrt ";
	y +=2;
	///
	gotoxy(x,y);
	psq(240,0.5);
		colorit(11);
		cout<<"I";
		colorit(15);
		psq(240,0.5);
		cout<<setw(14)<<left<<" \"Ice\"";
		cout<<": Frost target(target loss ability to walk and use items.) ";
		y +=2;
	/////
	gotoxy(x,y);
	colorit(11);
		cout<<"<";
		colorit(15);
		cout<<"W";
		colorit(11);
		cout<<">";
		colorit(15);
		cout<<setw(14)<<left<<" \"Wrapscroll\"";
		cout<<": Swap position of you and targrt. ";
	y +=2;
	///
	gotoxy(x,y);
		psq(252,0.5,'X');
		colorit(12);
		psq(124,0.5,'I');
		colorit(15);
		psq(252,0.5,'X');
		cout<<setw(14)<<left<<" \"Lock\"";
		cout<<": Target loss ability to use items. ";
	y +=2;
	///
	gotoxy(x,y);
	psq(252,0.5,'X');
		colorit(12);
		psq(124,0.5,'W');
		colorit(15);
		psq(252,0.5,'X');
		cout<<setw(14)<<left<<" \"Imprison\"";
		cout<<": Target loss ability to walk.";
	y +=2;
	///
	gotoxy(x,y);
	colorit(14);
		cout<<">>>";
		colorit(15);
		cout<<setw(14)<<left<<" \"Double\"";
		cout<<": You gain ability to step more .(the more step equal number that you dice.) ";
	y +=2;
	///
	gotoxy(x,y);
	psq(64,0.5);
		psq(4,0.5,'S');
		psq(64,0.5);
		cout<<setw(14)<<left<<" \"Slow\"";
		cout<<": Target step half of number that they dice. ";
	y +=2;
	///
	gotoxy(x,y);
	colorit(12);
		cout<<"[";
		colorit(2);
		cout<<"T";
		colorit(12);
		cout<<"]";	
		colorit(15);
		cout<<setw(14)<<left<<" \"Trap\"";
		cout<<": Set Trap on the normal pad.(First player that stop on this pad will fall down one floor.) ";
	y +=2;
	///
		gotoxy(x,y);
		psq(160,0.5);
		colorit(10);
		cout<<"L";
		colorit(15);
		psq(160,0.5);
		cout<<setw(14)<<left<<" \"Lucky\"";
		cout<<": You gain ability step equal the number that your bar stop on it. ";
	y +=2;
	///
		gotoxy(x,y);
		colorit(12);
		cout<<"<<<";
		colorit(15);
		cout<<setw(14)<<left<<" \"Reverse\"";
		cout<<": Target gain curse to step back equal number that they dice ";
	y +=2;
	gotoxy(x,y);
	cout<<"*You can collect most 4 items.";
	///
	y +=5;
	gotoxy(100,y);
	cout<<" Press \"ESC\" to back to main menu";
	while(getch() !=27)
	{
		
	}
	PlaySound(TEXT("sound/menu.wav"),NULL,SND_SYNC);
}

