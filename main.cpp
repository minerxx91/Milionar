#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "windows.h"
#include "funkcie.h"

using namespace std;

int main(){
    srand(time(NULL));
    system("CLS");
    bool GAME = true;
    int moznostCislo = 1;
    string spravnaOdpoved;
    string randomOdpovede[4];
    string odpovede[4];
    string moznost;
    int peniaze = 0;
    int peniazePole[] = {0, 100, 200, 500, 1000, 2000, 5000};

    string * PoleOtazky;
    PoleOtazky = ReadFile("otazky.txt");
    string * PoleOdpovede;
    PoleOdpovede = ReadFile("odpovede.txt");

    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect); 
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1920, 1080, true);
    
    while(GAME){
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
            if (i==3){
                while (true){
                    if((odpovede[0] != odpovede[1] && odpovede[0] != odpovede[2] && odpovede[0] != odpovede[3]) && (odpovede[1] != odpovede[0] && odpovede[1] != odpovede[2] && odpovede[1] != odpovede[3]) && (odpovede[2] != odpovede[0] && odpovede[2] != odpovede[1] && odpovede[2] != odpovede[3]) && (odpovede[3] != odpovede[1] && odpovede[3] != odpovede[2] && odpovede[3] != odpovede[0])){
                        break;
                    }
                    else{
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

        while(true){
            cin >> moznost;
            if (moznost != "a" && moznost != "A" && moznost != "b" && moznost != "B" && moznost != "c" && moznost != "C" && moznost != "d" && moznost != "D"){
                cout << "Takato moznost neexistuje !!!"<<endl;
            }
            else break;
        }
            
        if (kontrolujOdpoved(moznost, spravnaOdpoved, odpovede) == 1){
            peniaze++;
            cout << "Zatial mozes ziskat "<< peniazePole[peniaze] << " Eur !!!" << endl;
        }
        else {
            cout << "Spravna odpoved bola: " << spravnaOdpoved << " !!!" <<endl;
            cout << "Ziskal is "<< peniazePole[peniaze] << " Eur !!!" << endl;
            GAME = false;
        }

        moznostCislo = 1;
        system("PAUSE");
        system("CLS");
    }
    
    return 0;
}