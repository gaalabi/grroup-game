//
//  benchPlayers.hpp
//  Project4
//
//  Created by Tony Tran on 2/16/18.
//  Copyright © 2018 Tonney7. All rights reserved.
//

#ifndef benchPlayers_hpp
#define benchPlayers_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
#include "Player.hpp"


struct Node{
    Node * prev;
    player n;
    Node * next;
};


class benchPlayers: public player {
private:
    Node * head;
    Node * tail;
public:
    benchPlayers(){}
    void addToBenchinBeginning(player p1,player p2,player p3,player p4,player p5,player p6,player p7){
        Node *cu = new Node;
        Node* temp = new Node;
        head = cu;
        //player 1
        cu->n = p1;
        cu->prev = nullptr;
        cu->next = temp;
        //player 2
        temp->n = p2;
        temp->prev = cu;
        temp->next = new Node;
        temp = temp->next;
        cu = cu->next;
        //player 3
        temp->n = p3;
        temp->prev = cu;
        temp->next = new Node;
        temp = temp->next;
        cu = cu->next;
        //player 4
        temp->n = p4;
        temp->prev = cu;
        temp->next = new Node;
        temp = temp->next;
        cu = cu->next;
        //player 5
        temp->n = p5;
        temp->prev = cu;
        temp->next = new Node;
        temp = temp->next;
        cu = cu->next;
        //player 6
        temp->n = p6;
        temp->prev = cu;
        temp->next = new Node;
        temp = temp->next;
        cu = cu->next;
        //player 7
        temp->n = p7;
        temp->prev = cu;
        temp->next = nullptr;
        tail = temp;
    }
    //from top
    void addtobeginning(player P){
        Node * cu = new Node;
        cu->n = P;
        cu->prev = nullptr;
        cu->next = head;
        head->prev = cu;
        head = cu;
    }
    player takein2ndplayer(){
        Node * cu = head->next->next;
            //the 3rd person in list  [just added player][1][2][3][4][5][6][7], getting the #2
        player Player = cu->n;
        Delete(cu);
        return Player;
    }
    
    //from bottom
    void addtoEnd(player P){
        Node * cu = new Node;
        cu->n = P;
        cu->prev = tail;
        cu->next = nullptr;
        tail->next = cu;
        tail = cu;
    }
    player takein6thplayer(){
        Node * cu = tail->prev->prev;
        //the 6th person in list  [1][2][3][4][5][6][7][just added player], getting the #6
        player Player = cu->n;
        Delete(cu);
        return Player;
    }
    
    //delete
    void Delete(Node *p){
        Node * cu = p;
        cu->prev->next = cu->next;
        cu->next->prev = cu->prev;
    }
    void ReturnPlayers(player &p1,player &p2,player &p3,player &p4,player &p5,player &p6,player &p7){
        Node *cu = new Node;
        cu = head;
        p1 = cu->n;
        p2 = cu->next->n;
        p3 = cu->next->next->n;
        p4 = cu->next->next->next->n;
        p5 = cu->next->next->next->next->n;
        p6 = cu->next->next->next->next->next->n;
        p7 = cu->next->next->next->next->next->next->n;
        //return Player1,Player2,Player3,Player4,Player5,Player6,Player7;
    }
};
#endif /* benchPlayers_hpp */
