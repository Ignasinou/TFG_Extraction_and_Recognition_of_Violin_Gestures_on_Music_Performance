#ifndef MARKERS_H
#define MARKERS_H

#include <QDialog>

namespace Ui {
class markers;
}

class markers : public QDialog
{
    Q_OBJECT

public:
    explicit markers(QWidget *parent = 0);
    ~markers();

private slots:
    void on_bowMarkers_clicked();

    void on_violinMarkers_clicked();

    void cameraOnCapture(int typeofMarker, int webcamNum);

private:
    Ui::markers *ui;
};

#endif // MARKERS_H
