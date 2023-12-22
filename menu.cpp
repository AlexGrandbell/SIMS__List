//
// Created by 沈嘉瑞 on 2023.09.25.
//

#include "menu.h"
LinkList<Student> stuList;

void outPutMenu(){
    cout<<"\n ----------菜单----------"<<endl;
    cout<<" |1.显式所有学生信息记录|"<<endl;
    cout<<" |2.录入学生信息记录    |"<<endl;
    cout<<" |3.查找学生信息记录    |"<<endl;
    cout<<" |4.删除学生信息记录    |"<<endl;
    cout<<" |5.更改学生信息记录    |"<<endl;
    cout<<" |6.统计学生人数        |"<<endl;
    cout<<" |7.清空学生信息记录    |"<<endl;
    cout<<" |0.退出程序            |"<<endl;
    cout<<" ------------------------"<<endl;
    //输出提示选择编号
    cout<<"请选择菜单项编号(0-7):";
}

void ShowAll(){
    cout<<"--------学生信息--------"<<endl;
    try {
        stuList.PrintList();
    }catch (const exception& e){
        cout<<e.what()<<endl;
    }
    cout<<"------------------------"<<endl;
};

void Add() {
    cout << "--------插入信息--------" << endl;
    double score;
    string num, name;
    try {
        cout << "请输入学生学号:";
        num = inputString();
        cout << "请输入学生姓名:";
        name = inputString();
        cout << "请输入学生绩点:";
        score = inputDouble();
        stuList.Insert(Student(num, name, score));
        cout << "记录成功。" << endl;
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "------------------------" << endl;
};

void Find() {
    cout << "--------查找信息--------" << endl;
    try {
        cout << "使用学号查找。请输入学号:";
        stuList.Find(inputString());
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "------------------------" << endl;
};
void Delete() {
    cout << "--------删除信息--------" << endl;
    try {
        cout << "请输入删除信息的学号:";
        string num = inputString();
        stuList.Find(num);
        cout << "确认要删除该记录吗?(Y-确认/N-取消):";
        string tmp = inputString();
        if (tmp == "Y" || tmp == "y") {
            stuList.Delete(num);
            cout << "删除成功。" << endl;
        } else {
            cout << "已取消删除。" << endl;
        }
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "------------------------" << endl;
};
void Refresh() {
    cout << "--------更改信息--------" << endl;
    string oldNum;
    string tmp = "N";
    try {
        cout << "请输入更改信息的学号:";
        oldNum = inputString();
        stuList.Find(oldNum);
        cout << "确认要更改该记录吗?(Y-确认/N-取消):";
        tmp = inputString();
        if (tmp == "Y" || tmp == "y") {
            double score;
            string newNum,name, scoreInput;
            cout << "请输入新的学号:";
            newNum = inputString();
            cout << "请输入新的姓名:";
            name = inputString();
            cout << "请输入新的绩点:";
            score = inputDouble();
            cout << "正在写入新信息..." << endl;
            stuList.Insert(Student(newNum, name, score));
            cout << "写入成功。正在删除原信息..." << endl;
            stuList.Delete(oldNum);
            cout << "更改成功" << endl;
        } else {
            cout << "已取消更改。" << endl;
        }
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "------------------------" << endl;
};
void Length(){
    cout<<"--------学生人数--------"<<endl;
    cout<<"学生人数为"<<stuList.Length()<<"个"<<endl;
    cout<<"------------------------"<<endl;
};

void Clear(){
    cout<<"--------清除信息--------"<<endl;
    try {
        string tmp = "Y";
        cout << "是否清除所有学生信息(Y/N)?:";
        tmp = inputString();
        if (tmp == "Y" || tmp == "y") {
            stuList.Clear();
            cout << "清除成功。" << endl;
        } else {
            cout << "已取消。" << endl;
        }
    }catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout<<"------------------------"<<endl;
};
void ExitApp(){
    cout<<"\n欢迎再次使用，再见。"<<endl;
};