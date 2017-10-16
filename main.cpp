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
    //saveFile();

    compare();
    system("main.bat");

    return 0;
}

void compare(){
    ofstream file("main.bat");
    file<<"echo off\ncls\ncd data\ncompare.exe";
    //Use system("main.bat"); after calling this fn.
}

void editFile(){
   system("notepad file.txt");
}
void bringOld(){
     int version;
    char New[10]="";
    ifstream ver("vc.log");
        ver>>New;
        char txt[] = ".txt";
        strcat(New,txt);
    ofstream fileO("main.bat");
    fileO<<"echo off\ncls\n";
    fileO<<"copy data\\"<<New<<endl;
    fileO<<"rename "<<New<<" old.txt";
}
bool isSame(){
     bringOld();
     system("main.bat");
    system("cls");
    ifstream file("file.txt"),old("old.txt");     //New is going to be old if changes made.
    string a,b;bool flag=true;
    while(getline(file,a) && getline(old,b)){
        if(a!=b){return false;
        flag = false;

        break;}
    }               //Use system("del old.txt"); after calling this fn.
    return flag;
}

void saveFile(){
    if(isSame()){
        cout<<"No Changes were made.\n";
    }else{
    //copy file.txt to data

    //rename file.txt to X.txt X=version

    //update both vc.log
    }
    system("del old.txt");
}
