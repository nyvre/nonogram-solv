#include <QPainter>
#include "cell.h"

Cell::Cell(QWidget* parent, const int width, const int height)
{
    mCellRepresentation = std::make_shared<QLabel>(parent);
    mCellRepresentation->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    mCellRepresentation->setMinimumSize(20, 20);

    mCellPixmap = std::make_shared<QPixmap>(width, height);
    setBorder();
    mCellRepresentation->setPixmap(*mCellPixmap.get());
}

void Cell::fill()
{
    setColor(Qt::gray);
    mIsFilled = true;
}

void Cell::clear()
{
    setColor(Qt::white);
    mIsFilled = false;
}

bool Cell::isFilled()
{
    return mIsFilled;
}

void Cell::resize(const int width, const int height)
{
    mCellPixmap = std::make_shared<QPixmap>(width, height);
    setBorder();
    isFilled() ? fill() : clear();
    mCellRepresentation->setPixmap(*mCellPixmap.get());
}

std::shared_ptr<QLabel> Cell::getRepresentation()
{
    return mCellRepresentation;
}

void Cell::setColor(QBrush color)
{
    QPainter painter(mCellPixmap.get());
    painter.fillRect(1, 1, mCellPixmap->width() - 2, mCellPixmap->height() - 2, color);
    mCellRepresentation->setPixmap(*mCellPixmap.get());
}

void Cell::setBorder()
{
    QPainter painter(mCellPixmap.get());
    painter.fillRect(mCellPixmap.get()->rect(), QBrush(Qt::black));
    painter.fillRect(1, 1, mCellPixmap->width() - 2, mCellPixmap->height() - 2, QBrush(Qt::white));
    painter.end();
}

