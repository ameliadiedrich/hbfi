#ifndef DICE_H
#define DICE_H

#include<QRandomGenerator>
#include<QTime>

class Dice
{
public:
    Dice();
    int RollByRange(int from, int to);
};

#endif // DICE_H
