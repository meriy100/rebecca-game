//
//  ApplicationMaster.hpp
//  Rebecca
//
//  Created by 苅宿航太 on 2017/04/27.
//  Copyright © 2017年 meriy100. All rights reserved.
//

#ifndef ApplicationMaster_hpp
#define ApplicationMaster_hpp

#include "Unit.hpp"
#include "UnitRenderer.hpp"

class ApplicationMaster {
public:
    int x;
    int y;
    Unit* unit;
    ApplicationMaster();
    void move();
    void disp();
};


#endif /* ApplicationMaster_hpp */
