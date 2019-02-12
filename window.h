#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

signals:

public slots:
    void slotOpenMenu(int x, int y);
};

#endif // WINDOW_H
