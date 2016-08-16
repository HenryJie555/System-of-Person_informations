//
//  main.cpp
//  PresonInfo
//
//  Created by Mr_lee on 15-1-4.
//  Copyright (c) 2015年 北京渥瑞达科技发展有限公司. All rights reserved.
//

#include <iostream>
#include "PersonSet.h"

int main(int argc, const char * argv[])
{
    Person *p1 = new Person("Lou", "lou@chat.ca", 20, 6, 1960);
    Person *p2 = new Person("Frank", "f123@chat.ca", 20, 3, 1967);
    Person *p3 = new Person("Ann", "ann@chat.ca", 20, 8, 1960);
    
    PersonSet boys;
    boys.addElement(*p1);
    boys.addElement(*p2);
    boys.addElement(*p3);
  
    cout<<boys;
    cout<<"-------------------------------------------"<<endl;
    int numberOfBoys = boys.getSize();
    for (int i = 0; i<numberOfBoys; i++) {
      Person& boy = boys.removeElement();
        cout<<boy<<endl;
        //delete &boy;
    }
    
    boys.addElement(*p1);
    boys.addElement(*p2);
    boys.addElement(*p3);

    return 0;
}

