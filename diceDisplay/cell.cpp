#include "cell.h"

Cell::Cell(QString title, int from, int to)
{
    this->title = new QLabel(title);
    this->display = new QLCDNumber();

    /*I know I could have just assigned an individual dice to each cell, however,
    I tried to challenge myself to do this exercise with one dice instance only */
    this->from = from;
    this->to = to;

    this->cellLayout->addWidget(this->title);
    this->cellLayout->addWidget(this->display);
}

void Cell::RollDice(Dice *dice)
{
    display->display(dice->RollByRange(this->from, this->to));
}
