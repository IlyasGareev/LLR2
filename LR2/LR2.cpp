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
}