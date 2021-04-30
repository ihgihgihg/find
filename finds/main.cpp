#include "Givepoints.h"
#include <iostream>
int main() {
  double s0 = 100;
  double x0 = 0, y0 = 0, radd = 0; //初始数据
  /*   double s_[] = {2, 2, -2, -2, 2, 2, -2, -2};
    double r_[] = {2, 0, -2, 0, 2, 0, -2, 0};
    double rad_[] = {90, 0, 90, 0, -90, 0, -90, 0}; */
  GivePoints point(s0, x0, y0, radd);
  point.Points();
  return 0;
}
