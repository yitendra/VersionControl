#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;
void compare();
void editFile();
void saveFile();
bool isSame();

int main()
{
    /*isSame();
    system("del old.txt")*/
    compare();
    system("main.bat");
    return 0;
}

void compare(){
    ofstream file("main.bat");
    file<<"echo off\ncls\ncd data\ncompare.exe";
}

void editFile(){
   system("notepad file.txt");
}

bool isSame(){
    system("copy data\\old.txt");
    system("cls");
    ifstream file("file.txt"),old("old.txt");
    string a,b;bool flag=true;
    while(getline(file,a) && getline(old,b)){
        if(a!=b){return false;
        flag = false;

        break;}
    }
    return flag;
}

void saveFile(){
    if(isSame()){
        cout<<"No Changes were made.\n";
    }else{
        //save old to log++.txt

        //save new to old.txt

        //save file to new.txt
    }
}
