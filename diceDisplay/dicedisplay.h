#ifndef DICEDISPLAY_H
#define DICEDISPLAY_H

#include<QObject>
#include<QList>
#include<QBoxLayout>
#include"cell.h"

class DiceDisplay : public QObject
{
    Q_OBJECT

public:
    DiceDisplay(Dice* dice, QGridLayout* layout, int columnsPerRow);
    void AddCell(Cell* cell);

public slots:
    void RollDiceForCells();

private:
    Dice* _dice;
    QList<Cell*> _cellList = QList<Cell*>();
    QGridLayout* _layout;
    int _columnsPerRow;

    /*I decided to make this function private, in order to take the resposibility of allocating the cells from the user of the class.
    (the cells get allocated automatically, without the user doing anything!)*/
    void AllocateCells();
};

#endif // DICEDISPLAY_H
