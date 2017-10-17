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
void bringOld();
void saveNupdate();
void show();
void check();

int main()
{
    //check();
    saveNupdate();
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

bool isSame(){
    bringOld();
    system("main.bat");
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
    }
    system("del old.txt");
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

        check();
}

void check(){
    cout<<"Press '--help' to view the commands\n";
    s:
    cout<<"~$ ";
        cin>>command;

    if(command=="compare"){compare();system("main.bat");system("del main.bat");}
    else if(command=="edit")editFile();
    else if(command=="save")saveFile();
    else if(command=="clear"){system("cls");}
    else if(command=="exit"){goto Exit;}
    else if(command=="--help"){cout<<" Type 'compare' to compare old and new file\n Type 'edit' to open notepad\n Type 'save' to save the file\n New help commands will be updated soon;\n";goto s;}
    else {cout<<"'"<<command<<"' is not recognized as an internal or external command,\noperable program or batch file."<<endl;}
    goto s;
    Exit: cout<<"EXIT";
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
    ofstream file("main.bat");
    //copy file.txt to data folder
    file<<"xcopy file.txt data\\"<<endl;
    //update vc.log
    int Old,New;
    ifstream ver("vc.log");
        ver>>New>>Old;
        ++New;++Old;
        cout<<New<<" "<<Old<<endl;
    //getting versions.txt


}
