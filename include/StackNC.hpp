// Copyright 2020 Kondr11

#ifndef INCLUDE_STACKNC_HPP_
#define INCLUDE_STACKNC_HPP_

#include "MyStack.hpp"

template<class T>
class StackNC : public MainStack<T> { // наследуем методы от класса MainStack
public:
    template <typename ... Args>
    void push_emplace(Args &&... value) // передаем на добавление несколько элементов
    {
        auto *prevNode = MainStack<T>::headNode;

        MainStack<T>::headNode = new StackNode<T>{
                {std::forward<Args>(value)...}, // передаём управление наборов аргуметов с помощью forward новому элементу стека
                prevNode,
        };
    }

    T pop()
    {
        if (!MainStack<T>::headNode) { // если не существует верхнего элемента выводим исключение
            throw std::exception();
        }

        auto *prevNode = MainStack<T>::headNode;                        // делаем вершиной предыдущий элемент
        MainStack<T>::headNode = MainStack<T>::headNode->previous;     // предыдущий элемент

        T value = std::move(prevNode->value); // очищаем значение
        delete prevNode;                      // созданное с помощью forward
        return value;
    }
};


#endif //INCLUDE_STACKNC_HPP_
