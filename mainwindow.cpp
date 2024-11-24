#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadRawImage("/Users/ashutoshrajpal/Creator/MedicalImageEnhancer/barbara_gray.raw");
    setSliderRanges();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete[] img;
}

void MainWindow::on_pushButton_Reset_clicked()
{
    updateSliders(min, max, mid, mid, 0);
}

void MainWindow::on_horizontalScrollBar_Min_valueChanged(int value)
{
    updateSliders(value, ui->horizontalScrollBar_Max->value(), ui->horizontalScrollBar_Bri->value(), ui->horizontalScrollBar_Con->value(), 1);
}

void MainWindow::on_horizontalScrollBar_Max_valueChanged(int value)
{
    updateSliders(ui->horizontalScrollBar_Min->value(), value, ui->horizontalScrollBar_Bri->value(), ui->horizontalScrollBar_Con->value(), 2);
}

void MainWindow::on_horizontalScrollBar_Bri_valueChanged(int value)
{
    updateSliders(ui->horizontalScrollBar_Min->value(), ui->horizontalScrollBar_Max->value(), value, ui->horizontalScrollBar_Con->value(), 3);
}

void MainWindow::on_horizontalScrollBar_Con_valueChanged(int value)
{
    updateSliders(ui->horizontalScrollBar_Min->value(), ui->horizontalScrollBar_Max->value(), ui->horizontalScrollBar_Bri->value(), value, 4);
}

void MainWindow::findMinMax()
{
    min = max = img[0];
    for (int i = 0; i < height * width; ++i) {
        if (img[i] < min) {
            min = img[i];
        }
        if (img[i] > max) {
            max = img[i];
        }
    }
    mid = round((max + min) / 2.0);
}

void MainWindow::setSliderRanges()
{
    count = 1;
    ui->horizontalScrollBar_Min->setRange(min, max);
    ui->horizontalScrollBar_Max->setRange(min, max);
    ui->horizontalScrollBar_Bri->setRange(min, max);
    ui->horizontalScrollBar_Con->setRange(min, max);
    count = 0;
}

void MainWindow::displayImage(int a, int b)
{
    if (a == b) {
        alpha = max - min;
    }
    else {
        alpha = (max - min) * 1.0 / (b - a);
    }
    beta = min - alpha * a;

    cv::Mat imgBuff = cv::Mat(height, width, CV_8UC1, img);
    cv::Mat imgNew;
    imgBuff.convertTo(imgNew, -1, alpha, beta);

    QImage image(imgNew.data, imgNew.cols, imgNew.rows, static_cast<int>(imgNew.step), QImage::Format_Indexed8);
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(item);

    QVector<double> x(max-min+1), y(max-min+1);
    for (int i = min; i < max; ++i) {
        x[i-min] = i;
        y[i-min] = alpha * x[i-min] + beta;
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    ui->widget->xAxis->setRange(min, max);
    ui->widget->yAxis->setRange(min, max);
    ui->widget->replot();
}

void MainWindow::loadRawImage(const std::string &path)
{
    height = width = 512;
    img = new (std::nothrow) unsigned char[height * width];
    FILE *file = fopen(path.c_str(), "rb");
    if (file == nullptr){
        qDebug() << "File is empty";
        return;
    }
    fread(img, sizeof(unsigned char), height * width, file);
    fclose(file);
    findMinMax();
}

void MainWindow::updateSliders(int a, int b, int c, int d, int e)
{
    count++;
    if (count == 1) {
        switch (e) {
        case 1: b = std::max(a, b); c = min + round((max + (max - b) - a) / 2.0); d = round((max + (max - b) + a) / 2.0); break;
        case 2: a = std::min(a, b); c = min + round((max + (max - b) - a) / 2.0); d = round((max + (max - b) + a) / 2.0); break;
        case 3: a = min + d - c; b = max + (max + min - d - c); break;
        case 4: a = min + d - c; b = max + (max + min - d - c); break;
        }
        if (a < 0) {
            ui->label->setNum(0);
        }
        else {
            ui->label->setNum(a);
        }
        ui->label_2->setNum(b);
        ui->horizontalScrollBar_Min->setValue(a);
        ui->horizontalScrollBar_Max->setValue(b);
        ui->horizontalScrollBar_Bri->setValue(c);
        ui->horizontalScrollBar_Con->setValue(d);
        displayImage(a, b);
        count = 0;
    }
}
