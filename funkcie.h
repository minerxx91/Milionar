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

void menu(){

    cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmddhdhyyyssyyyyyyyysyyyhhdhdmmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNddhysyyssyyyyyhhhhdddddhhhhhyyyysssyyyhdmmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmdhyyssyyyhdmmmmmmdmmhdmyysyymmhydmmmmmddhyyssyyydmmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdhyysyyhdmmmmmmssmmm+-oh/smdh.ddm+/o+hmmmmsyyhdmdhyyssyyhmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMmdyysyyhdmmmydm:dmd.//dmy:h+-ommd.mmmsoo-hmmmmd:+yhmyyhdmdhysyyhmNMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMMMNdyyssydmmmmsyd./o.dms/hy+dmsmmhdmmmhmmmdhyhmmmmmh-mmm:ohy:dmmmdhyssyhmNMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMmhyssydmmmmmmmho+`ds:dmhdmddhhhyysoyyssyyyyyhhhddmmddmmm/shy-hmmmmhddhysyydNMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMNdhysyhmmdyooodmmmmdodmddhyysyhyo+oyyhhhhhhdddhyyshyysyyhdmmhyydmmmms-oshmdysyyhmMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMmyysydmmmm:smd:smmmmdhysyyyhddhyo+o+ooosooooooo+ossyyssssyyyshdmmmmms-so/:mmdmhsyyhNMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMmhysydmmd+hms/oo+dmdysshddhysoo++soyhhhyhhhddhhy++osyysssooosdmdysshdmdso+/md+/ohmhsyyhNMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMNhysydmmhmd+-+dmdmdysyyhhso++ssyh+odymmmmyhddmdho++ohmhhhddhysooossdyhyshmmmmh:++yssmmhsyydMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMhyysdmmdmo::hmshmhsshmds++oyshdddh/shydmmmdydmds+/+ydmmhyddmmdhhoss+++yddysydmds+ydmmmmmmysyymMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMNyysymmmd-hmdosmmhssdhyo+oodmmmhyhdy:+dyhddddyyh+:/ohddddyhmmmddys+smmys+osydhssdmmymmmmmmmmdssydMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMdyysdmmy/o+.dmmmyohmhs++shdhymmmmdyhy::hyhhdddhyy+:odydddhydmmmdyh+/hmdydhho+oydmsodmmmmdyso/dmysyyNMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMhyssmmmdd-oyoymdoymds+oyddddyshdddddyy:-/ydhhyhddymyhdyhhhdydmmhys//oddyhddmdhs++ymdosmmdss/+:mmmdoyymMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMyysymmmy+++.smmssyho/+sddddd+//+shdddhdo--/ho+syddydyddyhyddymmyho::+hhyhmmmmdhdho/+ydsohmmmo:mmmmmmsyymMMMMMMMM"<<endl;
    cout<<"MMMMMMMyyshmmmmmmmmmmdodmy+/ymmhhyhdh/::::+yhhhdo---yho/hddshddyyhdmyhso:::ohdhhmmmmdyhhdmdo/odmssmmdmmmmmmmmsyymMMMMMMM"<<endl;
    cout<<"MMMMMMhyshmmmmmmmmmmyodms+oymmmmmdhyhy+-----/oyhs/-./+sshddohddyyddd+:--:oyhddhmmdhyydddhmmhs++hmhodmmmmmmmmmmsyyNMMMMMM"<<endl;
    cout<<"MMMMMdysymmmmmmmmmmssdho+sdhyhddddddhhy/--:o/--:+h/../hyyhhhsdyyso/--:+syhdddyddhhhhhy+//ohhdhoosdhohmmmmmmmmmmsysNMMMMM"<<endl;
    cout<<"MMMMNsysmmmmmmmmmmssdho+yddddhyhhdddhhhds--:++/-.-/:../yhysdyyo/--:/shyyhddyshhddys+::::+hdddddo+sddodmmmmmmmmmdoyyMMMMM"<<endl;
    cout<<"MMMMsyommmmdhmmmmysmdoosyyyhhddhyhhhhhyhds-..os//-...../hyshy:..:shyyyhyssy++shs/:----:odmmmmddho+smm+dmmmmydmmmhsydMMMM"<<endl;
    cout<<"MMMdyohmmmo:-smmh+dhsossso++++oyhhhddhhso+s/..-ssyo-.```+syyo..:shyshhyyyo/ss:---/+:-/hmmmmddhhdho/ydh+mmm+-:ymmmsysNMMM"<<endl;
    cout<<"MMMsysmmmmd+shmm+yso+sddddhys+/::+yhhddyyyo++..-osyy+-.`.shs/`.osyyshyyhho/...:o/o:-+hddhhyhhddddd+/hhssmmhssmmmmdoyhMMM"<<endl;
    cout<<"MMhyodmmmmmmmmmsyys/+dmmmmmddhyo/-:+syhhh+syhs-`./sysy+:osss-``osyssyss/-..-+++y:--ohdhhyssooooosys/+dm+dmmmmmmmmmsysMMM"<<endl;
    cout<<"MMsyommmmmmmmmd+mso+yhhhddddddhhy+:-/yhyyhhysyy:``:sssososoo-``oosoo/-``-/osyy/..:y+oo/::::/+ossssso+ydhommmmmmmmmdoyhMM"<<endl;
    cout<<"MNosymmmmmmmmmssdsoohdhhhyyhhhhhhhs:--shyyyhhysy/``-osoooooo..:oos:.`.:oysyyo-../:/:---:oyyhyyhhhddh++oy+dmmmmmmmmmoyhMM"<<endl;
    cout<<"Mhsohhyyyyhhdd+yy+//ossyyyyssssyhhdh/--+sssssyyss/.:++++++//:/++++++/+oosso-.`.....--os/osssssyyssss//o+/oyyyyyyyyhsssMM"<<endl;
    cout<<"Msy+yso///soyy/ss/::/+++/oo+s//sosyhy::/:+oossso+o/:o//://:::://::/+:/o/+:/--+.-:++/:o+o+++/oo+/////::+++////////ossosNM"<<endl;
    cout<<"Msy+s++   -o++:o/   :+:/ +//o .soyhhyo:+ /::://::/- o::+-`-:::.`:/:+  :+:-+`.o/+/o.  o/++// o// :///:.`o/: ://///ossoyNM"<<endl;
    cout<<"Myyoy++ `: .o/+- :` :+// +::o .o+shhyo/+ /:.`````:- o:+. o:...:: +:+ /``/+o`.o//+-`s.`o//// o// /++++- o+: ////o+oyhoyNM"<<endl;
    cout<<"Myyoy++ .y/ `+.`+s` :o+/ +::o .o/osso+/+ //+ooo+:+- o:+` o.``../ /// o/:`.o`.o/+/ /++ `o/// +-/ .--  :++/: ::::++oyhoyNM"<<endl;
    cout<<"Msyoy++ .s++` .o/+` :+// +//o .s++ooo+/+ /++/+++/+- o::/ .:::::`.o:+ o--/-  .+-/ :::/: -o+/ o:/ +//+`.+++: ooooo+osy+yNM"<<endl;
    cout<<"Msy+yo+.-s++o:o/+o-./o++.o+/s--------o++.-------o+:.s/::/:-..--/+:/+.o////+.-so-:s///o/.+s/.oo+.o/::o-:ss/.------:soosNM"<<endl;
    cout<<"Mhs+hysssyyyyy//o+/+ooooossso++:+o+://-::----/+++/++o+++///////+++++//ooooo++oo+:::syssooo+oooooss+//++o++ooooooosyossMM"<<endl;
    cout<<"MNoohmddddmmmdosoo+shhhhyyyyyyyo::--..:/.../sssso/--:+ooo/-:++ooooo+.`:sysyysssys:-:syyyyyyysyyhhhhy++yh+ydddddddddoyhMM"<<endl;
    cout<<"MMyysmmmmmmmmmhody++hhyyhhhys+::-:/:sy--.:syyso:.``-/sos/.`/soososss/``-sysyhhyydh/--+yhhddddddhhhdy+oyd+mmmmmmmmmmoydMM"<<endl;
    cout<<"MMhsommmmmmmmmm+dms++ooo++////+oyhhy//.-/oyo/-..-/sysyss/``/ossooysyy+.`.ohyyyshyhy+--/shhdddmmmmmh++sysymmmmmmmmmyssMMM"<<endl;
    cout<<"MMMssymmmmmdmmmh+dh+/hddhhhyyyhhhdds--:oy/-..-+sysyysysy/``+yyo-.:osyyo:../so+yhddhyy/::+syhdddmmms/ysy+mmmmmmmmmmoydMMM"<<endl;
    cout<<"MMMdsodmmmy:/ymmssdy/+yhhhhdddmmmh+--+o--.-+:ohysyhyyhyy-..syys.``.-oyys/..-sy++yhddhhy+///osyyhhs++yh+dmms//dmmmyssNMMM"<<endl;
    cout<<"MMMMyssmmmy/:hmmmohmy+ohddddmmmdo:--::-:+o/soo+yyhyshhs/..:hhsho.....:oso/-.:/yhyhhhhhyhhysooooososdmsymmms:/hmmdosmMMMM"<<endl;
    cout<<"MMMMNoshmmmmmmmmmd+dmy+ohdddddy+::--:/shdhs+odhyyhdsh+-.-/sdyyyh+...:-.-/ho:--oddhhddddhyhdddddy+shmssmmmmmdmmmmssyMMMMM"<<endl;
    cout<<"MMMMMmsodmmmmmmmmmdohdyoohddys/:::+syhhhhhyddhyyhyo:--:+sdhhydyyyo..:/o:--:s+--+ydhhdddmdhyhddy+oddssmmmmmmmmmmyssMMMMMM"<<endl;
    cout<<"MMMMMMhsodmmmmmmmmmdoymho+yydmyoyhhyhhdmdyddhyso/--:oyhyhddshddyyh/../s+s+:-:---:shyhdmmmmmhho+sddsymmmmmmmmmmhssNMMMMMM"<<endl;
    cout<<"MMMMMMMhsodmmmmmmmmmmssmmo/odmmdhyhddmmmyhhhy+:-:+sdddyyddmsdddy++yo--:ddyhs/:---:ydhhhdmmmh++hmdohmmmmmmmmmmhosmMMMMMMM"<<endl;
    cout<<"MMMMMMMMhsodmmmmmm+smmhodyh+/shhhddmmmdyyhds:::+ymyddhhyddhhymdyyys++--+dhhddho/:::oddhhhyo/sdhyodmmmmmmmmmmhsymMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMdsohmmmd-/yohmmooddy++yddddddyhdds::oyhmmsdhhdhddymhhdhh+sdyo--ohhddddds++hmddhs+ohdy+ymmoosyyhmmmysyNMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMmssymms+so.hddmdoymds++shddhymmh//sydmmmshhddhhyyohydhdddhhh+-/hyddmmmdydddho+shmdssmmmms:+osdmdssyNMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMyssdmmh`/+ohmmmhoyhdysooyymmmo+shddmmdsdddddyo/:/yyhddddyhh::hdyhmmmmhhs++shdhssdmmmmmm+/mmmhssdMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMdsshmmdmmms:ymmmhsshmdyo+oydo+hddmddhydmmmdo//+hdyhdmmmhyd+/ddhhhddy++shmmysydmdsmmmmmmhmdyshNMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMNyssdmmd/o+oh+dmmdysydhhs+++oyhdddhdymmmy+/+sdmdhymmmmdyh++ddhyo++ohymdyshdmd+oshmdmmmmhssdMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMmyoydmdmd/:hdyyhmmdyssymdhsooossyhsdho+oyhdmddhhhmmmhyy+ooossydmhsoshdmdydm+-oyoymmhsshNMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMmysydmdymm:ohy:dmmmdhsyhhyyyso++ossooooosssyso+ooo++oyyhhhhhysyhdmmh+o+:ymh+ydmhsshNMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMdysshmmm/shy-dmmmddmddhyssssyhhhdydhhyyyyyyhhyssoydhhyssyhdmmmmmmh:/ss:dmmdhsshNMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMmhssydmhyydmmmmoodohmdmddhhyyssyyyhhyyyyyosssosyhhhdmmmdsooodmmmd/oydmhysydNMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMMMNmssshdmmmmmm:/+-os+dmdymmmmmmmdddddddhhdmmmmmmdyooym/omm:ommmmmmdysshmMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMNdyssydmmmssm/-smms/.hmmo/dmomdsossmdooohmmmhh/ommy/oo+dmmdhysshmNMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmyssshdmmhdmd+oy//mm-s:s.mmm:smmh/+++mmmmmh-mmmmdmdhyssyhmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmdhsssyhdmmmmdymd+md/:mmm/smmdoooommmmmmmmdhyysoydmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdhyosyyyhhddmmmmmmmdmmmmmmmmddhyyysosyhdNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmdhysyssosssssssssossyysyddmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;

}