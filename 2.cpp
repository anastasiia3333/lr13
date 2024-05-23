#include <iostream>
#include <cstdlib>
#include <typeinfo>
using namespace std;

class Shape { public: virtual void example() = 0; };

class Rectangle : public Shape
{
public:
    void example()
    {
        cout << "*******\n*******\n*******\n";
    }
};

class Triangle : public Shape
{
public:
    void example()
    {
        cout << "  *\n ***\n*****\n";
    }
};

class Line : public Shape
{
public:
    void example()
    {
        cout << "*******\n";
    }
};

class NullShape : public Shape
{
public:
    void example() {}
};
 
Shape *generator()
{
    switch (rand() % 4)
    {
    case 0:
        return new Line;
    case 1:
        return new Rectangle;
    case 2:
        return new Triangle;
    case 3:
        return new NullShape;
    }
    return NULL;
}
 
int main()
{
    Shape *p;
    // В циклі генеруються об'єкти, які є похідними від Shape, і перевіряється їх тип
    for (int i = 0; i < 10; i++)
    {
    p = generator(); 
    cout << "\nclass " << typeid(*p).name() << endl; // Виводить назву класу цього об'єкта
    NullShape *null;
    // Спроба перетворити вказівник p на вказівник типу NullShape
    if(!(null = dynamic_cast <NullShape *> (p))){
        // Якщо p не є об'єктом класу NullShape, виконується метод example()
        p->example(); 
    }
    // Якщо p є об'єктом класу NullShape, метод example() не викликається
}
    return 0;
}
