#cmake版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.5.1)

#项目名称
PROJECT(Iterator)

#让cmake自动去寻找Qt5
FIND_PACKAGE(Qt5 COMPONENTS Widgets REQUIRED)

#采用C++11标准
SET(CMAKE_CXX_STANDARD 11)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
# 添加头文件路径
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}" ./IteratorFunction ./IteratorWidget)

#添加所有的源文件
SET(Iterator_SOURCES 	
    main.cpp

    IteratorWidget/IteratorWidget.cpp

    IteratorFunction/IteratorFunction.cpp
    IteratorFunction/Aitken.cpp
    IteratorFunction/NewtonOriginal.cpp
    IteratorFunction/NewtonDownhill.cpp
    IteratorFunction/OnePoint.cpp
    IteratorFunction/TwoPoint.cpp
)

#添加所有的头文件
SET(Iterator_HEADERS 
    IteratorWidget/IteratorWidget.h

    IteratorFunction/IteratorFunction.h
    IteratorFunction/Aitken.h
    IteratorFunction/NewtonOriginal.h
    IteratorFunction/NewtonDownhill.h
    IteratorFunction/OnePoint.h
    IteratorFunction/TwoPoint.h
)

#调用预编译器moc，需要使用 QT5_WRAP_CPP宏
QT5_WRAP_CPP(Iterator_HEADERS_MOC ${Iterator_HEADERS})

#这些生成的中间文件都会在build目录下，这样的话，编译器则不能定位由uic程序产生的诸如_ui_mainwindow.h等文件。所以，我们需要把build目录添加到包含目录中
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

#生成可执行文件
ADD_EXECUTABLE(Iterator 
	${Iterator_SOURCES} 
	${Iterator_HEADERS_MOC} 
)

#为target添加需要链接的共享库
TARGET_LINK_LIBRARIES(Iterator ${Qt5Widgets_LIBRARIES})