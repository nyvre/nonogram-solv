#ifndef FIRSTDEPTH_H
#define FIRSTDEPTH_H

#include <QVector>
class FirstDepth
{
public:
    FirstDepth();
    bool isRowFulfilled(int rowIndex);
    bool isColumnViolated();
    bool areAllRowFulfilled();
    QVector<QVector<bool>> generateRowSolutions(QVector<int> rowHeader, int rowLength);
    QVector<bool> getColoredVector(int length);
    bool validateColumn(QVector<int> columnHeader, QVector<bool>column);
private:
    QVector<QVector<bool>> mBoard;
    QVector<QVector<int>> mRowHeader;
    QVector<QVector<int>> mColumnHeader;
};

#endif // FIRSTDEPTH_H
