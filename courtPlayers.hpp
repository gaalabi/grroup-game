//
//  courtPlayers.hpp
//  Project4
//
//  Created by Tony Tran on 2/16/18.
//  Copyright © 2018 Tonney7. All rights reserved.
//

#ifndef courtPlayers_hpp
#define courtPlayers_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
#include "Player.hpp"

struct node{
    node * prev;
    player n;
    node * next;
};


class courtPlayers: public player {
private:
    node * head;
public:
    courtPlayers(){}
    void addToCourtinBeginning(player p1,player p2,player p3,player p4,player p5){
        node *cu = new node;
        node* temp = new node;
        head = cu;
        //player 1
        cu->n = p1;
        cu->prev = nullptr;
        cu->next = temp;
        //player 2
        temp->n = p2;
        temp->prev = cu;
        temp->next = new node;
        temp = temp->next;
        cu = cu->next;
        //player 3
        temp->n = p3;
        temp->prev = cu;
        temp->next = new node;
        temp = temp->next;
        cu = cu->next;
        //player 4
        temp->n = p4;
        temp->prev = cu;
        temp->next = new node;
        temp = temp->next;
        cu = cu->next;
        //player 5
        temp->n = p5;
        temp->prev = cu;
        temp->next = head;
        
        //getting rid of nullptr from begining
        cu = head;
        cu->prev = temp;
        
    }
    
    void insertNewPlayer(player P){
        node * cu = head;
        node * temp = new node;
        temp->n = P;
        //setting next and prev for temp
        temp ->next = cu;
        temp->prev = cu->prev;
        
        //setting next and prev for circle list
        head->prev->next = temp;
        head->prev = temp;
        
    }
    player removeOldPlayer(double &timeLeft){
        node * cu = head;
        node * temp = cu;
        //find oldest member
        for (int i = 0; i < 5; i++){
            if (cu->n.getAge() < temp->n.getAge()){
                cu = temp;
            }
            temp = temp->next;
        }
        
        
        
        //add hours to each member
        temp = head;
        for (int i = 0; i < 5; i++){
            if(timeLeft < cu->n.getAgePer()){
                temp->n.updatePlayTime(timeLeft);
            }
            else{
                temp->n.updatePlayTime(cu->n.getAgePer());
            }
            temp = temp->next;
        }
        timeLeft -= cu->n.getAgePer();
        player Player = cu->n;
        
        //deleting pointer
        if (head == cu){
            head = cu->next;
        }
        
        cu->next->prev = cu->prev;
        cu->prev->next = cu->next;
        return Player;
    }
    //returning the players to regular
    void ReturnPlayers(player &p1,player &p2,player &p3,player &p4,player &p5){
        node *cu = new node;
        cu = head;
        p1 = cu->n;
        p2 = cu->next->n;
        p3 = cu->next->next->n;
        p4 = cu->next->next->next->n;
        p5 = cu->next->next->next->next->n;
        //return Player1,Player2,Player3,Player4,Player5;
    }
};

#endif /* courtPlayers_hpp */
