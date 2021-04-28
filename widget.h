#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void addContact();
    void remove();

private:

    QTabWidget *Tab;
    QWidget *Widget1;
    QWidget *Widget2;
    QVBoxLayout *mainLay;
    QGridLayout* lay2;
    QGridLayout * lay1;

    //in tab Favorites
    QListView *myListView;
    QStringListModel *model;
    QStringList list;


    // in tab Contacts
    QLineEdit *nameLine;
    QLineEdit *surNameLine;
    QLineEdit *phoneLine;
    QLabel *nameLable;
    QLabel *phoneLable;
    QLabel *surNameLable;
    QPushButton *addBtn;
    QPushButton *removeBtn;

    QMap<QString, QString> contacts;
    QString fullName;
    QString phone;
};
#endif // WIDGET_H
