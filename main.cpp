#include <bits/stdc++.h>
#include <sys/stat.h>
#include <windows.h>
#include <conio.h>

using namespace std;
void init();
void compare();
void editFile();
void saveFile();
bool isSame();
void bringOld();
void saveNupdate();
void about();
void check();
bool fileExist(const string& name);

int main()
{
    init();
    check();
    return 0;
}


void compare(){
    ofstream comp("main.bat");
    comp<<"echo off\ncls\ncd data\ncompare.exe";
    //Use system("main.bat"); after calling this fn.
}

void editFile(){
   system("notepad file.txt");
}
void init(){
    //initializing Version Control.
    if(fileExist("vc.log")){cout<<"Version Control is already initialized.\n";}
    else{
        //make vc.log files.
        ofstream vc("vc.log");
        vc<<"00";
        ofstream vc2("data/vc.log");
        vc2<<"00";
        //make file.txt and version 00.txt
        ofstream v0("data/00.txt");
        v0<<"Version 0.0 for testing";
        ofstream initfile("file.txt");
        initfile<<"//This is your first version";
        cout<<"Version Control Initialized.\n";
    }
}

bool isSame(){
    bringOld();
    system("main.bat");
    system("del main.bat");
    system("cls");
    ifstream file("file.txt"),old("old.txt");
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
        cout<<"Changes Found\n";
    //copy file.txt to data
    //rename file.txt to X.txt X=version
    //update both vc.log
    saveNupdate();
    system("main.bat");
    }
    system("cls");
    cout<<"File Saved.\n";
    system("del old.txt");

}


void about(){string disp;
    system("cls");
    ifstream doc("README.md");
    while(getline(doc,disp)){
        cout<<disp<<endl;
    }doc.close();
}


void check(){
    system("cls");
    string command;
    cout<<"Press '--help' to view the commands\n";
    s:
    cout<<"~$ ";
        cin>>command;
    if(command=="compare"){compare();system("main.bat");system("del main.bat");}
    else if(command=="edit")editFile();
    else if(command=="edit"){editFile();cout<<endl;}
    else if(command=="save")saveFile();
    else if(command=="clear"){system("cls");}
    else if(command=="about"){about();}
    else if(command=="exit"){goto Exit;}
    else if(command=="--help"){cout<<" Type 'compare' to compare with previous file\n Type 'edit' to open notepad\n Type 'save' to save the file\n Type 'about' to know about the Project\n Type 'exit' to EXIT\n New help commands will be updated soon;\n";}
    else {cout<<"'"<<command<<"' is not recognized as an internal or external command,\noperable program or batch file."<<endl;}
    goto s;
    Exit:system("cls");
}


void bringOld(){
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

void saveNupdate(){

    //update vc.log
    int Old,New;
    ifstream ver("vc.log");
        ver>>New;
        Old=New;
        ++New;
    ofstream verw("vc.log");
        if(New<=9){verw<<"0"<<New<<endl;}
        else verw<<New<<endl;
        if(Old<=9){verw<<"0"<<Old;}
        else verw<<Old;
    //copy file.txt to data folder
    system("xcopy file.txt data\\");
    //renaming file.txt to latest version
    //updating vc.log of data
    ofstream file("main.bat");
    file<<"echo off\n";
    file<<"del data\\vc.log"<<endl;
    file<<"xcopy vc.log data\\"<<endl;
    file<<"cd data\n";
    if(New<=9){file<<"rename file.txt 0"<<New<<".txt";}
    else{file<<"rename file.txt "<<New<<".txt";}
    //call main.bat after calling this fn.
}

bool fileExist(const string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}
