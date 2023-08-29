#ifndef IABSTRACTFACTORY_H
#define IABSTRACTFACTORY_H
#include <memory>
#include "IButton.h"
#include "ICheckbox.h"
class IAbstractFactory{
    public:
    virtual std::unique_ptr<IButton> createButton() = 0;
    virtual std::unique_ptr<ICheckbox> createCheckbox() = 0;
};
#endif