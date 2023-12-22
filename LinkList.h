//
// Created by 沈嘉瑞 on 2023.09.25.
//

#ifndef SIMS__LIST_LINKLIST_H
#define SIMS__LIST_LINKLIST_H

#include "Student.h"

template<class T>
struct LinkNode{
    T data;
    LinkNode* next;
    LinkNode():next(nullptr){};
    LinkNode(T d):data(d),next(nullptr){}
};

template<class T>
class LinkList {
public:
    LinkList();

    void PrintList();//显示当前所有学生信息记录
    void Insert(T);//从键盘输入一条学生信息记录，插入到表中
    void Find(string);//根据学号查找学生的各项信息
    bool Find(string,int );//根据学号查找学生是否存在,不可删除
    void Delete(string);//删除指定学号的学生信息记录
    int Length();//统计表中学生人数
    void Clear();//清空表中所有记录

    ~LinkList();
private:
    LinkNode<T>* head;
};

template<class T>
LinkList<T>::LinkList() {
    head = new LinkNode<T>;
}

template<class T>
void LinkList<T>::PrintList() {
    if (head->next == nullptr){
        throw EmptyExpection("数据为空。");
    } else{
        LinkNode<T>* curr = head;
        while (curr->next != nullptr){
            cout<<curr->next->data<< endl;
            curr = curr->next;
        }
    }
}

template<class T>
void LinkList<T>::Insert(T stu) {
    LinkNode<T>* curr = head;
    if (Find(stu.getNum(),1)){
        throw DuplicateNumExpection("该学号已存在，记录失败。可以使用1号菜单查看所有学生信息，使用5号菜单更改学生信息。");
    }
    while (curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = new LinkNode<T>(stu);
}

template<class T>
void LinkList<T>::Find(string num) {
    LinkNode<T>* curr = head;
    while (curr->next != nullptr){
        if (curr->next->data.getNum() == num){
            cout<<"找到该学生信息为:\n"<<curr->next->data<< endl;
            return ;
        }
        curr = curr->next;
    }
    throw NoFoundExpection("没有找到该学号对应的学生。");
}

template<class T>
bool LinkList<T>::Find(string num,int i) {
    LinkNode<T>* curr = head;
    while (curr->next != nullptr){
        if (curr->next->data.getNum() == num){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

template<class T>
void LinkList<T>::Delete(string num) {
    LinkNode<T>* curr = head;
    LinkNode<T>* prior = head;
    while (curr->next != nullptr){
        if (curr->data.getNum() == num){
            LinkNode<T>* next = curr->next;
            prior->next = next;
            delete curr;
            return;
        }
        prior = curr;
        curr = curr->next;
    }
    if (curr->data.getNum() == num){
        prior->next = nullptr;
        delete curr;
        return;
    } else{
        throw NoFoundExpection("没有找到该学号对应的学生，删除失败");
    }
}

template<class T>
int LinkList<T>::Length() {
    int i = 0;
    if (head->next == nullptr){
        return 0;
    } else{
        LinkNode<T>* curr = head;
        while (curr->next != nullptr){
            curr = curr->next;
            i++;
        }
    }
    return i;
}

template<class T>
void LinkList<T>::Clear() {
    if (head->next == nullptr){
        return;
    } else{
        LinkNode<T>* curr = head;
        LinkNode<T>* now = head;
        while (curr->next != nullptr){
            now = curr;
            curr = curr->next;
            delete now;
        }
        delete curr;
    }
    head = new LinkNode<T>;
}

template<class T>
LinkList<T>::~LinkList(){
    if (head->next == nullptr){
        delete head;
        return;
    } else{
        LinkNode<T>* curr = head;
        LinkNode<T>* now = head;
        while (curr->next != nullptr){
            now = curr;
            curr = curr->next;
            delete now;
        }
        delete curr;
    }
    head = nullptr;
};
#endif //SIMS__LIST_LINKLIST_H
