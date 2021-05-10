#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "cell.h"
class Board : public QWidget
{
    Q_OBJECT
public:
    Board(QWidget* parent);
public slots:
    void resize();
private:
    std::unique_ptr<QGridLayout> mLayout;
    QList<QList<std::shared_ptr<Cell>>> mBoard;
};

#endif // BOARD_H
