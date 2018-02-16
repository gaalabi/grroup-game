#include "Player.hpp"
player::player()
{
    _number = 0;
    _age = (rand() % 22) + 18;
    
    if(_age >= 41)
    {
        _age = 41;
    }
    else if(_age <= 19)
    {
        _age = 19;
    }
    
    _minutes = 0.0;
}
player::player(int n)
{
    _number = n;
    _age = (rand() % 22) + 18;
    
    if(_age >= 41)
    {
        _age = 41;
    }
    else if(_age <= 19)
    {
        _age = 19;
    }
    
    _minutes = 0.0;
    
}
int player::getAge() const
{
    return _age;
}
double player::getAgePer()
{
    return (_age*0.1);
}

int player::getNumber() const
{
    return _number;
}
double player::getPlayTime() const
{
    return _minutes;
}
void player::setNumber(int p)
{
    _number = p;
}
void player::updatePlayTime(double p)
{
    _minutes += p;
}
void player::NewLockerRoom(player r[])
{
    for(int i = 0; i < 12; i++)
    {
        r[i] = player(i);
        
    }
}
void player::print()
{
    cout << _number << "\t\t" << _age << "\t\t" << _minutes << endl;
}
player::~player()
{
    //dtor
}
