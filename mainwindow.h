#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Reset_clicked();
    void on_horizontalScrollBar_Min_valueChanged(int value);
    void on_horizontalScrollBar_Max_valueChanged(int value);
    void on_horizontalScrollBar_Bri_valueChanged(int value);
    void on_horizontalScrollBar_Con_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    unsigned char *img;
    double alpha, beta;
    int height, width, min, max, mid, count;

    void findMinMax();
    void setSliderRanges();
    void displayImage(int a, int b);
    void loadRawImage(const std::string &path);
    void updateSliders(int a, int b, int c, int d, int e);
};
#endif // MAINWINDOW_H
