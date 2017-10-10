#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;
void compare();
void editFile();
void saveFile();
void isDifferent();


int main()
{
    cout<<"testing\n";
    compare();
    system("main.bat");

    return 0;
}

void compare(){
    ofstream file("main.bat");
    file<<"echo off\ncls\ncd data\ncompare.exe";
}

void editFile(){
    ofstream file("main.bat");
    file<<"echo off\ncls\nnotepad file.txt";
    cout<<"Opening File...\n";
}

