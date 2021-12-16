#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "windows.h"

using namespace std;

string *ReadFile(string fileName){
    ifstream myFileL(fileName);
    ifstream myFile(fileName);
    string myText;
    int numberOfLines = 0;

    if (myFileL.is_open()){
        while (getline(myFileL,myText)){
            numberOfLines++;
        }
        //cout << "Number of lines: " << numberOfLines << endl;
        myFileL.close();
    }

    string * PoleRead = new string[numberOfLines];
    
    if (myFile.is_open()){
        int i = 0;
        while (getline(myFile,myText)){
            PoleRead[i] = myText;
            i++;
        }
        myFile.close();
    }
    else cout << "Unable to open file"; 


    return PoleRead;
}

char moznost(int vstup){
    if (vstup == 1){
        return 'A';
        }
    else if(vstup == 2){
        return 'B';
        }
    else if(vstup == 3){
        return 'C';
        }
    else{
        return 'D';
        }
};

int main(){
    srand(time(NULL));
    system("CLS");
    bool GAME = true;
    int moznostCislo = 1;
    string * PoleOtazky;
    PoleOtazky = ReadFile("otazky.txt");
    string * PoleOdpovede;
    PoleOdpovede = ReadFile("odpovede.txt");
    
    /*for(int i=0;i<2;i++){
        cout << PoleOtazky[i] << '\n';
    }
    for(int i=0;i<8;i++){
        cout << PoleOdpovede[i] << '\n';
    }*/

    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect); 
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1920, 1080, true);
    
    while (1)
    {
        for(int i=0;i<237;i++){
            cout << "-";
        }

        int cisloOtazky = rand()%15;
        cout << PoleOtazky[cisloOtazky] << '\n';
        for(int i=cisloOtazky*4;i<cisloOtazky*4+4;i++){
            cout << moznost(moznostCislo) << " " << PoleOdpovede[i] << '\n';
            moznostCislo ++;
        }
        moznostCislo = 1;
        break;
    }
    
    system("PAUSE");
    return 0;
}