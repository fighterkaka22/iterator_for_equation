/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-04 02:00:39
 * @LastEditTime: 2020-11-10 12:04:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorWidget/IteratorWidget.cpp
 */
#include"IteratorWidget.h"

IteratorWidget::IteratorWidget(QWidget *parent)
    : 
    _edit_fx(this),
    _edit_gx(this),
    _edit_x0(this),
    _edit_x1(this),
    _aitken(this),
    _newton_original(this),
    _newton_downhill(this),
    _one_point(this),
    _two_point(this),
    _start(this),
    _next(this),
    _exit(this)
{
    line="";
    this->image=QImage(1200,800,QImage::Format_RGB32);
    QColor backColor=qRgb(255,255,255);
    this->image.fill(backColor);

    setFixedSize(1200,800);
    setWindowTitle("迭代法解方程");

    _aitken.setText("埃特肯法");
    _aitken.setFixedSize(200,100);
    _aitken.move(50,50);

    _newton_original.setText("牛顿迭代法");
    _newton_original.setFixedSize(200,100);
    _newton_original.move(50,200);

    _newton_downhill.setText("牛顿下山法");
    _newton_downhill.setFixedSize(200,100);
    _newton_downhill.move(50,350);

    _one_point.setText("单点弦截法");
    _one_point.setFixedSize(200,100);
    _one_point.move(50,500);

    _two_point.setText("双点弦截法");
    _two_point.setFixedSize(200,100);
    _two_point.move(50,650);

    _start.setText("Start");

    _start.move(100,500);

    _next.setText("Next");
    _next.move(100,550);

    _exit.setText("Exit");
    _exit.move(100,600);

    _edit_fx.setGeometry(800,500,120,60);
    _edit_gx.setGeometry(800,550,120,60);
    _edit_x0.setGeometry(800,600,120,60);
    _edit_x1.setGeometry(800,650,120,60);

    connect(&_aitken,&QPushButton::clicked,[=]()
    {
        this->method=1;
    });
    connect(&_newton_original,&QPushButton::clicked,[=]()
    {
        this->method=2;
    });
    connect(&_newton_downhill,&QPushButton::clicked,[=]()
    {
        this->method=3;
    });
    connect(&_one_point,&QPushButton::clicked,[=]()
    {
        this->method=4;
    });
    connect(&_two_point,&QPushButton::clicked,[=]()
    {
        this->method=5;
    });

    connect(&_start,&QPushButton::clicked,[=]()
    {
        QString _expression = _edit_fx.text();
        QString _equivalent = _edit_gx.text();
        QString _x0 = _edit_x0.text();
        QString _x1 = _edit_x1.text();

        this->expression = _expression.toStdString();
        this->equivalent = _equivalent.toStdString();
        this->x0 = _x0.toDouble();
        this->x1 = _x1.toDouble();
        
        for(double x = x0 - 0.1; x <= x0 + 0.1; x += 0.0002)
        {
            IteratorFunction iterator_function(expression, equivalent, x0, x1, x);
            point_queue.push(iterator_function.cal());
        }
        drawline_flag=1;
        update(); 
    });

    connect(&_next,&QPushButton::clicked,[=]()
    {      
        QString _expression = _edit_fx.text();
        QString _equivalent = _edit_gx.text();
        QString _x0 = _edit_x0.text();
        QString _x1 = _edit_x1.text();

        this->expression = _expression.toStdString();
        this->equivalent = _equivalent.toStdString();
        this->x0 = _x0.toDouble();
        this->x1 = _x1.toDouble();
        
        if( drawline_flag ==1 )
        {
            for(double x = x0 - 0.1; x <= x0 + 0.1; x += 0.0002)
            {
                IteratorFunction iterator_function(expression, equivalent, x0, x1, x);
                point_queue.push(iterator_function.cal());
            }            
        }

        time++;

        if(flag == 0)
        {
            cout << "(x0,x1)=" << x0 << "," << x1 << endl;

            if(method == 1)aitken.initAitken(expression, equivalent, x0, x1);
            else if(method == 2)newton_original.initNewtonOriginal(expression, equivalent, x0, x1);
            else if(method == 3)newton_downhill.initNewtonDownhill(expression, equivalent, x0, x1);
            else if(method == 4)one_point.initOnePoint(expression, equivalent, x0, x1);
            else if(method == 5)two_point.initTwoPoint(expression, equivalent, x0, x1);

            cout << "(x0,x1)=" << x0 << "," << x1 << endl;
            flag = 1;
        }
        if(flag == 1)
        {
            if(method == 1)
            { 
                cout << "aitken.x0=" << aitken.x0 << endl;
                aitken.iterate();    		
                result = aitken.x;
            } 
            else if(method == 2)
            {
                if( fabs(newton_original.x - newton_original.x1) > YPSILON) 
                {
                    newton_original.iterate();    		
                }
                result = newton_original.x;   	
            }
            else if(method == 3)
            {	
                if( fabs(newton_downhill.x - newton_downhill.x1) > YPSILON) 
                {
                    newton_downhill.iterate();    		
                }
                result = newton_downhill.x;	
            }
            else if(method == 4)
            {
                if( fabs(one_point.xn - one_point.x_last) > YPSILON) 
                {
                    one_point.iterate();    		
                }
                result = one_point.x;	
            } 
            else if(method == 5)
            {	
                if( fabs(two_point.xn - two_point.xn_1) > YPSILON) 
                {
                    two_point.iterate();    		
                }
                result = two_point.x;	
            }
        }
        result_array[time] = result;
        update(); 
    });

    connect(&_exit,&QPushButton::clicked,[=]()
    {
        drawline_flag=0;
        drawpoint_flag=0;
        flag=0;
        time=0;
        method=0;
        while(!point_queue.empty())point_queue.pop();
        update(); 
    });
}

void IteratorWidget::paintEvent(QPaintEvent *event)
{  
    Q_UNUSED(event);

    QPainter drawBackground(this);
    drawBackground.setRenderHint(QPainter::Antialiasing,true);
    int pointx = 600, pointy = 300;
    int width = 300;
    drawBackground.drawRect(350,50,500,500);
    drawBackground.drawLine(350,300,850,300);


    if(drawline_flag == 1)
    {
        QPainter drawline(this);
        drawline.setPen(QPen(QColor(0,0,0),2));
        for(double x = - 0.1; x <= 0.1; x += 0.0002)
        {
            if(pointy+200*point_queue.front()<=550 && pointy+200*point_queue.front()>=50)
            {
                drawline.drawPoint(pointx+2500*x,pointy+200*point_queue.front());                
            }
            if(!point_queue.empty())point_queue.pop();
        }

        for(int i=1;i<time;i++)
        {
            QPainter drawpoint(this);
            drawpoint.setPen(QPen(QColor(255,0,0),5));
            if(result_array[i] >= this->x0 - 0.1 && result_array[i] <= this->x0 + 0.1)
            {
                drawpoint.drawPoint(pointx+2500*(result_array[i]-this->x0),pointy);
                //double x_debug = pointx+250*(result_array[i]-this->x0);
                //qDebug() << "pointx+250*(result_array[i]-this->x0)" << x_debug;    
            }
        }
    }
}

IteratorWidget::~IteratorWidget()
{

}
