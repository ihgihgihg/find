/* hw2.cpp */
#include "solution.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
// int main() {
//   Solution sln;
//   sln.Say();
//   getchar();
//   return 0;
// 需要判断处于那一段，那一段是什么线
int main() {
  //直线段
  //输入：起始点：（xi，yi），终点：（xj，yj）//FIXME:
  double xi = 0.0, yi = 0.0, xj = 2.0, yj = 0.0;           //
  double s0 = pow(pow(yj - yi, 2) + pow(xj - xi, 2), 0.5); // TODO:
  //直线段里程
  //给出点（x0，y0）
  //直线段映射点(xa,ya)
  double y0 = -0.7, x0 = 1.7;
  double xa, ya; //映射点
  double k = (yj - yi) / (xj - xi);
  if (yi == yj) {
    xa = x0;
    ya = yi;
  } else if (xj == xi) {
    xa = xi;
    ya = y0;
  } else {
    xa = (y0 + x0 / k - yi + k * xi) / (k + 1 / k);
    ya = yi + k * (xa - xi);
  }
  //里程
  double s = pow(pow(ya - yi, 2) + pow(xa - xi, 2), 0.5);
  //圆弧段
  //输入：起始点：（x1，y1），终点：（x2，y2），圆心坐标（x，y）,转弯半径r，弦长c，转弯角度rad
  double x1 = 2.0, y1 = 0.0, x2 = 2.5, y2 = -0.5, x = 2, y = -0.5;
  double r = pow(pow(y2 - y, 2) + pow(x2 - x, 2), 0.5);
  double c = pow(pow(y2 - y1, 2) + pow(x2 - x1, 2), 0.5);
  double c2 = pow(pow(y0 - y1, 2) + pow(x0 - x1, 2), 0.5);
  double a = pow(pow(y1 - y, 2) + pow(x1 - x, 2), 0.5);
  double b = pow(pow(y0 - y, 2) + pow(x0 - x, 2), 0.5);
  double rad = acos(1 - 0.5 * pow(c, 2) / pow(r, 2));
  double rad0 = acos((pow(a, 2) + pow(b, 2) - pow(c2, 2)) / (2 * a * b));
  double s2 = r * (rad - rad0);
  std::cout << s << "\r\n" << std::endl;
  return 0;
}