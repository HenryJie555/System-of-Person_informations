//
//  PersonSet.h
//  PresonInfo
//
//  Created by Mr_lee on 15-1-4.
//  Copyright (c) 2015年 北京渥瑞达科技发展有限公司. All rights reserved.

#ifndef __PresonInfo__PersonSet__
#define __PresonInfo__PersonSet__

/**
 *  集合类,用于存储多个Person对象的地址 因此需要声明一个数组成员变量 在这里使用的是动态数组
 */

#include "Person.h"
class PersonSet
{
    friend ostream& operator<<(ostream& out,const PersonSet& set);
public:
    PersonSet(int inital_size = 4);
public:
    ~PersonSet();
    void printOn()const;
   
    void addElement(Person& p);
    Person& removeElement();
    Person& removeElement(int index);
    Person& nextElement();
    void reset();
    
    Person& operator[](int index);
    const Person& operator[](int index)const;
   
    int getSize(){return _size;}
private:
    Person** _elements;
    int      _capacity;
    int      _size;
    int      _index;
};
#endif /* defined(__PresonInfo__PersonSet__) */
