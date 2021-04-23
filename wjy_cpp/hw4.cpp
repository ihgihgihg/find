/* hw2.cpp */
#include "solution.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#define pi 3.1415926535
int main() {
  double s = 2, rad = 90, r = -2, x0 = 0, y0 = 0, radd = 0, xz = 0, yz = 0;
  rad = (rad / 180) * pi;
  double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
  x1 = x0;
  y1 = y0;
  x2 = x1 + s * cos(radd);
  y2 = y1 + s * sin(radd);
  x0 = x2, y0 = y2;
  double xa = 0, ya = 0, xb = 0, yb = 0, xc = 0, yc = 0;
  xb = x0, yb = y0;
#include <stdio.h>
#include <stdlib.h>

struct _pid{
    float SetSpeed;    //定义设定值
    float ActualSpeed; //定义实际值
    float err;         //定义偏差值
    float err_next;    //定义上一个偏差值
    float err_last;    //定义最上前的偏差值
    float Kp, Ki, Kd;  //定义比例、积分、微分系数
  } pid;

  void PID_init() {
    pid.SetSpeed = 0.0;
    pid.ActualSpeed = 0.0;
    pid.err = 0.0;
    pid.err_last = 0.0;
    pid.err_next = 0.0;
    pid.Kp = 0.2;
    pid.Ki = 0.015;
    pid.Kd = 0.2;
  }

  float PID_realize(float speed) {
    pid.SetSpeed = speed;
    pid.err = pid.SetSpeed - pid.ActualSpeed;
    float incrementSpeed = pid.Kp * (pid.err - pid.err_next) +
                           pid.Ki * pid.err +
                           pid.Kd * (pid.err - 2 * pid.err_next + pid.err_last);
    pid.ActualSpeed += incrementSpeed;
    pid.err_last = pid.err_next;
    pid.err_next = pid.err;
    return pid.ActualSpeed;
  }

  int main() {
    PID_init();
    int count = 0;
    while (count < 1000) {
      float speed = PID_realize(200.0);
      printf("%f\n", speed);
      count++;
    }
    return 0;
  }
  yc = ya + yac;
  radd += rad;
  x0 = xc, y0 = yc;
  std::cout << xc << "       " << yc << "\r\n" << std::endl;
  return 0;
}