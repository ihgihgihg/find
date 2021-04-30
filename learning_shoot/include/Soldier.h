#pragma once
#include "Gun.h"
#include <string>

class Solider {
public:
  Solider(std::string name);
  ~Solider();
  void addGun(Gun *ptr_gun);
  void addBulletToGun(int num);
  bool fire();

private:
  std ::string _name;
  Gun *_ptr_gun;
};
