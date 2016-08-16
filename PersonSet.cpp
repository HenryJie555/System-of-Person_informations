//
//  PersonSet.cpp
//  PresonInfo
//
//  Created by Mr_lee on 15-1-4.
//  Copyright (c) 2015年 北京渥瑞达科技发展有限公司. All rights reserved.
//

#include "PersonSet.h"

PersonSet::PersonSet(int inital_size)
{
    inital_size = (inital_size > 0 && inital_size < 1000 ) ? inital_size : 4;
    _elements = new Person*[inital_size];
    _capacity = inital_size;
    _size = 0;
    _index = 0;
}

PersonSet::~PersonSet()
{
    delete []_elements;
    _elements = NULL;
}

void PersonSet::printOn()const
{
    cout<<*this;
}

void PersonSet::addElement(Person& p)
{
    if (_size >= _capacity) {
        Person** temp = _elements;
        _elements = new Person*[_capacity*2];
        for (int i = 0; i<_size-1; i++) {
            _elements[i] = temp[i];
        }
        _capacity *= 2;
        delete []temp;
    }
    _elements[_size++] = &p;
}


Person& PersonSet::removeElement()
{
    _size--;
    Person* p = _elements[_size];
    if (_size <= _capacity/2) {
        Person** temp = _elements;
        _elements = new Person*[_capacity/2];
        for (int i = 0; i<_size; i++) {
            _elements[i] = temp[i];
        }
        _capacity /= 2;
        delete []temp;
    }
    return *p;
}

Person& PersonSet::removeElement(int index)
{
    if (index < 1 || index > _size) {
        exit(0);
    }
    _size--;
    Person* p = _elements[index-1];
    for (int i = index-1; i<_size; i++) {
        _elements[i] = _elements[i+1];
    }
    if (_size <= _capacity/2) {
        Person** temp = _elements;
        _elements = new Person*[_capacity/2];
        for (int i = 0; i<_size; i++) {
            _elements[i] = temp[i];
        }
        _capacity /= 2;
        delete []temp;
    }

    return *p;
}

Person& PersonSet::nextElement()
{
    _index = _index%_size;
    return *_elements[_index++];
}

//重置下标
void PersonSet::reset()
{
    _index = 0;
}

Person& PersonSet::operator[](int index)
{
    return *_elements[index];
}

const Person& PersonSet::operator[](int index)const
{
    return *_elements[index];
}

ostream& operator<<(ostream& out,const PersonSet& set)
{
    int s = set._size;
    for (int i = 0; i< s; i++) {
        //out<<set[i];
        out<<*set._elements[i];
    }
    return out;
}