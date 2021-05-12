#include <QVector>
#include <QDebug>
#include "firstdepth.h"
FirstDepth::FirstDepth()
{
    for (int i = 0; i < 10; ++i) {
        QVector<int> test {1};
        mRowHeader.push_back(test);
        mColumnHeader.push_back(test);
    }
    for (int i = 0; i < 10; ++i) {
        QVector<bool> row;
        for (int j = 0; j < 10; ++j) {
            row.push_back(false);
        }
        mBoard.push_back(row);
    }
    for (auto result : generateRowSolutions(QVector<int>{1, 1, 1}, 100)) {
        //qDebug() <<result;
    }
    //generateNextRowSolution({1, 0, 0, 1});
}

QVector<QVector<bool>> FirstDepth::generateRowSolutions(QVector<int> rowHeader, int rowLength)
{
    int sum = 0;
    for (int number : rowHeader){
        sum+=number;
    }
    QVector<QVector<bool>> vectorOfVectors {};
    if (rowLength <= 0) {
        return {};
    }
    if (rowLength - (sum + rowHeader.length() - 1) > 0) {
        QVector<QVector<bool>> resultFalse {generateRowSolutions(rowHeader, rowLength - 1)};
        for (auto result: resultFalse) {
            QVector<bool> trueResult {false};
            trueResult+=result;
            vectorOfVectors.push_back(trueResult);
        }
    }
    if (rowHeader.length() == 0){
        QVector<bool> dummyReturn (rowLength, false);
        return QVector<QVector<bool>>{dummyReturn};
    }
    int firstHeaderValue = rowHeader.front();
    rowHeader.pop_front();
    QVector<bool> dummyResult;
    for (int i = 0; i < firstHeaderValue; ++i) {
        dummyResult.push_back(true);
    }
    if (dummyResult.length() < rowLength) {
        dummyResult.push_back(false);
    }
    QVector<QVector<bool>> resultTrue {generateRowSolutions(rowHeader, rowLength - firstHeaderValue - 1)};
    if (resultTrue.isEmpty()) {
        vectorOfVectors.push_back(dummyResult);
    } else {
        for (auto result: resultTrue) {
                 vectorOfVectors.push_back(dummyResult+result);
        }
    }
    return vectorOfVectors;


}
