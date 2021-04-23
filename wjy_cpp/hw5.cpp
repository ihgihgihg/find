#include <stdio.h>
#include <stdlib.h>

struct _pid {
  float SetS;       //定义设定值
  float ActS;       //定义实际值
  float err;        //定义偏差值
  float err_last;   //定义上一个偏差值
  float Kp, Ki, Kd; //定义比例、积分、微分系数
  float voltage;    //定义电压值（控制执行器的变量）
  float integral;   //定义积分值
  float dt;
  float derivative;
} pid;
void PID_init() {
  printf("PID_init begin \n");
  pid.SetS = 0.0;
  pid.ActS = 0.0;
  pid.err = 0.0;
  pid.err_last = 0.0;
  pid.voltage = 0.0;
  pid.integral = 0.0;
  pid.Kp = 0.6;
  pid.Ki = 0.0486;
  pid.Kd = 0.4;
  pid.dt = 0.1;
  pid.derivative = 0;
  printf("PID_init end \n");
}
float PID_realize(float S) {
  pid.SetS = S;
  pid.err = pid.SetS - pid.ActS;                      //偏差
  pid.integral += pid.err * pid.dt;                   //积分部分累计误差
  pid.derivative = (pid.err - pid.err_last) / pid.dt; //微分
  pid.voltage = pid.Kp * pid.err + pid.Ki * pid.integral +
                pid.Kd * pid.derivative; // kp*偏差+ki*累计误差+kd*微分
  pid.err_last = pid.err;                //保存偏差
  pid.ActS += pid.voltage * pid.dt;      //保存实际值
  return pid.ActS;
}
int main() {
  PID_init();
  int count = 0;
  while (count < 50) {
    float S = PID_realize(200.0);
    printf("%f\n", S);
    printf("%f\n", pid.voltage);
    count++;
  }
  /* struct _pid {
    float SetS;    //定义设定值
    float ActS; //定义实际值
    float err;         //定义偏差值
    float err_next;    //定义上一个偏差值
    float err_last;    //定义最上前的偏差值
    float Kp, Ki, Kd;  //定义比例、积分、微分系数
  } pid; */

  /* void PID_init() {
    pid.SetS = 0.0;
    pid.ActS = 0.0;
    pid.err = 0.0;
    pid.err_last = 0.0;
    pid.err_next = 0.0;
    pid.Kp = 0.25;
    pid.Ki = 0.23;
    pid.Kd = 0.15;
  } */

  /* float PID_realize(float speed) {
    pid.SetS = speed;
    pid.err = pid.SetS - pid.ActS;
    float incrementSpeed = pid.Kp * (pid.err - pid.err_next) + pid.Ki * pid.err
  + pid.Kd * (pid.err - 2 * pid.err_next + pid.err_last); pid.ActS +=
  incrementSpeed; pid.err_last = pid.err_next; pid.err_next = pid.err; return
  pid.ActS;
  } */

  return 0;
}