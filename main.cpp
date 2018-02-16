// Tony Tran: 50%
// Ganiyat: 50%
#include <iostream>
using namespace std;
#include "Player.hpp"
#include "benchPlayers.hpp"
#include "courtPlayers.hpp"
void SelectionSortNum(player Players[],int listLength){
    int highest_num_Index;
    player temp;
    for (int i = 0; i < listLength; i++){
        highest_num_Index = i;
        for (int j = i; j < listLength; j++){
            if(Players[highest_num_Index].getNumber() < Players[j].getNumber()){
                highest_num_Index = j;
            }
            temp = Players[i];
            Players[i] = Players[highest_num_Index];
            Players[highest_num_Index] = temp;
        }
    }
}

void SelectionSortHrs(player Players[],int listLength){
    int highest_num_Index;
    player temp;
    for (int i = 0; i < listLength; i++){
        highest_num_Index = i;
        for (int j = i; j < listLength; j++){
            if(Players[highest_num_Index].getPlayTime() < Players[j].getPlayTime()){
                highest_num_Index = j;
            }
            temp = Players[i];
            Players[i] = Players[highest_num_Index];
            Players[highest_num_Index] = temp;
        }
    }
}

void SelectionSortage(player Players[],int listLength){
    int highest_num_Index;
    player temp;
    for (int i = 0; i < listLength; i++){
        highest_num_Index = i;
        for (int j = i; j < listLength; j++){
            if(Players[highest_num_Index].getAge() < Players[j].getAge()){
                highest_num_Index = j;
            }
            temp = Players[i];
            Players[i] = Players[highest_num_Index];
            Players[highest_num_Index] = temp;
        }
    }
}



int main() {
    //initializing 12 members
    player Players[12];
    for(int i = 0; i < 12;i++){
        Players[i].setNumber(i+1);
    }
    //clock time
    double Time = 48.0;
    player temp1,temp2;
    bool AddBeginning = true;
    int counter = 48;
    
    
    
    benchPlayers B;
    B.addToBenchinBeginning(Players[0],Players[1],Players[2],Players[3],Players[4],Players[5],Players[6]);
    courtPlayers C;
    C.addToCourtinBeginning(Players[7],Players[8],Players[9],Players[10],Players[11]);
    
    while (Time > 0.0 && counter > 0){
        temp1 = C.removeOldPlayer(Time);
        if (AddBeginning){
            B.addtobeginning(temp1);
            temp2 = B.takein2ndplayer();
            AddBeginning = false;
        }
        else{
            B.addtoEnd(temp1);
            temp2 = B.takein6thplayer();
            AddBeginning = true;
        }
        C.insertNewPlayer(temp2);
        counter--;
    }
    
    //giving back the players
    B.ReturnPlayers(Players[0],Players[1],Players[2],Players[3],Players[4],Players[5],Players[6]);
    C.ReturnPlayers(Players[7],Players[8],Players[9],Players[10],Players[11]);
    
    
    //printing
    //by numbers
    SelectionSortNum(Players, 12);
    cout<<"By numbers"<<endl;
    cout<<"#\t\tage\t\thrs Played"<<endl<<endl;
    for(int i = 0; i < 12;i++){
        Players[i].print();
    }
    cout<<endl<<endl;
    //by hours
    SelectionSortHrs(Players, 12);
    cout<<"By hrs"<<endl;
    cout<<"#\t\tage\t\thrs Played"<<endl<<endl;
    for(int i = 0; i < 12;i++){
        Players[i].print();
    }
    cout<<endl<<endl;
    //by age
    SelectionSortage(Players, 12);
    cout<<"By age"<<endl;
    cout<<"#\t\tage\t\thrs Played"<<endl<<endl;
    for(int i = 0; i < 12;i++){
        Players[i].print();
    }
    cout<<endl<<endl;
    
    
    return 0;
}
