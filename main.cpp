#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include "game.h"
#include <algorithm> 
#include "winscreen.h"
#include "menu.h"
using namespace std;

player* play(map &mymap){

	setcursor(0,0);	
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
	    mymap.padgetPlay();
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
	    	guide(1,mymap.pads[0].pos.y+4);
	    	if(!mymap.myplayer[play].bot)key=getch();
	    	else
	    	{
	    		Sleep(800);
	    		int botact =rand()%act;
	    		if(botact ==0)
	    		{
	    			key = 32;
				}
				else if(botact ==1)
				{
						int randu = rand()%(mymap.myplayer[play].myitem.size());
						switch(randu)
						{
							case 0: 
							key ='1';
							break;
							case 1: 
							key ='2';
							break;
							case 2: 
							key ='3';
							break;
							case 3: 
							key ='4';
							break;
							default:
							key =32;
							break;
						}
					
				}
			}
	    	
		    if(key ==32 && mymap.myplayer[play].walk)/////sapce bar rolldice
		    { 	
		    	guide(2,mymap.pads[0].pos.y+4);
				mymap.myplayer[play].gotopad(mymap.myplayer[play].rolldice(mymap));
				if(mymap.myplayer[play].myPad->num == mymap.maxpad)
				{	
					PlaySound(TEXT("sound/win1.wav"),NULL,SND_SYNC);
					return &mymap.myplayer[play];
				}
		    	
		    	mymap.padgetPlay();
		    	key =0;
		    	act--;
		    	mymap.myplayer[play].walk=false;
		    	mymap.upPlayStat(turn);
		    	continue;
		    	
		    }
		    
		    if(!mymap.myplayer[play].walk && key == 32)break;

		    int u = atoi(&key);
		    if(mymap.myplayer[play].uitem &&mymap.myplayer[play].myitem.size() > 0 && u<=4 && u>0 )//useitem
		    {

		    	if(mymap.myplayer[play].myitem.size() >=u)
		    	{
		    		PlaySound(TEXT("sound/confirm.wav"),NULL,SND_SYNC);
		    		mymap.myplayer[play].useitem(u,mymap);
					act--;
					mymap.myplayer[play].uitem  = false;
					mymap.padgetPlay();
					mymap.upPlayStat(turn);
				}
				else
				{
					guide(6,mymap.pads[0].pos.y+4);
				}
				
			}
			else if(mymap.myplayer[play].myitem.size() == 0 && u<=4 && u>0 )
			{
				guide(6,mymap.pads[0].pos.y+4);
			}
			
			
		}
		mymap.myplayer[play].reset();
		turn++;
		//gotoxy(0,0);
		//cout << turn;
	   //mymap.update();
	}
}

void character(int num,map &mymap,int l,vector<string> face,vector<int> &color_f, vector<int> &color_b){
	//cin.ignore();
	int chosse=0;
	char comd;
	for(int y=0;y<1;y++){ for(int i=0;i<32;i++){ gotoxy(i+l,y);psq(128,0.5); } }
		for(int y=18;y<19;y++){ for(int i=0;i<32;i++){ gotoxy(i+l,y);psq(128,0.5); } }
		for(int y=0;y<19;y++){  gotoxy(l,y);psq(128,0.5); }
		for(int y=0;y<19;y++){  gotoxy(32+l,y);psq(128,0.5); }
		while(comd != 13)//Enter key = 13
		{
			//system("cls");
			colorit(11);
			gotoxy(3+l,2);	
			cout<<"Please select your character";
			gotoxy(5+l,12);
			gotoxy(80,40); colorit(15); cout << "PLEASE SELECT YOUR FACE";
			gotoxy(15+l,8);
			colorit(15);		
			chosse = (10 + chosse)%10; 
			psq(240,0.5,face[chosse][0]);
			psq(240,0.5,face[chosse][1]);
			comd = getch();	
			if(comd =='a')chosse--;
			else if(comd == 'd')chosse++;
			PlaySound(TEXT("sound/menu.wav"),NULL,SND_SYNC);
		}
		PlaySound(TEXT("sound/confirm.wav"),NULL,SND_SYNC);
		
		string p_f = face[chosse];
		comd = getch();chosse = 0;	
		while(comd != 13)//Enter key = 13
		{
			//system("cls");
			colorit(11);
			gotoxy(3+l,2);	
			cout<<"Please select your character";
			gotoxy(80,40); psq(1,15);
			gotoxy(80,40); colorit(15); cout << "PLEASE SELECT YOUR FACE COLOR";
			gotoxy(15+l,8);
			chosse = (color_f.size() + chosse)%color_f.size(); 
			psq(color_f[chosse],0.5,p_f[0]);
			psq(color_f[chosse],0.5,p_f[1]);
			comd = getch();	
			PlaySound(TEXT("sound/menu.wav"),NULL,SND_SYNC);
			if(comd =='a')chosse--;
			else if(comd == 'd')chosse++;
		}
		PlaySound(TEXT("sound/confirm.wav"),NULL,SND_SYNC);
		int c_f = color_f[chosse];
		gotoxy(80,40); psq(1,15);
		color_f.erase(color_f.begin()+chosse);
		comd = getch();
		chosse = 0;
		while(comd != 13)//Enter key = 13
		{
			gotoxy(80,40); psq(1,15);
			gotoxy(80,40); colorit(15); cout << "PLEASE SELECT YOUR BODY COLOR";
			gotoxy(15+l,9);
			chosse = (color_b.size() + chosse)%color_b.size();
			psq(color_b[chosse],0.5,p_f[0]);
			psq(color_b[chosse],0.5,p_f[1]);
			comd = getch();		
			PlaySound(TEXT("sound/menu.wav"),NULL,SND_SYNC);
			if(comd =='a')chosse--;
			else if(comd == 'd')chosse++;
		}
		PlaySound(TEXT("sound/confirm.wav"),NULL,SND_SYNC);
		int c_b = color_b[chosse];
		color_b.erase(color_b.begin()+chosse);
		string name;
		gotoxy(5+l,12);
		colorit(11);
		cout << "Please input your name: " ;
		gotoxy(13+l,13);
		
		getline(cin,name);
		gotoxy(5+l,12); psq(1,12);
		gotoxy(3+l,2); psq(1,14);
		gotoxy(14+l,2); cout<<"P"<<num;
		PlaySound(TEXT("sound/confirm.wav"),NULL,SND_SYNC);
		mymap.myplayer.push_back(player(num,name,c_f,c_b,&mymap.pads[0],mymap.maxpad,p_f));
}

void botton(int c,int x,int y,string text,int n){
	gotoxy(x,y);psq(c,5+(n/2));gotoxy(x,y+1);psq(c,5+(n/2));
	gotoxy(x,y+2);psq(c,2.5);colorit(c);cout << text; psq(c,2.5);
	gotoxy(x,y+3);psq(c,5+(n/2));gotoxy(x,y+4);psq(c,5+(n/2));
}

int crechar(map &mymap){

	setcursor(0,0);	
	string f[10] = {"><","##","^^","**","--","++","$$","!!","==","::"};
	int cf[23] = {27,15,42,46,59,63,79,89,95,106,116,160,180,188,192,207,208,220,225,236,240,245,252};
	int cb[16] = {0,17,34,51,68,85,102,119,136,153,170,187,204,221,238,255};
	vector<string> face; vector<int> color_f; vector<int> color_b;
	for(int i=0;i<10;i++){face.push_back(f[i]);}
	for(int i=0;i<23;i++){color_f.push_back(cf[i]);}
	for(int i=0;i<16;i++){color_b.push_back(cb[i]);}
	
	int chosse = 0;		
	char comd;
	int num = 0;
	int lenght = 0;
	colorit(15);gotoxy(72,32); cout<<"left<-A    D->right  Enter->Submit";
	for(int y=21;y<22;y++){ for(int i=0;i<200;i++){ gotoxy(i,y);psq(170,0.5); } }
	for(int y=34;y<35;y++){ for(int i=75;i<111;i++){ gotoxy(i,y);psq(221,0.5); } }
	for(int y=45;y<46;y++){ for(int i=75;i<111;i++){ gotoxy(i,y);psq(221,0.5); } }
	for(int y=34;y<46;y++){  gotoxy(75,y);psq(221,0.5); }
	for(int y=34;y<46;y++){  gotoxy(111,y);psq(221,0.5); }
	while(chosse != 3){
		while(comd != 13){	
			botton(96,20,23,"BACK TO MENU",12);
			botton(96,80,23,"ADD NEW PLAYER",14);
			botton(96,142,23,"ENTER GAME",10);
			switch(chosse){
				case 0:botton(199,20,23,"BACK TO MENU",12);break;					
				case 1:botton(199,80,23,"ADD NEW PLAYER",14);break;
				case 2:botton(199,142,23,"ENTER GAME",10);break;
				default:break;	
			}
			comd = getch();
			if(comd =='a')chosse--;
			else if(comd == 'd')chosse++;
			if(comd == 13) break;
			PlaySound(TEXT("sound/menu.wav"),NULL,SND_SYNC);
			chosse = (3+(chosse))%3;	
		}
		
		PlaySound(TEXT("sound/confirm.wav"),NULL,SND_SYNC);
		if(num>=2){ 
			if(chosse==2){ chosse=3; }
			if(num>=4){ if(chosse==1){ chosse = 4; } } 
		}
		if(chosse == 0){ 
			for(int i=0;i<num;i++){
				mymap.myplayer.pop_back();
			}
			system("cls"); 
			return 0;	
		}
		else if(chosse == 1){ num++; character(num,mymap,lenght,face,color_f,color_b); lenght+=50; }
		else if(chosse == 2){ gotoxy(80,40); colorit(15); cout << "PLEASE ADD NEW MORE PLAYER";	}
		else if(chosse == 3){ system("cls"); return 1; }
		else if(chosse == 4){ gotoxy(80,40); colorit(15); cout << "CAN'T ADD NEW MORE PLAYER"; }
		//gotoxy(0,0);cout << chosse <<" "<<num;
		comd = getch(); gotoxy(80,40); psq(1,15);
	}
}

int showmeneu(){
	setcursor(0,0);	
	int pX=60,pY=10;
	int chosse=0;
	char comd=0;
	gotoxy(pX+5,6+pY);
	cout<<"W";
	gotoxy(pX+5,7+pY);
	cout<<"^";
	gotoxy(pX-6,pY+8);
	psq(160,11);
	for(int i=0;i<13;i++)
	{
		gotoxy(pX-6,pY+8+i);
		psq(160,1);
		gotoxy(pX+16,pY+8+i);
		psq(160,1);
	}
	gotoxy(pX-6,pY+20);
	psq(160,11);
	gotoxy(pX+5,21+pY);
	cout<<"v";
	gotoxy(pX+5,22+pY);
	cout<<"S";
	gotoxy(pX-3,25+pY);
	cout<<"Press \"Enter\" to submit";
	while(comd != 13)
	{
		
		//system("cls");
		shownamegame(10,6);
		showkrop(10,4,125,12);
		
		colorit(15);
		gotoxy(pX+3,10+pY);	
		cout<<" START ";
		
		gotoxy(pX,14+pY);
		cout<<" HOW TO PLAY ";
		
		gotoxy(pX+3,18+pY);
		cout<<" EXIT ";
		
		switch(chosse)
		{
			case 0:
			gotoxy(pX+3,10+pY);
			psq(224,0.5);
			colorit(12);
			cout<<"START";
			psq(224,0.5);
			break;
			case 1:
			gotoxy(pX,14+pY);
			psq(224,0.5);
			colorit(12);
			cout<<"HOW TO PLAY";
			psq(224,0.5);
			break;
			case 2: 
			gotoxy(pX+3,18+pY);
			colorit(12);	
			psq(224,0.5);
			colorit(12);
			cout<<"EXIT";
			psq(224,0.5);
			break;
			default:
			break;
		}
		colorit(15);
		comd = getch();
		PlaySound(TEXT("sound/menu.wav"),NULL,SND_SYNC);
		if(comd =='w')chosse--;
		else if(comd == 's')chosse++;
		chosse = (3+(chosse))%3;
	}
	system("cls");
	return chosse;
	
}

map cremap(){
	int max,ppl,li,rd;
	//////////////////////////////
	int pX=60,pY=5;
	int chosse=0;
	char comd=0;
	gotoxy(pX-1,pY);
	cout<<"Choose map size";
	gotoxy(pX+5,6+pY);
	cout<<"W";
	gotoxy(pX+5,7+pY);
	cout<<"^";
	gotoxy(pX-6,pY+8);
	psq(160,11);
	for(int i=0;i<17;i++)
	{
		gotoxy(pX-6,pY+8+i);
		psq(160,1);
		gotoxy(pX+16,pY+8+i);
		psq(160,1);
	}
	gotoxy(pX-6,pY+24);
	psq(160,11);
	gotoxy(pX+5,25+pY);
	cout<<"v";
	gotoxy(pX+5,26+pY);
	cout<<"S";
	gotoxy(pX-3,29+pY);
	cout<<"Press \"Enter\" to submit";
	max =30;ppl=6;li=5;rd=6;
	while(comd != 13)
	{
	
		colorit(15);
		gotoxy(pX+3,10+pY);	
		cout<<" Small ";
		
		gotoxy(pX+1,14+pY);
		cout<<" Standard ";
		
		gotoxy(pX+3,18+pY);
		cout<<" Large ";
		
		gotoxy(pX,22+pY);
		cout<<" Costom Map ";
		
		switch(chosse)
		{
			case 0:
			gotoxy(pX+3,10+pY);
			psq(224,0.5);
			colorit(12);
			cout<<"Small";
			psq(224,0.5);
			max =30;ppl=6;li=5;rd=6;
			break;
			case 1:
			gotoxy(pX+1,14+pY);
			psq(224,0.5);
			colorit(12);
			cout<<"Standard";
			max =50;ppl=8;li=8;rd=8;
			psq(224,0.5);
			break;
			case 2: 
			gotoxy(pX+3,18+pY);
			colorit(12);	
			psq(224,0.5);
			colorit(12);
			cout<<"Large";
			max =100;ppl=10;li=10;rd=10;
			psq(224,0.5);
			break;
			case 3: 
			gotoxy(pX,22+pY);
			colorit(12);	
			psq(224,0.5);
			colorit(12);
			cout<<"Costom Map";
			psq(224,0.5);
			break;
			default:
			break;
		}
		colorit(15);
		comd = getch();
		PlaySound(TEXT("sound/menu.wav"),NULL,SND_SYNC);
		if(comd =='w')chosse--;
		else if(comd == 's')chosse++;
		chosse = (4+(chosse))%4;
	}
	
	if(chosse == 3)
	{
		
		system("cls");
		do{	
			int pX =40,pY=5;
			gotoxy(pX+5,pY);
			cout<<"Input you map data(number only)";
			pY=8;
			gotoxy(pX,pY);
			for(int i=0;i<12;i++)
			{
				gotoxy(pX,pY+i);
				psq(0,25);
			}
				if(max-2 < li*4 || max-2-(li*4) < rd || ppl > 12 || max<19)
			{
				gotoxy(pX+10,pY-2);
				colorit(12);
				
				cout<<"*You input wrong data.*";
				PlaySound(TEXT("sound/randpad.wav"),NULL,SND_SYNC);
				colorit(15);
			}
			gotoxy(pX,pY);
			cout<<"How many pads do you want?";
			gotoxy(pX,++pY);
			colorit(12);
			cout<<"> ";
			colorit(15);
			cin>>max;
			PlaySound(TEXT("sound/confirm.wav"),NULL,SND_SYNC);
			pY+=2;
			gotoxy(pX,pY);
			cout<<"How many pads do you want per one floor?";
			gotoxy(pX,++pY);
			colorit(12);
			cout<<"> ";
			colorit(15);
			cin>>ppl;
			PlaySound(TEXT("sound/confirm.wav"),NULL,SND_SYNC);
			pY+=2;
			gotoxy(pX,pY);
			cout<<"How many snake and ladder pads doyou want?";
			gotoxy(pX,++pY);
			cout<<"(number of snake pads = number of  ladder pads)";
			gotoxy(pX,++pY);
			colorit(12);
			cout<<"> ";
			colorit(15);
			cin>>li;
			PlaySound(TEXT("sound/confirm.wav"),NULL,SND_SYNC);
			pY+=2;
			gotoxy(pX,pY);
			cout<<"How many random pads doyou want? : ";
			gotoxy(pX,++pY);
			colorit(12);
			cout<<"> ";
			colorit(15);
			cin>>rd;
			PlaySound(TEXT("sound/confirm.wav"),NULL,SND_SYNC);
		}while(max-2 < li*4 || max-2-(li*4) < rd || ppl > 12 || max<19);
		cin.ignore();
		PlaySound(TEXT("sound/menu.wav"),NULL,SND_SYNC);
	}

	system("cls");
	SetWindow(250,(max/ppl)*7+30);
	return map(max,ppl,li,rd);
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
setcursor(0,0);	
	int pX=90,pY=20;
	gotoxy(pX+20,pY-10);
	cout<<"      Choose your card";
	gotoxy(pX+20,pY-9);
	cout<<"(Press \"Enter\" to confirm)";
	gotoxy(pX-10,pY+5);
	cout<<"A<-";
	gotoxy(pX+mymap.myplayer.size()*20+10,pY+5);
	cout<<"->D";
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
	vector<bool>cards;
	for(int i=0;i<4;i++)
	cards.push_back(false);
	vector<int>number;
	for(int i=0;i<mymap.myplayer.size();i++)number.push_back(i);
	random_shuffle ( number.begin(), number.end() );

	for(int i=0;i<mymap.myplayer.size();i++)
	{
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
			if(!mymap.myplayer[i].bot)key = getch();
			else
			{
				Sleep(100);
				int botact =rand()%3;
				switch(botact)
						{
							case 0: 
							key ='a';
							break;
							case 1: 
							key ='d';
							break;
							case 2: 
							key = 13;
							break;
						};
			}
			PlaySound(TEXT("sound/menu.wav"),NULL,SND_SYNC);
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
		PlaySound(TEXT("sound/confirm.wav"),NULL,SND_SYNC);
		mymap.myplayer[i].myturn = number[ch];
		cards[ch]= true;
		
	}
	
	for(int i=0;i<mymap.myplayer.size();i++)drawcard(number[i]+1,i);
	PlaySound(TEXT("sound/opencards.wav"),NULL,SND_SYNC);
	
	getch();
	PlaySound(TEXT("sound/confirm.wav"),NULL,SND_SYNC);
	system("cls");
} 
 
int main(){

	srand(time(0));
	setcursor(0,0);	
	colorit(15);
	int comd ;
	while(comd !=2)
	{
		SetWindow(141,40);
		comd =showmeneu();
		//cout<<comd;
		if(comd==0){
			int choose;
			player* winner;
				map mymap =cremap();
				choose = crechar(mymap);
				if(choose == 1){
					playerturn(mymap);
					mymap.drawmap();
					winner = play(mymap);
					winscreen(winner);
				}	
		}
		else if(comd == 1)
		{
			system("cls");
			htp();
			system("cls");
		}
	}
	return 0;
}
