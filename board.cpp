#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QPainter>
#include <QDebug>

#include "board.h"
#include "cell.h"
#include "firstdepth.h"
Board::Board(QWidget* parent)
    : QWidget(parent)
{
    mLayout = std::make_unique<QGridLayout>(this);
    mLayout->setSpacing(0);
    for (int rowIndex = 0; rowIndex < 10; ++rowIndex) {
        QList <std::shared_ptr<Cell>> row;
        for (int columnIndex = 0; columnIndex < 10; ++columnIndex) {
            auto cell = std::make_shared<Cell>(this, 20, 20);
            mLayout->addWidget(cell->getRepresentation().get(), rowIndex, columnIndex);
            row.append(cell);
            cell->fill();
            cell->getRepresentation()->show();
        }
        mBoard.append(row);
    }
    setLayout(mLayout.get());
    FirstDepth algorithm;
}

void Board::resize()
{
    for (int rowIndex = 0; rowIndex < 10; ++rowIndex) {
        for (int columnIndex = 0; columnIndex < 10; ++columnIndex) {
            auto cell = mBoard[rowIndex][columnIndex];
            cell.get()->resize(cell->getRepresentation()->width(), cell->getRepresentation()->height());
        }
    }
}

