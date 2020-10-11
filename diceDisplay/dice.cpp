#include "dice.h"

Dice::Dice()
{
    qsrand(uint(QTime::currentTime().msec()));
}

int Dice::RollByRange(int from, int to)
{
    return (rand() % (to - from + 1) + from);
}
