#include "window.h"
#include <QQuickWidget>
#include <QDebug>
#include <QQuickItem>
#include <QMenu>

Window::Window(QWidget* parent) :
    QMainWindow(parent), m_menu("Menu",this){

    setWindowFlags(Qt::FramelessWindowHint);

    QQuickWidget* view = new QQuickWidget(this);
    view->setSource(QUrl::fromLocalFile(":/qml/InnerPage.qml"));
    setCentralWidget(view);

    view->rootObject()->setProperty("height", this->height());
    view->rootObject()->setProperty("width", this->width());
    QObject::connect(view->rootObject(), SIGNAL(openMenu(int, int)),
                     this, SLOT(slotOpenMenu(int, int)));

    m_menu.addAction("Action0");
    m_menu.addAction("Action1");
    m_menu.addAction("Action3");
}


void Window::slotOpenMenu(int x, int y) {
    m_menu.move(x, y);
    m_menu.show();
}

