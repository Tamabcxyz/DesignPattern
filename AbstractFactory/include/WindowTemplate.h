#pragma one
#include "IAbstractFactory.h"
#include "Window.h"
class WindowTemplate : public IAbstractFactory {
    public:
    std::unique_ptr<ICheckbox> createCheckbox() override;
    std::unique_ptr<IButton> createButton() override;
};