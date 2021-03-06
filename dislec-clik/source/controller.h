#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QVector>
#include <QKeyEvent>
#include <iostream>

#include "modelconnection.h"
#include "modelnewuser.h"
#include "modelstat.h"
#include "modelmenuexercices.h"
#include "modelexercice.h"

#include "viewconnection.h"
#include "viewnewuser.h"
#include "viewmenu.h"
#include "viewstat.h"
#include "viewmenuexercices.h"
#include "viewexercice.h"

#include "db.h"

class View;
class Model;

class Controller : public QWidget
{
    Q_OBJECT
    
public:
    Controller();
    ~Controller();
    void setUser();
    QString getUser();

    //Stat*****
    QStringList getExos();
    QVector<int> getTentatives();
    QVector<int> getMoyennes();

    //Exercices
    QString getExoName();
    QString getExoDesc();
    void setUIExo(QStringList list);
    void menuExo();

private:
    View * _v;
    Model * _m;
    Db _db;
    QString _user;
    bool _mouse;

    void removeView();
    void removeModel();

private slots:
    void quit();

    //Connection*****
    void newUser();
    void connect();

    //New User****
    void newUserName(QString name);
    void retourConnection();
    void addUser();

    //Menu****
    void menuExercices();
    void menuStatistiques();

    //Stat****
    void menu();

    //MenuExercices****
    void nextExo();
    void prevExo();
    void firstExo();
    void secondExo();

    //Exercices
    void propEvent(int prop);

protected:
    void keyPressEvent ( QKeyEvent * event );
    void mousePressEvent(QMouseEvent *);

};

#endif // MAINWINDOW_H
