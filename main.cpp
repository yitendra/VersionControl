#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
	ifstream file1("file1.txt");
	ifstream file2("file2.txt");
	string f1,f2;int a;
	while(file1>>f1 && file2>>f2){
        if(f1==f2){cout<<"Match"<<endl;}else{cout<<"No Match\n";}
	}
}
