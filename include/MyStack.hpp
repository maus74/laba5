// Copyright 2020 Kondr11

#ifndef INCLUDE_MYSTACK_HPP_
#define INCLUDE_MYSTACK_HPP_

#include <type_traits>
#include <utility>
#include <exception>

template<class T> // шаблон для поддержки разных типов данных, передаваемых в параметр
struct StackNode{ // элемент стэка
    T value;
    StackNode *previous = nullptr;
};

template<class T>
class MainStack { // Класс реализующий методы стека
public:
    MainStack() = default; // Мы хотим использовать созданную компилятором версию этой функции
    MainStack(const MainStack &stack) = delete; //компилятор не должен автоматически генерировать эту функцию.
    MainStack(MainStack &&stack) noexcept = default;// нет исключений

    MainStack &operator=(const MainStack &stack)
            = delete;//перегрузка копирования
    MainStack &operator=(MainStack &&stack) noexcept
            = default;//перегрузка пермещения

    void push(T&& value){ // помещаем в конец стека
        auto *previousNode = headNode;
        headNode = new StackNode<T>{std::forward<T>(value), previousNode};
    }

    const T& head() const{ // получаем верхний элемент
        if (!headNode) {
            std::exception(); // если не существует верхнего элемента выводим исключение
        }

        return headNode->value;
    }

    ~MainStack() // функция вызываемая при уничтожении стека
    {
        while (headNode) {
            auto *currentNode = headNode;
            headNode = currentNode->previous;

            delete currentNode;
        }
    }

protected: // скрываем данные в protected (наследутся потомками)
    StackNode<T> *headNode = nullptr;
};







#endif // INCLUDE_MYSTACK_HPP_
