#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "windows.h"
#include "funkcie.h"
#include <ctime>
#include <mmsystem.h>

using namespace std;

//g++ main.cpp -o main.exe -lWinmm
int main(){
    bool firstStart = true; 
    bool LOOP = true;
    srand(time(NULL));

    string * PoleOtazky;
    PoleOtazky = ReadFile("otazky.txt");
    string * PoleOdpovede;
    PoleOdpovede = ReadFile("odpovede.txt");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect); 
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1920, 1080, true);
    SetConsoleTextAttribute(hConsole, 15);

    while(LOOP){
        bool GAME = true;
        int moznostCislo = 1;
        string spravnaOdpoved;
        string randomOdpovede[4];
        string odpovede[4];
        string moznost;
        int currentAnswer = 1;
        int oldAnswer = 1;
        int peniaze = 0;
        int peniazePole[] = {0, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000};
        int cisloOtazky;
        int otazkySize;
        int odpovedeSize[4];
        double start;
        int last;
        string otazkyTaken[15];

        bool endRound = false;
        bool endGame = false;
        bool changeRound = true;
        bool changeQuestion = true;
        history Historia[10];
        clock_t time_req;
        if(firstStart == true){
            menu();
            Sleep(1500);
            vlado();
            SetConsoleTextAttribute(hConsole, 4);
            cout <<"\n                                                 OVLADANIE:\n                                                 POHYB JE SIPKAMI\n                                                 POTVRDENIE VOLBY JE ENTER\n\n";
            SetConsoleTextAttribute(hConsole, 15);
            system("PAUSE");
            firstStart = false;
        }
        last = round(clock()/1000);
        start = clock();
        system("CLS");
        while(GAME == true){
            if(peniazePole[peniaze] == peniazePole[sizeof(peniazePole) / sizeof(peniazePole[0]) - 1] || endGame == true){
                cout << endl;
                for(int i=0;i<237;i++) cout << "-";
                cout << endl << endl << endl;
                for(int i=0;i<107;i++) cout << " ";
                SetConsoleTextAttribute(hConsole, 6);
                cout << "VYHRAL SI " << peniazePole[peniaze] <<" EUR !!!" << endl << endl << endl;
                for(int i=0;i<100;i++) cout << " ";
                cout << "DOLE SI MOZETE POZRIET VASE ODPOVEDE" << endl << endl << endl;
                SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<237;i++) cout << "-";
                drawHistory(hConsole, peniaze, Historia, peniazePole);
                GAME = false;
                start = clock();
            }
            else{
                if(changeRound == true){
                    system("CLS");
                    changeRound = false;
                    cout << endl;
                    for(int i=0;i<237;i++){
                        cout << "-";
                    }
                    cout << endl << endl << endl;
                    if(changeQuestion == true){
                        changeQuestion = false;
                        odpovedeSize[4];
                        int e=0;
                        bool otazkaTaken = true;
                        while(otazkaTaken){
                            otazkaTaken = false;
                            cisloOtazky = rand()%15;
                            otazkyTaken[peniaze] = PoleOtazky[cisloOtazky];
                            if(peniaze != 0){
                                for(int i=0;i<peniaze;i++){
                                    if(PoleOtazky[cisloOtazky] == otazkyTaken[i]) otazkaTaken = true;
                                }
                            }
                        }

                        otazkySize = PoleOtazky[cisloOtazky].size();
                        for(int i=0;i<(237-(otazkySize))/2-4;i++){
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
                                            odpovedeSize[z] = randomOdpovede[rCislo].size() + 3;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else{
                        for(int i=0;i<(237-(otazkySize))/2-4;i++){
                            cout << " ";
                        }
                        cout << "*** " << PoleOtazky[cisloOtazky] << " ***" << endl << endl;
                    }
                            
                    cout << endl;                
                    
                    drawQuestion(hConsole, currentAnswer, odpovedeSize, odpovede); 
                    drawPeniaze(hConsole, peniaze, peniazePole);
                    time_req = clock() - start;
                    showTime(time_req);

                    for(int i=0;i<235;i++){
                        cout << "-";
                    }
                    //cout << endl << "Current Answer: "<< currentAnswer << endl;
                }
                time_req = clock() - start;
                if (last != round(time_req/1000)){
                    last = round(time_req/1000);
                    changeRound = true;
                }
                oldAnswer = currentAnswer;
                currentAnswer = move(hConsole, currentAnswer, changeRound);
                if (oldAnswer != currentAnswer) changeRound = true;
                
                if(GetKeyState(VK_RETURN) & 0x8000 || round(time_req/1000) == 15){
                    endRound = true;
                    moznost = submit(currentAnswer);
                    if(kontrolujOdpoved(moznost, spravnaOdpoved, odpovede) == 1){
                        Historia[peniaze].correct = true;
                        Historia[peniaze].otazka = PoleOtazky[cisloOtazky];
                        Historia[peniaze].otazkaSize = (237-(otazkySize))/2-4;
                        Historia[peniaze].odpovedA = odpovede[0];
                        Historia[peniaze].odpovedB = odpovede[1];
                        Historia[peniaze].odpovedC = odpovede[2];
                        Historia[peniaze].odpovedD = odpovede[3];
                        Historia[peniaze].odpovedASize = odpovedeSize[0];
                        Historia[peniaze].odpovedBSize = odpovedeSize[1];
                        Historia[peniaze].odpovedCSize = odpovedeSize[2];
                        Historia[peniaze].odpovedDSize = odpovedeSize[3];
                        Historia[peniaze].moznost = moznost;
                        Historia[peniaze].spravnaOdpoved = spravnaOdpoved;
                        Historia[peniaze].cisloOtazky = peniaze+1;
                        peniaze++;
                        system("CLS");
                        cout << endl;
                        for(int i=0;i<235;i++) cout << "-";
                        cout << endl << endl << endl;
                        for(int i=0;i<(237-(otazkySize))/2-4;i++) cout << " ";
                        cout << "*** " << PoleOtazky[cisloOtazky] << " ***" << endl << endl << endl;
                        drawCQuestion(hConsole, odpovedeSize, odpovede, moznost, spravnaOdpoved); 
                        drawPeniaze(hConsole, peniaze, peniazePole);
                        for(int i=0;i<235;i++) cout << "-";
                        
                        PlaySound(TEXT("correct.wav"), NULL, SND_SYNC);
                    }
                    else{
                        Historia[peniaze].correct = false;
                        Historia[peniaze].otazka = PoleOtazky[cisloOtazky];
                        Historia[peniaze].otazkaSize = (237-(otazkySize))/2-4;
                        Historia[peniaze].odpovedA = odpovede[0];
                        Historia[peniaze].odpovedB = odpovede[1];
                        Historia[peniaze].odpovedC = odpovede[2];
                        Historia[peniaze].odpovedD = odpovede[3];
                        Historia[peniaze].odpovedASize = odpovedeSize[0];
                        Historia[peniaze].odpovedBSize = odpovedeSize[1];
                        Historia[peniaze].odpovedCSize = odpovedeSize[2];
                        Historia[peniaze].odpovedDSize = odpovedeSize[3];
                        Historia[peniaze].moznost = moznost;
                        Historia[peniaze].spravnaOdpoved = spravnaOdpoved;
                        Historia[peniaze].cisloOtazky = peniaze+1;
                        endGame = true;
                        system("CLS");
                        cout << endl;
                        for(int i=0;i<235;i++) cout << "-";
                        cout << endl << endl << endl;
                        for(int i=0;i<(237-(otazkySize))/2-4;i++) cout << " ";
                        cout << "*** " << PoleOtazky[cisloOtazky] << " ***" << endl << endl << endl;
                        drawCQuestion(hConsole, odpovedeSize, odpovede, moznost, spravnaOdpoved); 
                        drawPeniaze(hConsole, peniaze, peniazePole, false);
                        for(int i=0;i<235;i++) cout << "-";

                        PlaySound(TEXT("incorrect.wav"), NULL, SND_SYNC);
                    }
                }

                if(endRound == true){
                    endRound = false;
                    changeRound = true;
                    changeQuestion = true;
                    currentAnswer = 1;
                    moznostCislo = 1;
                    system("PAUSE");
                    Sleep(500);
                    system("CLS");
                    start = clock();
                }
            }
        }
        cout << endl << endl << "Ak chces zacat novu hru stlac ENTER, inak stlac ESC . . . ";
        bool askToPlayAgain = true;
        while(askToPlayAgain){
            if(GetKeyState(VK_RETURN) & 0x8000){
                askToPlayAgain = false;
                start = clock();
            }
            if(GetKeyState(VK_ESCAPE) & 0x8000){
                askToPlayAgain = false;
                LOOP = false;
            }
        }
    }
    
    return 0;
}