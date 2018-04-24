#include<iostream>
#include<windows.h>
#include<vector>
#include<string>
#include<cstring>
#include<iomanip>
#include "func.h"
#include "mmsystem.h"
using namespace std;

class pad;
class item;
class player;
class map;

void  drawstar(position);

struct linkpad{
	int Head,Tail;
};
class item{
	int id;
	//string name;
	public:
	string name;
	char type;
	int rate;
	item(int,string);
	void useme(player *,player *,pad *);
	void drawitem(position);
	void upitem();	
	int randitem();
};

item::item(int i,string n){
	id =i;
	name = n;
	if(name =="Sheild") 
	{
		rate=5;
		type='S';
	}
	else if(name =="Ice") 
	{
		rate=3;
		type='T';
	}
	else if(name =="Warpscroll")
	{
		rate=3;
		type='T';
	} 
	else if(name =="Lock")
	{
		rate=6;
		type='T';
	} 
	else if(name =="Block")
	{
		rate=6;
		type='T';
	} 
	else if(name =="Double")
	{
		rate=4;
		type='S';
	} 
	else if(name =="Mug")
	{
		rate=6;
		type='T';
	} 
	else if(name =="Trap")
	{
		rate=5;
		type='P';
	} 
	else if(name =="Fortune")
	{
		rate=4;
		type='S';
	}
	else if(name =="Reverse")
	{
		rate=4;
		type='T';
	}
	
}
/////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------------------ITEM-------------------------------------------------------------------------------------------//
string itemNameList[]={"Sheild","Ice","Warpscroll","Lock","Block","Double","Mug","Trap","Fortune","Reverse"};
vector<item> itemlist;
void creitem(){
	for(int i=0;i< sizeof(itemNameList)/sizeof(itemNameList[0]) ;i++)
	{
	itemlist.push_back(item(i,itemNameList[i]));
	//cout<< &itemlist[i]<<endl;
	}
	
}
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
position posItemPad(position p){
	return position(p.x+8,p.y-3);
}
//////////////////////////////////////////////////////////////////////////
int randitem(){
	int sum=0,num=0;
	for(int i = 0;i<itemlist.size();i++){
		sum+=itemlist[i].rate;
		}
	num =rand()%sum;
	int stack = 0;
		for(int k=0;k<itemlist.size();k++)
		{		
			if(num< stack+itemlist[k].rate )
			{
				return k;
			}
			stack+=itemlist[k].rate;
		}
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
	else if(name =="Lock"){
	
		psq(252,0.5,'X');
		colorit(12);
		psq(124,0.5,'I');
		colorit(15);
		psq(252,0.5,'X');
	}
	else if(name =="Block"){
	
		psq(252,0.5,'X');
		colorit(12);
		psq(124,0.5,'W');
		colorit(15);
		psq(252,0.5,'X');
	}
	else if(name =="Double"){
		colorit(10);
		cout<<">>>";
		colorit(15);

	}
	else if(name =="Mug"){
	
		psq(64,0.5);
		psq(4,0.5,'M');
		psq(64,0.5);
	}
	else if(name =="Trap"){
		colorit(12);
		cout<<"[";
		colorit(2);
		cout<<"T";
		colorit(12);
		cout<<"]";	
		colorit(15);
	
	}
	else if(name =="Fortune"){
	
		psq(224,0.5);
		colorit(14);
		cout<<"F";
		colorit(15);
		psq(224,0.5);
	}
	else if(name =="Reverse"){
	
		colorit(12);
		cout<<"<<<";
		colorit(15);
	}

	
	//gotoxy(0,0);
}
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/////////////////////////////////////////////////////////////////
class pad{
	//int num;
	int color;
	public:
	position pos;
	int linktopad;
	int num;
	char type;
	item *onpadItem;
	vector<player *> onpadPlay;
	pad(int,int,char,int,int,int);
	void spawnitem(int);
	void drawpad(int);
	void uppad(int,int);
	void removeItem();
	//void reOnPlayer();w

};
/////////////////////////////////////////////////////////////////
pad::pad(int n,int l,char t,int x,int y,int go){
	num =n;
	color =l;
	type= t;
	pos.x = x;
	pos.y =y;
	linktopad =go;
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
	position statpos;
	int color_b;
	int color_f;
	string face;
	public:
	int maxpad;
	int num;
		//////status//////
	bool walk;
	bool walkdrt;
	bool uitem;
	int protect;
	bool randp;
	bool doub;
	bool fortune;
	bool slow;
	
	//////////////////
	position mypos;
	int no;
	pad *myPad;
	vector<item *> myitem;
	int myturn;
	//position pos;
	player(int n,string na,int cf,int cb,pad *p,int mp,string f);
	void drawme(int,int);
	void drawstat(int,int);
	void gotopad(int);
	void ladsnakto(pad *);
	void getitem(item *);
	void useitem(int,map &);
	player* chtarget(map &);
	int rolldice(map &);
	void reset();
};
//////////////////////////////////////////////////
player::player(int n,string na,int cf,int cb,pad *p,int mp,string f){
	name =na;
	num=n;
	no=1;
	myPad = p;
	myPad->onpadPlay.push_back(this);
	//myturn=0;
	color_b=cb;
	color_f=cf;
	face = f;
	mypos.x=myPad->pos.x+2+((num-1)*4);
	mypos.y=myPad->pos.y-2;
	statpos.y = myPad->pos.y+6;
	statpos.x = 20+(30*(num-1));
	maxpad=mp;
	//////////bufff debuff////
	walk= true;
	walkdrt= true;//true ++ / false --
	uitem= true;
	protect = 0;
	randp =true;
	doub = false;
	fortune= false;
	slow=false;

}
/////////////////////////////////////////////////////////////////
void player::getitem(item * t=0){
	if(myitem.size()<4)
	{
	
		if(t ==0)
		{
			if(myPad->onpadItem !=0){
				myitem.push_back(myPad->onpadItem);
				myPad->onpadItem =0;
				myPad->drawpad(0);
			}
		}
		else
		{
			myitem.push_back(t);
		}
	}
	drawstat(-1,-1);
}
/////////////////////////////////////////////////////////////////
void player::drawme(int x=0,int y=0){
	if(x==0 && y==0)
	{
	gotoxy(mypos.x,mypos.y);
	psq(color_b,1);
	gotoxy(mypos.x,mypos.y-1);
	psq(color_f,0.5,face[0]);
	psq(color_f,0.5,face[1]);
	gotoxy(mypos.x,mypos.y-2);
	if(protect>0)colorit(11);
	cout<<"P"<<num;
	colorit(15);
		if( !walk && !uitem)
		{
			gotoxy(mypos.x,mypos.y);
			psq(176,1);
			gotoxy(mypos.x,mypos.y-1);
			psq(176,1);	
		}
	}
	else
	{
		gotoxy(x,y);
		psq(color_b,1);
		gotoxy(x,y-1);
		psq(color_f,0.5,face[0]);
		psq(color_f,0.5,face[1]);
		gotoxy(x,y-2);
		cout<<"P"<<num;
		
		
	}
	//gotoxy(0,0);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void player::drawstat(int p=-1,int t=-1){
	gotoxy(statpos.x,statpos.y);
	cout <<"   "<<name;
	gotoxy(statpos.x,statpos.y+1);
	cout<<"   ";
	if(no == 1)cout<<"1st";
	else if(no == 2)cout<<"2nd";
	else if(no == 3)cout<<"3rd";
	else if(no == 4)cout<<"4th";
	cout<<"(pad: "<<myPad->num<<")";
	drawme(statpos.x,statpos.y+1);
	if(p !=-1 && t !=-1){
//	gotoxy(statpos.x-2,statpos.y-2);
	//cout<< myturn;
	
		gotoxy(statpos.x,statpos.y-2);
		colorit(12);
		cout<<"  >";
		colorit(15);
		if(t%p == myturn)
		{
			cout<<"Your turn";
			colorit(12);
			cout<<"<     ";
			colorit(15);
		}
		else if((t+1)%p == myturn) 
		{
			cout<<"Next";
			colorit(12);
			cout<<"<     ";
			colorit(15);
	
		}
		else 
		{
			gotoxy(statpos.x,statpos.y-2);
			cout<<"               ";	
		}
	}
	//draw stat buff de buff
	gotoxy(statpos.x,statpos.y+2);
	cout<<"                 ";
	gotoxy(statpos.x,statpos.y+2);
	if( !walk)
	{
		colorit (252);
		cout<<"W";
		colorit (15);
		cout<<" ";
	}
	if(!uitem)
	{
		colorit (252);
		cout<<"I";
		colorit (15);
		cout<<" ";
	}
	if( protect<0)
	{
		colorit (11);
		cout<<"P ";
	}
	if( fortune)
	{
		colorit (14);
		cout<<"F ";
	}
	if(slow)
	{
		colorit (4);
		cout<<"M ";
	}
	if(doub)
	{
		colorit (14);
		cout<<"x2 ";
	}
	colorit (15);
	///draw myitem
	gotoxy(statpos.x+2,statpos.y+3);
	cout<<"<ITEM>";
	for(int i=0;i < 4;i++)
	{
		gotoxy(statpos.x,statpos.y+4+i);
		cout<< "        ";
	}
	if(myitem.size() ==0){
		gotoxy(statpos.x+1,statpos.y+4);
		cout<< "[Empty]";
	}
	for(int i=0;i < myitem.size();i++)
	{
		gotoxy(statpos.x,statpos.y+4+i);
		cout <<i+1<<":";
		myitem[i]->drawitem(position(statpos.x+2,statpos.y+4+i));
	}
	//gotoxy(0,0);
	
	
}
///////////////////////////////////////////////////////////////////////////
void player::ladsnakto(pad *despad){
	/////check pad that ladder pat//////////
	vector<pad*>pastpad;
	pad* temppad= myPad;
	gotoxy(0,0);
	if(despad->pos.y > temppad->pos.y)//snake
	{
		while(temppad->pos.y <=despad->pos.y && temppad->num >0)
		{			
			if(temppad->pos.x==myPad->pos.x ) pastpad.push_back(temppad);
			temppad--;			
		}
	}
	else if(despad->pos.y < temppad->pos.y)//ladder
	{
		while(temppad->pos.y>=despad->pos.y && temppad->num <maxpad)
		{
			if(temppad->pos.x==myPad->pos.x )pastpad.push_back(temppad);
			temppad++;
			
		}
	}
	///////////draw lader/////////
	position tdes;
	if(pastpad.size() >0)tdes = position(pastpad.back()->pos.x+2+((num-1)*4),pastpad.back()->pos.y-2);
	else tdes = position(despad->pos.x+2+((num-1)*4),despad->pos.y-2);
	int k;
	if(pastpad.size()>0)k=pastpad.back()->pos.y-myPad->pos.y;
	else k=0;
	if(k<0) k =-k;		
	int pY =mypos.y,tempY=pY,pX=mypos.x-1;
	
	for(int i=0;i < k;i++)
	{
		/////lader/////
		if(despad->pos.y-myPad->pos.y<0)
		{
			gotoxy(pX,pY);
			if(i%2 == 0)
			{
				psq(240,0.5);
				psq(0,1);
				psq(240,0.5);
			}
			else psq(240,2);
			pY--;
		}
		/////lader/////
		/////snake////
		if( despad->pos.y-myPad->pos.y >0 ){
			pY++;
			gotoxy(pX,pY);
			if( i<k-5)
			{
				if(i%2 == 0)
				{
					psq(32,0.5);
					psq(160,1);
					psq(32,0.5);
				}
				else psq(32,2);
			}
			else
			{
				if(i == k-5){
					psq(240,0.5);
					psq(0,0.5);
					psq(32,1);
				}
				else if(i == k-4){
					psq(32,1);
					psq(192,0.5);
					psq(32,0.5);
				}

			}
			/////snake////
		}
		drawme();
		Sleep(50);

	}
	/////move////////////////////////////
	///y axis////
	int i=0;
	//if( despad->pos.y-myPad->pos.y >0)PlaySound(TEXT("snake.wav"),NULL,SND_SYNC);
	while(mypos.y != tdes.y)
	{
		///delete old//////
		/////lader/////
		if(despad->pos.y-myPad->pos.y<0)
		{
			gotoxy(mypos.x-1,mypos.y);
			if(i%2 == 0)
			{
				psq(240,0.5);
				psq(0,1);
				psq(240,0.5);
			}
			else psq(240,2);
		}
		/////lader/////
		/////snake////
		if( despad->pos.y-myPad->pos.y >02)
		{	gotoxy(mypos.x-1,mypos.y-2);
			if(i>2)
			{
				if( i<k-2)
				{
					if(i%2 == 0)
					{
						psq(32,0.5);
						psq(160,1);
						psq(32,0.5);
					}
					else psq(32,2);
				}
				else
				{
					if(i == k-2){
						psq(240,0.5);
						psq(0,0.5);
						psq(32,1);
					}
					else if(i == k-1){
						psq(32,1);
						psq(192,0.5);
						psq(32,0.5);
					}
	
				}
			}
			else
			{
				psq(0,2);
				
			}
		}
		/////snake////
			//delete old////
		if(mypos.y > tdes.y) mypos.y--;
		else mypos.y++;
		drawme();
		Sleep(50);
		i++;
		
	}


////x axis/////
	pad* renext;
	pad* renow;
	if(pastpad.size() >0)
	{
		renext= pastpad.back();
		renow= pastpad.back();
	}
	else{
		renext= myPad;
		renow= myPad;
	}
	
	if(renext->num > despad->num) renext--;
	else renext++;
	while(renow->num != despad->num)
	{	
		tdes=position(renext->pos.x+2+((num-1)*4),renext->pos.y-2);
		while(mypos.x != tdes.x)
		{
			//delete old
			gotoxy(mypos.x,mypos.y);
			psq(0,1);
			gotoxy(mypos.x,mypos.y-1);
			psq(0,1);
			gotoxy(mypos.x,mypos.y-2);
			psq(0,1);
			//delete old
				
			// re draw pad////////////
				if(renext->onpadItem != 0)renext->onpadItem->drawitem(posItemPad(renext->pos));//redraw item(for blocking item fade)
				if(renow->onpadItem != 0)renow->onpadItem->drawitem(posItemPad(renow->pos));
				if(renext->onpadPlay.size() >0){//re draw palyer
					for(int i =0;i<renext->onpadPlay.size();i++)
					{
						if(renext->onpadPlay[i]->num != num)
						{
							renext->onpadPlay[i]->drawme();
						}
					}
				}
				if(renow->onpadPlay.size() >0){//re draw palyer
					for(int i =0;i<renow->onpadPlay.size();i++)
					{
						if(renow->onpadPlay[i]->num != num)
						{
							renow->onpadPlay[i]->drawme();
						}
						
					}
				}
			// re draw pad////////////
			if(mypos.x > tdes.x) mypos.x--;
			else mypos.x++;
			if(mypos.y != tdes.y && mypos.x == tdes.x) 
			{
			mypos.y -=7;
			}
			drawme();
			Sleep(25);
		}
		
		if(renow->num > despad->num) {
		 	renext--;
			renow--;	
		}
		else {
			renext++;
			renow++;
		}
		
	}
	/////delete path//////
	pY=tempY;
	
		for(int i=0;i < k;i++)
	{
		/////lader/////
		if(despad->pos.y-myPad->pos.y<0)
		{
			gotoxy(pX,pY);
			psq(0,2);
			pY--;
		}
		/////lader/////
		/////snake////
		if( despad->pos.y-myPad->pos.y >0 ){
			if(i<k-3)
			{
			pY++;
			gotoxy(pX,pY);
			psq(0,2);
			}
			
		}
		Sleep(50);
	}
	/////redraw pad/////////
	for(int i=0; i< pastpad.size();i++)
	{
		pastpad[i]->drawpad(0);
		if(pastpad[i]->onpadItem != 0)
		{
			position p=posItemPad(pastpad[i]->pos);
			pastpad[i]->onpadItem->drawitem(p);
		}
		for(int j=0; j< pastpad[i]->onpadPlay.size();j++)
		{
			pastpad[i]->onpadPlay[j]->drawme();
		}
		Sleep(100);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void randomevent(position &,player*);
void player::gotopad(int n){
	bool walkdirec =true;//true = go upper +,flase = go back - 
	if(n<0) walkdirec =false;
	pad * temppad = myPad;
	if(n<0 && myPad->num+n <1) myPad = myPad+1-myPad->num;
	else
	{
		if(myPad->num+n <= maxpad) myPad = myPad+n;
		else{
			n= maxpad-(myPad->num+n);
			myPad =myPad+(maxpad-myPad->num);
		}
	}
	position des(myPad->pos.x+2+((num-1)*4),myPad->pos.y-2);
	
	/*if(temppad->num == maxpad && n<0)
	{
		walkdirec=false;
		myPad = myPad+n;
		des =position(myPad->pos.x+2+((num-1)*4),myPad->pos.y-2);
	}*/
	
	while(temppad != myPad)
	{

		pad *redrawpad = temppad;
		if(walkdirec)temppad++;
		else temppad--;
		
		position tdes(temppad->pos.x+2+((num-1)*4),temppad->pos.y-2) ;
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
			
			if(redrawpad->onpadItem != 0)redrawpad->onpadItem->drawitem(posItemPad(redrawpad->pos));//redraw item(for blocking item fade)
			if(temppad->onpadItem != 0)temppad->onpadItem->drawitem(posItemPad(temppad->pos));
			if(redrawpad->onpadPlay.size() >0){//re draw palyer
				for(int i =0;i<redrawpad->onpadPlay.size();i++)
				{
					if(redrawpad->onpadPlay[i]->num != num)
					{
						redrawpad->onpadPlay[i]->drawme();
					}
				}
			}
			if(temppad->onpadPlay.size() >0){//re draw palyer
				for(int i =0;i<temppad->onpadPlay.size();i++)
				{
					if(temppad->onpadPlay[i]->num != num)
					{
						temppad->onpadPlay[i]->drawme();
					}
					
				}
			}
			if(redrawpad->num == maxpad) drawstar(redrawpad->pos);
			if(temppad->num == maxpad) drawstar(temppad->pos);
			
			
			if(tdes.y == mypos.y){
				
				if(tdes.x > mypos.x )
				{
					mypos.x++;
				}
				else if(tdes.x < mypos.x)
				{
					mypos.x--;
				}
			}
			else if(tdes.y != mypos.y)
			{
					mypos.y = tdes.y;
			}
			
			drawme();
			if(temppad->num == maxpad && n<0 && walkdirec)
			{
				walkdirec=false;
				myPad = myPad+n;
				des =position(myPad->pos.x+2+((num-1)*4),myPad->pos.y-2);
			}
			//PlaySound(TEXT("walk.wav"),NULL,SND_SYNC);
			Sleep(25);
		}

	}
	if(myPad->linktopad !=0)
	{

		pad * temp= myPad+(myPad->linktopad-myPad->num);
		ladsnakto(temp);
		myPad=temp;
	}
	if(myPad->type =='T')
	{

		pad *temp = myPad;
			if(temp->num < maxpad)temp--;
			while(temp->pos.x != myPad->pos.x &&temp->num>1)
			{
				temp--;
			}
			if(temp->pos.y!= myPad->pos.y)ladsnakto(temp);
		myPad=temp;
		myPad->type ='N';
	}
	getitem(0);
	if(myPad->type =='R' && rand){
	position randpos(170,statpos.y+4);
	randomevent(randpos,this);
	}
	drawme();
	/*mypos.x=myPad->pos.x+2+((num-1)*4);
	mypos.y=myPad->pos.y-2;*/
}
//////////////////////////////////////////////////////////////////////////
void player::useitem(int i,map & m){
	if(	myitem.size() >=i)
	{
		player* p=this;
		if(myitem[i-1]->type == 'T') 
		{			
			p = chtarget(m);
		} 
		myitem[i-1]->useme(p,this,myPad);
		myitem.erase(myitem.begin()+i-1);
		drawstat();
	}
}

///////////////////////////////////////////////////////////////////////////
/*void pad::reOnPlayer(){
	while(onpadPlay.size()>0){
		onpadPlay.erase(onpadPlay.begin());
	}
}*/
///////////////////////////////////////////////////////////////////////
void player::reset(){
	if(randp)
	{
		walk= true;			//walkdrt= true;
		uitem = true;
	}
	if(protect >0)protect--;
	randp =true;
	
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
	//void createmap();
	map(int,int,int,int);
	void update();
	void spawnitem();
	void checkno();
	void padgetPlay();
	void upPlayStat(int);
};

/////////////////////////////////////////////////////////////////
/*int pad::posX(){
	return pos.x;
}
int pad::posY(){
	return pos.y;
}*/
/////////////////////////////////////////////////////////////////
void drawstar(position p)
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
/////////////////////////////////////////////////////////////////
void pad::drawpad(int last=0){
	int pcl=color;
	if(num ==1 ||last !=0)pcl=236;
	gotoxy(pos.x,pos.y);
	psq(pcl,9);
	//Sleep(100);
	gotoxy(pos.x+1,pos.y-1);

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
		if(linktopad < num) colorit(207);
		else colorit(97);
		
		if(linktopad < num) 
		{
			if(linktopad<10)cout <<"0";
			cout<<linktopad<<"<-";
		}
		else {
			cout<<"->";
			if(linktopad<10)cout <<"0";
			cout<<linktopad;
		}
		colorit(15);
	}
	if(type =='R'){
		gotoxy(pos.x+6,pos.y);
		colorit(112);
		cout<<"RANDOM";
		colorit(15);
		
	}
	if(onpadItem !=0)
	{
	onpadItem->drawitem(posItemPad(pos));
	}
	else
	{
		position tp = posItemPad(pos);
		gotoxy(tp.x,tp.y);
		cout<<"   ";
	}
		if(num==last){
		drawstar(pos);
		
		gotoxy(pos.x+6,pos.y);
		colorit(pcl);
		cout<<"FINISH";
		colorit(15);
		
	}

	//cout<< onpadPlay.size();
	/*for(int i =0;i<onpadPlay.size();i++)
	{
			onpadPlay[i]->drawme();			
	}*/
			
	
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
		pX +=(int)((250-(18*PPL))/2);//
		
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
	//padgetPlay();
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
			else x=-2;
				if(x==-2)
				{
					gotoxy(pads[i].pos.x+x,pads[i].pos.y);
					psq(c,0.5);
				}
				else
				{
						gotoxy(pads[i].pos.x+(x+2),pads[i].pos.y);
					psq(c,0.5);
				}
				for(int j=0;j<7;j++)
				{
					gotoxy(pads[i].pos.x+x,pads[i].pos.y-1-j);
					psq(c,0.5);
				}
				for(int j=0;j<8;j+=2)
				{
					gotoxy(pads[i].pos.x+(x+1),pads[i].pos.y-j);
					psq(c,0.5);

				}
				gotoxy(pads[i].pos.x+(x+1),pads[i].pos.y-7);
					psq(c,0.5);
				for(int j=0;j<7;j++)
				{
					gotoxy(pads[i].pos.x+(x+2),pads[i].pos.y-1-j);
					psq(c,0.5);

				}

		}
		if(i+2 == maxpad)pads[i+1].drawpad(maxpad);
	}
	for(int i =0;i<myplayer.size();i++)
	{
		myplayer[i].drawme();
		myplayer[i].drawstat(myplayer.size(),0);
	}
	gotoxy(0,pads[0].pos.y+1);//draw surface
	psq(160,125);
	gotoxy(0,pads[0].pos.y+2);
	psq(64,125);
/////////drawwall/////////
	for(int i=pads[0].pos.y;i>pads[maxpad-1].pos.y;i--)
	{
		gotoxy(pads[0].pos.x-4,i);
		if(i%2==0)psq(112,1);
		else psq(128,1);
	}

	for(int i=pads[0].pos.y;i>pads[maxpad-1].pos.y;i--)
	{
		gotoxy(pads[PPL-1].pos.x+20,i);
		if(i%2==0)psq(112,1);
		else psq(128,1);
	}
	/////////draw square/////////
	gotoxy(140,pads[0].pos.y+4);
	psq(224,36);
	for(int i=0;i<17;i++)
	{
		gotoxy(140,pads[0].pos.y+4+i);
		psq(224,1);
		gotoxy(140+72,pads[0].pos.y+4+i);
		psq(224,1);
	}
	gotoxy(140,pads[0].pos.y+20);
	psq(224,36);
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/*void map::update(){
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

}*/
/////////////////////////////////////////////////////////////////////////////////
void map::padgetPlay(){
	for(int i=0;i<pads.size();i++)
	{

		pads[i].onpadPlay.clear();
	}
	for(int i=0;i<myplayer.size();i++)
	{
		myplayer[i].myPad->onpadPlay.push_back(&myplayer[i]);
	}

	vector<player*> odp;
	for(int i=0;i<myplayer.size();i++)
	{
		odp.push_back(&myplayer[i]);
	}
	int count=1;
	int omax;
	//int max = 0;
	for(int i=0;i<myplayer.size();i++)
	{
		int loc =0;
		int max = odp[0]->myPad->num;
		
		for(int j=0;j<odp.size();j++)
		{
			if(odp[j]->myPad->num >max )
			{
				loc=j;
				max = odp[j]->myPad->num;
			
			}
		}	
		if(max==omax) count--;;
		odp[loc]->no = count;
		omax =max;
		odp.erase(odp.begin()+loc);
		count++;

	}
	
}
/////////////////////////////////////////////////////////////////////////////////
void map::upPlayStat(int t){
	for(int i=0;i<myplayer.size();i++)
	{
		myplayer[i].drawstat(myplayer.size(),t);
	}

}

void map::spawnitem(){
	//cout<<"spawnitem\n";
	vector<int> numpad;//get pad that empty(ready for push item in)
		for(int i = 1;i<maxpad-1;i++ )
		{
			if(pads[i].onpadItem == 0 && pads[i].onpadPlay.size()==0 && pads[i].type != 'L')
			{
			numpad.push_back(i);
			}
			
		}
		
		for(int i=0;i< (maxpad/10);i++)
		{
			if(numpad.size()>0)
			{	
				int loc = rand()%numpad.size();
				int id = randitem();
				//int id = rand()%itemlist.size();
				pads[numpad[loc]].spawnitem(id);
				numpad.erase(numpad.begin()+loc);
			}
		}
}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//void pad::uppad(int f,int last =0){
	
/*	if(num == last)
	{
		drawstar(pos);
	}
	/*if(onpadItem != 0)
	{
		//cout<<num<<"\n";
		onpadItem->drawitem(posItemPad(pos));
	}
}*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pad::spawnitem(int id){
	//cout<<"pawnitem\n";
	onpadItem = &itemlist[id];
	int r=200;
	position p=posItemPad(pos);//
	//bilnk action
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void drawDice(int d,position p)
{
	switch (d)
	{
			case 0:
					for(int i=0;i<10;i++)
						{
							for(int j=0;j<5;j++)
							{
								gotoxy(p.x+i,p.y+j);
									psq(0,0.5);			
							}
						}
						break;
			case 1:
				for(int i=0;i<10;i++)
					{
						for(int j=0;j<5;j++)
						{
							gotoxy(p.x+i,p.y+j);
							if(j==2&&(i==4||i==5))
								psq(192,0.5);
							else psq(123,0.5);			
						}
					}
					break;
			case 2:
				for(int i=0;i<10;i++)
					{
						for(int j=0;j<5;j++)
						{
							gotoxy(p.x+i,p.y+j);
							if(j==2&&(i%4==2||i%4==3))
								psq(192,0.5);
							else psq(123,0.5);			
						}
					}break;
			case 3:
				for(int i=0;i<10;i++)
					{
						for(int j=0;j<5;j++)
						{
							gotoxy(p.x+i,p.y+j);
							if(j>0&&j<4&&(i/2==j))
								psq(192,0.5);
							else psq(123,0.5);			
						}
					}
					break;
			case 4:
				for(int i=0;i<10;i++)
					{
						for(int j=0;j<5;j++)
						{
							gotoxy(p.x+i,p.y+j);
							if((j==1||j==3)&&(i%4==2||i%4==3))
								psq(192,0.5);
							else psq(123,0.5);			
						}
					}
					break;
			case 5:
				for(int i=0;i<10;i++)
					{
						for(int j=0;j<5;j++)
						{
							gotoxy(p.x+i,p.y+j);
							if(j>0&&j<4)
							{
								if((j%2==1)&&(i%6==1||i%6==2))
									psq(192,0.5);
								else if(j%2==0&&(i%6==4||i%6==5))
									psq(192,0.5);
								else psq(123,0.5);				
							}
							else psq(123,0.5);
						}
					}
					break;
			case 6:
				for(int i=0;i<10;i++)
					{
						for(int j=0;j<5;j++)
						{
							gotoxy(p.x+i,p.y+j);
							if((j==1||j==3)&&(i==1||i==2||i==4||i==5||i==7||i==8))
								psq(192,0.5);
							else psq(123,0.5);			
						}
					}
					break;
	}

} 
int player::rolldice(map & m){
	
	position p= m.pads[0].pos;
	p.x=150;
	p.y= p.y+7;
	int dice;
	int c=getch();
			////god mode////
	switch (c)
	{
		case 32:
			//dice= (rand()%6)+1;
			break;
		case 113:
			return 1;
			break;
		case 119:
			return 2;
			break;
		case 101:
			return 3;
			break;
		case 114:
			return 4;
			break;
		case 116:
			return 5;
			break;
		case 121:
			return 6;
			break;
	}
		////god mode////
	 c='0';
	vector<int> dicelist;
	int R=0;
	for(int i=1; i<7 ; i++)
	{
		dicelist.push_back(i);	
	}	
	for(int i=1;i<7;i++)
	{
		gotoxy(6*i+p.x+2,p.y);//number
	   	cout <<i;
	   	gotoxy(6*i+p.x,p.y+1);//cloar bar
		if(i%2==0) psq (32,3);
		else psq (203,3);	
	}
	
	PlaySound(TEXT("sound/dice.wav"),NULL,SND_SYNC);
		while(c !=32)
	{
		gotoxy(6+(R%35)+p.x,p.y+1);
		psq(224,0.5);	        
	    Sleep(20);
		if (_kbhit()==1)
	    {	
			c=getch();
			if(c==32)break;
	    }
	    gotoxy(6+(R%35)+p.x,p.y+1);
		if((1+(R%35)/6)%2==0) psq (32,0.5);
		else psq (203,0.5);
	    R++;
	    
	}
		gotoxy(6+(R%35)+p.x,p.y+1);
	    psq(245,0.5);
	    for(int i=0;i<5;i++)//increaces rate
	    {
			dicelist.push_back((R%35)/6+1);
		}
		
	//gotoxy(p.x,p.y+3);
	dice = dicelist[rand()%dicelist.size()];
	if(fortune)////////////////////////buff
	{
		dice =(R%35)/6+1;
		fortune=false;
	}
	 
	 
	PlaySound(TEXT("sound/dice.wav"),NULL,SND_SYNC);
	for(int i=20;i<=300;i+=20)
	{
		drawDice(((i-20)/20)%6+1,position(p.x+20,p.y+5));
		Sleep(i);
			
		if(i==300)
		{
			
			int j=0;
			while(((i+j-20)/20)%6+1 !=dice){
				j+=20;
				drawDice(((i+j-20)/20)%6+1,position(p.x+20,p.y+5));
				if(((i+j-20)/20)%6+1 == dice)PlaySound(TEXT("sound/dice.wav"),NULL,SND_SYNC);
				Sleep(i+j);
			}
		}
	}
	
	Sleep(800);
	drawDice(0,position(p.x+20,p.y+5));
	////////////////////////buff
	if(doub) 
	{
		dice*=2;
		doub = false;
	}
	if(!walkdrt) 
	{
		dice*=-1;	
		walkdrt = true;
	}
	if(slow) 
	{
		dice/=2;;	
		slow = false;
	}
	//cout<< dice;
	//pd
	///clean////
	gotoxy(p.x,p.y);
	psq(0,21);
	gotoxy(p.x,p.y+1);
	psq(0,21);
	
	return dice;
	
}
////////////////////////////////////////////////////////////////////////
player* player::chtarget(map & m)
{
	position p= m.pads[0].pos;
	p.y= p.y+6;
	p.x = 170;
	vector<player*> plist;
	for(int i=0;i<m.myplayer.size();i++)
	{
		if(m.myplayer[i].num != num && m.myplayer[i].protect ==0) 
		plist.push_back(&m.myplayer[i]);
	}
		for(int i=0;i<plist.size();i++)
	{
		plist[i]->drawme(p.x+(i*6),p.y+6);
	}
	
	int ch=0;
	char comd;
	while(comd !=13)
	{
		for(int i=0;i<plist.size();i++)
		{
			gotoxy(p.x+(i*6),p.y+3);
			colorit(12);
			cout<<" ";
			colorit(15);
		}
		gotoxy(p.x+(ch*6),p.y+3);
		colorit(12);
		cout<<"v";
		colorit(15);
		comd=getch();
		if(comd =='a')ch--;
		else if(comd == 'd')ch++;
			PlaySound(TEXT("sound/menu.wav"),NULL,SND_SYNC);
		ch= (plist.size()+ch)%plist.size();
		
	}
	/////clr screen//////
	for(int i=0;i<plist.size();i++)
		{
			for(int j=0;j<3;j++)
			{
			gotoxy(p.x+(i*6),p.y+j);
			colorit(12);
			cout<<"  ";
			colorit(15);
			}
		}
		
	for(int j=0;j<4;j++)
	{
		gotoxy(p.x,p.y+3+j);
		psq(0,21);
	}

	return plist[ch];
}
///////////////////////////////////////////////////////////////////////////////	
void item::useme(player *tar,player*me,pad*p )
{ 	

	if(this->name =="Sheild") 
	{
		for(int i=0;i< 3;i++)
		{
			gotoxy(me->mypos.x,me->mypos.y);
			psq(162,1);
			gotoxy(me->mypos.x,me->mypos.y-1);
			psq(162,1);

			Sleep(200);
			gotoxy(me->mypos.x,me->mypos.y);
			psq(0,1);
			gotoxy(me->mypos.x,me->mypos.y-1);
			psq(0,1);
			me->drawme();
			Sleep(200);
		}
		me->protect += 2;
			PlaySound(TEXT("sound/shield.wav"),NULL,SND_SYNC);
	}
	else if(this->name =="Ice") 
	{
		tar->walk = false;
		tar->uitem = false;
		PlaySound(TEXT("sound/ice.wav"),NULL,SND_SYNC);

	}
	else if(this->name =="Warpscroll")
	{
		gotoxy(0,0);
		cout<<"a ";
		position tPos = me->mypos;
		pad * tPad = me->myPad;
		cout<<"b ";
		me->mypos.x = tar->mypos.x;
		me->mypos.y = tar->mypos.y;
		cout<<"c ";
		tar->mypos.x =  tPos.x;
		tar->mypos.y =  tPos.y;
		me->myPad = tar->myPad;
		tar->myPad = tPad;
		for(int i=0;i< 3;i++)
		{
			gotoxy(me->mypos.x,me->mypos.y);
			psq(240,1);
			gotoxy(me->mypos.x,me->mypos.y-1);
			psq(240,1);
			gotoxy(tar->mypos.x,tar->mypos.y);
			psq(240,1);
			gotoxy(tar->mypos.x,tar->mypos.y-1);
			psq(240,1);
			Sleep(200);
			gotoxy(me->mypos.x,me->mypos.y);
			psq(0,1);
			gotoxy(me->mypos.x,me->mypos.y-1);
			psq(0,1);
			gotoxy(tar->mypos.x,tar->mypos.y);
			psq(0,1);
			gotoxy(tar->mypos.x,tar->mypos.y-1);
			psq(0,1);
			Sleep(200);
		}
		
		player* tplay;
		for(int i=0;i<2;i++)
		{
			if(i==0)tplay = me;
			else if(i ==1)tplay = tar;
			position des(tplay->myPad->pos.x+2+((tplay->num-1)*4),tplay->myPad->pos.y-2);
			while(tplay->mypos.x != des.x)
			{
				//delete old
				gotoxy(tplay->mypos.x,tplay->mypos.y);
				psq(0,1);
				gotoxy(tplay->mypos.x,tplay->mypos.y-1);
				psq(0,1);
				gotoxy(tplay->mypos.x,tplay->mypos.y-2);
				psq(0,1);
				//delete old
				
				if(tplay->myPad->onpadItem != 0)tplay->myPad->onpadItem->drawitem(posItemPad(tplay->myPad->pos));//redraw item(for blocking item fade)
				if(tplay->myPad->onpadPlay.size() >0){//re draw palyer
					for(int i =0;i<me->myPad->onpadPlay.size();i++)
					{
						if(tplay->myPad->onpadPlay[i]->num != tplay->num)
						{
							tplay->myPad->onpadPlay[i]->drawme();
						}
					}
				}
				if(tplay->mypos.x > des.x)tplay->mypos.x--;
				else tplay->mypos.x++;
				tplay->drawme();
				Sleep(25);
			}
		}

	} 
	else if(name =="Block")
	{
		tar->walk = false;
	} 
	else if(name =="Double")
	{
		tar->doub = true;
	} 
	else if(name =="Mug")
	{
		tar->slow = true;
	} 
	else if(name =="Trap")
	{
		if(me->myPad->type == 'N')
		{
			me->myPad->type = 'T';
		}
		
	} 
	else if(name =="Fortune")
	{
		tar->fortune = true;
	}
	else if(name =="Reverse")
	{
		tar->walkdrt = false;
	}

	tar->drawme();
	me->drawme();
	tar->drawstat();
	me->drawstat();
	
}
void drawevent(position &p,int x){
	gotoxy(p.x-2,p.y-1);
	psq(143,7);
	gotoxy(p.x+2,p.y-1);
	colorit(143);
	cout<<"RANDOM";
	colorit(15);
	for(int i=0;i<5;i++)
	{
		gotoxy(p.x-2,p.y+i);
		psq(143,1);
		gotoxy(p.x+10,p.y+i);
		psq(143,1);
	}
	gotoxy(p.x-2,p.y+5);
	psq(143,7);
	
	for(int i =0;i<5;i++){
		gotoxy(p.x,p.y+i);
		psq(0,5);
	}
	switch(x)
	{
		case 0://clear
			for(int i =0;i<7;i++)
			{
			gotoxy(p.x-2,p.y+i-1);
			psq(0,7);
			}
		break;
		case 1://>
			
			gotoxy(p.x+2,p.y);
			psq(160,1);
			gotoxy(p.x+4,p.y+1);
			psq(160,1);
			gotoxy(p.x+6,p.y+2);
			psq(160,1);
			gotoxy(p.x+4,p.y+3);
			psq(160,1);
			gotoxy(p.x+2,p.y+4);
			psq(160,1);
			break;
		case 2://<
			gotoxy(p.x+6,p.y);
			psq(192,1);
			gotoxy(p.x+4,p.y+1);
			psq(192,1);
			gotoxy(p.x+2,p.y+2);
			psq(192,1);
			gotoxy(p.x+4,p.y+3);
			psq(192,1);
			gotoxy(p.x+6,p.y+4);
			psq(192,1);
			break;
		case 3://s
			gotoxy(p.x+2,p.y);
			psq(32,3);
			gotoxy(p.x+2,p.y+1);
			psq(32,1);
			gotoxy(p.x+2,p.y+2);
			psq(32,3);
			gotoxy(p.x+6,p.y+3);
			psq(32,1);
			gotoxy(p.x+2,p.y+4);
			psq(32,3);
			break;
		case 4://L ladder
			gotoxy(p.x+2,p.y);
			psq(240,1);
			gotoxy(p.x+2,p.y+1);
			psq(240,1);
			gotoxy(p.x+2,p.y+2);
			psq(240,1);
			gotoxy(p.x+2,p.y+3);
			psq(240,1);
			gotoxy(p.x+2,p.y+4);
			psq(240,3);
			break;
		case 5://I(green) randitem
			gotoxy(p.x+2,p.y);
			psq(160,3);
			gotoxy(p.x+4,p.y+1);
			psq(160,1);
			gotoxy(p.x+4,p.y+2);
			psq(160,1);
			gotoxy(p.x+4,p.y+3);
			psq(160,1);
			gotoxy(p.x+2,p.y+4);
			psq(160,3);
		break;
		case 6://-I(red) rand remove item
			gotoxy(p.x+2,p.y);
			psq(192,3);
			gotoxy(p.x+4,p.y+1);
			psq(192,1);
			gotoxy(p.x+4,p.y+2);
			psq(192,1);
			gotoxy(p.x+4,p.y+3);
			psq(192,1);
			gotoxy(p.x+2,p.y+4);
			psq(192,3);	
		break;
		case 7://v debuff rand
		gotoxy(p.x+4,p.y);
			psq(192,1);
			gotoxy(p.x+4,p.y+1);
			psq(192,1);
			gotoxy(p.x,p.y+2);
			psq(192,1);
			psq(0,1);
			psq(192,1);
			psq(0,1);
			psq(192,1);
			gotoxy(p.x+2,p.y+3);
			psq(192,3);
			gotoxy(p.x+4,p.y+4);
			psq(192,1);	
		break;
		case 8://^ buff rand
		gotoxy(p.x+4,p.y);
			psq(160,1);
			gotoxy(p.x+4,p.y+3);
			psq(160,1);
			gotoxy(p.x,p.y+2);
			psq(160,1);
			psq(0,1);
			psq(160,1);
			psq(0,1);
			psq(160,1);
			gotoxy(p.x+2,p.y+1);
			psq(160,3);
			gotoxy(p.x+4,p.y+4);
			psq(160,1);	
		break;
	}
	
}

void randomevent(position &p,player*me){
	int i=1;
	me->randp = false;
		while(true)
		{
			if (_kbhit()==1)
	    	{	
				if(getch()==32)break;
	    	}
	    	i= rand()%8+1;
	    	drawevent(p,i);
	    	Sleep(500);

		}
		drawevent(p,i);
	pad* temp;
	int t;
	switch(i)
	{
		case 1:
		me->gotopad(rand()%9+1);
		break;
		
		case 2:
		me->gotopad(-(rand()%9+1));
		break;
		
		case 4:
		temp = me->myPad;
		if(temp->num < me->maxpad)temp++;
		while(temp->pos.x!= me->myPad->pos.x &&temp->num < me->maxpad-1)
		{
			temp++;
		}
		if(temp->pos.y!= me->myPad->pos.y)me->ladsnakto(temp);
		break;
		
		case 3:
			temp = me->myPad;
			if(temp->num < me->maxpad)temp--;
			while(temp->pos.x != me->myPad->pos.x &&temp->num>1)
			{
				temp--;
			}
			if(temp->pos.y!= me->myPad->pos.y)me->ladsnakto(temp);
			break;
		case 5://I(green) randitem
			me->getitem(&itemlist[randitem()]);
			break;
			
		case 6://I(red)
			if(me->myitem.size()>0)
			{
				t=rand()%me->myitem.size();
		 		me->myitem.erase(me->myitem.begin()+t);
			}
			break;
			
		case 7://de buf
			t=rand()%4;
				switch(t){
					case 0:
						me->walkdrt = false;
						break;
					case 1:
						me->uitem= false;
						break;
					case 2:
						me->walk = false;
						break;
					case 3:
						me->walk = false;
						me->uitem= false;
						break;
				}
			break;
		case 8://buf
			t=rand()%3;
				switch(t){
					case 0:
						me->doub = true;
						break;
					case 1:
						me->protect +=2;
						break;
					case 2:
						me->fortune = true;
						break;

				}
			break;
	}
	me->drawstat();
	Sleep(1000);
	drawevent(p,0);
}




