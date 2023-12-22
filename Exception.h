//
// Created by 沈嘉瑞 on 2023.09.25.
//

#ifndef SIMS__LIST_EXCEPTION_H
#define SIMS__LIST_EXCEPTION_H

#include <stdexcept> // 包含stdexcept头文件以使用标准异常类
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

//空链表异常
class EmptyExpection:public exception{
public:
    EmptyExpection(const char* message):errorMessage(message){}

    const char * what() const noexcept override{
        return errorMessage.c_str();
    }
private:
    string errorMessage;
};


//没有找到错误
class NoFoundExpection:public exception{
public:
    NoFoundExpection(const char* message):errorMessage(message){}

    const char * what() const noexcept override{
        return errorMessage.c_str();
    }
private:
    string errorMessage;
};

//绩点错误
class ScoreExpection:public exception{
public:
    ScoreExpection(const char* message):errorMessage(message){}

    const char * what() const noexcept override{
        return errorMessage.c_str();
    }
private:
    string errorMessage;
};

//学号重复错误
class DuplicateNumExpection:public exception{
public:
    DuplicateNumExpection(const char* message):errorMessage(message){}

    const char * what() const noexcept override{
        return errorMessage.c_str();
    }
private:
    string errorMessage;
};

//数字输入字符错误
class NumberExpection:public exception{
public:
    NumberExpection(const char* message):errorMessage(message){}

    const char * what() const noexcept override{
        return errorMessage.c_str();
    }
private:
    string errorMessage;
};

//手动退出
class ExitExpection:public exception{
public:
    ExitExpection(const char* message):errorMessage(message){}

    const char * what() const noexcept override{
        return errorMessage.c_str();
    }
private:
    string errorMessage;
};

#endif //SIMS__LIST_EXCEPTION_H
