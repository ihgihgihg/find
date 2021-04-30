#include "swap.h"
int main(int argc, char **argv) {
  swap myswap(10, 20);
  myswap.printinfo();
  myswap.run();
  myswap.printinfo();
  return 0;
}