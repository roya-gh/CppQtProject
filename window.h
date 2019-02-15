#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QMenu>

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

signals:

public slots:
    void slotOpenMenu(int x, int y);
private:
    QMenu m_menu;
};

#endif // WINDOW_H
