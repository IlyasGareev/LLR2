#include <iostream>
#include<conio.h>

class Point {
protected:
    int x, y;
public:
    Point() {                      //конструктор 
        printf("Point()\n");      //отладочный вывод
        x = 0;
        y = 0;
    }
    Point(int x, int y) {                   //конструктор с параметрами 
        printf("Point(int x, int y)\n");
        this->x = x;
        this->y = y;
    }
    Point(const Point& p) {                   //конструктор копирования  
        printf("Point(const Point &p)\n");
        x = p.x;
        y = p.y;
    }
    virtual ~Point() {                                   //деструктор
        printf("%d, %d\n", x, y);                //вывод текущего состояния объекта
        printf("~Point()\n");
    }
    void move(int dx, int dy) {
        x = x + dx;
        y = y + dy;
    }
    void reset();
};

void Point::reset() {
    x = 0;
    y = 0;
}

class ColoredPoint : public Point {                          //класс потомок
protected:
    int color;
public:
    ColoredPoint() : Point() {
        printf("ColoredPoint()\n");
        color = 0;
    }
    ColoredPoint(int x, int y, int color) : Point(x, y) {
        printf("ColoredPoint(int x, int y)\n");
        this->color = color;
    }
    ColoredPoint(const ColoredPoint& p) {
        printf("ColoredPoint(const Point &p)\n");
        x = p.x;
        y = p.y;
        color = p.color;
    }
    ~ColoredPoint() {
        printf("%d, %d color=%d\n", x, y, color);                //вывод текущего состояния объекта
        printf("~ColoredPoint()\n");
    }
    void ChangeColor(int NewColor) {
        color = NewColor;
    }
};
class Section {
protected:
    Point* p1;
    Point* p2;
public:
    Section() {                      //конструктор 
        printf("Section()\n");      //отладочный вывод
        p1 = new Point;
        p2 = new Point;
    }
    Section(int x1, int y1, int x2, int y2) {                   //конструктор с параметрами 
        printf("Section(int x1, int y1, int x2, int y2)\n");
        p1 = new Point(x1, y1);
        p2 = new Point(x2, y2);
    }
    Section(const Section& s) {                   //конструктор копирования  
        printf("Section(const Section &s)\n");
        p1 = new Point(*(s.p1));
        p2 = new Point(*(s.p2));
    }
    ~Section() {                                   //деструктор
        delete p1;
        delete p2;
        printf("~Section()\n");
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    {
        printf("Статическое создание объектов и их удаление\n");
        Point p;
        Point p2(1, 5);
        Point p3(p2);
    }

    printf("--------------------------------------------------------------\n");
    {
        printf("Динамическое создание объектов и их удаление\n");
        Point* p = new Point;
        Point* p2 = new Point(7, 7);
        Point* p3 = new Point(*p2);

        delete p;
        delete p2;
        delete p3;
    }
    printf("--------------------------------------------------------------\n");
    {
        printf("Изменение координат объектов с заданными координатами\n");
        Point* p = new Point(7, 17);
        Point* p2 = new Point(4, 4);
        Point* p3 = new Point(*p2);
        p->move(3, 3);
        p2->move(1, 1);
        p3->reset();
        p3->move(2, 2);

        delete p;
        delete p2;
        delete p3;
    }
    printf("--------------------------------------------------------------\n");
    {
        printf("Объекты класса наследника\n");
        ColoredPoint* p = new ColoredPoint(7, 8, 99);
        ColoredPoint* p2 = new ColoredPoint(1, 2, 3);
        ColoredPoint* p3 = new ColoredPoint(*p2);

        delete p;
        delete p2;
        delete p3;
    }
    printf("--------------------------------------------------------------\n");
    {
        printf("Помещение объектов в переменные различных типов\n");
        Point* p1 = new ColoredPoint(7, 8, 99);
        ColoredPoint* p2 = new ColoredPoint(1, 2, 3);
        p1->reset();
        p2->ChangeColor(4);
        delete p1;
        delete p2;
    }
    printf("--------------------------------------------------------------\n");
    {
        printf("Композиция\n");
        Section* s1 = new Section(1, 2, 3, 4);
        Section* s2 = new Section(*s1);

        delete s1;
        delete s2;
    }

    _getch();
}