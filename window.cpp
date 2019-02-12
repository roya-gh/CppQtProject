#include "window.h"
#include <QQuickWidget>
#include <QDebug>
#include <QQuickItem>
#include <QMenu>

Window::Window(QWidget* parent) : QMainWindow(parent) {

    setWindowFlags(Qt::FramelessWindowHint);

    QQuickWidget* view = new QQuickWidget(this);
    view->setSource(QUrl::fromLocalFile("../hayoolaQt/InnerPage.qml"));
    setCentralWidget(view);

    QObject* item = view->rootObject();
    item->setProperty("height", this->height());
    item->setProperty("width", this->width());

    QObject::connect(item, SIGNAL(openMenu(int, int)),
                     this, SLOT(slotOpenMenu(int, int)));
}


void Window::slotOpenMenu(int x, int y) {
    QMenu* menu = new QMenu("File", this);
    menu->addAction("Action0");
    menu->addAction("Action1");
    menu->addAction("Action3");
    menu->move(x, y);
    menu->show();
}


