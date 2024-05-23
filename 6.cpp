#include <iostream>
#include <typeinfo>
#include <cmath>
#include <cstdlib>
#include <stdexcept>
using namespace std;
 
template <class T> class Num
{
public:
    T x;
    Num(T i) { x = i; }
    virtual T get_val() { return x; }
};
 
template <class T> class Square : public Num<T>
{
public:
    Square(T i) : Num<T>(i) {}
    T get_val() { return this->x * this->x; }
};
 
template <class T> class Sqr_root : public Num<T>
{
public:
    Sqr_root(T i) : Num<T>(i) {}
    T get_val() { return sqrt((double)this->x); }
};
 
Num<double> *generator()
{
    Num<double> *obj = nullptr;
    try {
        switch (rand() % 2)
        {
        case 0:
            obj = new (nothrow) Square<double>(rand() % 100);
            if (!obj) throw bad_alloc();
            break;
        case 1:
            obj = new (nothrow) Sqr_root<double>(rand() % 100);
            if (!obj) throw bad_alloc();
            break;
        }
    } catch (const bad_alloc& e) {
        cerr << "Memory allocation failed: " << e.what() << '\n';
    }
    return obj;
}
 
int main()
{
    Num<double> ob1(5), *p1;
    Square<double> ob2(50.0);
    Sqr_root<double> ob3(102.2);
    cout << typeid(ob1).name() << endl;
    cout << typeid(ob2).name() << endl;
    cout << typeid(ob3).name() << endl;
    // Перевірка, чи тип ob2 є Square<double>
    if (typeid(ob2) == typeid(Square<double>))
        cout << "is Square <double>\n";  // Якщо так, вивести повідомлення
    // Встановлення вказівника p1 на об'єкт ob2
    p1 = &ob2;
    // Перевірка, чи тип об'єкта, на який вказує p1, відрізняється від типу ob1
    if (typeid(*p1) != typeid(ob1))
        cout << "Value is: " << p1->get_val() << "\n\n";  // Якщо так, вивести значення об'єкта
    cout << "--Random generation of objects--\n"; 
    for (int i = 0; i < 10; i++)
    {
        p1 = generator();  // Виклик функції generator, яка повертає вказівник на об'єкт Num<double>
        // Перевірка, чи був об'єкт успішно створений
        if (!p1) {
            cerr << "Failed to generate object.\n";  
            continue;  // Пропустити ітерацію циклу
        }
        // Перевірка типу об'єкта: чи є він екземпляром класу Square<double>
        if (typeid(*p1) == typeid(Square<double>))
            cout << "Square object ";  

        // Перевірка типу об'єкта: чи є він екземпляром класу Sqr_root<double>
        if (typeid(*p1) == typeid(Sqr_root<double>))
            cout << "Sqr_root object "; 
        cout << "value is: " << p1->get_val() << endl;
        delete[] p1;  
        }
        return 0;
    }


/* Функція generator() створює об'єкти типу Square<double> або Sqr_root<double> 
з використанням new (nothrow), що повертає nullptr замість виключення, 
якщо пам'ять не може бути виділена. Якщо об'єкт не створюється, 
кидається виняток bad_alloc, який перехоплюється і обробляється, 
повідомляючи про помилку виділення */






