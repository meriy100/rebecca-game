//
//  UnitRenderer.hpp
//  Rebecca
//
//  Created by 苅宿航太 on 2017/04/27.
//  Copyright © 2017年 meriy100. All rights reserved.
//

#ifndef UnitRenderer_hpp
#define UnitRenderer_hpp

#include <stdio.h>
class Unit;
class UnitRenderer {
public:
    Unit* unit;
    UnitRenderer(Unit* m_unit);
    
    void render();
};

#endif /* UnitRenderer_hpp */
