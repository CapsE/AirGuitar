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

    loadSelectedSlots();
    loadSelections();
    loadUnselects();

    guitarStrings = new QLabel(this);
    guitarStrings->setPixmap(QPixmap(":assets/images/guitarStrings.png"));
    guitarStrings->move(QPoint(0,262));
    guitarStrings->show();

    button = new Button(this, QPoint(590,620) ,QPoint(590,220));

    chordTable = new QLabel(this);
    chordTable->setPixmap(QPixmap(":assets/images/accordSelective2.png"));
    chordTable->move(QPoint(92,256));
    chordTable->show();

    loadAccords();

    startscreen = new QLabel(this);
    loadingAnimation = new QMovie(":assets/images/startscreen.gif");
    startscreen->setMovie(loadingAnimation);
//    startscreen->show();
    loadingAnimation->start();

    tableIsDown = false;

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

             if(tableIsDown){
                moveChordTable();
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

             Accord *accord = static_cast<Accord*>(child);
             if(accord->isSelected()) {
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
        Selection* selection = selections[i];
        if(selection->getAccord()){
            Accord* selectedAccord = selection->getAccord();
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
        for(int i=0; i < 14; i++){
           akkords[i]->show();
        }
        chordTable->move(QPoint(92, 256));
        tableIsDown = false;
        button->setButton(tableIsDown);
        for(int i=0; i < 4; i++){
            unselects[i]->hide();
        }

    }else{
        for(int i=0; i < 14; i++){
           if(!akkords[i]->isSelected()){
               akkords[i]->hide();
         }
    }
        chordTable->move(QPoint(92, 656));
        tableIsDown = true;
        button->setButton(tableIsDown);
    }
}

void DragWidget::highlightSelection(int slot){

    unselects[slot]->hide();

    for(int i = 0; i < 4; i++){

        if (i != slot){
           unselects[i]->show();

        }
    }

}

void DragWidget::loadAccords(){

    akkordA = new Accord(this, "A",QPoint(256,310));
    akkordH = new Accord(this, "H", QPoint(384, 310));
    akkordC = new Accord(this, "C", QPoint(512, 310));
    akkordD = new Accord(this, "D", QPoint(640, 310));
    akkordE = new Accord(this, "E", QPoint(768, 310));
    akkordF = new Accord(this, "F", QPoint(896, 310));
    akkordG = new Accord(this, "G", QPoint(1024, 310));

    akkordAm = new Accord(this, "Am",QPoint(256,438));
    akkordHm = new Accord(this, "Hm", QPoint(384, 438));
    akkordCm = new Accord(this, "Cm", QPoint(512, 438));
    akkordDm = new Accord(this, "Dm", QPoint(640, 438));
    akkordEm = new Accord(this, "Em", QPoint(768, 438));
    akkordFm = new Accord(this, "Fm", QPoint(896, 438));
    akkordGm = new Accord(this, "Gm", QPoint(1024, 438));

    akkords[0] = akkordA;
    akkords[1] = akkordH;
    akkords[2] = akkordC;
    akkords[3] = akkordD;
    akkords[4] = akkordE;
    akkords[5] = akkordF;
    akkords[6] = akkordG;
    akkords[7] = akkordAm;
    akkords[8] = akkordHm;
    akkords[9] = akkordCm;
    akkords[10] = akkordDm;
    akkords[11] = akkordEm;
    akkords[12] = akkordFm;
    akkords[13] = akkordGm;
}

void DragWidget::loadSelections(){

    selection0 = new Selection(this, 0,QPoint(224, 160));
    selections[0] = selection0;
    selection1 = new Selection(this, 1,QPoint(480, 160));
    selections[1] = selection1;
    selection2 = new Selection(this, 2, QPoint(736, 160));
    selections[2] = selection2;
    selection3 = new Selection(this, 3, QPoint(992, 160));
    selections[3] = selection3;

}

void DragWidget::loadSelectedSlots(){

    selectedSlot0 = new QLabel(this);
    selectedSlot0->setPixmap(QPixmap(":assets/images/slot0selected.png"));
    selectedSlot0->move(QPoint(192,128));
    selectedSlot0->show();

    selectedSlots[0] = selectedSlot0;

    selectedSlot1 = new QLabel(this);
    selectedSlot1->setPixmap(QPixmap(":assets/images/slot1selected.png"));
    selectedSlot1->move(QPoint(448,128));
    selectedSlot1->show();

    selectedSlots[1] = selectedSlot1;

    selectedSlot2 = new QLabel(this);
    selectedSlot2->setPixmap(QPixmap(":assets/images/slot2selected.png"));
    selectedSlot2->move(QPoint(704,128));
    selectedSlot2->show();

    selectedSlots[2] = selectedSlot2;

    selectedSlot3 = new QLabel(this);
    selectedSlot3->setPixmap(QPixmap(":assets/images/slot3selected.png"));
    selectedSlot3->move(QPoint(960,128));
    selectedSlot3->show();

    selectedSlots[3] = selectedSlot3;
}

void DragWidget::loadUnselects(){
    unselect0 = new QLabel(this);
    unselect0->setPixmap(QPixmap(":assets/images/unselected.png"));
    unselect0->move(selectedSlot0->pos());
    unselect0->hide();

    unselects[0] = unselect0;

    unselect1 = new QLabel(this);
    unselect1->setPixmap(QPixmap(":assets/images/unselected.png"));
    unselect1->move(selectedSlot1->pos());
    unselect1->hide();

    unselects[1] = unselect1;

    unselect2 = new QLabel(this);
    unselect2->setPixmap(QPixmap(":assets/images/unselected.png"));
    unselect2->move(selectedSlot2->pos());
    unselect2->hide();

    unselects[2] = unselect2;

    unselect3 = new QLabel(this);
    unselect3->setPixmap(QPixmap(":assets/images/unselected.png"));
    unselect3->move(selectedSlot3->pos());
    unselect3->hide();

    unselects[3] = unselect3;
}
