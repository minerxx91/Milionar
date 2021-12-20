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
}

int kontrolujOdpoved(string moznost, string spravnaOdpoved, string odpovede[]){
    if(moznost == "A" || moznost == "a"){
        if (spravnaOdpoved == odpovede[0])
        {
            cout << "Spravne !!!"<<endl;
            return 1;
        }
        else
        {
            cout << "Nespravna odpoved !!!"<<endl;
            return 0;
        }  
    }
    else if(moznost == "B" || moznost == "b"){
        if (spravnaOdpoved == odpovede[1])
        {
            cout << "Spravne !!!"<<endl;
            return 1;
        }
        else
        {
            cout << "Nespravna odpoved !!!"<<endl;
            return 0;
        }  
    }
    else if(moznost == "C" || moznost == "c"){
        if (spravnaOdpoved == odpovede[2])
        {
            cout << "Spravne !!!"<<endl;
            return 1;
        }
        else
        {
            cout << "Nespravna odpoved !!!"<<endl;
            return 0;
        }  
    }
    else if(moznost == "D" || moznost == "d"){
        if (spravnaOdpoved == odpovede[3])
        {
            cout << "Spravne !!!" <<endl;
            return 1;
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
        return 0;
    }
    
}