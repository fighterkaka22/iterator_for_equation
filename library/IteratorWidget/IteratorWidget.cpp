/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-04 02:00:39
 * @LastEditTime: 2020-11-11 06:22:21
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
    _ypsilon_00000001(this),
    _multiple_001(this),
    _multiple_01(this),
    _multiple_1(this),
    _multiple_10(this),
    _edit_time(this),
    _edit_result(this),
    _edit_lamda(this)
{
    setFixedSize(1200,900);
    setWindowTitle("迭代法解方程");

    _aitken.setText("埃特肯法");
    _aitken.setStyleSheet("font-size:20px;");
    _aitken.setFixedSize(200,50);
    _aitken.move(50,40);

    _newton_original.setText("牛顿迭代法");
    _newton_original.setStyleSheet("font-size:20px;");
    _newton_original.setFixedSize(200,50);
    _newton_original.move(50,155);

    _newton_downhill.setText("牛顿下山法");
    _newton_downhill.setStyleSheet("font-size:20px;");
    _newton_downhill.setFixedSize(200,50);
    _newton_downhill.move(50,270);

    _one_point.setText("单点弦截法");
    _one_point.setStyleSheet("font-size:20px;");
    _one_point.setFixedSize(200,50);
    _one_point.move(50,385);

    _two_point.setText("双点弦截法");
    _two_point.setStyleSheet("font-size:20px;");
    _two_point.setFixedSize(200,50);
    _two_point.move(50,500);

    _start.setText("Start");
    _start.setFixedSize(200,30);
    _start.move(950,645);

    _next.setText("Next");
    _next.setFixedSize(200,30);
    _next.move(950,710);

    _exit.setText("Exit");
    _exit.setFixedSize(200,30);
    _exit.move(950,775);

    _ypsilon_00001.setText("0.0001");
    _ypsilon_00001.setFixedSize(100,30);
    _ypsilon_00001.move(25,650);

    _ypsilon_000001.setText("0.00001");
    _ypsilon_000001.setFixedSize(100,30);
    _ypsilon_000001.move(25,690);

    _ypsilon_0000001.setText("0.000001");
    _ypsilon_0000001.setFixedSize(100,30);
    _ypsilon_0000001.move(25,730);

    _ypsilon_00000001.setText("0.0000001");
    _ypsilon_00000001.setFixedSize(100,30);
    _ypsilon_00000001.move(25,770);

    _multiple_001.setText("×0.01");
    _multiple_001.setFixedSize(100,30);
    _multiple_001.move(175,650);

    _multiple_01.setText("×0.1");
    _multiple_01.setFixedSize(100,30);
    _multiple_01.move(175,690);

    _multiple_1.setText("×1");
    _multiple_1.setFixedSize(100,30);
    _multiple_1.move(175,730);

    _multiple_10.setText("×10");
    _multiple_10.setFixedSize(100,30);
    _multiple_10.move(175,770);

    _edit_fx.setGeometry(600,628,250,40);
    _edit_gx.setGeometry(600,676,250,40);
    _edit_x0.setGeometry(600,724,250,40);
    _edit_x1.setGeometry(600,772,250,40);

    _edit_time.setGeometry(982,72,30,40);
    _edit_result.setGeometry(1005,120,135,30);
    _edit_lamda.setGeometry(1070,320,70,30);

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
        this->ypsilon_num=5;
    });

    connect(&_ypsilon_000001,&QPushButton::clicked,[=]()
    {
        this->ypsilon=0.00001;
        this->ypsilon_num=6;
    });

    connect(&_ypsilon_0000001,&QPushButton::clicked,[=]()
    {
        this->ypsilon=0.000001;
        this->ypsilon_num=7;
    });

    connect(&_ypsilon_00000001,&QPushButton::clicked,[=]()
    {
        this->ypsilon=0.0000001;
        this->ypsilon_num=8;
    });

    connect(&_multiple_001,&QPushButton::clicked,[=]()
    {
        this->multiple=10;
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
        QString _expression = _edit_fx.toPlainText();
        QString _equivalent = _edit_gx.toPlainText();
        QString _x0 = _edit_x0.toPlainText();
        QString _x1 = _edit_x1.toPlainText();

        this->expression = _expression.toStdString();
        this->equivalent = _equivalent.toStdString();
        this->x0 = _x0.toDouble();
        this->x1 = _x1.toDouble();
        
        for(double x = x0 - multiple; x <= x0 + multiple; x += multiple/250)
        {
            IteratorFunction iterator_function(expression, equivalent, x0, x1, x);
            point_queue.push(iterator_function.cal());
        }
        result_array[0] = x0;
        drawline_flag = 1;
        update(); 
    });

    connect(&_next,&QPushButton::clicked,[=]()
    {      
        QString _expression = _edit_fx.toPlainText();
        QString _equivalent = _edit_gx.toPlainText();
        QString _x0 = _edit_x0.toPlainText();
        QString _x1 = _edit_x1.toPlainText();

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
            if(method == 1)aitken.initAitken(expression, equivalent, x0, x1);
            else if(method == 2)newton_original.initNewtonOriginal(expression, equivalent, x0, x1);
            else if(method == 3)newton_downhill.initNewtonDownhill(expression, equivalent, x0, x1);
            else if(method == 4)one_point.initOnePoint(expression, equivalent, x0, x1);
            else if(method == 5)two_point.initTwoPoint(expression, equivalent, x0, x1);

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
                _edit_lamda.setPlainText(QString::number(newton_downhill.lamda, 'g', ypsilon_num));
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
        _edit_time.setPlainText(QString::number(time, 10));
        result_array[time] = result;
        _edit_result.setPlainText(QString::number(result, 'g', ypsilon_num));
        update(); 
    });

    connect(&_exit,&QPushButton::clicked,[=]()
    {
        if(method == 1)aitken.initAitken(expression, equivalent, x0, x1);
        else if(method == 2)newton_original.initNewtonOriginal(expression, equivalent, x0, x1);
        else if(method == 3)newton_downhill.initNewtonDownhill(expression, equivalent, x0, x1);
        else if(method == 4)one_point.initOnePoint(expression, equivalent, x0, x1);
        else if(method == 5)two_point.initTwoPoint(expression, equivalent, x0, x1);

        _edit_time.setPlainText("");
        _edit_result.setPlainText("");
        _edit_lamda.setPlainText("");
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

    QPainter draw_background(this);
    draw_background.setRenderHint(QPainter::Antialiasing,true);
    int pointx = 600, pointy = 300;
    int width = 300;
    draw_background.drawRect(350,50,500,500);
    draw_background.drawRect(950,50,200,500);
    draw_background.drawLine(350,300,850,300);
    draw_background.drawLine(950,300,1150,300);
    draw_background.drawLine(0,600,1600,600);
    draw_background.drawLine(300,0,300,900);
    draw_background.drawLine(900,0,900,900);
    draw_background.drawLine(150,600,150,900);

    QPainter draw_text(this);
    QFont font;
    // 大小
    font.setPointSize(15);
    draw_text.setFont(font);

    draw_text.drawText(35,630,"精度要求");
    draw_text.drawText(185,630,"图像缩放");
    draw_text.drawText(350,658,"请输入方程f(x):");
    draw_text.drawText(350,706,"请输入等价形式φ(x):");
    draw_text.drawText(350,754,"请输入初值x0:");
    draw_text.drawText(350,802,"请输入弦截法x1:");


    draw_text.drawText(960,95,"第");
    draw_text.drawText(1015,95,"次迭代结果为:");
    draw_text.drawText(960,140,"xi = ");

    draw_text.drawText(960,340,"下山因子 = ");

    if(time > 0 && fabs(result_array[time]-result_array[time-1]) < ypsilon)
    {
        QPainter draw_message(this);
        QFont font;
        // 大小
        font.setPointSize(15);
        draw_message.setPen(QColor(255, 0, 0));
        draw_message.setFont(font);
        draw_message.drawText(960,280,"迭代成功！");
    }

    if(drawline_flag == 1)
    {
        QPainter draw_line(this);
        draw_line.setPen(QPen(QColor(0,0,255),2));
        for(double x = - 250; x <= 250; x ++ )
        {
            if(pointy+25/multiple*point_queue.front()<=550 && pointy+25/multiple*point_queue.front() >= 50)
            {
                draw_line.drawPoint(pointx+x,pointy+25/multiple*point_queue.front());                
            }
            if(!point_queue.empty())point_queue.pop();
        }

        for(int i = 0; i <= time; i++)
        {
            QPainter draw_point(this);
            QPainter draw_plumb(this);
            QFont _font;
            // 大小
            _font.setPointSize(5);
            draw_text.setFont(_font);
            if(i*20 <= 200)
            {
                draw_point.setPen(QPen(QColor(255-20*i,0,0),5));  
                draw_plumb.setPen(QPen(QColor(255-20*i,0,0),1));
            }
            else
            {
                draw_point.setPen(QPen(QColor(0,0,0),5));
                draw_plumb.setPen(QPen(QColor(0,0,0),1));
            }
            
            if(result_array[i] >= this->x0 - multiple && result_array[i] <= this->x0 + multiple)
            {
                double x_temp = pointx + 250 * (result_array[i] - this->x0) / multiple;
                draw_point.drawPoint(x_temp, pointy);
                draw_plumb.drawLine(x_temp, 50, x_temp, 550);
                draw_point.drawText(x_temp, pointy-1, "xi");
            }
        }
        if((result_array[time] < this->x0 - multiple || result_array[time] > this->x0 + multiple) && (time < 0 || fabs(result_array[time]-result_array[time-1]) >= ypsilon))
        {
            QPainter draw_message(this);
            QFont font;
            // 大小
            font.setPointSize(15);
            draw_message.setPen(QColor(255, 0, 0));
            draw_message.setFont(font);
            draw_message.drawText(960,280,"超出图示区域！");
        }
    }
}

IteratorWidget::~IteratorWidget()
{

}
