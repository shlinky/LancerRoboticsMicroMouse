#ifndef MICROMOUSESERVER_H
#define MICROMOUSESERVER_H
#include "mazeConst.h"
#include "mazeBase.h"
#include "mazegui.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QLineF>
#include <QTimer>
#include "Stack.h"


namespace Ui {
class microMouseServer;
}

class microMouseServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit microMouseServer(QWidget *parent = 0);
    ~microMouseServer();

private slots:
    void on_tabWidget_tabBarClicked(int index);
    void loadMaze();
    void saveMaze();
    void addLeftWall(QPoint cell);
    void addRightWall(QPoint cell);
    void addTopWall(QPoint cell);
    void addBottomWall(QPoint cell);
    void removeRightWall(QPoint cell);
    void removeLeftWall(QPoint cell);
    void removeTopWall(QPoint cell);
    void removeBottomWall(QPoint cell);
    void netComs();
    void connect2mouse();
    void startAI();
    void studentAI();


private:
    bool isWallLeft();
    bool isWallRight();
    bool isWallForward();
    bool moveForward();
    void turnLeft();
    void turnRight();
    void foundFinish();
    void printUI(const char *mesg);
    void coordLeft();
    void coordRight();
    void coordForward();
    bool checkStack(int x1, int y1);

    QTimer *_comTimer;
    QTimer *_aiCallTimer;
    static const int _mDelay = 100;
    Ui::microMouseServer *ui;
    mazeGui *maze;
    std::vector<QGraphicsLineItem*> backgroundGrid;
    struct baseMapNode mazeData[MAZE_WIDTH][MAZE_HEIGHT];
    void connectSignals();
    void initMaze();
    Stack *turnStack = nullptr;
    int state = 0;
    int x = 0;
    int y = 0;
    int dir = 0;
    int l = 0;
    int r = 0;
};

#endif // MICROMOUSESERVER_H
