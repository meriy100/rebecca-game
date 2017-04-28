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
