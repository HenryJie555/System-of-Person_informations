//
//  Date.h
//  PresonInfo
//
//  Created by Mr_lee on 15-1-4.
//  Copyright (c) 2015年 北京渥瑞达科技发展有限公司. All rights reserved.
//

/**
 *  #ifndef
 *  #define
 *   防止头文件重复包含
 *  #endif
 */
#ifndef __PresonInfo__Date__
#define __PresonInfo__Date__

#include <iostream>
using namespace std;
/**
 *  日期类,记录人的出生年月日
 */
class Date
{
    friend ostream& operator<<(ostream&,const Date&);
public:
    Date();
    Date(int y,int m,int d);
    
public:
    int getYear()const;
    int getMonth()const;
    int getDay()const;
    
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    
public:
    void printOn()const;
    
private:
    int _year;
    int _month;
    int _day;
};

#endif /* defined(__PresonInfo__Date__) */
