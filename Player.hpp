#ifndef PLAYER_H
#define PLAYER_H
#include <cstdlib>
#include <iostream>

using namespace std;
class player
{
public:
    player();
    player(int n);
    int getNumber() const;
    int getAge() const;
    double getAgePer(); //get ten percent of an age
    double getPlayTime() const;
    void setNumber(int p);
    void updatePlayTime(double p);
    void NewLockerRoom(player r[]); //fill array with players (locker room)
    void print();
    virtual ~player();
    
protected:
    
private:
    
    int _number, _age;
    double _minutes;
};


#endif // PLAYER_H
