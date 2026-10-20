
#include <iostream>
#include "Linked_list.h"

int main()
{
    Linked_list<int> list = Linked_list<int>();

    list.push(15);
    list.push(33);

    std::cout << list.at(1) << std::endl;

    std::cout << list.remove(0) << std::endl;
}