#ifndef BMPFILES_H
#define BMPFILES_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <fstream>

struct FileHeader{
char type[3];
uint32_t size;
char reserved1[2];
char reserved2[2];
uint32_t info;
//-----
uint32_t sizeHead;
uint32_t widht;
uint32_t height;
uint16_t numberP;
uint16_t sizeP; //tamaño pixel
uint32_t compresion;
uint32_t sizeImage;
uint32_t resoX;
uint32_t resoY;
uint32_t sizeTableColor;
uint32_t countColor;

FileHeader(){
type[2]=0;
}
};



namespace Ui {
class BMPFiles;
}

class BMPFiles : public QMainWindow
{
    Q_OBJECT

public:
    explicit BMPFiles(QWidget *parent = nullptr);
    ~BMPFiles();

private:
    Ui::BMPFiles *ui;
     std::ifstream fileBMP;
    void show8bits(uint32_t, uint32_t, uint32_t);
    void show16bits(uint32_t, uint32_t, uint32_t);
    void show24bits(uint32_t, uint32_t, uint32_t);
};

#endif // BMPFILES_H
