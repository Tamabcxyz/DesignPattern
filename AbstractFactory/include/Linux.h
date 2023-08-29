#pragma one
#include "IButton.h"
#include "ICheckbox.h"
#include <iostream>
namespace Linux {
class LinuxCheckBox : public ICheckbox {
public:
  void pain() override;
};
class LinuxButton : public IButton {
public:
  void pain() override;
};
} // namespace Linux