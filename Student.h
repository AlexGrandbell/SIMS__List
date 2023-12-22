//
// Created by 沈嘉瑞 on 2023.09.25.
//

#ifndef SIMS__LIST_STUDENT_H
#define SIMS__LIST_STUDENT_H

#include "tool.h"

class Student {
private:
    string num;
    string name;
    double score;
public:
    Student();
    Student(string num,string name,double s);

    string getNum();
    string getName();
    double getScore();

    friend ostream & operator<<(ostream &,Student const &);
};

#endif //SIMS__LIST_STUDENT_H
