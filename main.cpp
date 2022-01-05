#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "windows.h"
#include "funkcie.h"
#include <ctime>

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
    int currentAnswer = 1;
    int peniaze = 0;
    int peniazePole[] = {0, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000};

    string * PoleOtazky;
    PoleOtazky = ReadFile("otazky.txt");
    string * PoleOdpovede;
    PoleOdpovede = ReadFile("odpovede.txt");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect); 
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1920, 1080, true);
    
    menu();
    Sleep(3000);
    system("CLS");  
    
    while(GAME){
        clock_t time_req;
        time_req = clock();
        if(peniazePole[peniaze] == peniazePole[sizeof(peniazePole) / sizeof(peniazePole[0]) - 1]){
            for(int i=0;i<237;i++){
                cout << "-";
            }
            cout << endl << endl;
            for(int i=0;i<101;i++){
                cout << " ";
            }
            cout << "VYHRALI SI 100000 EUR !!!" << endl;
            system("pause");
            GAME = false;
        }
        else{
            for(int i=0;i<235;i++){
                cout << "-";
            }
            cout << endl << endl;
            vlado();
            int otazkySize;
            int odpovedeSize[4];
            int e=0;
            int cisloOtazky = rand()%15;

            otazkySize = PoleOtazky[cisloOtazky].size();
            for(int i=0;i<110 - (otazkySize/2);i++){
                cout << " ";
            }
            cout << "*** " << PoleOtazky[cisloOtazky] << " ***" << endl << endl;
            
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
                                int rCislo = rand() % (4);
                                odpovede[z] = randomOdpovede[rCislo];
                                odpovedeSize[z] = randomOdpovede[rCislo].size();
                            }
                        }
                    }
                }
            }
            /*
            printf("%d %d %d %d \n" , odpovedeSize[0],odpovedeSize[1],odpovedeSize[2],odpovedeSize[3]);
            for(int i=0;i<4;i++){
                cout << zobrazMoznosti(moznostCislo) << ": " << odpovede[i] << " ";
                moznostCislo ++;
                if(i % 2 == 1){
                    cout<< " " << endl;
                }
            }
            */
            
            for(int i=0;i<80;i++) cout << " ";
            if(currentAnswer == 1){
                SetConsoleTextAttribute(hConsole, 100);}
            cout << "A: " << odpovede[0];
            SetConsoleTextAttribute(hConsole, 15);
            for(int i=0;i<64 - odpovedeSize[0] - odpovedeSize[1];i++) cout << " ";
            cout << "B: " << odpovede[1];
            cout << endl;
            for(int i=0;i<80;i++) cout << " ";
            cout << "C: " << odpovede[2];
            for(int i=0;i<64 - odpovedeSize[2] - odpovedeSize[3];i++) cout << " ";
            cout << "D: " << odpovede[3];
            cout << endl << endl;
            for(int i=0;i<235;i++){
                cout << "-";
            }
            cout << endl << endl;

            while(true){
                for(int i=0;i<105;i++) cout << " ";
                cout << "Tvoja odpoved: ";
                getline(cin, moznost);
                time_req = clock() - time_req;
                showTime(time_req/1000);
                
                if (moznost != "a" && moznost != "A" && moznost != "b" && moznost != "B" && moznost != "c" && moznost != "C" && moznost != "d" && moznost != "D"){
                    for(int i=0;i<99;i++) cout << " ";
                    cout << "Takato moznost neexistuje !!!" << endl << endl;
                }
                else break;
            }

            if (kontrolujOdpoved(moznost, spravnaOdpoved, odpovede) == 1){
                for(int i=0;i<104;i++) cout << " ";
                cout << "Spravna odpoved !!!" << endl;
                peniaze++;
                for(int i=0;i<98;i++) cout << " ";
                cout << "Zatial mozes ziskat "<< peniazePole[peniaze] << " Eur !!!" << endl;
            }
            else {
                for(int i=0;i<103;i++) cout << " ";
                cout << "Nespravna odpoved !!!" << endl;
                for(int i=0;i<100-(spravnaOdpoved.size()/2);i++) cout << " ";
                cout << "Spravna odpoved bola: " << spravnaOdpoved << " !!!" <<endl;
                for(int i=0;i<104;i++) cout << " ";
                cout << "Ziskal is "<< peniazePole[peniaze] << " Eur !!!" << endl;
                GAME = false;
            }

            moznostCislo = 1;
            system("PAUSE");
            system("CLS");
        }
    }
    
    return 0;
}