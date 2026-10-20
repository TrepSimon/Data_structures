
#include <iostream>
#include "Linked_list.h"

int main()
{
    Linked_list<int> list = Linked_list<int>();

    list.push(15);

    std::cout << list.at(0) << std::endl;
}
