//
//  Person.h
//  PresonInfo
//
//  Created by Mr_lee on 15-1-4.
//  Copyright (c) 2015年 北京渥瑞达科技发展有限公司. All rights reserved.
//

#ifndef __PresonInfo__Person__
#define __PresonInfo__Person__

#include "Date.h"
/**
 *  人:复合类,包含一个Date类对象和name、email_address
 */
class Person
{
public:
    Person();
    Person(const char* n,const char* e,int y,int m,int d);
public:
    //set、get函数
    char* getName();
    char* getEmailAddress();
    Date& getDate();
    
    void setName(char*);
    void setEmailAddress(char*);
public:
    //三大件 big three
    ~Person();
    Person(const Person& p);
    Person& operator=(const Person& p);
public:
    void printOn();
    friend ostream& operator<<(ostream&,const Person&);

private:
    char* _name;
    char* _email_address;
    Date _date;
};

#endif /* defined(__PresonInfo__Person__) */
