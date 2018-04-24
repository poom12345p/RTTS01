#include <iostream>
#include <windows.h>
using namespace std;
void psq(int c,float i,char p=0){//draw pixel i block,color code c
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,c); 
	for(int j=0;j <i*2 ;j++)
	{
		if(p!=0)cout <<p;
		else cout<<" ";
	}
	SetConsoleTextAttribute(hConsole,15); 
}
void SetWindow(int Width, int Height)//don,t care//set window size
    {
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Width-1;
    Rect.Right = Height-1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
    }
void numberwinner(int winner){
	int space=60,colors=176;
if(winner==1){
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,4);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,2);
	psq(colors,4);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(colors,2);
	psq(1,2);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,4);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,4);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,4);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,2);
	psq(colors,6);
	cout<<endl;}
	}
else if(winner ==2){
		for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,2);
	psq(colors,4);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	
	psq(colors,2);
	psq(1,4);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	
	psq(1,6);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,4);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,2);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(colors,8);
	cout<<endl;}
	}
else if(winner ==3){
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,2);
	psq(colors,4);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(colors,2);
	psq(1,4);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,6);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,2);
	psq(colors,4);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,6);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(colors,2);
	psq(1,4);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,2);
	psq(colors,4);
	cout<<endl;}
	}
else if(winner ==4){
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(colors,2);
	psq(1,4);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(colors,2);
	psq(1,4);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(colors,2);
	psq(1,4);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,2);
	psq(colors,6);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,6);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,6);
	psq(colors,2);
	cout<<endl;}
	for(int i=0;i<2;i++){
	psq(1,space);
	psq(1,6);
	psq(colors,2);
	cout<<endl;}
	}
}
void cup(){
	psq(1,125);
	//1
	psq(1,63/2);
  	psq(120,3);
  	psq(1,18);
	psq(236,20);	
	psq(1,18);
	psq(120,3);
	psq(1,63/2); 
	//2
	psq(1,57/2+1);
	psq(120,3);
	psq(254,3);
	psq(120,1);
	psq(1,17);
	psq(236,20);
	psq(1,17);
	psq(120,1);	
	psq(254,3);
	psq(120,3);
	psq(1,57/2);
	//3
	psq(1,21/2+1);
	psq(120,2);
	psq(1,12);
	psq(120,4);
	psq(254,6);
	psq(120,1);
	psq(1,12);
	psq(236,30);
	psq(1,12);
	psq(120,1);	
	psq(254,6);
	psq(120,4);
	psq(1,12);
	psq(120,2);
	psq(1,21/2);
	//4
	psq(1,21/2+1);
	psq(120,14);
	psq(254,11);
	psq(120,1);
	psq(1,11);
	psq(236,1);
	psq(1,4);
	psq(236,20);//1
	psq(1,4);
	psq(236,1);
	psq(1,11);
	psq(120,1);	
	psq(254,11);
	psq(120,14);
	psq(1,21/2);
	//5
	psq(1,23/2+1);
	psq(120,2);
	psq(254,22);
	psq(120,1);
	psq(1,11);
	psq(236,1);
	psq(1,4);
	psq(236,20);//1
	psq(1,4);
	psq(236,1);
	psq(1,11);
	psq(120,1);
	psq(254,22);
	psq(120,2);
	psq(1,23/2+1);
	//6
	psq(1,23/2+1);
	psq(120,3);
	psq(254,21);
	psq(120,1);
	psq(1,10);
	psq(236,1);
	psq(1,4);
	psq(236,20);//1
	psq(1,4);
	psq(236,1);
	psq(1,10);
	psq(120,1);
	psq(254,21);
	psq(120,3);
	psq(1,23/2+1);
	//7
	psq(1,29/2+1);
	psq(120,3);
	psq(254,20);
	psq(120,1);
	psq(1,9);
	psq(236,1);
	psq(1,4);
	psq(236,20);//1
	psq(1,4);
	psq(236,1);
	psq(1,9);
	psq(120,1);	
	psq(254,20);
	psq(120,3);
	psq(1,29/2+1);
	//8
	psq(1,31/2+1);
	psq(120,3);
	psq(254,5);
	psq(120,4);
	psq(254,10);
	psq(120,1);
	psq(1,8);
	psq(236,1);
	psq(1,4);
	psq(236,20);//1
	psq(1,4);
	psq(236,1);
	psq(1,8);
	psq(120,1);
	psq(254,10);
	psq(120,4);	
	psq(254,5);
	psq(120,3);
	psq(1,31/2+1);
	//9
	psq(1,37/2+1);
	psq(120,9);	
	psq(254,12);
	psq(120,1);
	psq(1,7);
	psq(236,1);
	psq(1,4);
	psq(236,20);//1
	psq(1,4);
	psq(236,1);
	psq(1,7);
	psq(120,1);
	psq(254,12);
	psq(120,9);	
	psq(1,37/2+1);
	//10
	psq(1,37/2+1);
	psq(120,4);
	psq(254,3);
	psq(120,2);
	psq(254,3);
	psq(120,2);
	psq(254,2);
	psq(120,1);
	psq(254,4);
	psq(120,1);
	psq(1,6.5);
	psq(236,1.5);
	psq(1,3);
	psq(236,20);//1
	psq(1,3);
	psq(236,1.5);
	psq(1,6.5);
	psq(120,1);
	psq(254,4);
	psq(120,1);
	psq(254,2);
	psq(120,2);
	psq(254,3);
	psq(120,2);
	psq(254,3);
	psq(120,4);
	psq(1,37/2+1);
	//11
	psq(1,35/2+1);
	psq(120,3);
	psq(254,8);
	psq(120,4);
	psq(254,4);
	psq(120,2);
	psq(254,3);
	psq(120,2);
	psq(1,5.5);
	psq(236,1.5);
	psq(1,2);
	psq(236,20);//1
	psq(1,2);
	psq(236,1.5);
	psq(1,5.5);
	psq(120,2);
	psq(254,3);
	psq(120,2);
	psq(254,4);
	psq(120,4);
	psq(254,8);
	psq(120,3);
	psq(1,41/2+1);
	//12
	psq(1,23/2+1);
	psq(120,3);
	psq(254,11);
	psq(120,2);
	psq(254,3);
	psq(120,1);
	psq(254,2);
	psq(120,2);
	psq(254,4);
	psq(120,2);
	psq(1,4.5);
	psq(236,1.5);
	psq(1,1);
	psq(236,20);//1
	psq(1,1);
	psq(236,1.5);
	psq(1,4.5);
	psq(120,2);
	psq(254,4);
	psq(120,2);
	psq(254,2);
	psq(120,1);
	psq(254,3);
	psq(120,2);
	psq(254,11);
	psq(120,3);
	psq(1,23/2);
	//13
	psq(1,37/2+1);
	psq(120,2);
	psq(254,11);
	psq(120,2);
	psq(254,1);
	psq(120,1);
	psq(254,3);
	psq(120,1);
	psq(254,9);
	psq(120,3);
	psq(1,3.5);
	psq(236,1.5);
	psq(236,20);//1
	psq(236,1.5);
	psq(1,3.5);
	psq(120,3);
	psq(254,9);
	psq(120,1);
	psq(254,3);
	psq(120,1);
	psq(254,1);
	psq(120,2);
	psq(254,11);
	psq(120,2);
	psq(1,37/2);
	//14
	psq(1,21/2);
	psq(120,2);
	psq(254,10);
	psq(120,3);
	psq(254,2);
	psq(120,1);
	psq(254,2);
	psq(120,1);
	psq(254,12);
	psq(120,3);
	psq(1,3);
	psq(236,20);//1
	psq(1,3);
	psq(120,3);
	psq(254,12);
	psq(120,1);
	psq(254,2);
	psq(120,1);
	psq(254,2);
	psq(120,3);
	psq(254,10);
	psq(120,2);
	psq(1,21/2);
	//15
	psq(1,33/2);
	psq(120,5);
	psq(254,4);
	psq(120,5);
	psq(254,4);
	psq(120,3);
	psq(254,3);
	psq(120,15);
	psq(1,2);
	psq(236,18);//1
	psq(1,2);
	psq(120,15);
	psq(254,3);
	psq(120,3);
	psq(254,4);
	psq(120,5);
	psq(254,4);
	psq(120,5);
	psq(1,33/2);
	//16
	psq(1,27/2);
	psq(120,8);
	psq(254,6);
	psq(120,3);
	psq(254,3);
	psq(120,2);
	psq(254,8);
	psq(120,6);
	psq(1,2);
	psq(236,16);//1
	psq(1,2);
	psq(120,6);
	psq(254,8);
	psq(120,2);
	psq(254,3);
	psq(120,3);
	psq(254,6);
	psq(120,8);
	psq(1,27/2);
	//17
	psq(1,53/2);
	psq(120,2);
	psq(254,6);
	psq(120,3);
	psq(254,2);
	psq(120,2);
	psq(254,7);
	psq(120,8);
	psq(1,3);
	psq(236,14);//1
	psq(1,3);
	psq(120,8);
	psq(254,7);
	psq(120,2);
	psq(254,2);
	psq(120,3);
	psq(254,6);
	psq(120,2);
	psq(1,53/2);
	//18
	psq(1,37/2);
	psq(120,2);
	psq(254,6);
	psq(120,3);
	psq(254,3);
	psq(120,1);
	psq(254,8);
	psq(120,4);
	psq(1,8);
	psq(236,12);//1
	psq(1,8);
	psq(120,4);
	psq(254,8);
	psq(120,1);
	psq(254,3);
	psq(120,3);
	psq(254,6);
	psq(120,2);
	psq(1,37/2);
	//19
	psq(1,51/2);
	psq(120,1);
	psq(254,5);
	psq(120,4);
	psq(254,3);
	psq(120,2);
	psq(254,7);
	psq(120,4);
	psq(1,12);
	psq(236,6);//1
	psq(1,12);
	psq(120,4);
	psq(254,7);
	psq(120,2);
	psq(254,3);
	psq(120,4);
	psq(254,5);
	psq(120,1);
	psq(1,51/2);
	//20
	psq(1,35/2);
	psq(120,2);
	psq(254,3);
	psq(120,3);
	psq(1,2);
	psq(120,1);
	psq(254,1);
	psq(120,4);
	psq(254,5);
	psq(120,4);
	psq(1,14);
	psq(236,6);//1
	psq(1,14);
	psq(120,4);
	psq(254,5);
	psq(120,4);
	psq(254,1);
	psq(120,1);
	psq(1,2);
	psq(120,3);
	psq(254,3);
	psq(120,2);
	psq(1,35/2);
	//21
	psq(1,49/2);
	psq(120,7);
	psq(1,3);
	psq(120,4);
	psq(1,1);
	psq(120,1);
	psq(254,3);
	psq(120,3);
	psq(1,17);
	psq(236,6);//1
	psq(1,17);
	psq(120,3);
	psq(254,3);
	psq(120,1);
	psq(1,1);
	psq(120,4);
	psq(1,3);
	psq(120,7);
	psq(1,49/2);
	//22
	psq(1,35/2);
	psq(120,3);
	psq(1,7);
	psq(120,1);
	psq(1,4);
	psq(120,1);
	psq(254,1);
	psq(120,3);
	psq(1,19);
	psq(236,6);//1
	psq(1,19);
	psq(120,3);
	psq(254,1);
	psq(120,1);
	psq(1,4);
	psq(120,1);
	psq(1,7);
	psq(120,3);
	psq(1,35/2);
	//23
	psq(1,79/2);
	psq(120,3);
	psq(1,21);
	psq(236,6);//1
	psq(1,21);
	psq(120,3);
	psq(1,79/2);
	//24
	psq(1,113/2);
	psq(236,6);//1
	cout<<endl;
	//25
	psq(1,119/2);
	psq(236,6);//1
	cout<<endl;
	psq(1,119/2);
	psq(236,6);//1
	cout<<endl;
	psq(1,113/2);
	psq(236,12);//1
	cout<<endl;
	psq(1,109/2);
	psq(236,16);//1
	cout<<endl;
	psq(1,105/2);
	psq(236,20);//1
}
void playerword(){
		int color=235,wak=36;
for(int i=0;i<3;i++){
	color=162;
	psq(1,wak);
	psq(color,6);
	psq(1,4);
	psq(color,2);
	psq(1,2);
	cout<<endl;}
	
	for(int i=0;i<3;i++){
	color=162;
	psq(1,wak);
	psq(color,2);
	psq(1,4);
	psq(color,2);
	psq(1,2);
	psq(color,2);
	psq(1,4);
	psq(color,6);
	psq(1,2);
	psq(color,2);
	psq(1,4);
	psq(color,2);
	psq(1,4);
	psq(color,4);
	psq(1,4);
	psq(color,2);
	psq(1,2);
	psq(color,2);
	cout<<endl;}
	
	for(int i=0;i<3;i++){
	color=162;
	psq(1,wak);
	psq(color,2);
	psq(1,4);
	psq(color,2);
	psq(1,2);
	psq(color,2);
	psq(1,2);
	psq(color,2);
	psq(1,4);
	psq(color,2);
	psq(1,2);
	psq(color,2);
	psq(1,4);
	psq(color,2);
	psq(1,2);
	psq(color,2);
	psq(1,4);
	psq(color,2);
	psq(1,2);
	psq(color,4);
	cout<<endl;}
	
	for(int i=0;i<3;i++){
	color=162;
	psq(1,wak);
	psq(color,6);
	psq(1,4);
	psq(color,2);
	psq(1,2);
	psq(color,2);
	psq(1,4);
	psq(color,2);
	psq(1,2);
	psq(color,2);
	psq(1,4);
	psq(color,2);
	psq(1,2);
	psq(color,2);
	psq(1,2);
	psq(color,2);
	psq(1,4);
	psq(color,2);
	cout<<endl;}
	
	for(int i=0;i<3;i++){
	color=162;
	psq(1,wak);
	psq(color,2);
	psq(1,8);
	psq(color,2);
	psq(1,4);
	psq(color,6);
	psq(1,4);
	psq(color,6);
	psq(1,4);
	psq(color,6);
	psq(1,2);
	psq(color,2);
	cout<<endl;}
for(int i=0;i<3;i++){
	color=162;
	psq(1,wak+30);
	psq(color,2);
	cout<<endl;}
for(int i=0;i<3;i++){
 	color=162;
	psq(1,wak+26);
	psq(color,4);
	cout<<endl;}
}
void winword(){
	int N=38,c=207;
for(int i=0;i<3;i++){
c=162;
	psq(1,N);
	psq(c,2);
	psq(1,6);
	psq(c,2);
	psq(1,2);
	psq(c,6);
	psq(1,2);
	psq(c,2);
	psq(1,6);
	psq(c,2);
	psq(1,4);
	psq(c,8);
	psq(1,2);
	psq(c,2);
	cout<<endl;}
for(int i=0;i<3;i++){
	c=225;
	psq(1,N);
	psq(c,2);
	psq(1,6);
	psq(c,2);
	psq(1,4);
	psq(c,2);
	psq(1,4);
	psq(c,4);
	psq(1,4);
	psq(c,2);
	psq(1,2);
	psq(c,2);
	psq(1,10);
	psq(c,2);
	cout<<endl;}
for(int i=0;i<3;i++){
	c=207;
	psq(1,N);
	psq(c,2);
	psq(1,2);
	psq(c,2);
	psq(1,2);
	psq(c,2);
	psq(1,4);
	psq(c,2);
	psq(1,4);
	psq(c,2);
	psq(1,2);
	psq(c,2);
	psq(1,2);
	psq(c,2);
	psq(1,4);
	psq(c,6);
	psq(1,4);
	psq(c,2);
	cout<<endl;

}
for(int i=0;i<3;i++){
	c=144;
	psq(1,N);
	psq(c,4);
	psq(1,2);
	psq(c,4);
	psq(1,4);
	psq(c,2);
	psq(1,4);
	psq(c,2);
	psq(1,4);
	
	
	psq(c,4);
	
	psq(1,10);
	psq(c,2);

	cout<<endl;
	
}
for(int i=0;i<3;i++){
c=252;
	psq(1,N);
	psq(c,2);
	psq(1,6);
	psq(c,2);
	psq(1,2);
	psq(c,6);
	psq(1,2);
	psq(c,2);
	psq(1,6);
	psq(c,2);
	psq(1,2);
	psq(c,8);
	psq(1,4);
	psq(c,2);
	cout<<endl;}
	cout<<endl;


}
int main(){
	SetWindow(250,300);
cup();
	cout<<endl;
	cout<<endl;
	cout<<endl;
playerword();

	
	cout<<endl;
	cout<<endl;
	cout<<endl;

numberwinner(1);// input playernumber winner 1,2,3,4
	
	
	cout<<endl;
	cout<<endl;
	cout<<endl;
winword();

}


