#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;
//declarations
string disp,command;
void compare();
void editFile();
void saveFile();
bool isSame();
void show();
void check();


int main()
{
    show();
     /*isSame();
    system("del old.txt")*/

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
void show(){


    ifstream doc("show.txt");
    while(getline(doc,disp)){
        cout<<disp<<endl;
    }doc.close();
    l:
    cout<<endl<<"~$ ";
    cin>>command;
    if(command=="Start"){
        system("cls");
    }else{
        cout<<"'"<<command<<"' is not recognized as an internal or external command,\noperable program or batch file."<<endl;
        goto l;
    }
    ifstream help("help.txt");
    while(getline(help,disp))
        {
            cout<<disp<<endl;

        }help.close();
        check();





}
void check(){s:
    cout<<endl<<"~$ ";
        cin>>command;

    if(command=="compare")compare();
    else if(command=="edit")editFile();
    else if(command=="save")saveFile();
    else {cout<<"'"<<command<<"' is not recognized as an internal or external command,\noperable program or batch file."<<endl;
    goto s;}

}
