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
        int getAgePer(); //get ten percent of an age
        int getPlayTime() const;
        void setPlayTime(int p);
        void NewLockerRoom(player r[]); //fill array with players (locker room)
        void print();
        virtual ~player();

    protected:

    private:

        int _number, _age, _minutes;
};


#endif // PLAYER_H
