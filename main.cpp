#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include "game.h"
#include <algorithm> 
using namespace std;

int play(map &mymap){
	int turn=0;
	//int spawnitem =0;
	bool spawnitem=false;
	char key;
	mymap.padgetPlay();
	mymap.upPlayStat(turn);
	/////////////////////////////////////////////////////////////////////////////////
	while(key != 27)//ESC
	{
		///////////////////////triged spawn item////////////////////////////////////
		if(turn %4==0){
			spawnitem =true;
		}

		if(spawnitem)
	    {
	    	mymap.spawnitem();
	    	spawnitem =false;
		}

		///////////////////////////////////////////////////////////////////////////
		
		/*if (_kbhit()==1)////////////animation
	    {
	        key=getch();
	    }*/
	    int act =2;
	    int play;
	    //mymap.padgetPlay();
	    mymap.upPlayStat(turn);
	    	for(int i=0;i<mymap.myplayer.size();i++)
		    {
		    	if(mymap.myplayer[i].myturn == turn%mymap.myplayer.size())
		    	{
		    		play =i;
		    	}
		    }
		    	
		    if(mymap.myplayer[play].myitem.size() == 0)
	    	{
	    		act--;
			}
			else if(!mymap.myplayer[play].uitem)
			{
				act--;
			}
			
			if(!mymap.myplayer[play].walk)act--;
	
	    while(act != 0)
	    {
	    	
	    	key=getch();
	    	
		    if(key ==32 && mymap.myplayer[play].walk)/////sapce bar rolldice
		    { 	
		    	
				mymap.myplayer[play].gotopad(mymap.myplayer[play].rolldice(mymap));
				if(mymap.myplayer[play].myPad->num == mymap.maxpad)
				{	
					return play;
					Sleep(300);
					break;
				}
		    	
		    	mymap.padgetPlay();
		    	key =0;
		    	act--;
		    	mymap.myplayer[play].walk=false;
		    	continue;
		    	
		    }
		    
		    if(!mymap.myplayer[play].walk && key == 32)break;

		    int u = atoi(&key);
		    if(mymap.myplayer[play].uitem &&mymap.myplayer[play].myitem.size() > 0 && u<=4 && u>0 )//useitem
		    {

		    	if(mymap.myplayer[play].myitem.size() >=u)
		    	{
		    		mymap.myplayer[play].useitem(u,mymap);
				}
				act--;
				mymap.myplayer[play].uitem  = false;
				mymap.padgetPlay();
			}
			
		}
		mymap.myplayer[play].reset();
		turn++;
		//gotoxy(0,0);
		//cout << turn;
	   //mymap.update();
	}
}
void crechar(map &mymap){
	mymap.myplayer.push_back(player(1,"P1",192,&mymap.pads[0],mymap.maxpad));
	mymap.myplayer.push_back(player(2,"P2",16,&mymap.pads[0],mymap.maxpad));
	mymap.myplayer.push_back(player(3,"P3",208,&mymap.pads[0],mymap.maxpad));
	mymap.myplayer.push_back(player(4,"P4",160,&mymap.pads[0],mymap.maxpad));
}

int showmeneu(){
	int chosse=0;
	char comd;
	while(comd != 13)
	{
		system("cls");
		colorit(15);
		gotoxy(20,2);	
		cout<<"START";
		gotoxy(20,3);
		cout<<"HOW TO PLAY";
		gotoxy(20,4);
		cout<<"EXIT";
		gotoxy(20,6);
		cout<<"w->up    s->down  Enter->Submit";
		switch(chosse)
		{
			case 0:
			gotoxy(19,2);
			colorit(199);	
			cout<<">START";
			break;
			case 1:
			gotoxy(19,3);
			colorit(199);	
			cout<<">HOW TO PLAY";
			break;
			case 2: 
			gotoxy(19,4);
			colorit(199);	
			cout<<">EXIT";
			break;
			default:break;
		}
		colorit(15);
		gotoxy(0,0);
		comd = getch();
		PlaySound(TEXT("sound/menu.wav"),NULL,SND_SYNC);
		if(comd =='w')chosse--;
		else if(comd == 's')chosse++;
		//cout<<comd;
		chosse = (3+(chosse))%3;
	}
	system("cls");
	return chosse;
	
}

map cremap(){
	int max,ppl,li,rd;
	do{
	cout<<"input [maxpad] [pad per lv] [number of ladder] [number of randompad] \n";
	cin>>max;
	cin>>ppl;
	cin>>li;
	cin>>rd;
	}while(max-2 < li*4 || max-2-(li*4) < rd || ppl > 12 || max<19);
	system("cls");
	return map(max,ppl,li,rd);
}

void winscreen(int w){
	system("cls");
	colorit(15);
	gotoxy(20,2);
	cout<<"Winner is "<< w+1;
	getch();
}
void drawcard(int R,int a)
{
	int pX=90,pY=20;
	int b=5;
	switch (R)
	{
			case 1:
				for(int i=0;i<15;i++)
				{
					for(int j=0;j<11;j++)
					{
						gotoxy(i+a*20+b+pX,j+pY);
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
						gotoxy(i+a*20+b+pX,j+pY);
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
						gotoxy(i+a*20+b+pX,j+pY);
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
						gotoxy(i+a*20+b+pX,j+pY);
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
void playerturn(map &mymap){
/*	/////////////////////////set player turn//////////////////////////////////
	vector<int> order;
	for(int i=0;i<mymap.myplayer.size();i++)
	{
		order.push_back(i);
	}
	////////random player turn
	for(int i=0;i<mymap.myplayer.size();i++)
	{
		int loc = rand()%order.size();
		mymap.myplayer[i].myturn=order[loc];
		order.erase(order.begin()+loc);
	}
	//////////////////////////////////////////////////////////////////////////*/
	int pX=90,pY=20;
	for(int a=0; a<mymap.myplayer.size();a++)
	{
		for(int i=0;i<15;i++)
		{
			for(int j=0;j<11;j++)
			{
				
				if(i==8&&j==10)
				{
					gotoxy(i+(a*20)+5+pX,11+pY);
					cout<<a+1;
				}
				gotoxy(i+(a*20)+5+pX,j+pY);
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
	//bool havecard=true;
	vector<bool>cards;
	for(int i=0;i<4;i++)
	cards.push_back(false);
	//vector<player*> pcc;
	vector<int>number;
	for(int i=0;i<mymap.myplayer.size();i++)number.push_back(i);
	random_shuffle ( number.begin(), number.end() );
/*	gotoxy(0,0);
	for(int i=0;i<number.size();i++)
	{
		cout<< number[i]<<"  ";
	}	*/
	for(int i=0;i<mymap.myplayer.size();i++)
	{
		//player * p= &mymap.myplayer[i];
		int ch;
		char key =0;
		for(int j=0;j<mymap.myplayer.size();j++)
		{
			if(!cards[j])
			{
				ch=j;
				break;
			}
		}
	
		while(true)
		{
			
			mymap.myplayer[i].drawme(pX+10+(ch*20),pY-2);
			key = getch();
			/////delete old/////
			if(key == 13) break;
			gotoxy(pX+10+(ch*20),pY-2);
			cout<<"  ";
			gotoxy(pX+10+(ch*20),pY-3);
			cout<<"  ";
			gotoxy(pX+10+(ch*20),pY-4);
			cout<<"  ";
			/////////////
			if(key =='a')ch--;
			else if(key == 'd')ch++;
			ch =ch%mymap.myplayer.size();
			while(cards[ch])
			{
				ch++;
				ch =ch%mymap.myplayer.size();
			}
			//gotoxy(0,1);
			//cout<<ch;
		}
		mymap.myplayer[i].myturn = number[ch];
	/*	gotoxy(0,2);
		cout<<mymap.myplayer[i].myturn;*/
		cards[ch]= true;
		
	}
	for(int i=0;i<mymap.myplayer.size();i++)drawcard(number[i]+1,i);
	getch();
	system("cls");
} 
 
int main(){
	srand(time(0));
	colorit(15);
	SetWindow(250,200);
	int comd ;
	while(comd !=2)
	{
		comd =showmeneu();
		//cout<<comd;
		if(comd==0){
			int winner;
			map mymap =cremap();
			crechar(mymap);
			playerturn(mymap);
			mymap.drawmap();
			winner = play(mymap);
			winscreen(winner);

		}
	}
	return 0;
}
