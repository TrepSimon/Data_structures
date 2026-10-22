
#include <iostream>
#include "Linked_list.h"
#include "Stack.h"
#include "Queue.h"

void test_linked_list() {
    Linked_list<int> list = Linked_list<int>();
    int x = 15;
    int y = 33;
    int z = 22;

    list.push(x);
    list.push(y);
    list.push(z);

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
        int z = idx;
        stack.push(z);
    }
    

    std::cout << stack.peek() << std::endl;
}

void test_queue() {
    Queue<int> q = Queue<int>();

    q.enqueue(-1);

    std::cout << q.dequeue() << std::endl;

    for (int idx = 0; idx < 25; idx++) {
        q.enqueue(idx);
        std::cout << q.get_front() << std::endl;
    }

    std::cout << q.dequeue() << std::endl;
    std::cout << q.get_front();
}

int main()
{
    test_queue();
}