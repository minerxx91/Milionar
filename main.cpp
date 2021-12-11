#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    srand(time(NULL));
    system("CLS");

    ifstream MyFileOtazkyC("otazky.txt");
    ifstream MyFileOtazky("otazky.txt");
    ifstream MyFileOdpovedeC("odpovede.txt");
    ifstream MyFileOdpovede("odpovede.txt");
    string myText;
    int numberOfLinesOtazky = 0;
    int numberOfLinesOdpovede = 0;

    // get number of lines otazky
    if (MyFileOtazkyC.is_open()){
        while (getline(MyFileOtazkyC,myText)){
            numberOfLinesOtazky++;
        }
        cout << "Number of lines: " << numberOfLinesOtazky << endl;
        MyFileOtazkyC.close();
    }

    // save lines from file otazky to array
    string PoleOtazky[numberOfLinesOtazky];
    if (MyFileOtazky.is_open()){
        int i = 0;
        while (getline(MyFileOtazky,myText)){
            PoleOtazky[i] = myText;
            i++;
        }
        MyFileOtazky.close();
    }
    else cout << "Unable to open file"; 





    // get number of lines odpovede
    if (MyFileOdpovedeC.is_open()){
        while (getline(MyFileOdpovedeC,myText)){
            numberOfLinesOdpovede++;
        }
        cout << "Number of lines: " << numberOfLinesOdpovede << endl;
        MyFileOdpovedeC.close();
    }

    // save lines from file odpovede to array
    string PoleOdpovede[numberOfLinesOdpovede];
    if (MyFileOdpovede.is_open()){
        int i = 0;
        while (getline(MyFileOdpovede,myText)){
            PoleOdpovede[i] = myText;
            i++;
        }
        MyFileOdpovede.close();
    }
    else cout << "Unable to open file"; 

    

    // printing to terminal some debug information
    for(int i=0;i<numberOfLinesOtazky;i++){
        cout << PoleOtazky[i] << '\n';
    }
    for(int i=0;i<numberOfLinesOdpovede;i++){
        cout << PoleOdpovede[i] << '\n';
    }

    return 0;
}