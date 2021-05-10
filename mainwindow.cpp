#include <QResizeEvent>
#include "mainwindow.h"
#include "board.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    mBoard = std::make_unique<Board>(parent);
    setCentralWidget(mBoard.get());
    connect(this, &MainWindow::resizeEvent, mBoard.get(), &Board::resize);
    mBoard->show();
    setGeometry(geometry().x(), geometry().y(), 218, 218);
}

MainWindow::~MainWindow()
{
}

