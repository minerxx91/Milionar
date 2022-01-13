#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "windows.h"
#include <cmath>
#include <mmsystem.h>

using namespace std;

struct history{
    bool correct;
    string otazka;
    int otazkaSize;
    string odpovedA;
    string odpovedB;
    string odpovedC;
    string odpovedD;
    int odpovedASize;
    int odpovedBSize;
    int odpovedCSize;
    int odpovedDSize;
    string moznost;
    string spravnaOdpoved;
    int cisloOtazky;
};

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
            //cout << "Spravne !!!"<<endl;
            return 1;
        }
        else
        {
            //cout << "Nespravna odpoved !!!"<<endl;
            return 0;
        }  
    }
    else if(moznost == "B" || moznost == "b"){
        if (spravnaOdpoved == odpovede[1])
        {
            //cout << "Spravne !!!"<<endl;
            return 1;
        }
        else
        {
            //cout << "Nespravna odpoved !!!"<<endl;
            return 0;
        }  
    }
    else if(moznost == "C" || moznost == "c"){
        if (spravnaOdpoved == odpovede[2])
        {
            //cout << "Spravne !!!"<<endl;
            return 1;
        }
        else
        {
            //cout << "Nespravna odpoved !!!"<<endl;
            return 0;
        }  
    }
    else if(moznost == "D" || moznost == "d"){
        if (spravnaOdpoved == odpovede[3])
        {
            //cout << "Spravne !!!" <<endl;
            return 1;
        }
        else
        {
            //cout << "Nespravna odpoved !!!"<<endl;
            return 0;
        }   
    }
    else
    {
        cout << "Takato moznost neexistuje !!!"<<endl;
        return 0;
    }
    
}

void showTime(double cas){
    int time = round(cas/1000);

    if (time == 15)
    {
        cout<<"  #   "<<endl;
        cout<<" ##   "<<endl;
        cout<<"# #   "<<endl;
        cout<<"  #   "<<endl;
        cout<<"  #   "<<endl;
        cout<<"  #   "<<endl;
        cout<<"##### "<<endl;
    }
    else if (time == 14)
    {
        cout<<" #####  "<<endl;
        cout<<"#     # "<<endl;
        cout<<"      # "<<endl;
        cout<<" #####  "<<endl;
        cout<<"#       "<<endl;
        cout<<"#       "<<endl;
        cout<<"####### "<<endl;
    }
    else if (time == 13)
    {
        cout<<" #####  "<<endl;
        cout<<"#     # "<<endl;
        cout<<"      # "<<endl;
        cout<<" #####  "<<endl;
        cout<<"      # "<<endl;
        cout<<"#     # "<<endl;
        cout<<" #####  "<<endl;
    }
    else if (time == 12)
    { 
        cout<<"#       "<<endl;
        cout<<"#    #  "<<endl;
        cout<<"#    #  "<<endl;
        cout<<"#    #  "<<endl;
        cout<<"####### "<<endl;
        cout<<"     #  "<<endl;
        cout<<"     #  "<<endl;
    }
    else if (time == 11)
    {    
        cout<<"####### "<<endl;
        cout<<"#       "<<endl;
        cout<<"#       "<<endl;
        cout<<"######  "<<endl;
        cout<<"      # "<<endl;
        cout<<"#     # "<<endl;
        cout<<" #####  "<<endl;
    }

    else if (time == 10)
    {      
        cout<<" #####  "<<endl;
        cout<<"#     # "<<endl;
        cout<<"#       "<<endl;
        cout<<"######  "<<endl;
        cout<<"#     # "<<endl;
        cout<<"#     # "<<endl;
        cout<<" #####  "<<endl;
    }

    else if (time == 9)
    { 
        cout<<"####### "<<endl;
        cout<<"#    #  "<<endl;
        cout<<"    #   "<<endl;
        cout<<"   #    "<<endl;
        cout<<"  #     "<<endl;
        cout<<"  #     "<<endl;
        cout<<"  #     "<<endl;
    }
    
    else if (time == 8)
    {  
        cout<<" #####  "<<endl;
        cout<<"#     # "<<endl;
        cout<<"#     # "<<endl;
        cout<<" #####  "<<endl;
        cout<<"#     # "<<endl;
        cout<<"#     # "<<endl;
        cout<<" #####  "<<endl;
    }
    
    else if (time == 7)
    {   
        cout<<" #####  "<<endl;
        cout<<"#     # "<<endl;
        cout<<"#     # "<<endl;
        cout<<" ###### "<<endl;
        cout<<"      # "<<endl;
        cout<<"#     # "<<endl;
        cout<<" #####  "<<endl;
    }

    else if (time == 6)
    {   
        cout<<"  #     ###   "<<endl;
        cout<<" ##    #   #  "<<endl;
        cout<<"# #   #     # "<<endl;
        cout<<"  #   #     # "<<endl;
        cout<<"  #   #     # "<<endl;
        cout<<"  #    #   #  "<<endl;
        cout<<"#####   ###   "<<endl;
    }

    else if (time == 5)
    {
        cout<<"  #     #   "<<endl;
        cout<<" ##    ##   "<<endl;
        cout<<"# #   # #   "<<endl;
        cout<<"  #     #   "<<endl;
        cout<<"  #     #   "<<endl;
        cout<<"  #     #   "<<endl;
        cout<<"##### ##### "<<endl; 
    }
    
    else if (time == 4)
    {
        cout<<"  #    #####  "<<endl; 
        cout<<" ##   #     # "<<endl; 
        cout<<"# #         # "<<endl; 
        cout<<"  #    #####  "<<endl; 
        cout<<"  #   #       "<<endl; 
        cout<<"  #   #       "<<endl; 
        cout<<"##### ####### "<<endl; 
    }

    else if (time == 3)
    {
        cout<<"  #    #####  "<<endl; 
        cout<<" ##   #     # "<<endl; 
        cout<<"# #         # "<<endl; 
        cout<<"  #    #####  "<<endl; 
        cout<<"  #         # "<<endl; 
        cout<<"  #   #     # "<<endl; 
        cout<<"#####  #####  "<<endl; 
    }

    else if (time == 2)
    {
        cout<<"  #   #       "<<endl;
        cout<<" ##   #    #  "<<endl;
        cout<<"# #   #    #  "<<endl;
        cout<<"  #   #    #  "<<endl;
        cout<<"  #   ####### "<<endl;
        cout<<"  #        #  "<<endl;
        cout<<"#####      #  "<<endl;
    }

    else if (time == 1)
    {
        cout<<"  #   ####### "<<endl;
        cout<<" ##   #       "<<endl;
        cout<<"# #   #       "<<endl;
        cout<<"  #   ######  "<<endl;
        cout<<"  #         # "<<endl;
        cout<<"  #   #     # "<<endl;
        cout<<"#####  #####  "<<endl;
    }

}

int move(HANDLE hConsole, int currentAnswer, bool changeRound){
    if(GetKeyState(VK_LEFT) & 0x8000){
        if (currentAnswer == 2){
            currentAnswer = 1;
            PlaySound(TEXT("select.wav"), NULL, SND_SYNC);
        }
        else if (currentAnswer == 4){
            currentAnswer = 3;
            PlaySound(TEXT("select.wav"), NULL, SND_SYNC);
        }
    }
    else if(GetKeyState(VK_RIGHT) & 0x8000){
        if (currentAnswer == 1){
            currentAnswer = 2;
            PlaySound(TEXT("select.wav"), NULL, SND_SYNC);
        }
        else if(currentAnswer == 3){
            currentAnswer = 4;
            PlaySound(TEXT("select.wav"), NULL, SND_SYNC);
        }
    }
    else if(GetKeyState(VK_DOWN) & 0x8000){
        if (currentAnswer == 1){
            currentAnswer = 3;
            PlaySound(TEXT("select.wav"), NULL, SND_SYNC);
        }
        else if (currentAnswer == 2){ 
            currentAnswer = 4;
            PlaySound(TEXT("select.wav"), NULL, SND_SYNC);
        }
    }    
    else if(GetKeyState(VK_UP) & 0x8000){
        if (currentAnswer == 3){
            currentAnswer = 1;
            PlaySound(TEXT("select.wav"), NULL, SND_SYNC);
        }
        else if (currentAnswer == 4){
            currentAnswer = 2;
            PlaySound(TEXT("select.wav"), NULL, SND_SYNC);
        }    
    }
    return currentAnswer;
}

string submit(int currentAnswer){
    string odpoved;
    if (currentAnswer == 1){
        odpoved = "a";
    }
    else if (currentAnswer == 2){
        odpoved = "b";
    }
    else if (currentAnswer == 3){
        odpoved = "c";
    }
    else if (currentAnswer == 4){
        odpoved = "d";
    }

    return odpoved;    
}

void vlado(){
    cout<<"                                                                                                                             `.`.....``  ``                                                                                   "<<endl;   
    cout<<"                                                                                                                       ``-------::///////+++::-.`                                                                             "<<endl;   
    cout<<"                                                                                                                  ```.-:://///://////++++oooooos+--+-                                                                         "<<endl;   
    cout<<"                                                                                                                `-::://++oooo+oo++///+oooossoooossossoo/.`                                                                    "<<endl;   
    cout<<"                                                                                                              `-://////+++ossoso++++oooo+oosso+o++++oosyss+.                                                                  "<<endl;   
    cout<<"                                                                                                            ``/+++++///++osssooooooso++oooooooooo++++++ossss:                                                                 "<<endl;   
    cout<<"                                                                                                           -//+o++++///+++o++oo+o++ooooosoo+++ossooo+++++oooo:`                                                               "<<endl;   
    cout<<"                                                                                                         `:++oo++++///:/:://+++///+++++oo+o++/+sssooo++++o+ooo/`                                                              "<<endl;   
    cout<<"                                                                                                         .+ooo+++////:::::///:://///+//++oo++/++ooooo++ooooooso+-                                                             "<<endl;   
    cout<<"                                                                                                         -ooo+++////::::::::::::::::://///+oo++++oooooosssssooooo.                                                            "<<endl;   
    cout<<"                                                                                                        -ooo+++//////::::::::::::::::::::///////++++oosssssso+osoo-                                                           "<<endl;   
    cout<<"                                                                                                      `-+++++///////::::::::::::::::::://////++++++++osssyyyyyyyso+.                                                          "<<endl;   
    cout<<"                                                                                                      :hhyso+///::::::-::::::::::::::::////+++++++++/+oooyyyyyyyssso:                                                         "<<endl;   
    cout<<"                                                                                                     .syydddy+/:::-----::::::::::::::://///++++ooo+++++++sssyyssyyyyo-                                                        "<<endl;   
    cout<<"                                                                                                     .oo+oshhyo/::----::::----------::////++++ooo+++++oooosssoosyyhhy/                                                        "<<endl;   
    cout<<"                                                                                                    .ossso++oyyo/:--:::::::::::////////////++++ooo++++osooosooosyyhhs/                                                        "<<endl;   
    cout<<"                                                                                                    :ssssso+++oso/:::::::/+osyhhhhhhyyso///+++++o++++++ooosooossssyhs:                                                        "<<endl;   
    cout<<"                                                                                                   `:ossyyhy++oos/::::::+ossyyssoooooosys+/++++++++++++++osssssoosyhho                                                        "<<endl;   
    cout<<"                                                                                                  .++oo+++++//+o+/:--:+ossooo+++///::::/ss++++++++++++++++osyssooshydh                                                        "<<endl;   
    cout<<"                                                                                                  :+++oooooo++/+/:::/++//oossso+//++////+oo++++++++ooooo++oosyyoosyymd                                                        "<<endl;   
    cout<<"                                                                                                 `/++///+++++++/:://///::+oooyyyo+++++++/+o+/+++++oooooo++osyyyosyyhd/                                                        "<<endl;   
    cout<<"                                                                                                 .+++//////++//://///:::/+ooo+///+o+++++//+////++ooooooo+ossyysssyhdo                                                         "<<endl;   
    cout<<"                                                                                                 +++///////+/////////:::://++o+////+++//:////++ooosso+++ossyhysyshds`                                                         "<<endl;   
    cout<<"                                                                                                 oo+/////+o/:::/++///::::::://////:::::::://+++oosso+ooosyyyyhhyhms                                                           "<<endl;   
    cout<<"                                                                                                .oo+///++sy+//++++////:-----:::::::-::::://+++oosssoossssyyyyyhhmm-                                                           "<<endl;   
    cout<<"                                                                                               :sso++++++ydsoosys+//+++/:---.----::::::///++ooosssossshhhyhhhhyys-                                                            "<<endl;   
    cout<<"                                                                                               +ooo++oossshdyyysyysso/:+/::-----:::::///++oooossssosyhddhhs/ooo+.                                                             "<<endl;   
    cout<<"                                                                                              `+++/oossssssssooo+////--:+//:::::::////+++oooooosssosydddy+//oo//.                                                             "<<endl;   
    cout<<"                                                                                              /oo//ssyyssso+ooooo++///:://///////////++++ooososoosssyosso+++s/-`                                                              "<<endl;   
    cout<<"                                                                                              /o+//ssyyyyso++oo+oo+++++/://////////+++++ooooooooossy+/+:://oo-`                                                               "<<endl;   
    cout<<"                                                                                              /so/+sssssoossooooo++o+ooo++++++++++++/++oooosooooosyyos/-://o:                                                                 "<<endl;   
    cout<<"                                                                                             `ysooooosoo++/++++ooossoso+oo//////++++++oooooo+oooosyso+/+++o:`                                                                 "<<endl;   
    cout<<"                                                                                             `yysso+ooo+++++///++++++ssoo+:::::///+++ooooooooo+osys+//+++/.`                                                                  "<<endl;   
    cout<<"                                                                                              oysso++++////////+++///+oo+/:::///+/+++oooooooooooyy/+///oy+                                                                    "<<endl;   
    cout<<"                                                                                              :ysso+///////::/:://::///o+//////++++o+ooossoosssshho+++ohs.                                                                    "<<endl;   
    cout<<"                                                                                               oyso+//////::::-::::///+o+//+//++++ooooooososssyhmNy::o:.                                                                      "<<endl;   
    cout<<"                                                                                              `+hsoo+//://:::::://///+oo+++++++ooooosoooossssshdm:`                                                                           "<<endl;   
    cout<<"                                                                                  `.........:ohmdhyoo///+//+/////++oosss++++oooooosssssssssyyhmN+                                                                             "<<endl;   
    cout<<"                                                   `..........---:///////////+++++ossssysssyyhmNNNmhyooooooo+oo++osshyssoo+ooososssyssyyyyyhdmNd`                                                                             "<<endl;   
    cout<<"                                                  :ossssssssssssssssyyyyyyyyyyyyyyyyyyyyyyyyyhmNNNNmdhyyyhhysyyyyhhhhyyysssossssyyyhyyyhhhdmNNN-                                                                              "<<endl;   
    cout<<"                                                 `syyyyyyyyyyyyyyhhhhhhhhhhhhhhhhhhhhhhyyyyyyhmNNNMMmdhdhdddhddddddhhhhhyyyyyyhhhhddhhddmmmNNNN+`                                                                             "<<endl;   
    cout<<"                                                 `yyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyyyyyhdNMMMMNmdddhhhhhhhhhhyhhhhhhhhhhdddddmmmmmmmNNNmNNh-`                                                                           "<<endl;   
    cout<<"                                                 `yhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyyyyhhhmNMMMmmmdddhhhhhhhhhyyhyyhhhhhddddddddmmmmNNNmNNNNmyo.`                                                                        "<<endl;   
    cout<<"                                                 `yhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyyyhhhhhddNMNmmddddddhhhhhhhyyhhhyyhhhhhddddddmmmNNmmmNMNNmmdhyys/`                                                                    "<<endl;   
    cout<<"                                                 `yhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyyyyyhhhhhhhhmNNmmdddddddhhyyyyyhyyyyyyhyhhhhhhhdmdhhhhdmNNNmdddddhyys/:-.                                                                "<<endl;   
    cout<<"                                                 `yhhhhhhhhhhhhhhhhhhhhyyyyyhhhhhhhyyyyyyhhhhhhhhhdNmddddddddhyysssssssysyyysyyysso+/:::/+oydmmmddhhhhyyyyyyys/:::::.                                                         "<<endl;   
    cout<<"                                                 `yhhhhhhhhhhhhhyyyyyyyhhhhhhhhhhhyyyyyyyyhhhhhhhhhddhhhhs+++-..-:++ooooooooo+/:.````.-:/+ohdmmmddhhhhhhyyyyyyyyyyyyso+.                                                      "<<endl;   
    cout<<"                                                 `yhhhhhhhhhhhhyyyyyyyyyyyyhhhhhhhyyyyyyyyyhhhhhhhyh/://:`        `.-/++/::-``     `.-:/+oshdmmmddhhhhhhhyhhhhhhhhhhyyyy+..`                                                  "<<endl;   
    cout<<"                                                 `yhyhhhhyyyyyyyyyyyyyyyyyyyhhhhhyyyyyyyyyyyhhhhhhyy/``..`       ```..-..`        `.:///+shddmmddhhhhhhdddhhhhhhhhhhhhhhyyyo:```                                              "<<endl;   
    cout<<"                                                 `yhhhhhhhyyyyyyyyyyyyyyyyyyhhhhyhyyyyyyyyhhhhhhhhyy/```.`   `.:--.``````````   `.-:://+ohhhdmmdhhhhhdddddddhhhhhhhhhhhhhhhhhyyo:`                                            "<<endl;   
    cout<<"                                                 `//////////////////////////////////////////////////-  ``    .:--..``   ```..   ``....--:////++//////++++++//////////////////////-                                            "<<endl;
}

void menu(){
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmddhdhyyyssyyyyyyyysyyyhhdhdmmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNddhysyyssyyyyyhhhhdddddhhhhhyyyysssyyyhdmmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmdhyyssyyyhdmmmmmmdmmhdmyysyymmhydmmmmmddhyyssyyydmmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdhyysyyhdmmmmmmssmmm+-oh/smdh.ddm+/o+hmmmmsyyhdmdhyyssyyhmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMmdyysyyhdmmmydm:dmd.//dmy:h+-ommd.mmmsoo-hmmmmd:+yhmyyhdmdhysyyhmNMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMMMNdyyssydmmmmsyd./o.dms/hy+dmsmmhdmmmhmmmdhyhmmmmmh-mmm:ohy:dmmmdhyssyhmNMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMmhyssydmmmmmmmho+`ds:dmhdmddhhhyysoyyssyyyyyhhhddmmddmmm/shy-hmmmmhddhysyydNMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMNdhysyhmmdyooodmmmmdodmddhyysyhyo+oyyhhhhhhdddhyyshyysyyhdmmhyydmmmms-oshmdysyyhmMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMmyysydmmmm:smd:smmmmdhysyyyhddhyo+o+ooosooooooo+ossyyssssyyyshdmmmmms-so/:mmdmhsyyhNMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMmhysydmmd+hms/oo+dmdysshddhysoo++soyhhhyhhhddhhy++osyysssooosdmdysshdmdso+/md+/ohmhsyyhNMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMNhysydmmhmd+-+dmdmdysyyhhso++ssyh+odymmmmyhddmdho++ohmhhhddhysooossdyhyshmmmmh:++yssmmhsyydMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMhyysdmmdmo::hmshmhsshmds++oyshdddh/shydmmmdydmds+/+ydmmhyddmmdhhoss+++yddysydmds+ydmmmmmmysyymMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMNyysymmmd-hmdosmmhssdhyo+oodmmmhyhdy:+dyhddddyyh+:/ohddddyhmmmddys+smmys+osydhssdmmymmmmmmmmdssydMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMdyysdmmy/o+.dmmmyohmhs++shdhymmmmdyhy::hyhhdddhyy+:odydddhydmmmdyh+/hmdydhho+oydmsodmmmmdyso/dmysyyNMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMhyssmmmdd-oyoymdoymds+oyddddyshdddddyy:-/ydhhyhddymyhdyhhhdydmmhys//oddyhddmdhs++ymdosmmdss/+:mmmdoyymMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMyysymmmy+++.smmssyho/+sddddd+//+shdddhdo--/ho+syddydyddyhyddymmyho::+hhyhmmmmdhdho/+ydsohmmmo:mmmmmmsyymMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMyyshmmmmmmmmmmdodmy+/ymmhhyhdh/::::+yhhhdo---yho/hddshddyyhdmyhso:::ohdhhmmmmdyhhdmdo/odmssmmdmmmmmmmmsyymMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMhyshmmmmmmmmmmyodms+oymmmmmdhyhy+-----/oyhs/-./+sshddohddyyddd+:--:oyhddhmmdhyydddhmmhs++hmhodmmmmmmmmmmsyyNMMMMMM"<<endl;
    cout<<"                                                 MMMMMdysymmmmmmmmmmssdho+sdhyhddddddhhy/--:o/--:+h/../hyyhhhsdyyso/--:+syhdddyddhhhhhy+//ohhdhoosdhohmmmmmmmmmmsysNMMMMM"<<endl;
    cout<<"                                                 MMMMNsysmmmmmmmmmmssdho+yddddhyhhdddhhhds--:++/-.-/:../yhysdyyo/--:/shyyhddyshhddys+::::+hdddddo+sddodmmmmmmmmmdoyyMMMMM"<<endl;
    cout<<"                                                 MMMMsyommmmdhmmmmysmdoosyyyhhddhyhhhhhyhds-..os//-...../hyshy:..:shyyyhyssy++shs/:----:odmmmmddho+smm+dmmmmydmmmhsydMMMM"<<endl;
    cout<<"                                                 MMMdyohmmmo:-smmh+dhsossso++++oyhhhddhhso+s/..-ssyo-.```+syyo..:shyshhyyyo/ss:---/+:-/hmmmmddhhdho/ydh+mmm+-:ymmmsysNMMM"<<endl;
    cout<<"                                                 MMMsysmmmmd+shmm+yso+sddddhys+/::+yhhddyyyo++..-osyy+-.`.shs/`.osyyshyyhho/...:o/o:-+hddhhyhhddddd+/hhssmmhssmmmmdoyhMMM"<<endl;
    cout<<"                                                 MMhyodmmmmmmmmmsyys/+dmmmmmddhyo/-:+syhhh+syhs-`./sysy+:osss-``osyssyss/-..-+++y:--ohdhhyssooooosys/+dm+dmmmmmmmmmsysMMM"<<endl;
    cout<<"                                                 MMsyommmmmmmmmd+mso+yhhhddddddhhy+:-/yhyyhhysyy:``:sssososoo-``oosoo/-``-/osyy/..:y+oo/::::/+ossssso+ydhommmmmmmmmdoyhMM"<<endl;
    cout<<"                                                 MNosymmmmmmmmmssdsoohdhhhyyhhhhhhhs:--shyyyhhysy/``-osoooooo..:oos:.`.:oysyyo-../:/:---:oyyhyyhhhddh++oy+dmmmmmmmmmoyhMM"<<endl;
    cout<<"                                                 Mhsohhyyyyhhdd+yy+//ossyyyyssssyhhdh/--+sssssyyss/.:++++++//:/++++++/+oosso-.`.....--os/osssssyyssss//o+/oyyyyyyyyhsssMM"<<endl;
    cout<<"                                                 Msy+yso///soyy/ss/::/+++/oo+s//sosyhy::/:+oossso+o/:o//://:::://::/+:/o/+:/--+.-:++/:o+o+++/oo+/////::+++////////ossosNM"<<endl;
    cout<<"                                                 Msy+s++   -o++:o/   :+:/ +//o .soyhhyo:+ /::://::/- o::+-`-:::.`:/:+  :+:-+`.o/+/o.  o/++// o// :///:.`o/: ://///ossoyNM"<<endl;
    cout<<"                                                 Myyoy++ `: .o/+- :` :+// +::o .o+shhyo/+ /:.`````:- o:+. o:...:: +:+ /``/+o`.o//+-`s.`o//// o// /++++- o+: ////o+oyhoyNM"<<endl;
    cout<<"                                                 Myyoy++ .y/ `+.`+s` :o+/ +::o .o/osso+/+ //+ooo+:+- o:+` o.``../ /// o/:`.o`.o/+/ /++ `o/// +-/ .--  :++/: ::::++oyhoyNM"<<endl;
    cout<<"                                                 Msyoy++ .s++` .o/+` :+// +//o .s++ooo+/+ /++/+++/+- o::/ .:::::`.o:+ o--/-  .+-/ :::/: -o+/ o:/ +//+`.+++: ooooo+osy+yNM"<<endl;
    cout<<"                                                 Msy+yo+.-s++o:o/+o-./o++.o+/s--------o++.-------o+:.s/::/:-..--/+:/+.o////+.-so-:s///o/.+s/.oo+.o/::o-:ss/.------:soosNM"<<endl;
    cout<<"                                                 Mhs+hysssyyyyy//o+/+ooooossso++:+o+://-::----/+++/++o+++///////+++++//ooooo++oo+:::syssooo+oooooss+//++o++ooooooosyossMM"<<endl;
    cout<<"                                                 MNoohmddddmmmdosoo+shhhhyyyyyyyo::--..:/.../sssso/--:+ooo/-:++ooooo+.`:sysyysssys:-:syyyyyyysyyhhhhy++yh+ydddddddddoyhMM"<<endl;
    cout<<"                                                 MMyysmmmmmmmmmhody++hhyyhhhys+::-:/:sy--.:syyso:.``-/sos/.`/soososss/``-sysyhhyydh/--+yhhddddddhhhdy+oyd+mmmmmmmmmmoydMM"<<endl;
    cout<<"                                                 MMhsommmmmmmmmm+dms++ooo++////+oyhhy//.-/oyo/-..-/sysyss/``/ossooysyy+.`.ohyyyshyhy+--/shhdddmmmmmh++sysymmmmmmmmmyssMMM"<<endl;
    cout<<"                                                 MMMssymmmmmdmmmh+dh+/hddhhhyyyhhhdds--:oy/-..-+sysyysysy/``+yyo-.:osyyo:../so+yhddhyy/::+syhdddmmms/ysy+mmmmmmmmmmoydMMM"<<endl;
    cout<<"                                                 MMMdsodmmmy:/ymmssdy/+yhhhhdddmmmh+--+o--.-+:ohysyhyyhyy-..syys.``.-oyys/..-sy++yhddhhy+///osyyhhs++yh+dmms//dmmmyssNMMM"<<endl;
    cout<<"                                                 MMMMyssmmmy/:hmmmohmy+ohddddmmmdo:--::-:+o/soo+yyhyshhs/..:hhsho.....:oso/-.:/yhyhhhhhyhhysooooososdmsymmms:/hmmdosmMMMM"<<endl;
    cout<<"                                                 MMMMNoshmmmmmmmmmd+dmy+ohdddddy+::--:/shdhs+odhyyhdsh+-.-/sdyyyh+...:-.-/ho:--oddhhddddhyhdddddy+shmssmmmmmdmmmmssyMMMMM"<<endl;
    cout<<"                                                 MMMMMmsodmmmmmmmmmdohdyoohddys/:::+syhhhhhyddhyyhyo:--:+sdhhydyyyo..:/o:--:s+--+ydhhdddmdhyhddy+oddssmmmmmmmmmmyssMMMMMM"<<endl;
    cout<<"                                                 MMMMMMhsodmmmmmmmmmdoymho+yydmyoyhhyhhdmdyddhyso/--:oyhyhddshddyyh/../s+s+:-:---:shyhdmmmmmhho+sddsymmmmmmmmmmhssNMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMhsodmmmmmmmmmmssmmo/odmmdhyhddmmmyhhhy+:-:+sdddyyddmsdddy++yo--:ddyhs/:---:ydhhhdmmmh++hmdohmmmmmmmmmmhosmMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMhsodmmmmmm+smmhodyh+/shhhddmmmdyyhds:::+ymyddhhyddhhymdyyys++--+dhhddho/:::oddhhhyo/sdhyodmmmmmmmmmmhsymMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMdsohmmmd-/yohmmooddy++yddddddyhdds::oyhmmsdhhdhddymhhdhh+sdyo--ohhddddds++hmddhs+ohdy+ymmoosyyhmmmysyNMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMmssymms+so.hddmdoymds++shddhymmh//sydmmmshhddhhyyohydhdddhhh+-/hyddmmmdydddho+shmdssmmmms:+osdmdssyNMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMyssdmmh`/+ohmmmhoyhdysooyymmmo+shddmmdsdddddyo/:/yyhddddyhh::hdyhmmmmhhs++shdhssdmmmmmm+/mmmhssdMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMdsshmmdmmms:ymmmhsshmdyo+oydo+hddmddhydmmmdo//+hdyhdmmmhyd+/ddhhhddy++shmmysydmdsmmmmmmhmdyshNMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMNyssdmmd/o+oh+dmmdysydhhs+++oyhdddhdymmmy+/+sdmdhymmmmdyh++ddhyo++ohymdyshdmd+oshmdmmmmhssdMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMmyoydmdmd/:hdyyhmmdyssymdhsooossyhsdho+oyhdmddhhhmmmhyy+ooossydmhsoshdmdydm+-oyoymmhsshNMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMmysydmdymm:ohy:dmmmdhsyhhyyyso++ossooooosssyso+ooo++oyyhhhhhysyhdmmh+o+:ymh+ydmhsshNMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMdysshmmm/shy-dmmmddmddhyssssyhhhdydhhyyyyyyhhyssoydhhyssyhdmmmmmmh:/ss:dmmdhsshNMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMmhssydmhyydmmmmoodohmdmddhhyyssyyyhhyyyyyosssosyhhhdmmmdsooodmmmd/oydmhysydNMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMMMNmssshdmmmmmm:/+-os+dmdymmmmmmmdddddddhhdmmmmmmdyooym/omm:ommmmmmdysshmMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMNdyssydmmmssm/-smms/.hmmo/dmomdsossmdooohmmmhh/ommy/oo+dmmdhysshmNMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmyssshdmmhdmd+oy//mm-s:s.mmm:smmh/+++mmmmmh-mmmmdmdhyssyhmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmdhsssyhdmmmmdymd+md/:mmm/smmdoooommmmmmmmdhyysoydmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdhyosyyyhhddmmmmmmmdmmmmmmmmddhyyysosyhdNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmdhysyssosssssssssossyysyddmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl<<endl;
}             

void drawQuestion(HANDLE hConsole, int currentAnswer, int odpovedeSize[], string odpovede[]){
    // prve dva obdlzniky
    // riadok 1
    if(currentAnswer == 1) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<30;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    if(currentAnswer == 2) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<37;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    cout << endl;
    // riadok 2
    if(currentAnswer == 1) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    if(currentAnswer == 2) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 3
    if(currentAnswer == 1) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    if(currentAnswer == 2) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 4 odpovede a, b
    if(currentAnswer == 1) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<((68 - odpovedeSize[0])/2);i++) cout << " ";
    cout << "A: " << odpovede[0];
    if(odpovedeSize[0]% 2 == 1) cout << " ";
    for(int i=0;i<((68 - odpovedeSize[0])/2);i++) cout << " ";
    cout << static_cast<char>(254);
    if(currentAnswer == 2) SetConsoleTextAttribute(hConsole, 6);
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
    if(currentAnswer == 1) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    if(currentAnswer == 2) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 6
    if(currentAnswer == 1) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    if(currentAnswer == 2) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 7
    if(currentAnswer == 1) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<30;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    if(currentAnswer == 2) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<37;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    
    cout << endl << endl;


    // druhe dva obdlzniky
    // riadok 1
    if(currentAnswer == 3) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<30;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    if(currentAnswer == 4) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<37;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    cout << endl;
    // riadok 2
    if(currentAnswer == 3) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    if(currentAnswer == 4) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 3
    if(currentAnswer == 3) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    if(currentAnswer == 4) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 4 odpovede c, d
    if(currentAnswer == 3) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<((68 - odpovedeSize[2])/2);i++) cout << " ";
    cout << "C: " << odpovede[2];
    if(odpovedeSize[2]% 2 == 1) cout << " ";
    for(int i=0;i<((68 - odpovedeSize[2])/2);i++) cout << " ";
    cout << static_cast<char>(254);
    if(currentAnswer == 4) SetConsoleTextAttribute(hConsole, 6);
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
    if(currentAnswer == 3) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    if(currentAnswer == 4) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 6
    if(currentAnswer == 3) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    if(currentAnswer == 4) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 7
    if(currentAnswer == 3) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<30;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    if(currentAnswer == 4) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    for(int i=0;i<37;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    cout << endl << endl << endl << endl;
    
    SetConsoleTextAttribute(hConsole, 15);
}

void drawCQuestion(HANDLE hConsole, int odpovedeSize[], string odpovede[], string moznost, string spravnaOdpoved){
    // prve dva obdlzniky
    // riadok 1
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "a") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[0]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<30;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "b") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[1]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<37;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    cout << endl;
    // riadok 2
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "a") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[0]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "b") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[1]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 3
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "a") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[0]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "b") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[1]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 4 odpovede a, b
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "a") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[0]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<((68 - odpovedeSize[0])/2);i++) cout << " ";
    cout << "A: " << odpovede[0];
    if(odpovedeSize[0]% 2 == 1) cout << " ";
    for(int i=0;i<((68 - odpovedeSize[0])/2);i++) cout << " ";
    cout << static_cast<char>(254);
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "b") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[1]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<((68 - odpovedeSize[1])/2);i++) cout << " ";
    cout << "B: " << odpovede[1];
    if(odpovedeSize[1]% 2 == 1) cout << " ";
    for(int i=0;i<((68 - odpovedeSize[1])/2);i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 5
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "a") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[0]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "b") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[1]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 6
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "a") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[0]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "b") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[1]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 7
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "a") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[0]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<30;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "b") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[1]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<37;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    
    cout << endl << endl;


    // druhe dva obdlzniky
    // riadok 1
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "c") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[2]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<30;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "d") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[3]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<37;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    cout << endl;
    // riadok 2
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "c") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[2]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "d") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[3]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 3
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "c") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[2]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "d") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[3]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 4 odpovede c, d
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "c") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[2]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<((68 - odpovedeSize[2])/2);i++) cout << " ";
    cout << "C: " << odpovede[2];
    if(odpovedeSize[2]% 2 == 1) cout << " ";
    for(int i=0;i<((68 - odpovedeSize[2])/2);i++) cout << " ";
    cout << static_cast<char>(254);
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "d") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[3]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<((68 - odpovedeSize[3])/2);i++) cout << " ";
    cout << "D: " << odpovede[3];
    if(odpovedeSize[3]% 2 == 1) cout << " ";
    for(int i=0;i<((68 - odpovedeSize[3])/2);i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 5
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "c") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[2]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "d") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[3]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 6
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "c") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[2]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<30;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "d") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[3]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<37;i++)cout << " ";
    cout << static_cast<char>(254);
    for(int i=0;i<68;i++) cout << " ";
    cout << static_cast<char>(254);
    cout << endl;
    // riadok 7
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "c") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[2]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<30;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    SetConsoleTextAttribute(hConsole, 15);
    if(moznost == "d") SetConsoleTextAttribute(hConsole, 4);
    if(spravnaOdpoved == odpovede[3]) SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<37;i++)cout << " ";
    for(int i=0;i<70;i++) cout << static_cast<char>(254);
    cout << endl << endl << endl << endl;
    
    SetConsoleTextAttribute(hConsole, 15);
}

void drawPeniaze(HANDLE hConsole, int peniaze, int peniazePole[], bool correct = true){
    for(int i=0;i<91;i++) cout << " "; 
    if(peniaze < 0 && correct == false) SetConsoleTextAttribute(hConsole, 12);
    else if(peniaze > 0) SetConsoleTextAttribute(hConsole, 14);
    else if(peniaze == 0) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    cout << peniazePole[0] << " ";
    if(peniaze < 1 && correct == false) SetConsoleTextAttribute(hConsole, 12);
    else if(peniaze > 1) SetConsoleTextAttribute(hConsole, 14);
    else if(peniaze == 1) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    cout << peniazePole[1] << " ";
    if(peniaze < 2 && correct == false) SetConsoleTextAttribute(hConsole, 12);
    else if(peniaze > 2) SetConsoleTextAttribute(hConsole, 14);
    else if(peniaze == 2) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    cout << peniazePole[2] << " ";
    if(peniaze < 3 && correct == false) SetConsoleTextAttribute(hConsole, 12);
    else if(peniaze > 3) SetConsoleTextAttribute(hConsole, 14);
    else if(peniaze == 3) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    cout << peniazePole[3] << " ";
    if(peniaze < 4 && correct == false) SetConsoleTextAttribute(hConsole, 12);
    else if(peniaze > 4) SetConsoleTextAttribute(hConsole, 14);
    else if(peniaze == 4) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    cout << peniazePole[4] << " ";
    if(peniaze < 5 && correct == false) SetConsoleTextAttribute(hConsole, 12);
    else if(peniaze > 5) SetConsoleTextAttribute(hConsole, 14);
    else if(peniaze == 5) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    cout << peniazePole[5] << " ";
    if(peniaze < 6 && correct == false) SetConsoleTextAttribute(hConsole, 12);
    else if(peniaze > 6) SetConsoleTextAttribute(hConsole, 14);
    else if(peniaze == 6) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    cout << peniazePole[6] << " ";
    if(peniaze < 7 && correct == false) SetConsoleTextAttribute(hConsole, 12);
    else if(peniaze > 7) SetConsoleTextAttribute(hConsole, 14);
    else if(peniaze == 7) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    cout << peniazePole[7] << " ";
    if(peniaze < 8 && correct == false) SetConsoleTextAttribute(hConsole, 12);
    else if(peniaze > 8) SetConsoleTextAttribute(hConsole, 14);
    else if(peniaze == 8) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    cout << peniazePole[8] << " ";
    if(peniaze < 9 && correct == false) SetConsoleTextAttribute(hConsole, 12);
    else if(peniaze > 9) SetConsoleTextAttribute(hConsole, 14);
    else if(peniaze == 9) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    cout << peniazePole[9] << " ";
    if(peniaze < 10 && correct == false) SetConsoleTextAttribute(hConsole, 12);
    else if(peniaze > 10) SetConsoleTextAttribute(hConsole, 14);
    else if(peniaze == 10) SetConsoleTextAttribute(hConsole, 6);
    else SetConsoleTextAttribute(hConsole, 15);
    cout << peniazePole[10] << " ";
    cout << endl << endl << endl;
    SetConsoleTextAttribute(hConsole, 15);
}

void drawHistory(HANDLE hConsole,int peniaze, history historia[], int peniazePole[]){
    if(peniaze > 9) peniaze = 9;
    for(int i=0;i<peniaze+1;i++){
        cout << endl << "Otazka " << historia[i].cisloOtazky << endl << endl; 
        int idkBugProste = historia[i].otazkaSize;
        for(int i=0;i<(idkBugProste);i++) cout << " ";
        cout << "*** " << historia[i].otazka << " ***" << endl << endl << endl;
        string historiaOdpovede[] = {historia[i].odpovedA, historia[i].odpovedB, historia[i].odpovedC, historia[i].odpovedD};
        int odpovedeSize[] = {historia[i].odpovedASize, historia[i].odpovedBSize, historia[i].odpovedCSize, historia[i].odpovedDSize};
        drawCQuestion(hConsole, odpovedeSize, historiaOdpovede, historia[i].moznost, historia[i].spravnaOdpoved); 
        for(int i=0;i<237;i++) cout << "-";
    }

}
