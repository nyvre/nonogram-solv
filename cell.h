#ifndef CELL_H
#define CELL_H

#include <QLabel>
#include <QPixmap>
class Cell
{
public:
    explicit Cell(QWidget* parent, const int width, const int height);
    void fill();
    void clear();
    bool isFilled();
    void resize(const int width, const int height);
    int getSideLength();
    std::shared_ptr<QLabel> getRepresentation();

private:
    void setColor(QBrush color);
    void setBorder();
    bool mIsFilled = false;
    std::shared_ptr<QPixmap> mCellPixmap;
    std::shared_ptr<QLabel> mCellRepresentation;
};

#endif // CELL_H
