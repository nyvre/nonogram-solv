#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "board.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void resizeEvent(QResizeEvent *event) override;

private:
    std::unique_ptr<Board> mBoard;
};
#endif // MAINWINDOW_H
