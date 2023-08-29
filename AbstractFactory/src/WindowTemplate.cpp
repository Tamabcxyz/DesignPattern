#include "WindowTemplate.h"
std::unique_ptr<ICheckbox> WindowTemplate::createCheckbox(){
    return std::make_unique<Window::WindowCheckBox>();
}
std::unique_ptr<IButton> WindowTemplate::createButton(){
    return std::make_unique<Window::WindowButton>();
}