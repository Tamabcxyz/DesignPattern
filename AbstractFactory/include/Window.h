#pragma one
#include "IButton.h"
#include "ICheckbox.h"
#include <iostream>
namespace Window {
class WindowCheckBox : public ICheckbox {
public:
  void pain() override;
};
class WindowButton : public IButton {
public:
  void pain() override;
};
} // namespace Window