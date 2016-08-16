//
//  Person.cpp
//  PresonInfo
//
//  Created by Mr_lee on 15-1-4.
//  Copyright (c) 2015年 北京渥瑞达科技发展有限公司. All rights reserved.
//

#include "Person.h"

/**
 *  默认构造函数中给_name和_email_address开辟一个字节空间
 *  里面存储一个空字符串 防止_name=NULL空指针时 输出崩溃
 */
Person::Person()
{
    _name = new char[1];
    strcpy(_name, "");
    _email_address = new char[1];
    strcpy(_email_address, "");
}

Person::Person(const char* n,const char* e,int y,int m,int d):_date(y,m,d)
{    
    if (n == NULL) {
        _name = new char[1];
        strcpy(_name, "");
    }else{
        _name = new char[strlen(n)+1];
        strcpy(_name, n);
    }
    if (e == NULL) {
        _email_address = new char[1];
        strcpy(_email_address, "");
    }else{
        _email_address = new char[strlen(n)+1];
        strcpy(_email_address, n);
    }
}

char* Person::getName()
{
    return _name;
}

char* Person::getEmailAddress()
{
    return _email_address;
}

Date&  Person::getDate()
{
    return _date;
}

/**
 *  修改人的姓名,不能直接将新名字拷贝到_name空间中
 *  直接删除_name原有的旧空间 开辟一块和新名字空间大小一样的空间
 *  将新名字拷贝到新空间中
 */
void Person::setName(char* n)
{
    delete []_name;
    _name = new char[strlen(n)+1];
    strcpy(_name, n);
}

/**
 *  与setName操作类似
 */
void Person::setEmailAddress(char* e)
{
    delete []_email_address;
    _email_address = new char[strlen(e)+1];
    strcpy(_email_address, e);
}

Person::~Person()
{
    if (_name) {
        delete []_name;
        _name = NULL;
    }
    if (_email_address) {
        delete []_email_address;
        _email_address = NULL;
    }
}

Person::Person(const Person& p)
{
    _name = new char[strlen(p._name)+1];
    _email_address= new char[strlen(p._email_address)+1];
    
    strcpy(_name, p._name);
    strcpy(_email_address, p._email_address);
    
    _date = p._date;  //注意别忘记拷贝出生年月
}

Person& Person::operator=(const Person& p)
{
    if (this != &p) {
        _date = p._date;  //注意别忘记拷贝出生年月
        
        delete []_name;
        delete []_email_address;
        _name = new char[strlen(p._name)+1];
        _email_address= new char[strlen(p._email_address)+1];
        
        strcpy(_name, p._name);
        strcpy(_email_address, p._email_address);
    }
    return *this;
}

void Person::printOn()
{
    cout<<*this;
}

ostream& operator<<(ostream& out,const Person& p)
{
    out<<"姓名："<<p._name<<"邮箱："<<p._email_address;
    out<<p._date;
    return out;
}
