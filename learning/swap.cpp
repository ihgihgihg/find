#include "swap.h"
// use namespace swap;
void swap::run() {
  int temp;
  temp = _a;
  _a = _b;
  _b = temp;
}
void swap::printinfo() {
  std::cout  << "a=" << _a << std::endl;
  std::cout  << "b=" << _b << std::endl;
}