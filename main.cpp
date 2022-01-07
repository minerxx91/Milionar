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
    int oldAnswer = 1;
    int peniaze = 0;
    int peniazePole[] = {0, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000};
    int cisloOtazky;
    int otazkySize;
    int odpovedeSize[4];

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

    bool endRound = false;
    bool changeRound = true;
    bool changeQuestion = true;
    
    menu();
    Sleep(150);
    vlado();
    Sleep(150);
    system("CLS");    
    
    while(GAME == true){
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
            if(changeRound == true){
                system("CLS");
                changeRound = false;
                for(int i=0;i<237;i++){
                    cout << "-";
                }
                cout << endl << endl << endl;
                if(changeQuestion == true){
                    changeQuestion = false;
                    odpovedeSize[4];
                    int e=0;
                    cisloOtazky = rand()%15;
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
                
                // prve dva obdlzniky
                // riadok 1
                if(currentAnswer == 1) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<30;i++)cout << " ";
                for(int i=0;i<70;i++) cout << static_cast<char>(254);
                if(currentAnswer == 2) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<37;i++)cout << " ";
                for(int i=0;i<70;i++) cout << static_cast<char>(254);
                cout << endl;
                // riadok 2
                if(currentAnswer == 1) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<30;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                if(currentAnswer == 2) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<37;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                cout << endl;
                // riadok 3
                if(currentAnswer == 1) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<30;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                if(currentAnswer == 2) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<37;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                cout << endl;
                // riadok 4 odpovede a, b
                if(currentAnswer == 1) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<30;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<((68 - odpovedeSize[0])/2);i++) cout << " ";
                cout << "A: " << odpovede[0];
                if(odpovedeSize[0]% 2 == 1) cout << " ";
                for(int i=0;i<((68 - odpovedeSize[0])/2);i++) cout << " ";
                cout << static_cast<char>(254);
                if(currentAnswer == 2) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<37;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<((68 - odpovedeSize[1])/2);i++) cout << " ";
                cout << "B: " << odpovede[1];
                if(odpovedeSize[1]% 2 == 1) cout << " ";
                for(int i=0;i<((68 - odpovedeSize[1])/2);i++) cout << " ";
                cout << static_cast<char>(254);
                cout << endl;
                // riadok 5
                if(currentAnswer == 1) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<30;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                if(currentAnswer == 2) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<37;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                cout << endl;
                // riadok 6
                if(currentAnswer == 1) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<30;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                if(currentAnswer == 2) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<37;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                cout << endl;
                // riadok 7
                if(currentAnswer == 1) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<30;i++)cout << " ";
                for(int i=0;i<70;i++) cout << static_cast<char>(254);
                if(currentAnswer == 2) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<37;i++)cout << " ";
                for(int i=0;i<70;i++) cout << static_cast<char>(254);
                
                cout << endl << endl;


                // druhe dva obdlzniky
                // riadok 1
                if(currentAnswer == 3) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<30;i++)cout << " ";
                for(int i=0;i<70;i++) cout << static_cast<char>(254);
                if(currentAnswer == 4) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<37;i++)cout << " ";
                for(int i=0;i<70;i++) cout << static_cast<char>(254);
                cout << endl;
                // riadok 2
                if(currentAnswer == 3) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<30;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                if(currentAnswer == 4) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<37;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                cout << endl;
                // riadok 3
                if(currentAnswer == 3) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<30;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                if(currentAnswer == 4) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<37;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                cout << endl;
                // riadok 4 odpovede c, d
                if(currentAnswer == 3) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<30;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<((68 - odpovedeSize[2])/2);i++) cout << " ";
                cout << "C: " << odpovede[2];
                if(odpovedeSize[2]% 2 == 1) cout << " ";
                for(int i=0;i<((68 - odpovedeSize[2])/2);i++) cout << " ";
                cout << static_cast<char>(254);
                if(currentAnswer == 4) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<37;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<((68 - odpovedeSize[3])/2);i++) cout << " ";
                cout << "D: " << odpovede[3];
                if(odpovedeSize[3]% 2 == 1) cout << " ";
                for(int i=0;i<((68 - odpovedeSize[3])/2);i++) cout << " ";
                cout << static_cast<char>(254);
                cout << endl;
                // riadok 5
                if(currentAnswer == 3) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<30;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                if(currentAnswer == 4) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<37;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                cout << endl;
                // riadok 6
                if(currentAnswer == 3) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<30;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                if(currentAnswer == 4) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<37;i++)cout << " ";
                cout << static_cast<char>(254);
                for(int i=0;i<68;i++) cout << " ";
                cout << static_cast<char>(254);
                cout << endl;
                // riadok 7
                if(currentAnswer == 3) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<30;i++)cout << " ";
                for(int i=0;i<70;i++) cout << static_cast<char>(254);
                if(currentAnswer == 4) SetConsoleTextAttribute(hConsole, 11);
                else SetConsoleTextAttribute(hConsole, 15);
                for(int i=0;i<37;i++)cout << " ";
                for(int i=0;i<70;i++) cout << static_cast<char>(254);
                cout << endl << endl << endl << endl;
                SetConsoleTextAttribute(hConsole, 15);

                for(int i=0;i<237;i++){
                    cout << "-";
                }
                //cout << endl << "Current Answer: "<< currentAnswer << endl;
            }
            oldAnswer = currentAnswer;
            currentAnswer = move(hConsole, currentAnswer, changeRound);
            if (oldAnswer != currentAnswer) changeRound = true;
            
            if(GetKeyState(VK_RETURN) & 0x8000){
                endRound = true;
                moznost = submit(currentAnswer);
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
            }
        }
    }
    
    return 0;
}