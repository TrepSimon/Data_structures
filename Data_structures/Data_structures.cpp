
#include <iostream>
#include "Linked_list.h"
#include "Stack.h"
#include "Queue.h"
#include "List.h"

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

    list.print();

    std::cout << list.index_of(22) << std::endl;

    list.insert(1, 44);

    std::cout << list.index_of(225) << std::endl;

    list.print();

    std::cout << list.at(0) << std::endl;
    list.back() = 3; 

    list.clear();

    for (int idx = 0; idx < 25; idx++) {
        list.push(idx);
    }
    
    for (auto i : list) {
        std::cout << &i << std::endl;
    }
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

void test_list() {
    auto list = List<int>();

    list.add(12);
    list.add(22);
    list.add(44);

    std::cout << list.get_at(0) << std::endl;

    std::cout << list.size() << "\n" << list.remove_at(1) << "\n" << list.size() << std::endl;
    std::cout << list.remove(12) << "\n" << list.size() << std::endl;

    list.insert(1, 33);
    std::cout << list.get_at(1) << std::endl;

    list.clear();

    for (int idx = 0; idx < 25; idx++) {
        list.add(idx);
    }

    std::cout << "\n\n\n\n";

    for (auto i : list) {
        std::cout << i << std::endl;
    }


    std::cout << "\n\n\n\n";
    auto end = list.rEnd();

    for (auto it = list.rBegin(); it != end; it--) {
        std::cout << *it << std::endl;
    }
}

int main()
{
    //test_list();
    test_linked_list();
}