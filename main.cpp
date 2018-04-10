#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include "game.h"

using namespace std;

int play(map &mymap){
	int turn=0;
	int spawnitem =0;
	char key;
	mymap.padgetPlay();
	/////////////////////////set player turn//////////////////////////////////
	vector<int> order;
	order.push_back(0);order.push_back(1);order.push_back(2);order.push_back(3);
	////////random player turn
	for(int i=0;i<mymap.myplayer.size();i++)
	{
		int loc = rand()%order.size();
		mymap.myplayer[i].myturn=order[loc];
		order.erase(order.begin()+loc);
	}
	mymap.upPlayStat(turn%mymap.myplayer.size());
	/////////////////////////////////////////////////////////////////////////////////
	while(key != 27)//ESC
	{
		///////////////////////triged spawn item////////////////////////////////////
		if(turn %4==0 && spawnitem !=2){
			spawnitem =1;
		}
		else if(spawnitem ==2 &&turn %4!=0)
		{
			spawnitem =0;
		}
		if(spawnitem ==1)
	    {
	    	mymap.spawnitem();
	    	spawnitem++;
		}
		///////////////////////////////////////////////////////////////////////////
		if (_kbhit()==1)////////////animation
	    {
	        key=getch();
	    }
	    if(key ==32)/////sapce bar rolldice and turn+
	    { 	
	    	for(int i=0;i<mymap.myplayer.size();i++)
	    	{
	    		if(mymap.myplayer[i].myturn == turn%mymap.myplayer.size())
	    		{
					mymap.myplayer[i].gotopad(rolldice(mymap));
					if(mymap.myplayer[i].myPad->num == mymap.maxpad)
					{	
						return i;
						Sleep(300);
					}
	    			break;
				}
	    		
	    	}
	    	mymap.padgetPlay();
	    	key =0;
	    	turn++;

	    	mymap.upPlayStat(turn);
		}
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
	cout<<"Winner is"<< w+1;
	getch();
}
int main(){
	srand(time(0));
	colorit(15);
	SetWindow(250,300);
	int comd ;
	while(comd !=2)
	{
		comd =showmeneu();
		//cout<<comd;
		if(comd==0){
			int winner;
			map mymap =cremap();
			crechar(mymap);
			mymap.drawmap();
			winner = play(mymap);
			winscreen(winner);

		}
	}
	return 0;
}
