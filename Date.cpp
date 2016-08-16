//
//  Date.cpp
//  PresonInfo
//
//  Created by Mr_lee on 15-1-4.
//  Copyright (c) 2015年 北京渥瑞达科技发展有限公司. All rights reserved.
//

#include "Date.h"

Date::Date() {
    _year = 1970;
    _month = 12;
    _day = 12;
}

Date::Date(int y,int m,int d) {
    _year = y;
    _month = m;
    _day = d;
}


int Date::getYear()const {return _year;}

int Date::getMonth()const {return _month;}

int Date::getDay()const {return _day;}

void Date::setYear(int y) {
    _year = y;
}

void Date::setMonth(int m) {
    _month = m;
}

void Date::setDay(int d) {
    _day = d;
}

/**
 *  打印函数中不需要单独输出每一个变量的值
 *  只需要调用已经重载的输出运算符即可
 */
void Date::printOn()const {
    cout<<*this;
}

ostream& operator<<(ostream& out,const Date& date) {
    out<<"出生日期为："<<date._year<<"/"<<date._month<<"/"<<date._day<<endl;
    return out;
}
