/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-04 02:00:39
 * @LastEditTime: 2020-11-10 19:58:41
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
    _exit(this),
    _ypsilon_00001(this),
    _ypsilon_000001(this),
    _ypsilon_0000001(this),
    _multiple_01(this),
    _multiple_1(this),
    _multiple_10(this)
{
    line="";
    this->image=QImage(1200,800,QImage::Format_RGB32);
    QColor backColor=qRgb(255,255,255);
    this->image.fill(backColor);

    setFixedSize(1200,900);
    setWindowTitle("迭代法解方程");

    _aitken.setText("埃特肯法");
    _aitken.setFixedSize(200,100);
    _aitken.move(50,20);

    _newton_original.setText("牛顿迭代法");
    _newton_original.setFixedSize(200,100);
    _newton_original.move(50,135);

    _newton_downhill.setText("牛顿下山法");
    _newton_downhill.setFixedSize(200,100);
    _newton_downhill.move(50,250);

    _one_point.setText("单点弦截法");
    _one_point.setFixedSize(200,100);
    _one_point.move(50,365);

    _two_point.setText("双点弦截法");
    _two_point.setFixedSize(200,100);
    _two_point.move(50,480);

    _start.setText("Start");
    _start.setFixedSize(200,60);
    _start.move(950,605);

    _next.setText("Next");
    _next.setFixedSize(200,60);
    _next.move(950,670);

    _exit.setText("Exit");
    _exit.setFixedSize(200,60);
    _exit.move(950,735);

    _ypsilon_00001.setText("0.0001");
    _ypsilon_00001.setFixedSize(100,30);
    _ypsilon_00001.move(25,670);

    _ypsilon_000001.setText("0.00001");
    _ypsilon_000001.setFixedSize(100,30);
    _ypsilon_000001.move(25,710);

    _ypsilon_0000001.setText("0.000001");
    _ypsilon_0000001.setFixedSize(100,30);
    _ypsilon_0000001.move(25,750);

    _multiple_01.setText("×0.1");
    _multiple_01.setFixedSize(100,30);
    _multiple_01.move(175,670);

    _multiple_1.setText("×1");
    _multiple_1.setFixedSize(100,30);
    _multiple_1.move(175,710);

    _multiple_10.setText("×10");
    _multiple_10.setFixedSize(100,30);
    _multiple_10.move(175,750);

    _edit_fx.setGeometry(500,608,350,40);
    _edit_gx.setGeometry(500,656,350,40);
    _edit_x0.setGeometry(500,704,350,40);
    _edit_x1.setGeometry(500,752,350,40);

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

    connect(&_ypsilon_00001,&QPushButton::clicked,[=]()
    {
        this->ypsilon=0.0001;
    });

    connect(&_ypsilon_000001,&QPushButton::clicked,[=]()
    {
        this->ypsilon=0.00001;
    });

    connect(&_ypsilon_0000001,&QPushButton::clicked,[=]()
    {
        this->ypsilon=0.000001;
    });

    connect(&_multiple_01,&QPushButton::clicked,[=]()
    {
        this->multiple=1;
    });

    connect(&_multiple_1,&QPushButton::clicked,[=]()
    {
        this->multiple=0.1;
    });
    
    connect(&_multiple_10,&QPushButton::clicked,[=]()
    {
        this->multiple=0.01;
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
        
        for(double x = x0 - multiple; x <= x0 + multiple; x += multiple/250)
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
            for(double x = x0 - multiple; x <= x0 + multiple; x += multiple/250)
            {
                IteratorFunction iterator_function(expression, equivalent, x0, x1, x);
                point_queue.push(iterator_function.cal());
            }            
        }

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
                if( fabs(aitken.x - aitken.x1) > ypsilon)
                {
                    aitken.iterate(); 
                }
                result = aitken.x;
            } 
            else if(method == 2)
            {
                if( fabs(newton_original.x - newton_original.x1) > ypsilon) 
                {
                    newton_original.iterate();    		
                }
                result = newton_original.x;   	
            }
            else if(method == 3)
            {	
                if( fabs(newton_downhill.x - newton_downhill.x1) > ypsilon) 
                {
                    newton_downhill.iterate();    		
                }
                result = newton_downhill.x;	
            }
            else if(method == 4)
            {
                if( fabs(one_point.xn - one_point.x_last) > ypsilon) 
                {
                    one_point.iterate();    		
                }
                result = one_point.x;	
            } 
            else if(method == 5)
            {	
                if( fabs(two_point.xn - two_point.xn_1) > ypsilon) 
                {
                    two_point.iterate();    		
                }
                result = two_point.x;	
            }
        }
        time++;
        result_array[time] = result;
        update(); 
    });

    connect(&_exit,&QPushButton::clicked,[=]()
    {
        if(method == 1)aitken.initAitken(expression, equivalent, x0, x1);
        else if(method == 2)newton_original.initNewtonOriginal(expression, equivalent, x0, x1);
        else if(method == 3)newton_downhill.initNewtonDownhill(expression, equivalent, x0, x1);
        else if(method == 4)one_point.initOnePoint(expression, equivalent, x0, x1);
        else if(method == 5)two_point.initTwoPoint(expression, equivalent, x0, x1);
        drawline_flag = 0;
        drawpoint_flag = 0;
        flag = 0;
        time = 0;
        method = 0;
        x0 = 0;
        x1 = 0;
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
        drawline.setPen(QPen(QColor(0,0,255),2));
        for(double x = - 250; x <= 250; x ++ )
        {
            if(pointy+200*point_queue.front()<=550 && pointy+200*point_queue.front()>=50)
            {
                drawline.drawPoint(pointx+x,pointy+200*point_queue.front());                
            }
            if(!point_queue.empty())point_queue.pop();
        }

        for(int i=1;i<time;i++)
        {
            QPainter drawpoint(this);
            if(i*50 <= 255)
            {
                drawpoint.setPen(QPen(QColor(255-50*i,50*i,0),5));                
            }
            else
            {
                drawpoint.setPen(QPen(QColor(0,255,0),5));
            }
            
            if(result_array[i] >= this->x0 - multiple && result_array[i] <= this->x0 + multiple)
            {
                drawpoint.drawPoint(pointx + x0 + 250 * (result_array[i] - this->x0) / multiple, pointy);
                //cout << "x_position =  " << pointx + x0 + 250*(result_array[i]-this->x0) << endl ;
            }
        }
    }
}

IteratorWidget::~IteratorWidget()
{

}
