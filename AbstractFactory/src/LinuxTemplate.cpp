#include "LinuxTemplate.h"
std::unique_ptr<ICheckbox> LinuxTemplate::createCheckbox(){
    return std::make_unique<Linux::LinuxCheckBox>();
}
std::unique_ptr<IButton> LinuxTemplate::createButton(){
    return std::make_unique<Linux::LinuxButton>();
}