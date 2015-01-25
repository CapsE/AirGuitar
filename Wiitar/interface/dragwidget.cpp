#include "dragwidget.h"
#include <QLabel>
#include <QtGui>
#include <QRect>


DragWidget::DragWidget(QWidget *parent, ChordManager *chordManager) :
    QFrame(parent)
{
    this->chordManager = chordManager;
    setMinimumSize(1280, 720);
    QPalette palette = this->palette();
    palette.setColor( backgroundRole(), QColor( 23, 23, 26 ) );
    setPalette( palette );
    setAutoFillBackground( true );
   // setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);




    selectedAccord0 = new QLabel(this);
    selectedAccord0->setPixmap(QPixmap(":assets/images/accord0selected.png"));
    selectedAccord0->move(QPoint(192,128));
    selectedAccord0->show();

    selectedAccord1 = new QLabel(this);
    selectedAccord1->setPixmap(QPixmap(":assets/images/accord1selected.png"));
    selectedAccord1->move(QPoint(448,128));
    selectedAccord1->show();

    selectedAccord2 = new QLabel(this);
    selectedAccord2->setPixmap(QPixmap(":assets/images/accord2selected.png"));
    selectedAccord2->move(QPoint(704,128));
    selectedAccord2->show();

    selectedAccord3 = new QLabel(this);
    selectedAccord3->setPixmap(QPixmap(":assets/images/accord3selected.png"));
    selectedAccord3->move(QPoint(960,128));
    selectedAccord3->show();

    guitarStrings = new QLabel(this);
    guitarStrings->setPixmap(QPixmap(":assets/images/guitarStrings.png"));
    guitarStrings->move(QPoint(0,262));
    guitarStrings->show();

    button = new Button(this, QPoint(590,620) ,QPoint(590,220));

    chordTable = new QLabel(this);
    chordTable->setPixmap(QPixmap(":assets/images/accordSelective2.png"));
    chordTable->move(QPoint(92,256));
    chordTable->show();



    selection0 = new Selection(this, 0,QPoint(224, 160));
    selections[0] = selection0;
    selection1 = new Selection(this, 1,QPoint(480, 160));
    selections[1] = selection1;
    selection2 = new Selection(this, 2, QPoint(992, 160));
    selections[2] = selection2;
    selection3 = new Selection(this, 3, QPoint(736, 160));
    selections[3] = selection3;



    akkordA = new Accord(this, "A",QPoint(256,310));
    akkordH = new Accord(this, "H", QPoint(384, 310));
    akkordC = new Accord(this, "C", QPoint(512, 310));
    akkordD = new Accord(this, "D", QPoint(640, 310));
    akkordE = new Accord(this, "E", QPoint(768, 310));
    akkordF = new Accord(this, "F", QPoint(896, 310));
    akkordG = new Accord(this, "G", QPoint(1024, 310));

    akkords[0] = akkordA;
    akkords[1] = akkordH;
    akkords[2] = akkordC;
    akkords[3] = akkordD;
    akkords[4] = akkordE;
    akkords[5] = akkordF;
    akkords[6] = akkordG;

    tableIsDown = false;

    //selection0->setAccord(akkordA);

}

void DragWidget::dragEnterEvent(QDragEnterEvent *event)
 {
     if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
         if (event->source() == this) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
         } else {
             event->acceptProposedAction();
         }
     } else {
         event->ignore();
     }
 }


void DragWidget::dragMoveEvent(QDragMoveEvent *event)
 {
     if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
         if (event->source() == this) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
         } else {
             event->acceptProposedAction();
         }
     } else {
         event->ignore();
     }
 }


void DragWidget::dropEvent(QDropEvent *event)

 {
     if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
         QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
         QDataStream dataStream(&itemData, QIODevice::ReadOnly);

         // Check auf was gedroppt wurde
         QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
         if (dynamic_cast<Selection*>(child) == NULL && dynamic_cast<Accord*>(child) == NULL){
             draggedAkkord->move(draggedAkkord->getStartPos());
             if(draggedAkkord->isSelected()){
                 draggedAkkord->setSelected(false);
                   getSelection(draggedAkkord)->setAccord(NULL);
                }
             return;
         }

         QPixmap pixmap;
         QPoint offset;
         dataStream >> pixmap >> offset;

         //check ob auf selection gezogen wurde
         if(dynamic_cast<Accord*>(child) == NULL){
             draggedAkkord->move(child->pos());
             draggedAkkord->setSelected(true);
             draggedAkkord->show();
             Selection *selection = static_cast<Selection*>(child);
             selection->setAccord(draggedAkkord);
         //check ob auf besetzte selection gezogen wurde
         } else if (dynamic_cast<Selection*>(child) == NULL) {
//             qDebug("SHIIT");
             Accord *accord = static_cast<Accord*>(child);
             if(accord->isSelected()) {
//                 qDebug((accord->getChord().toStdString().c_str()));
                 qDebug() << "aSDasd";
                 draggedAkkord->setSelected(true);
                 draggedAkkord->move(child->pos());
                 draggedAkkord->show();

                 Selection* selection = getSelection(accord);
                 selection->setAccord(draggedAkkord);
                 accord->hide();
                 accord->setSelected(false);
                 accord->move(accord->getStartPos());
                 accord->show();

             } else {
                 draggedAkkord->move(draggedAkkord->getStartPos());
                 draggedAkkord->setSelected(false);
                 draggedAkkord->show();
             }
//             qDebug("GEHT");
         }
         //check ob ins leere gezogen wurde
         else{
           draggedAkkord->show();
         }
         //newIcon->setAttribute(Qt::WA_DeleteOnClose);


         if (event->source() == this) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
         } else {
             event->acceptProposedAction();
         }
     } else {
         event->ignore();
     }
 }


void DragWidget::mousePressEvent(QMouseEvent *event)
 {
     Button *pressedButton = dynamic_cast<Button*>(childAt(event->pos()));
     if(pressedButton){
        moveChordTable();
        qDebug() << "Es  ist ein Button";
        return;
     }
     Accord *child = dynamic_cast<Accord*>(childAt(event->pos()));
     if (!child) return;

     draggedAkkord = child;
     if(!(draggedAkkord->isSelected())){
        chordManager->Strum(draggedAkkord->getChord(), 0.95f);
     }
     child->setPixmap(QPixmap(":assets/images/akkord" + child->getChord() + ".png"));
     QPixmap pixmap = *child->pixmap();

     QByteArray itemData;
     QDataStream dataStream(&itemData, QIODevice::WriteOnly);
     dataStream << pixmap << QPoint(event->pos() - child->pos());

     QMimeData *mimeData = new QMimeData;
     mimeData->setData("application/x-dnditemdata", itemData);

     QDrag *drag = new QDrag(this);
     drag->setMimeData(mimeData);
     drag->setPixmap(pixmap);
     drag->setHotSpot(event->pos() - child->pos());

     child->hide();

     if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction){
//         child->close();
     }else {
         child->show();
         child->setPixmap(pixmap);
     }
 }

Selection* DragWidget::getSelection(Accord* accord){
    for(int i = 0; i < 4; i++){
        QVariant var(i);
        qDebug()<< i;
        Selection* selection = selections[i];
        if(selection->getAccord()){
            Accord* selectedAccord = selection->getAccord();
            qDebug((accord->getChord().toStdString().c_str()));
            if (accord->getChord() == selectedAccord->getChord()){
                return selection;
            }
        }else{
            continue;
        }
    }

}

void DragWidget::moveChordTable(){


    if(tableIsDown){
        for(int i=0; i < 7; i++){
           akkords[i]->show();
        }
        chordTable->move(QPoint(92, 256));
        tableIsDown = false;
        button->setButton(tableIsDown);

    }else{
        for(int i=0; i < 7; i++){
           if(!akkords[i]->isSelected()){
               akkords[i]->hide();
           }
        }
        chordTable->move(QPoint(92, 656));
        tableIsDown = true;
        button->setButton(tableIsDown);
    }
}
