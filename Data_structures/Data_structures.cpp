
#include <iostream>
#include "Linked_list.h"

int main()
{
    Linked_list<int> list = Linked_list<int>();

    list.push(15);
    list.push(33);
    list.push(22);

    //std::cout << list.pop() << std::endl;

    std::cout << list.remove(1) << std::endl;

    std::cout << list.at(0) << std::endl;
    std::cout << list.at(1) << std::endl;

    std::cout << list.pop() << std::endl;

    list.clear();

    list.front();
}