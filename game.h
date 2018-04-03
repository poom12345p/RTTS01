#include<iostream>
#include<windows.h>
#include<vector>
#include<string>
#include<cstring>
#include "func.h"
using namespace std;

class pad;
//class item;
class player;

struct position{
	int x,y;
};
struct linkpad{
	int Head,Tail;
};
class item{
	int id;
	string name;
	public:
	//string name;
	item(int,string);
	void use(string,player *,pad *);
	void drawitem(const position &);
	void upitem();	
};
item::item(int i,string n){
	id =i;
	name = n;
	
}
/////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------------------ITEM-------------------------------------------------------------------------------------------//
string itemNameList[]={"Sheild","Ice","Warpscroll"};
vector<item> itemlist;
void creitem(){
	for(int i=0;i< sizeof(itemNameList)/sizeof(itemNameList[0]) ;i++)
	{
	itemlist.push_back(item(i,itemNameList[i]));
	cout<<itemNameList[i]<<endl;
	}
	
}

position posItemPad(const position &p){
	position np;
	np.x= p.x+8;
	np.y= p.y-4;
	return np;
	
}
void item::drawitem(const position &p){
	if(name =="Sheild" ){
		gotoxy(p.x,p.y);
		psq(176,1.5);
		gotoxy(p.x,p.y-1);
		psq(176,0.5);
		colorit(11);
		cout<<"S";
		colorit(15);
		psq(176,0.5);
	}
	else if(name =="Ice")
	{
		gotoxy(p.x,p.y);
		psq(240,1.5);
		gotoxy(p.x,p.y-1);
		psq(176,0.5);
		colorit(11);
		cout<<"I";
		colorit(15);
		psq(240,0.5);
	}
	else if(name =="Warpscroll"){
		gotoxy(p.x,p.y);
		colorit(15);
		cout<<"W";
		colorit(11);
		cout<<"<=";
		gotoxy(p.x+8,p.y-1);
		cout<<"=>";
		colorit(15);
		cout<<"W";
	}
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/////////////////////////////////////////////////////////////////
class pad{
	int num;
	int color;
	int gotopad;
	position pos;
	public:
	char type;
	item *onpadItem;
	pad(int,int,char,int,int,int);
	void spawnitem(int);
	void drawpad(int);
	position ppos;
	void uppad(int,int);
	void removeItem();

};
/////////////////////////////////////////////////////////////////
class player{
	int No;
	int myOrder;
	pad *myPad;
	vector<item *> myitem;
	position pos;
	
};

/////////////////////////////////////////////////////////////////
class map{
	vector<pad> pads;
	int link;
	int maxpad ;
	int coutrp;
	int PPL;//pad per level
	public:
	int frame;
	void drawmap();
	void createmap();
	map(int,int,int,int);
	void update();
	void spawnitem();
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
}
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
		loc=(rand()%(loc-2))+1;
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
	//creitem();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void map::drawmap(){
	for(int i =0;i<pads.size()-1;i++)
	{	int c=127;
		int level= ((i-(i%PPL))/PPL);
		pads[i].drawpad();
		if((i+1)%PPL==0 )
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
void map::spawnitem(){
	vector<int> numpad;//get pad that empty(ready for push item in)
		for(int i=2;i<maxpad;i++ )
		{
			if(pads[i].type =='N' && pads[i].onpadItem == NULL) {
			numpad.push_back(i);
			cout<<i;
			}
			cout<<"i";
		}
	for(int i=0;i< (maxpad/10);i++)
		{
			int loc = (rand()%(numpad.size()-2))+1;
			int id = rand()%itemlist.size();
			pads[i].spawnitem(id);
			numpad.erase(numpad.begin()+loc);
		}
}
//////////////////////////////////////////////////////////////////////////
void pad::uppad(int f,int last =0){
	if(num == last)
	{
		drawstar(pos,f);
	}
	/*if(onpadItem != NULL)
	{
		onpadItem->drawitem(posItemPad(pos));
	}*/
}

//////////////////////////////////////////////////////////////////////////
void pad::spawnitem(int id){
	onpadItem = &itemlist[id];
}






