#include <bits/stdc++.h>
#include <windows.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);   //Used printing in color
//color code=> 242 for green and 252 for red and 240 for black.
using namespace std;
void printInGreen(string);
void printInRed(string);
void compare(string *a, string *b);

int main()
{

system("COLOR f0");

	ifstream file1("file1.txt"),file2("file2.txt");
	string f1,f2,temp1[100],temp2[100];
	int i=1,j=1;
	while(getline(file1,f1)){
        if(f1!=""){temp1[i]=f1;i++;}
        }
    while(getline(file2,f2)){
        if(f2!=""){temp2[j]=f2;j++;}
    }
compare(temp1,temp2);

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
void compare(string *a, string *b){
    int i=1,j=1;
    while(a[i]!="" && b[j]!=""){
        if(a[i]==b[j]){
            cout<<a[i]<<endl;i++;j++;
        }else{
            a[i].insert(0,1,'-');
            b[j].insert(0,1,'+');
            printInRed(a[i]);i++;
            printInGreen(b[j]);j++;
        }
    }
}

