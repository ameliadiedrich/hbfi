#ifndef CELL_H
#define CELL_H

#include<QLCDNumber>
#include<QLabel>
#include<QString>
#include<QVBoxLayout>
#include"dice.h"

class Cell
{
public:
    Cell(QString title, int from, int to);
    void RollDice(Dice* dice);

    QVBoxLayout* cellLayout = new QVBoxLayout();

private:
    QLabel* title;
    QLCDNumber* display;
    int from;
    int to;
};

#endif // CELL_H
