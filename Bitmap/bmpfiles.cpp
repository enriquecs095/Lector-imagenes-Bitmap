#include "bmpfiles.h"
#include "ui_bmpfiles.h"


BMPFiles::BMPFiles(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BMPFiles){
    ui->setupUi(this);
    char File[54];
    FileHeader fileHeader;
    fileBMP.open("/home/enriquecs/Documents/ExamplesEstru2/Proyecto1/resources/imagen16.bmp",std::ifstream::in | std::ifstream::binary);
    if(fileBMP.fail()){
    return;
    }
    fileBMP.read(File,sizeof(File));
    fileHeader.type[0]=File[0];
    fileHeader.type[1]=File[1];
    char size[4];
    size[0]=File[2];
    size[1]=File[3];
    size[2]=File[4];
    size[3]=File[5];
    memcpy(&fileHeader.size,size,4);
    fileHeader.reserved1[0]=File[6];
    fileHeader.reserved1[1]=File[7];
    fileHeader.reserved2[0]=File[8];
    fileHeader.reserved2[1]=File[9];
    char info[4];
    info[0]=File[10];
    info[1]=File[11];
    info[2]=File[12];
    info[3]=File[13];
    memcpy(&fileHeader.info,info,4);
    char Head[4];
    Head[0]=File[14];
    Head[1]=File[15];
    Head[2]=File[16];
    Head[3]=File[17];
    memcpy(&fileHeader.sizeHead,Head,4);
    char Widht[4];
    Widht[0]=File[18];
    Widht[1]=File[19];
    Widht[2]=File[20];
    Widht[3]=File[21];
    memcpy(&fileHeader.widht,Widht,4);
    char Height[4];
    Height[0]=File[22];
    Height[1]=File[23];
    Height[2]=File[24];
    Height[3]=File[25];
    memcpy(&fileHeader.height,Height,4);
    char Planos[2];
    Planos[0]=File[26];
    Planos[1]=File[27];
    memcpy(&fileHeader.numberP,Planos,2);
    char Pixel[2];
    Pixel[0]=File[28];
    Pixel[1]=File[29];
    memcpy(&fileHeader.sizeP,Pixel,2);
    char Compresion[4];
    Compresion[0]=File[30];
    Compresion[1]=File[31];
    Compresion[2]=File[32];
    Compresion[3]=File[33];
    memcpy(&fileHeader.compresion,Compresion,4);
    char SImage[4];
    SImage[0]=File[34];
    SImage[1]=File[35];
    SImage[2]=File[36];
    SImage[3]=File[37];
    memcpy(&fileHeader.sizeImage,SImage,4);
    char ResoX[4];
    ResoX[0]=File[38];
    ResoX[1]=File[39];
    ResoX[2]=File[40];
    ResoX[3]=File[41];
    memcpy(&fileHeader.resoX,ResoX,4);
    char ResoY[4];
    ResoY[0]=File[42];
    ResoY[1]=File[43];
    ResoY[2]=File[44];
    ResoY[3]=File[45];
    memcpy(&fileHeader.resoY,ResoY,4);
    char sizeColor[4];
    sizeColor[0]=File[46];
    sizeColor[1]=File[47];
    sizeColor[2]=File[48];
    sizeColor[3]=File[49];
    memcpy(&fileHeader.sizeTableColor,sizeColor,4);
    char CountColor[4];
    CountColor[0]=File[50];
    CountColor[1]=File[51];
    CountColor[2]=File[52];
    CountColor[3]=File[53];
    memcpy(&fileHeader.countColor,CountColor,4);
    if(fileHeader.sizeP==8){
       show8bits(fileHeader.widht,fileHeader.height,fileHeader.info);
    }else if(fileHeader.sizeP==16){
         show16bits(fileHeader.widht,fileHeader.height,fileHeader.info);
    }else{
          show24bits(fileHeader.widht,fileHeader.height,fileHeader.info);
    }
}



void BMPFiles::show8bits(uint32_t W, uint32_t H, uint32_t I){
uint32_t sizeP=W*H;
char datos[sizeP];
fileBMP.seekg(I,std::ios::beg);
fileBMP.read(datos, sizeof(datos));
fileBMP.close();
float *Color=new float[sizeP];
QImage *image=new QImage(W,H,QImage::Format_Grayscale8);
int count=0;
for (int i =0; i < sizeP; i++){
    Color[count]=datos[i];
    count++;
   }
    count=0;
           for(int j=H-1;j>=0;j--){
                for(int i=0; i<W;i++){
               image->setPixel(i,j,qRgb(Color[count],Color[count],Color[count]));
           count++;
   }
}
QGraphicsScene *graphic=new QGraphicsScene(this);
graphic->addPixmap(QPixmap::fromImage(*image));
ui->graphicsView->setScene(graphic);
delete []Color;
}



void BMPFiles::show16bits(uint32_t W, uint32_t H, uint32_t I){
uint32_t sizeP=2*W*H;
char datos[sizeP];
fileBMP.seekg(I,std::ios::beg);
fileBMP.read(datos, sizeof(datos));
fileBMP.close();
uint16_t *R=new uint16_t[sizeP];
uint16_t *G=new uint16_t[sizeP];
uint16_t *conversionR=new uint16_t[sizeP];
uint16_t *conversionG=new uint16_t[sizeP];
uint16_t *conversionB=new uint16_t[sizeP];
QImage *image=new QImage(W,H,QImage::Format_RGB16);
int count=0;
for (int i =0; i < sizeP; i+=2){
   R[count]=datos[i];
   G[count]=datos[i+1];
   conversionR[count]=(datos[i] & 0x1FF)>>5;
   conversionG[count]=(datos[i] & 0x1FF)>>10;
   conversionB[count]=(datos[i+1] & 0x1FF)>>6;
   count++;
}
  count=0;
           for(int j=H-1;j>=0;j--){
                for(int i=0; i<W;i++){
               image->setPixel(i,j,qRgb(conversionR[count],conversionG[count],conversionB[count]));
            count++;
            }
        }
QGraphicsScene *graphic=new QGraphicsScene(this);
graphic->addPixmap(QPixmap::fromImage(*image));
ui->graphicsView->setScene(graphic);
delete []R;
delete []G;
}


void BMPFiles::show24bits(uint32_t W, uint32_t H, uint32_t I){
uint32_t sizeP=3*W*H;
char datos[sizeP];
fileBMP.seekg(I,std::ios::beg);
fileBMP.read(datos, sizeof(datos));
fileBMP.close();
float *R=new float[sizeP];
float *G=new float[sizeP];
float *B=new float[sizeP];
QImage *image=new QImage(W,H,QImage::Format_RGB666);
int count=0;
for (int i =0; i < sizeP; i+=3){
   R[count]=datos[i];
   G[count]=datos[i+1];
   B[count]=datos[i+2];
   count++;
   }
  count=0;
           for(int j=H-1;j>=0;j--) {
                for(int i=0; i<W;i++) {
                   image->setPixel(i,j,qRgb(B[count],G[count],R[count]));
                  count++;
   }
         count++;
}
QGraphicsScene *graphic=new QGraphicsScene(this);
graphic->addPixmap(QPixmap::fromImage(*image));
ui->graphicsView->setScene(graphic);
delete []B;
delete []G;
delete []R;
}




BMPFiles::~BMPFiles()
{
    delete ui;
}
