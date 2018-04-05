#include<iostream>
#include<windows.h>
#include<vector>
#include<string>
#include<cstring>
#include "func.h"
using namespace std;

class pad;
class item;
class player;
class map;
class position{
	public:
	int x,y;
	position(int,int);
};
position::position(int px=0,int py=0){
	x=px;
	y=py;
}

struct linkpad{
	int Head,Tail;
};
class item{
	int id;
	string name;
	int rate;
	public:
	//string name;
	item(int,string);
	void use(string,player *,pad *);
	void drawitem(position);
	void upitem();	
	int randitem();
};
item::item(int i,string n){
	id =i;
	name = n;
	if(name =="Sheild") rate=5;
	else if(name =="Ice") rate=5;
	else if(name =="Warpscroll") rate=5;
	
}
/////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------------------ITEM-------------------------------------------------------------------------------------------//
string itemNameList[]={"Sheild","Ice","Warpscroll"};
vector<item> itemlist;
void creitem(){
	for(int i=0;i< sizeof(itemNameList)/sizeof(itemNameList[0]) ;i++)
	{
	itemlist.push_back(item(i,itemNameList[i]));
	//cout<< &itemlist[i]<<endl;
	}
	
}
///////////////////////////////////////////////////////////////////////
position posItemPad(position p){
	return position(p.x+8,p.y-3);
}
///////////////////////////////////////////////////////////////////////
void item::drawitem(position p){

	gotoxy(p.x,p.y);
	if(name =="Sheild" ){

		psq(176,0.5);
		colorit(11);
		cout<<"S";
		colorit(15);
		psq(176,0.5);
	}
	else if(name =="Ice")
	{

		psq(240,0.5);
		colorit(11);
		cout<<"I";
		colorit(15);
		psq(240,0.5);
	}
	else if(name =="Warpscroll"){
		colorit(11);
		cout<<"<";
		colorit(15);
		cout<<"W";
		colorit(11);
		cout<<">";
		colorit(15);
	}
	//gotoxy(0,0);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/////////////////////////////////////////////////////////////////
class pad{
	//int num;
	int color;
	int gotopad;
	position pos;
	public:
	int num;
	char type;
	item *onpadItem;
	vector<player *> onpadPlay;
	pad(int,int,char,int,int,int);
	void spawnitem(int);
	void drawpad(int);
	position ppos;
	void uppad(int,int);
	void removeItem();

};
/////////////////////////////////////////////////////////////////
pad::pad(int n,int l,char t,int x,int y,int go){
	num =n;
	color =l;
	type= t;
	pos.x = x;
	pos.y =y;
	gotopad =go;
	ppos.x=pos.x;
	ppos.y=pos.y;
	onpadItem =0;
	/*for(int i=0;i<4;i++)
	{
		onpadPlay[i]=0;
	}*/
}
/////////////////////////////////////////////////////////////////
class player{
	string name;
	int color;
	int num;
	position statpos;
	int maxpad;
	public:////////////
	position mypos;
	int no;
	int myturn;
	pad *myPad;
	vector<item *> myitem;
	//position pos;
	player(int,string,int,pad *,int);
	void drawme();
	void drawstat();
	void gotopad(int);
	
	
};
//////////////////////////////////////////////////
player::player(int n,string na,int c,pad *p,int mp){
	name =na;
	num=n;
	no=1;
	myPad = p;
	myturn=0;
	color=c;
	mypos.x=myPad->ppos.x+2+((num-1)*4);
	mypos.y=myPad->ppos.y-2;
	statpos.y = myPad->ppos.y+3;
	statpos.x = myPad->ppos.x+(30*(num-1));
	maxpad=mp;

}
/////////////////////////////////////////////////////////////////
void player::drawme(){
	gotoxy(mypos.x,mypos.y);
	psq(color,1);
	gotoxy(mypos.x,mypos.y-1);
	psq(240,1);
	gotoxy(mypos.x,mypos.y-2);
	cout<<"P"<<num;
	//gotoxy(0,0);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void player::drawstat(){
	gotoxy(statpos.x,statpos.y);
	psq(240,1);
	cout <<" "<<"P"<<num<<": "<<name;
	gotoxy(statpos.x,statpos.y+1);
	psq(color,1);
	cout<<" ";
	if(no == 1)cout<<"1st";
	else if(no == 2)cout<<"2nd";
	else if(no == 3)cout<<"3rd";
	else if(no == 4)cout<<"4th";
	cout<<"(pad: "<<myPad->num<<")";
	
	///draw myitem
	gotoxy(statpos.x+2,statpos.y+3);
	cout<<"<ITEM>";
	if(myitem.size() ==0){
		gotoxy(statpos.x+1,statpos.y+4);
		cout<< "Empty";
	}
	for(int i=0;i < myitem.size();i++)
	{
		gotoxy(statpos.x,statpos.y+4+i);
		cout <<i<<":";
		myitem[i]->drawitem(position(statpos.x+5,statpos.y+3+i));
	}
	//gotoxy(0,0);
	
	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void player::gotopad(int n){
	pad * temppad = myPad;
	if(myPad->num+n<= maxpad)myPad = myPad+n;
	position des(myPad->ppos.x+2+((num-1)*4),myPad->ppos.y-2);
	
	
	while(temppad != myPad)
	{
		pad *redrawpad = temppad;
		//position p =posItemPad(redrawpad->ppos);
		/*	//delete old
			gotoxy(mypos.x,mypos.y);
			psq(0,1);
			gotoxy(mypos.x,mypos.y-1);
			psq(0,1);
			gotoxy(mypos.x,mypos.y-2);
			psq(0,1);
			//delete old*/
			//if(temppad->onpadItem != 0)temppad->onpadItem->drawitem(p);//redraw item(for blocking item fade)
		temppad++;
		position tdes(temppad->ppos.x+2+((num-1)*4),temppad->ppos.y-2) ;
		while(mypos.x != tdes.x || mypos.y != tdes.y)
		{
			//delete old
			gotoxy(mypos.x,mypos.y);
			psq(0,1);
			gotoxy(mypos.x,mypos.y-1);
			psq(0,1);
			gotoxy(mypos.x,mypos.y-2);
			psq(0,1);
			//delete old
			if(redrawpad->onpadItem != 0)redrawpad->onpadItem->drawitem(posItemPad(redrawpad->ppos));//redraw item(for blocking item fade)
			if(temppad->onpadItem != 0)temppad->onpadItem->drawitem(posItemPad(temppad->ppos));
			if(tdes.y == mypos.y){
				if(tdes.x > mypos.x )
				{
					mypos.x +=1;
				}
				else if(tdes.x < mypos.x)
				{
					mypos.x -=1;
				}
			}
			else if(tdes.y != mypos.y)
			{
					mypos.y = tdes.y;
			}
			
			drawme();
			Sleep(25);
		}
	}
	/*mypos.x=myPad->ppos.x+2+((num-1)*4);
	mypos.y=myPad->ppos.y-2;*/
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
class map{
	int link;
	//int maxpad ;
	int coutrp;
	int PPL;//pad per level
	public:
	int maxpad ;
	vector<pad> pads;
	vector<player>  myplayer;
	int frame;
	void drawmap();
	void createmap();
	map(int,int,int,int);
	void update();
	void spawnitem();
	void checkno();
};

/////////////////////////////////////////////////////////////////
/*int pad::posX(){
	return pos.x;
}
int pad::posY(){
	return pos.y;
}*/
/////////////////////////////////////////////////////////////////
void drawstar(position p, int f=0)
{
	if(f%2==0)
	{
		gotoxy(p.x+4,p.y-6);
		psq(239,1);
		gotoxy(p.x+8,p.y-6);
		psq(0,1);
		gotoxy(p.x+12,p.y-6);
		psq(239,1);
		gotoxy(p.x+6,p.y-5);
		psq(239,1);
		psq(240,1);
		psq(239,1);
		gotoxy(p.x+4,p.y-4);
		psq(0,1);
		psq(240,1);
		psq(239,1);
		psq(240,1);
		psq(0,1);
		gotoxy(p.x+6,p.y-3);
		psq(239,1);
		psq(240,1);
		psq(239,1);
		gotoxy(p.x+4,p.y-2);
		psq(239,1);
		gotoxy(p.x+8,p.y-2);
		psq(0,1);
		gotoxy(p.x+12,p.y-2);
		psq(239,1);
	}
	else
	{
		gotoxy(p.x+4,p.y-6);
		psq(0,1);
		gotoxy(p.x+8,p.y-6);
		psq(239,1);
		gotoxy(p.x+12,p.y-6);
		psq(0,1);
		gotoxy(p.x+6,p.y-5);
		psq(240,1);
		psq(239,1);
		psq(240,1);
		gotoxy(p.x+4,p.y-4);
		psq(239,2);
		psq(240,1);
		psq(239,2);

		gotoxy(p.x+6,p.y-3);
		psq(240,1);
		psq(239,1);
		psq(240,1);
		gotoxy(p.x+4,p.y-2);
		psq(0,1);
		gotoxy(p.x+8,p.y-2);
		psq(239,1);
		gotoxy(p.x+12,p.y-2);
		psq(0,1);
		
	}
}
/////////////////////////////////////////////////////////////////
void pad::drawpad(int last=0){
	int pcl=color;
	if(num ==1 ||last !=0)pcl=236;
	gotoxy(pos.x,pos.y);
	psq(pcl,9);
	//Sleep(100);
	gotoxy(pos.x,pos.y-1);
	psq(0,0.5);
	psq(pcl,3.5);
	//Sleep(100);
	colorit(pcl);
	if(num<10) cout<<"0";
	cout<<num;
	//Sleep(100);
	colorit(15);
	if(num>=100)psq(pcl,3);
	else psq(pcl,3.5);
	//Sleep(100);
	if(num== 1)
	{
		gotoxy(pos.x+6,pos.y);
		colorit(pcl);
		cout<<"START";
		colorit(15);
	}
	if(type == 'L')
	{	
		gotoxy(pos.x+7,pos.y);
		if(gotopad < num) colorit(207);
		else colorit(97);
		
		if(gotopad < num) 
		{
			if(gotopad<10)cout <<"0";
			cout<<gotopad<<"<-";
		}
		else {
			cout<<"->";
			if(gotopad<10)cout <<"0";
			cout<<gotopad;
		}
		colorit(15);
	}
	if(type =='R'){
		gotoxy(pos.x+6,pos.y);
		colorit(112);
		cout<<"RANDOM";
		colorit(15);
		
	}
	if(num==last){
		drawstar(pos,0);
		
		gotoxy(pos.x+6,pos.y);
		colorit(pcl);
		cout<<"FINISH";
		colorit(15);
		
	}
}
///////////////////////////////////////////////////////////////////////////////////
map::map(int mp,int pl,int l,int crp){
	 link=l;
	 maxpad =mp;
	 coutrp=crp;
	 PPL=pl;

	int prand[coutrp];
	linkpad snake[link],ladder[link];
	vector<int> numpad;
		for(int i=1;i<=maxpad;i++ )
	{
		numpad.push_back(i);

	}
	
	for(int i=0;i<link;i++ )
	{
		//cout<<i<<endl;
		int loc;
		loc=(rand()%(numpad.size()-3))+2;
		snake[i].Head=numpad[loc];
		numpad.erase(numpad.begin()+loc);
		loc=(rand()%(loc-1))+1;
		snake[i].Tail=numpad[loc];
		numpad.erase(numpad.begin()+loc);
		
		loc=(rand()%(numpad.size()-3))+1;
		ladder[i].Head=numpad[loc];
		numpad.erase(numpad.begin()+loc);
		loc=((rand()%(numpad.size()-1-loc))+loc);
		ladder[i].Tail=numpad[loc];
		//cout<<ladder[i].Tail<<"/"<<numpad[ladder[i].Tail-1];
		numpad.erase(numpad.begin()+loc);
		//cout<<"snake:"<<snake[i].Head<<"->"<<snake[i].Tail<<endl;
		//cout<<"ladder:"<<ladder[i].Head<<"->"<<ladder[i].Tail<<endl;
	
	}
	
	for(int i=0;i<coutrp;i++ )
	{
		int loc=rand()%(numpad.size()-2)+1;
		prand[i]=numpad[loc];
		numpad.erase(numpad.begin()+loc);
	}
	
	int pX=0,pY=0;
	for(int i=0;i<maxpad;i++ )
	{
		
		int pcolor;
		char ptype='N';
		int level= ((i-(i%PPL))/PPL);
		pcolor = i%2==0? 159:47;
		
		if(level%2==0) pX = 18*(i%PPL);
		else pX=18*((PPL-1)-(i%PPL));
		pX +=(int)((230-(18*PPL))/2);
		
		pY = (7*((maxpad-(maxpad%PPL))/PPL+1))-(7*level);//set position of map
		int go=0;
		
		for(int j=0;j<link ;j++)
		{
			if(i+1 ==ladder[j].Head) 
			{
				go = ladder[j].Tail;
				ptype = 'L';
				break;
			}
			else if(i+1 == snake[j].Head)
			{
				go =snake[j].Tail;
				ptype='L';
				break;
			}
		}
		
		for(int j=0;j< coutrp;j++ )
		{
			if(i+1 ==prand[j]) 
			{
				ptype= 'R';
				break;
			}
		}
		
		pads.push_back(pad(i+1,pcolor,ptype,pX,pY,go));
		
	}
	creitem();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void map::drawmap(){
	for(int i =0;i<pads.size()-1;i++)
	{	int c=127;
		int level= ((i-(i%PPL))/PPL);
		pads[i].drawpad();
		if((i+1)%PPL==0 )//draw side lader
		{
			int x;
			if(level%2 ==0)x=17;
			else x=0;
				for(int j=0;j<7;j++)
				{
					gotoxy(pads[i].ppos.x+x,pads[i].ppos.y-1-j);
					psq(c,0.5);
				}
				for(int j=0;j<6;j+=2)
				{
					gotoxy(pads[i].ppos.x+(x-1),pads[i].ppos.y-2-j);
					psq(c,0.5);

				}
				for(int j=0;j<6;j+=2)
				{
					gotoxy(pads[i].ppos.x+(x+1),pads[i].ppos.y-2-j);
					psq(c,0.5);

				}

		}
		if(i+2 == maxpad)pads[i+1].drawpad(maxpad);
	}
	for(int i =0;i<myplayer.size();i++)
	{
		myplayer[i].drawme();
		myplayer[i].drawstat();
	}
	frame=0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
void map::update(){
		//pad's animation
		int rate=300;//frame rate
		for(int i =0;i<maxpad;i++)
		{
			pads[i].uppad(frame,maxpad);
		}
		//spawn item

		//delay
		Sleep(rate);
		frame++;
		frame = frame%8;
		gotoxy(0,0);

}
/////////////////////////////////////////////////////////////////////////
int item::randitem(){
	
}
/////////////////////////////////////////////////////////////////////////////////
void map::spawnitem(){
	//cout<<"spawnitem\n";
	vector<int> numpad;//get pad that empty(ready for push item in)
		for(int i = 1;i<maxpad-1;i++ )
		{
			if(pads[i].onpadItem == 0)
			{
			numpad.push_back(i);
			}
			
		}
		for(int i=0;i< (maxpad/10);i++)
		{
			int loc = rand()%numpad.size();
			int id = rand()%itemlist.size();
			// = randitem();
			pads[numpad[loc]].spawnitem(id);
			numpad.erase(numpad.begin()+loc);
		}
}
//////////////////////////////////////////////////////////////////////////
void pad::uppad(int f,int last =0){
	
	if(num == last)
	{
		drawstar(pos,f);
	}
	/*if(onpadItem != 0)
	{
		//cout<<num<<"\n";
		onpadItem->drawitem(posItemPad(pos));
	}*/
}

//////////////////////////////////////////////////////////////////////////
void pad::spawnitem(int id){
	//cout<<"pawnitem\n";
	onpadItem = &itemlist[id];
	int r=200;
	position p=posItemPad(pos);//bilnk action
	gotoxy(p.x,p.y);
	psq(240,1.5);
	Sleep(r);
	gotoxy(p.x,p.y);
	psq(0,1.5);
	gotoxy(p.x,p.y);
	Sleep(r);
	gotoxy(p.x,p.y);
	psq(240,1.5);
	Sleep(r);
	gotoxy(p.x,p.y);
	onpadItem->drawitem(p);
	//cout<<"pawnitem\n";
}
//////////////////////////////////////////////////////////////////////////


int rolldice(map & m){
	
	position p= m.pads[0].ppos;
	p.y= p.y+10;
	
	int dice= (rand()%6)+1;
	gotoxy(p.x,p.y);
	cout<< dice;
	return dice;
	
}
