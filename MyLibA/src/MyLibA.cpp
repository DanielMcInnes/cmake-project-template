#include <MyLibA/MyLibA.h>
#include <MyLibUtils/MyLibUtils.h>
#include <iostream>

namespace MyLibA {

void doSomething() {
    std::cout << "MyLibA::doSomething() was called.\n";
    MyLibUtils::utilFunction();
}

} // namespace MyLibA
