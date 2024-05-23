#include <iostream>
using namespace std;
#define SIZE 2  // Визначення максимальної кількості елементів у стеку/черзі
 
template <class T>
class DataStruct {
protected:
    T stck[SIZE];  // Масив для зберігання елементів стеку або черги
    int tos;      

public:
    DataStruct() : tos(0) {}  
    virtual void push(T obj) = 0;  //  віртуальна функція для додавання елементів
    virtual T pop() = 0;          //  віртуальна функція для вилучення елементів
};
 
template <class T>
class Stack : public DataStruct<T> {  
public:
    void push(T obj) override;  
    T pop() override;           
};
 
template <class T>
void Stack<T>::push(T obj) {
    if (this->tos == SIZE) {  // Перевірка, чи стек повний
        cout << "Stack is full\n";
        throw 0;  // Кидання винятку
    }
    this->stck[this->tos++] = obj;  // Додавання елемента і збільшення індексу
}
 
template <class T>
T Stack<T>::pop() {
    if (this->tos == 0) {  // Перевірка, чи стек порожній
        cout << "Stack is empty\n";
        throw 0;  // Кидання винятку
    }
    return this->stck[--this->tos];  // Зменшення індексу і повернення елемента
}
 
template <class T>
class Queue : public DataStruct<T> {
    int bos;  // Індекс для початку черги
 
public:
    Queue() : bos(0) {}  // Конструктор, ініціалізує індекс початку черги
    void push(T obj) override;  
    T pop() override;           
};
 
template <class T>
void Queue<T>::push(T obj) {
    if (this->tos == SIZE) {  // Перевірка, чи черга повна
        cout << "\nQueue is full\n";
        throw 0;  // Кидання винятку
    }
    this->stck[this->tos++] = obj;  // Додавання елемента у кінець черги
}
 
template <class T>
T Queue<T>::pop() {
    if (bos == this->tos) {  // Перевірка, чи черга порожня
        cout << "\nQueue is empty\n";
        throw 0;  // Кидання винятку
    }
    return this->stck[bos++];  // Вилучення елемента з початку черги
}
 
template <class T>
DataStruct<T>* DataStructFactory(char what) {
    if (what == 's')
        return new Stack<T>;  // Створення стеку
    else 
        return new Queue<T>;  // Створення черги
}
 
int main()

 {
    DataStruct<int>* s = DataStructFactory<int>('s');  // Створення стеку для int
    DataStruct<char>* q = DataStructFactory<char>('q');  // Створення черги для char

    try {
        s->push(1);
        s->push(2);
        s->push(3);  // Спроба додати третій елемент в стек, що викличе виняток
    }
    catch (int) {}
 
    try {
        for (int i = 0; i < 3; i++) {
            cout << "S pop: " << s->pop() << endl;  // Вилучення елементів з стеку
        }
    }
    catch (int) {}
 
    try {
        q->push('a');
        q->push('b');
        q->push('c');  // Спроба додати третій елемент в чергу, що викличе виняток
    }
    catch (int) {}
 
    try {
        for (int i = 0; i < 3; i++) {
            cout << "Q pop: " << q->pop() << endl;  // Вилучення елементів з черги
        }
    }
    catch (int) {}
 
    delete[] s;  
    delete[] q;  

    return 0;
}