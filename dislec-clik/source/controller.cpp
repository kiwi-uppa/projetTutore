#include "controller.h"
#include "model.h"
#include "view.h"

Controller::Controller() : QWidget()
{

    QSize s = qApp->desktop()->size();
    int dW = s.width() - WIN_WIDTH;
    int dH = s.height() - WIN_HEIGHT;
    dW /= 2;
    dH /= 2;
    setGeometry(dW, dH, WIN_WIDTH, WIN_HEIGHT);
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);

    this->setPalette(QPalette(QColor(192,192,255)));

    _m = new ModelConnection(this, &_db);
    _m->setModel();

    _v = new ViewConnection(this);
    _v->setView();
}

Controller::~Controller()
{
    delete _v;
    delete _m;
    _db.closeDB();
}

void Controller::setUser()
{
    for(int i=0; i<_m->getUsersSize(); i++)
        _v->setComboBoxUser(_m->getUserAt(i));
}

void Controller::quit()
{
    if(QMessageBox::warning(NULL, "Fermeture du programme", "Etes vous sure de vouloir arrêter le programme?", QMessageBox::Ok, QMessageBox::Abort) == QMessageBox::Ok)
        this->close();
}

void Controller::newUser()
{
    delete _v;
    _v = new ViewNewUser(this);
    _v->setView();
}

void Controller::connect()
{
}

void Controller::newUserName(QString name)
{
    if((name.size()>15) || (name.size()<1))
        _v->erreur(true);
    else
        _v->erreur(false);
}

void Controller::retour()
{
    delete _v;
    _v = new ViewConnection(this);
    _v->setView();
}
