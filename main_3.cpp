#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include "game.h"

using namespace std;

int play(map &mymap){
	int turn=0;
	//int spawnitem =0;
	bool spawnitem=false;
	char key;
	mymap.padgetPlay();
	/////////////////////////set player turn//////////////////////////////////
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
	/*	if(turn %4==0 && spawnitem !=2){
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
		}*/
		///////////////////////////////////////////////////////////////////////////
		
		/*if (_kbhit()==1)////////////animation
	    {
	        key=getch();
	    }*/
	    int act =2;
	    bool walk=true;
	    bool item=true;
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
	    while(act != 0)
	    {
	    	
	    	key=getch();
	    	
		    if(key ==32 && walk)/////sapce bar rolldice
		    { 	
		    	
				mymap.myplayer[play].gotopad(rolldice(mymap));
				if(mymap.myplayer[play].myPad->num == mymap.maxpad)
				{	
					return play;
					Sleep(300);
					break;
				}
		    	
		    	mymap.padgetPlay();
		    	key =0;
		    	act--;
		    	walk=false;
		    }
		    if(!walk && key == 32)break;

		    int u = atoi(&key);
		    if(item &&mymap.myplayer[play].myitem.size() > 0 && u<=4 && u>0)
		    {

		    	if(mymap.myplayer[play].myitem.size() >=u)
		    	{
		    		mymap.myplayer[play].useitem(u,mymap);
				}
				act--;
			}
		
		}
		
		turn++;
		gotoxy(0,0);
		cout << turn;
	   //mymap.update();
	}
}

void character(int num,map &mymap,int l,vector<string> face,vector<int> &color_f, vector<int> &color_b){
	
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
			gotoxy(80,40); colorit(15); cout << "PLEASE SELECT YOUR FACE";
			gotoxy(15+l,8);
			colorit(15);		
			chosse = (10 + chosse)%10; 
			psq(240,0.5,face[chosse][0]);
			psq(240,0.5,face[chosse][1]);
			comd = getch();	
			if(comd =='a')chosse--;
			else if(comd == 'd')chosse++;
		}
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
			if(comd =='a')chosse--;
			else if(comd == 'd')chosse++;
		}
		int c_f = color_f[chosse];
		color_f.erase(color_f.begin()+chosse);
		comd = getch();chosse = 0;
		while(comd != 13)//Enter key = 13
		{
			gotoxy(80,40); psq(1,15);
			gotoxy(80,40); colorit(15); cout << "PLEASE SELECT YOUR BODY COLOR";
			gotoxy(15+l,9);
			chosse = (color_b.size() + chosse)%color_b.size();
			psq(color_b[chosse],0.5,p_f[0]);
			psq(color_b[chosse],0.5,p_f[1]);
			comd = getch();	
			if(comd =='a')chosse--;
			else if(comd == 'd')chosse++;
		}
		int c_b = color_b[chosse];
		gotoxy(80,40); psq(1,15);
		color_b.erase(color_b.begin()+chosse);
		string name;
		gotoxy(5+l,12);
		colorit(11);
		cout << "Please input your name: " ;
		gotoxy(13+l,13); ;
		comd = getch(); 
		cin.ignore();
		getline(cin,name);
		comd = getch();
		gotoxy(5+l,12); psq(1,12);
		gotoxy(3+l,2); psq(1,14);
		mymap.myplayer.push_back(player(num,name,c_f,c_b,&mymap.pads[0],mymap.maxpad,p_f));

}

void botton(int c,int x,int y,string text,int n){
	gotoxy(x,y);psq(c,5+(n/2));gotoxy(x,y+1);psq(c,5+(n/2));
	gotoxy(x,y+2);psq(c,2.5);colorit(c);cout << text; psq(c,2.5);
	gotoxy(x,y+3);psq(c,5+(n/2));gotoxy(x,y+4);psq(c,5+(n/2));
}

int crechar(map &mymap){
	string f[10] = {"><","##","^^","**","--","++","$$","!!","==","::"};
	int cf[23] = {27,15,42,46,59,63,79,89,95,106,116,160,180,188,192,207,208,220,225,236,240,245,252};
	int cb[16] = {0,17,34,51,68,85,102,119,136,153,170,187,204,221,238,255};
	vector<string> face; vector<int> color_f; vector<int> color_b;
	for(int i=0;i<10;i++){face.push_back(f[i]);}
	for(int i=0;i<23;i++){color_f.push_back(cf[i]);}
	for(int i=0;i<16;i++){color_b.push_back(cb[i]);}
	
	int chosse = 0;		char comd;
	int num = 0;
	int lenght = 0;
	colorit(15);gotoxy(75,32); cout<<"left<-a    d->right  Enter->Submit";
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
				//case 3:botton(199,132,23,"ENTER GAME",10);break;
				default:break;	
			}
			comd = getch();
			if(comd =='a')chosse--;
			else if(comd == 'd')chosse++;
			chosse = (3+(chosse))%3;	
		}
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
		comd = getch(); gotoxy(80,40); psq(1,13);
	}
	
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
	cout<<"Winner is "<< w+1;
	getch();
}
int main(){
	srand(time(0));
	colorit(15);
	SetWindow(250,300);
	int comd ;
	map mymap(0,0,0,0);
	while(comd !=2)
	{
			
			comd =showmeneu();
			//cout<<comd;
			if(comd==0){
				int choose;int winner;
				mymap =cremap();
				choose = crechar(mymap);
				if(choose == 1){
					mymap.drawmap();
					winner = play(mymap);
					winscreen(winner);
				}	
			}
	
	}
	return 0;
}
