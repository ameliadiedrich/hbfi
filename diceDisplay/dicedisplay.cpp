#include "dicedisplay.h"

DiceDisplay::DiceDisplay(Dice* dice, QGridLayout* layout, int columnsPerRow)
{
    this->_dice = dice;
    this->_layout = layout;
    this->_columnsPerRow = columnsPerRow;
}

void DiceDisplay::AddCell(Cell* cell)
{
    _cellList.append(cell);
    AllocateCells();
}

void DiceDisplay::AllocateCells()
{
    //Allocates the cells in the QGridLayout
    int currentRow = 1;
    int currentColumn = 1;
    for(int i = 0; i < _cellList.count(); i++)
    {
        this->_layout->addLayout(_cellList.at(i)->cellLayout, currentRow, currentColumn);
        if(currentColumn == _columnsPerRow)
        {
            currentRow++;
            currentColumn = 0;
        }
        currentColumn++;
    }
}

void DiceDisplay::RollDiceForCells()
{
    foreach(Cell* cell, _cellList)
    {
        cell->RollDice(this->_dice);
    }
}
