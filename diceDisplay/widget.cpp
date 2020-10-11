#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Würfler");
    this->setFixedSize(600, 400);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QGridLayout* diceLayout = new QGridLayout();
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    DiceDisplay* display = new DiceDisplay(new Dice(), diceLayout, 2);


    QList<int> cellTypes = QList<int>({4, 6, 8, 10, 12, 20});
    foreach(int cell, cellTypes)
    {
        display->AddCell(new Cell("<h1>" + QString::number(cell) + "er</h1>", 1, cell));
    }

    QPushButton* rollDiceButton = new QPushButton("Roll the dice!");
    QPushButton* closeButton = new QPushButton("Close");

    QObject::connect(rollDiceButton, SIGNAL(clicked()), display, SLOT(RollDiceForCells()));
    QObject::connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    buttonLayout->addWidget(rollDiceButton);
    buttonLayout->addWidget(closeButton);

    mainLayout->addLayout(diceLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

Widget::~Widget()
{
}

