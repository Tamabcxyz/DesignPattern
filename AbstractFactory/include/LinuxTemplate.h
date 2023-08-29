#pragma one
#include "IAbstractFactory.h"
#include "Linux.h"
class LinuxTemplate : public IAbstractFactory {
    public:
    std::unique_ptr<ICheckbox> createCheckbox() override;
    std::unique_ptr<IButton> createButton() override;
};
