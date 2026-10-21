
#include <iostream>
#include "Linked_list.h"
#include "Stack.h"

void test_linked_list() {
    Linked_list<int> list = Linked_list<int>();
    int x = 15;
    int y = 33;
    int z = 22;

    list.push(&x);
    list.push(&y);
    list.push(&z);

    //std::cout << list.pop() << std::endl;

    std::cout << list.remove(1) << std::endl;

    std::cout << list.at(0) << std::endl;

    list.at(0) = 10;

    std::cout << list.at(0) << std::endl;
    list.back() = 3; 
}

void test_stack() {
    Stack<int> stack = Stack<int>();
    int x = 10;
    int y = 20;

    for (int idx = 0; idx < 25; idx++) {
        int* z = (int*)malloc(sizeof(int));
        *z = idx;
        stack.push(z);
    }
    

    std::cout << stack.peek() << std::endl;
}

int main()
{
    test_stack();

}