#include "Unit.hpp"

#include "defines.h"
#include <iostream>
#include <random>
#include "ApplicationMaster.hpp"

Unit::Unit(float m_x, float m_y, float m_r) {
  x = m_x;
  y = m_y;
  v = 2.0f;
  r = m_r;
  direction = 0.0f;
}

void Unit::perform(ApplicationMaster* applicationMaster) {
  if (applicationMaster->tile[(int)(x / 10)][(int)(y / 10)] > 0) {
    v = 0.f;
    applicationMaster->tile[(int)(x / 10)][(int)(y / 10)]--;
  } else {
    v = 2.0f;
  }

  float vx = v * cos(direction / 180.0 * Pai);
  float vy = v * sin(direction / 180.0 * Pai);

  direction = wallCollision(vx, vy);
  if ( applicationMaster->time_count % 60 == 0 ) {
    direction = applicationMaster->random() % 360;
    direction = wallCollision(vx, vy);
  }
  x += vx;
  y += vy;
}

float Unit::wallCollision(float vx, float vy) {
  float nextx = x + vx;
  float nexty = y + vy;
  if (nextx + r >= WIDTH) {
    return 180 - direction;
  } else if (nextx - r <= 0) {
    return 180 - direction;
  }

  if (nexty + r >= HEIGHT) {
    return 360 - direction;
  } else if (nexty - r <= 0) {
    return 360 - direction;
  }
  return direction;
}
