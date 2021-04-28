#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    Tab =new QTabWidget(this);
    mainLay = new QVBoxLayout(this);
    mainLay->addWidget(Tab);
    Tab->setCurrentIndex(0);


    Widget1 = new QWidget;
    lay1=new  QGridLayout(Widget1);
    Tab->addTab(Widget1,QString("Contacts") );


    Widget2 = new QWidget;
    lay2=new  QGridLayout(Widget2);
    Tab->addTab(Widget2,QString("Favorites") );
    myListView = new QListView;
    //lay2=new  QGridLayout(myListView);
    //Tab->addTab(myListView,QString("Favorites") );
    lay2->addWidget(myListView);

    removeBtn = new QPushButton("Remove");
    lay2->addWidget(removeBtn);
    connect(removeBtn, SIGNAL(clicked()), this, SLOT(remove()));

    nameLine = new QLineEdit();
    surNameLine = new QLineEdit();
    phoneLine = new QLineEdit();
    nameLable = new QLabel("Name");
    phoneLable = new QLabel("Phone");
    surNameLable= new QLabel("Surname");

    addBtn= new QPushButton("Add");
    connect(addBtn, SIGNAL(clicked()), this, SLOT(addContact()));

    lay1->addWidget(nameLable,0,0, Qt::AlignTop);
    lay1->addWidget(nameLine, 0, 1 );
    lay1->addWidget(surNameLable,1,0);
    lay1->addWidget(surNameLine, 1, 1 );
    lay1->addWidget(phoneLable,  2,0);
    lay1->addWidget(phoneLine,2,1);
    lay1->addWidget(addBtn, 3, 0);

    list.append("Ivan Ivanovich \n 000");

    //in favorites
    model = new QStringListModel();
    model->setStringList(list);
    myListView->setModel(model);

    QModelIndex parentIndex = QModelIndex();
    parentIndex = model->index(0,0, parentIndex);
}

Widget::~Widget()
{
}

void Widget::addContact()
{
    QString contact;
    QString name;
    name= nameLine->text();
    QString surName = surNameLine->text();
    phone = phoneLine->text();
    contact = name + " " +surName + "\n"+ phone;
    if(contact.isEmpty())return;
    if(model->insertRow(model->rowCount())){
        QModelIndex index = model->index(model->rowCount()-1,0);
        model->setData(index, contact);
     }
}
void Widget::remove()
{
    QModelIndex index = myListView->currentIndex();
    qDebug() << index.row();
    model->removeRow(index.row());

}
