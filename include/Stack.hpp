// Copyright 2020 Kondr11
#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

#include "MyStack.hpp"

template<class T>
class Stack: public MainStack<T> { // наследуем методы от класса MainStack
public:
    void push(const T &value)
    {
        auto *prevNode =  MainStack<T>::headNode;

        MainStack<T>::headNode = new StackNode<T>{ // создаём новый элемент стека
                value, // помещаем значение
                prevNode, // текущую вершину стека делаем предыдущим элементом
        };
    }

    void pop()
    {
        if (!MainStack<T>::headNode) { // если не существует верхнего элемента выводим исключение
            throw std::exception();
        }

        auto *prevNode = MainStack<T>::headNode;                        // делаем вершиной предыдущий элемент
        MainStack<T>::headNode = MainStack<T>::headNode->previous;      // предыдущий элемент

        delete prevNode; // чистим объект
    }
};

#endif //INCLUDE_STACK_HPP_
