#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);   //Used printing in color
//color code=> 242 for green and 252 for red and 240 for black.
using namespace std;
void printInGreen(string);
void printInRed(string);
void compare(string *a, string *b);
void greyT();
void restoreT();
void greenT();
void redT();

int main()
{
system("COLOR f0");
    //getting versions
    char Old[10]="", New[10]="";
    ifstream ver("vc.log");
        ver>>New>>Old;
        char txt[] = ".txt";
        strcat(New,txt);
        strcat(Old,txt);

    //geting comparable files
	ifstream file1(Old),file2(New);
	string f1,f2,temp1[1000],temp2[1000];
	int i=1,j=1;
	while(getline(file1,f1)){
        if(f1!=""){temp1[i]=f1;i++;}
        }
    while(getline(file2,f2)){
        if(f2!=""){temp2[j]=f2;j++;}
    }
compare(temp1,temp2);
    getch();
    system("cls");
    system("COLOR 0f");

}
//Enf of Main function

void printInGreen(string a){
    SetConsoleTextAttribute(console, 242);
    a.insert(0,1,'+');
    cout<<a<<endl;
    SetConsoleTextAttribute(console, 240);
}
void printInRed(string a){
    SetConsoleTextAttribute(console, 252);
    a.insert(0,1,'-');
    cout<<a<<endl;
    SetConsoleTextAttribute(console, 240);
}
void compare(string *a, string *b){
    SetConsoleTextAttribute(console, 176);
    cout<<"  Old   New   Content "<<setw(30)<<setfill(' ')<<" "<<endl;
    restoreT();
    int i=1,j=1;
    while(a[i]!="" && b[j]!=""){
        if(a[i]==b[j]){
                greyT();
            cout<<" "<<setw(3)<<i<<"   "<<setw(3)<<j;
            restoreT();
            cout<<"    "<<a[i]<<endl;i++;j++;
        }else{
            int scan =j; bool found=0;
            while(b[scan]!=""){
                if(a[i]==b[scan]){found=1;break;}
                scan++;
            }
            if(!found){
                    redT();
                    cout<<" "<<setw(3)<<i<<"      ";
                    restoreT();
                    cout<<"    ";
                    printInRed(a[i]);i++;
                }else{
                    for(j; j<scan; j++){
                            greenT();
                     cout<<"       "<<setw(3)<<j;
                    restoreT();
                     cout<<"    ";
                        printInGreen(b[j]);
                        }
                    }
        }
            if(a[i]=="" && b[j]!=""){
                  while(b[j]!=""){
                        greenT();
                cout<<"       "<<setw(3)<<j;
                restoreT;
                cout<<"    ";
                printInGreen(b[j]);j++;}
            }
    }
}

//247=grey,
void greyT(){
SetConsoleTextAttribute(console, 247);
}
void restoreT(){
SetConsoleTextAttribute(console, 240);
}
void greenT(){
SetConsoleTextAttribute(console, 168);
}
void redT(){
SetConsoleTextAttribute(console, 203);
}

