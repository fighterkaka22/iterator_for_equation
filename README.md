<!--
 * @Author: Sun Yuxin
 * @Date: 2020-10-16 23:00:15
 * @LastEditTime: 2020-10-31 09:23:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/README.md
-->
# 《数值分析》课程设计
## 摘要
本项目根据《数值分析》课程相关知识，通过运用C++，Qt等工具，演示用五种迭代方法解方程及图示过程。
## 目录
[TOC]
## 系统概述
本项目将制作一个小程序，用户可以输入其需要的目标函数（仅支持含x的加、减、乘、除、幂运算）、希望进行迭代的等价形式、进行迭代的初值x0及弦截法需要的x1，选择五中迭代法其一，得到函数图像，并通过单击按钮控制迭代过程，画出迭代过程点及输出中间值。
本项目意在形象理解课程内容，并提高工程能力。考虑到期待通过本实验学习知识：
* 形象理解《数值分析》第二章五种迭代方法及其原理
* 栈、队列等数据结构的实际应用
* 基于C++的面向对象的思想和方法，类的继承和封装等
* QT的UI设计，并通过信号和槽机制实现前后端的交互
* 其他工具的使用，包括cmake，git，markdown等
## 需求分析
### 功能需求
* 可通过前端可视化界面和用户交互
* 绘制出函数图像
* 绘制出每一步迭代点
* 在窗口中显示每一步结果和详细信息
* 用户可通过按钮控制开始迭代结束迭代
### 性能需求
* 支持跨Windows、Linux平台运行
* 可靠性高，由于用户输入等问题产生错误，可以及时作出异常处理。
* 易操作性，简单易懂，容易上手
* 模块化设计，易于以后的维护和扩展
### 开发环境需求
本实验采用：
* Linux ubuntu 18.04 操作系统
* vscode编辑器
* cmake
## 系统设计
### 系统总体模块图
#### 模块划分
![模块划分](https://github.com/fighterkaka22/numerical_analysis_iterator/blob/main/pictures/%E6%A8%A1%E5%9D%97%E5%88%92%E5%88%86.png?raw=true)
#### 类设计
#### 界面设计
![界面设计](https://raw.githubusercontent.com/fighterkaka22/numerical_analysis_iterator/main/pictures/%E7%95%8C%E9%9D%A2%E8%AE%BE%E8%AE%A1.png)
### 软件动态模型设计
#### 时序图
![时序图](https://github.com/fighterkaka22/numerical_analysis_iterator/blob/main/pictures/%E6%97%B6%E5%BA%8F%E5%9B%BE.png?raw=true)
#### 流程图
### 详细设计
第一步：读取表达式并绘制函数图像
为了能看到迭代过程，显然初值那个点应当放在图中间。那么为了清楚看到迭代过程，就画初值左右各三格的函数图像还是比较合适的。绘图具体过程，建立一个1000×1000的二维数组或者图，储存对应的x,y坐标，画出来就行了。具体数据根据实际情况决定。
另外，输入表达式如果含有小数，比如“0.6x^2”,“0.6”作为三个字符，并且带小数点，不太好识别。鉴于暂时还不急于优化，暂且只允许以分数格式输入小数，以后有空再处理。
## 相关代码
## 设计总结
