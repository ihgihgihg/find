/* hw2.cpp */
#include "solution.h"
#include "yaml.h"
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
#define pi 3.1415926535

int main() {
  //  已知参数【直线距离，旋转角度，旋转半径】顺时针为旋转角度为负
  double x0 = 0, y0 = 0, radd = 0;
  // double s = 2, rad = 90, r = 2;
  double mes[10][100];
  double s_sum;
  int m = 1;
  double s_[] = {2, 2, -2, -2, 2, 2, -2, -2};
  double r_[] = {2, 0, -2, 0, 2, 0, -2, 0};
  double rad_[] = {90, 0, 90, 0, -90, 0, -90, 0};
  double s, rad, r, d_s;
  int d = sizeof(s_) / sizeof(s_[0]);
  for (size_t i = 0; i < d; i++) {
    s = s_[i];
    rad = rad_[i];
    r = r_[i];
    s_sum += abs(s);
    rad = (rad / 180) * pi; //转弧度
    //引入新变量radd=车头朝向角(x坐标夹角)，每一段线段的起点和终点（x0，y0）、（xz，yz）
    //直线段
    //输入：起始点：（x1,y1），终点：（x2，y2）//
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0; //初始化变量起点终点
    x1 = x0;
    y1 = y0; //读取直线起点
    x2 = x1 + s * cos(radd);
    y2 = y1 + s * sin(radd);
    //解析式y-x1=(x-x1)*(y2-y1)/(x2-x1);
    x0 = x2, y0 = y2; //下一个点的起点赋值为直线终点
    if (r > 0) {
      // std::cout << x0 << "       " << y0 << "\r\n" << std::endl;
    }
    if (s != 0) {
      mes[0][m] = m;     //节点计数
      mes[1][m] = x0;    //终点x坐标
      mes[2][m] = y0;    //终点y坐标
      mes[3][m] = 0;     //直线0曲线1
      mes[4][m] = s_sum; //总长度
      mes[5][m] = 0;     //转角
      mes[6][m] = 0;     //半径
      mes[7][m] = radd;  //最终角
      d_s = s > 0 ? 1.0 : -1.0;
      mes[8][m] = d_s;
      /*       std::cout << mes[1][m] << "       " << mes[2][m] << "\r\n"
                      << mes[4][m] << std::endl; */
      m++;
    }
    //圆弧段
    //圆心坐标（xa，ya），起点坐标（xb，yb），终点坐标（xc，yc）
    double xa = 0, ya = 0, xb = 0, yb = 0, xc = 0, yc = 0, sgn;
    s_sum += abs(r) * abs(rad);
    sgn = rad > 0 ? 1.0 : -1.0;
    xb = x0, yb = y0;                       //读取起点坐标
    xa = xb + r * cos(sgn * pi / 2 + radd); //求圆心坐标
    ya = yb + r * sin(sgn * pi / 2 + radd);
    double xab = xb - xa, yab = yb - ya; //向量ab
    double xac = xab * cos(rad) - yab * sin(rad),
           yac = xab * sin(rad) + yab * cos(rad);
    xc = xa + xac;
    yc = ya + yac;
    radd += rad;
    x0 = xc, y0 = yc;
    if (r != 0) {
      mes[0][m] = m;     //节点计数
      mes[1][m] = x0;    //终点x坐标
      mes[2][m] = y0;    //终点y坐标
      mes[3][m] = 1;     //直线0曲线1
      mes[4][m] = s_sum; //总长度
      mes[5][m] = rad;   //转角
      mes[6][m] = r;     //半径
      mes[7][m] = radd;  //最终角
      mes[8][m] = xa;    //圆心x
      mes[9][m] = ya;    //圆心y
      /*      std::cout << mes[1][m] << "       " << mes[2][m] << "\r\n"
            << mes[4][m] << std::endl; */
      m++;
    }
    //圆弧解析式（x-xa）*（x-xa）+（y-ya）*（y-ya）=r*r 取值范围为起点到终点的弧
    // std::cout << x0 << "       " << y0 << "\r\n" << std::endl;
  }
  //给点部分：
  int n = 0; //确定直线段
  double b_x0, e_x0, b_y0, e_y0, d_x0, d_y0, r_x0, r_y0;
  double s0 = 100;
  double d_rad, d_radd;
  for (int i = 0; i < m; i++) {
    n = i;
    if (s0 <= mes[4][n]) {
      // std::cout << n << std::endl;
      break;
    }
    if (s0 > mes[4][m - 1]) {
      s0 = mes[4][m - 1];
    }
  }
  /*   if (n < m) {
      s0 = mes[4][m - 1];
    } */
  // std::cout << mes << std::endl;
  //直线段
  if (mes[3][n] == 0) {
    b_x0 = mes[1][n - 1];
    b_y0 = mes[2][n - 1];
    e_x0 = mes[1][n];
    e_y0 = mes[2][n];
    d_x0 = b_x0 + mes[8][n] * (s0 - mes[4][n - 1]) * cos(mes[7][n - 1]);
    d_y0 = b_y0 + mes[8][n] * (s0 - mes[4][n - 1]) * sin(mes[7][n - 1]);
    // std::cout << b_x0 << "      " << b_y0 << std::endl;
    // std::cout << e_x0 << "      " << e_y0 << std::endl;
    std::cout << d_x0 << "      " << d_y0 << std::endl;
    std::cout << mes[7][n] << "      " << mes[6][n] << std::endl; // phi和r
  }
  //圆弧段
  if (mes[3][n] == 1) {
    b_x0 = mes[1][n - 1];
    b_y0 = mes[2][n - 1];
    e_x0 = mes[1][n];
    e_y0 = mes[2][n];
    r_x0 = mes[8][n];
    r_y0 = mes[9][n];
    d_rad =
        mes[5][n] * (s0 - mes[4][n - 1]) / (abs(mes[6][n]) * abs(mes[5][n]));
    double xbr = b_x0 - r_x0, ybr = b_y0 - r_y0;
    //向量起点到圆心
    double xdr = xbr * cos(d_rad) - ybr * sin(d_rad),
           ydr = xbr * sin(d_rad) + ybr * cos(d_rad);
    d_x0 = r_x0 + xdr;
    d_y0 = r_y0 + ydr;
    d_radd = d_rad + mes[7][n - 1];
    // std::cout << b_x0 << "      " << b_y0 << std::endl;
    // std::cout << e_x0 << "      " << e_y0 << std::endl;
    std::cout << d_x0 << "      " << d_y0 << std::endl;
    std::cout << d_radd << "      " << mes[6][n] << std::endl; // phi和r
  }
  return 0;
}
