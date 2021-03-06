#include "ApplicationMaster.hpp"
#include <iostream>

#include "DrawFuncs.hpp"

#include "Unit.hpp"
#include "UnitRenderer.hpp"

// TODO
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

int nolumn(int value) {
  return value < 0 ? (0 - value) : value;
}

ApplicationMaster::ApplicationMaster() {
  for(int i = 0; i < 1; i++) {
    units.push_back(
      new Unit(
        nolumn(random() % WIDTH),
        nolumn(random() % HEIGHT),
        4.0f,
        random() % 360
      )
    );
  }
  time_count = 0;
  std::random_device rd;
  for(int x = 0; x < MAP_WIDTH; x++) {
    for(int y = 0; y < MAP_HEIGHT; y++) {
      tile[x][y] = nolumn(rd() % 100);
    }
  }
  //std::mt19937 mt(rd()); // TODO
}

void ApplicationMaster::perform(Mouse mouse) {
  time_count++;
  if (mouse.left == 1) {
    units.push_back(new Unit(mouse.x, mouse.y, 4.0f, random() % 360));
  }
  for(auto itr = units.begin(); itr != units.end();) {
    (*itr)->perform(this);
    if (!(*itr)->isAlive()) {
      printf("%d %d\n", (int)(*itr)->x / 10, (int)(*itr)->y / 10);
      // TODO
      int tilex = (int)(*itr)->x / 10;
      int tiley = (int)(*itr)->y / 10;
      if (tilex > 10 && tiley > 10 && tilex < MAP_WIDTH - 5 && tiley < MAP_HEIGHT - 5 ) {
        for(int x = tilex - 5; x < tilex + 5; x++ )
          for(int y = tiley - 5; y < tiley + 5; y++ )
            if (tilex >= 0 && tilex < MAP_WIDTH && tiley >= 0 && tiley < MAP_HEIGHT)
              tile[x][y] += 10;
      }
      units.erase(itr);
    }
    ++itr;
  }
}

void ApplicationMaster::disp() {
  for(int x = 0; x < 120; x++) {
    for(int y = 0; y < 80; y++) {
      glColor4f(
          (100 - tile[x][y]) / 100.0f,
          1.0f,
          (100 - tile[x][y])/ 100.0f,
          1.0f);
      SquareFill2D(x * 10, y * 10, x * 10 + 10, y * 10 + 10);
    }
  }
  UnitRenderer* renderer;
  for(auto itr = units.begin(); itr != units.end(); ++itr) {
    renderer = new UnitRenderer(*itr);
    renderer->render();
  }
  std::stringstream value;
  value << "Unit" << units.size();
  PrintString(value, WIDTH - 80, HEIGHT - 80);
}

int ApplicationMaster::random() {
  return rd();

}
