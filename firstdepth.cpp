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
    for (auto result : generateRowSolutions(QVector<int>{2, 1, 4}, 10)) {
        qDebug() <<result;
    }
    //generateNextRowSolution({1, 0, 0, 1});
}

QVector<QVector<bool>> FirstDepth::generateRowSolutions(QVector<int> rowHeader, int rowLength)
{
    if (rowLength <= 0) {
        return {};
    }
    if (rowHeader.length() == 0) {
        return QVector<QVector<bool>>{QVector<bool> (rowLength, false)};
    }
    int sumOfRowHeader = std::accumulate(rowHeader.begin(), rowHeader.end(), 0);
    QVector<QVector<bool>> vectorOfVectors {};
    if (rowLength > (sumOfRowHeader + rowHeader.length() - 1)) {
        QVector<QVector<bool>> resultFalse {generateRowSolutions(rowHeader, rowLength - 1)};
        for (auto result: resultFalse) {
            QVector<bool> trueResult {false};
            trueResult += result;
            vectorOfVectors.push_back(trueResult);
        }
    }
    int firstHeaderValue = rowHeader.takeFirst();
    QVector<bool> coloredVector(firstHeaderValue, true);
    if (coloredVector.length() < rowLength) {
        coloredVector.push_back(false);
    }
    QVector<QVector<bool>> resultTrue {generateRowSolutions(rowHeader, rowLength - firstHeaderValue - 1)};
    if (resultTrue.isEmpty()) {
        vectorOfVectors.push_back(coloredVector);
    } else {
        for (auto result: resultTrue) {
            vectorOfVectors.push_back(coloredVector + result);
        }
    }
    return vectorOfVectors;
}

bool FirstDepth::validateColumn(QVector<int> columnHeader, QVector<bool> column)
{

}


