#include "dragwidget.h"
#include <QLabel>
#include <QtGui>

DragWidget::DragWidget(QWidget *parent) :
    QFrame(parent)
{
    setMinimumSize(1280, 720);
//    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);

    selection1 = new Selection(this);
    selection1->setPixmap(QPixmap(":/images/slot.png"));
    selection1->move(640-32, 160-39);
    selection1->show();
    selection1->setAttribute(Qt::WA_DeleteOnClose);

    selection2 = new Selection(this);
    selection2->setPixmap(QPixmap(":/images/slot.png"));
    selection2->move(840-32, 160-39);
    selection2->show();
    selection2->setAttribute(Qt::WA_DeleteOnClose);

    selection3 = new Selection(this);
    selection3->setPixmap(QPixmap(":/images/slot.png"));
    selection3->move(440-32, 160-39);
    selection3->show();
    selection3->setAttribute(Qt::WA_DeleteOnClose);

    selection4 = new Selection(this);
    selection4->setPixmap(QPixmap(":/images/slot.png"));
    selection4->move(240-32, 160-39);
    selection4->show();
    selection4->setAttribute(Qt::WA_DeleteOnClose);

    akkord1 = new Accord(this, "1",QPoint(640-32, 360-39));

    akkord2 = new Accord(this, "2", QPoint(840-32, 360-39));

    akkord3 = new Accord(this, "3", QPoint(240-32, 360-39));

    akkord4 = new Accord(this, "4", QPoint(440-32, 360-39));
}

void DragWidget::dragEnterEvent(QDragEnterEvent *event)
 {
     if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
         if (event->source() == this) {
//             akkord1->hide();
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
         if (!child){
             draggedAkkord->move(draggedAkkord->getStartPos());
             draggedAkkord->setSelected(false);
             return;
         }
         QPixmap pixmap;
         QPoint offset;
         dataStream >> pixmap >> offset;

//         QLabel *newIcon = new QLabel(this);
//         newIcon->setPixmap(pixmap);
         //check ob auf selection gezogen wurde
         if(dynamic_cast<Selection*>(child) != NULL){
             draggedAkkord->move(child->pos());
             draggedAkkord->setSelected(true);
             draggedAkkord->show();
             Selection *selection = static_cast<Selection*>(child);
             selection->setAccord(draggedAkkord);
         //check ob auf besetzte selection gezogen wurde
         } else if (dynamic_cast<Accord*>(child) != NULL) {
             Accord *accord = static_cast<Accord*>(child);
             if(accord->isSelected()) {
                 draggedAkkord->move(child->pos());
                 draggedAkkord->show();
                 draggedAkkord->setSelected(true);
                 accord->move(accord->getStartPos());
                 accord->setSelected(false);
             } else {
                 draggedAkkord->move(draggedAkkord->getStartPos());
                 draggedAkkord->setSelected(false);
                 draggedAkkord->show();
             }
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
     Accord *child = static_cast<Accord*>(childAt(event->pos()));
     if (!child)
         return;
     draggedAkkord = child;
 //    draggedAkkord->setText(chord);
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
