#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

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

int main(){
    srand(time(NULL));
    system("CLS");
    
    string * PoleOtazky;
    PoleOtazky = ReadFile("otazky.txt");
    string * PoleOdpovede;
    PoleOdpovede = ReadFile("odpovede.txt");

    for(int i=0;i<2;i++){
        cout << PoleOtazky[i] << '\n';
    }
    
    //system("PAUSE");
    return 0;
}