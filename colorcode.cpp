#include <iostream>
#include <windows.h>
using namespace std;


int main (void)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

   for(int i=0;i <=256 ;i+=1)
   {
   		
   		 SetConsoleTextAttribute(hConsole,i);
   		cout <<i;
   		
   }
	return 0;
}
