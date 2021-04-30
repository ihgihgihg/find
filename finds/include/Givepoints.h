#pragma once
#include <vector>
class GivePoints {
private:
  double _s0;
  double x_begin;
  double y_begin;
  double radd_begin;
  /*   double s_[] = {2, 2, -2, -2, 2, 2, -2, -2};
    double r_[] = {2, 0, -2, 0, 2, 0, -2, 0};
    double rad_[] = {90, 0, 90, 0, -90, 0, -90, 0};
   */
public:
  GivePoints(double s0, double x0, double y0, double radd) {
    this->_s0 = s0;
    this->x_begin = x0;
    this->y_begin = y0;
    this->radd_begin = radd;
  }
  double Points();
};
