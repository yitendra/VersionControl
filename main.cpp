#include <bits/stdc++.h>
#include <windows.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);   //Used printing in color
//color code=> 242 for green and 252 for red and 240 for black.
using namespace std;
void printInGreen(string);
void printInRed(string);

int main()
{

system("COLOR f0");

	ifstream file1("file1.txt"),file2("file2.txt");
	string f1,f2;
	while(getline(file1,f1) && getline(file2,f2)){
        if(f1==f2){printInRed("Match");}
        else{
               printInGreen("No match");
        }}
        cout<<"Testing";

        return 0;

}

void printInGreen(string a){
    SetConsoleTextAttribute(console, 242);
    cout<<a<<endl;
    SetConsoleTextAttribute(console, 240);
}
void printInRed(string a){
    SetConsoleTextAttribute(console, 252);
    cout<<a<<endl;
    SetConsoleTextAttribute(console, 240);
}
