#include <unistd.h>
#include <iostream>
#include "grove.h"

int
main(int argc, char **argv)
{
    upm::GroveButton* button = new upm::GroveButton(8);
    std::cout << button->value() << std::endl;
    sleep(1);
    delete button;
    return 0;
}
