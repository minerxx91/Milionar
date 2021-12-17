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

string randomOdpovede[4];
string odpovede[4];
string moznost;
int peniaze;

string zobrazMoznosti(int vstup){
    if (vstup == 1){
        return "A";
        }
    else if(vstup == 2){
        return "B";
        }
    else if(vstup == 3){
        return "C";
        }
    else{
        return "D";
        }
};

int kontrolujOdpoved(string moznost, string spravnaOdpoved, string odpovede[]){
    if(moznost == "a" or "A"){
        if (spravnaOdpoved == odpovede[0])
        {
            cout << "Spravne !!!"<<endl;
        }
        else
        {
            cout << "Nespravna odpoved !!!"<<endl;
            return 0;
        }  
    }
    else if(moznost == "b" or "B"){
        if (spravnaOdpoved == odpovede[1])
        {
            cout << "Spravne !!!"<<endl;
        }
        else
        {
            cout << "Nespravna odpoved !!!"<<endl;
            return 0;
        }  
    }
    else if(moznost == "c" or "C"){
        if (spravnaOdpoved == odpovede[2])
        {
            cout << "Spravne !!!"<<endl;
        }
        else
        {
            cout << "Nespravna odpoved !!!"<<endl;
            return 0;
        }  
    }
    else if(moznost == "d" or "D"){
        if (spravnaOdpoved == odpovede[3])
        {
            cout << "Spravne !!!" <<endl;
        }
        else
        {
            cout << "Nespravna odpoved !!!"<<endl;
            return 0;
        }   
    }
    else
    {
        cout << "Takato moznost neexistuje !!!"<<endl;
    }
    
}

int main(){
    srand(time(NULL));
    system("CLS");
    bool GAME = true;
    int moznostCislo = 1;
    string spravnaOdpoved;
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

        int e=0;
        int cisloOtazky = rand()%15;
        cout << PoleOtazky[cisloOtazky] << '\n';
        for(int i=cisloOtazky*4;i<cisloOtazky*4+4;i++){
            randomOdpovede[e] = PoleOdpovede[i];
            e++;
        }
        spravnaOdpoved = randomOdpovede[0];
        for(int i=0;i<4;i++){
            odpovede[i] = randomOdpovede[rand() % (4)];
            if (i==3)
            {
                while (true)
                {
                    if((odpovede[0] != odpovede[1] && odpovede[0] != odpovede[2] && odpovede[0] != odpovede[3]) && (odpovede[1] != odpovede[0] && odpovede[1] != odpovede[2] && odpovede[1] != odpovede[3]) && (odpovede[2] != odpovede[0] && odpovede[2] != odpovede[1] && odpovede[2] != odpovede[3]) && (odpovede[3] != odpovede[1] && odpovede[3] != odpovede[2] && odpovede[3] != odpovede[0])){
                        break;
                    }
                    else
                    {
                        for(int z=0;z<4;z++){
                            odpovede[z] = randomOdpovede[rand() % (4)];
                        }
                    }
                    
                }
            }
        }
        for(int i=0;i<4;i++){
            cout << zobrazMoznosti(moznostCislo) << ": " << odpovede[i] << " ";
            moznostCislo ++;
            if(i % 2 == 1){
                cout<< " " << endl;
            }
        }
        cin >> moznost;
        peniaze = kontrolujOdpoved(moznost, spravnaOdpoved, odpovede);
        moznostCislo = 1;
        break;
    }
    
    system("PAUSE");
    return 0;
}