#include <iostream>
//RU
#include <locale.h>
#include <windows.h>
//
#include "graphics.h"
#include <stdio.h>

class Point  // базовый класс
{
public:
    //переменныее класса - координаты и цвет
    int x, y;
    WORD cvet;
    //конструктор с параметрами
    Point(int xn, int yn, WORD color) : x(xn), y(yn), cvet(color)
    {
        x = xn; y = yn; cvet = color;
    }
    // виртуальные функции
    virtual void Show();
    virtual void Hide();
    // методы
    void Locat(int&, int&);
    void Fly(int cost);
};
class Krug : public Point // производный класс от Point
{
public:
    // параметр класса - радиус
    WORD radius;
    // наследование конструктора с параметром
    Krug(int xn, int yn, WORD color, WORD r) : Point(xn, yn, color), radius(r) 
    {
        Point(xn, yn, color);
        radius = r;
        Show();
    }
    // виртуальные функции
    virtual void Show();
    virtual void Hide();
};
class Ring : public Krug // производный класс от Krug
{
 public:
     // параметр класса - ширина
    WORD width;
    // наследование конструктора с параметром
    Ring(int xn, int yn, WORD color, WORD r, WORD wid) : Krug(xn, yn, color, r), width(wid) 
    {
        width = wid;
        Krug(xn, yn, color, r);
    }
    //виртуальные фанкции
    virtual void Show();
};


int main()
{
    //для работы с русским языком
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //
    std::cout << "Объекты перемещаются по экрану при нажатии любой клавиши кроме ESC \n";
    std::cout << "Координаты объектов задаются генератором случайных чисел \n";
    std::cout << "При нажатии ESC программа выполняется дальше... \n";
    // иницмализация графичсекого окна
    initwindow(500, 500);
    std::cout << "Графическое окно активно! Сделайте его активным для работы... \n";
    setbkcolor(0); // установка цвета фона
    // создаем объекты с начальными параметрами
    Krug TestKrug(150, 40, 15, 10);
    Ring TestRing(450, 80, 90, 50, 10);
    // перемещение объектов с выводом их координат
    std::cout << "--> Перемещение 1-го объекта! \n";
    TestKrug.Fly(100);
    std::cout << "--> 1-й объект стоп! \n";
    std::cout << "--> Перемещение 2-го объекта! \n";
    TestRing.Fly(60);
    std::cout << "--> 2-й объект стоп! \n";
    std::cout << "--> Перемещение 1-го объекта! \n";
    TestKrug.Fly(60);
    std::cout << "--> 2-й объект стоп! \n";
    getch();
    std::cout << "--> Скрыть объекты! \n";
    // прячем объекты в конце
    TestKrug.Hide();
    TestRing.Hide();
    getch();
    // закрываем графическое окно
    closegraph();
    std::cout << "Графическое окно закрыто! \n";
    system("pause");
    
}
void Point::Show()
{
    // виртуальные функции
}
void Point::Hide()
{
    // виртуальные функции
}
void Point::Locat(int& xl, int& yl)
{
    // запрос координат внутри класса
    xl = x; yl = y;
}
void Point::Fly(int cost)
{
    int xx, yy;
    Show();
    //генератор случайных чисел
    srand(time(0)); // автоматическая рандомизация r=1 + rand() % 10; где 1 - начало, 10 - ширина диапазона
    int in;
    do 
    {
        Locat(xx, yy); // запрос текущих координат, в 1-й раз из конструктора
         do //перемещение 1
        {
            xx = xx + round(((rand() % 2) - 0.5) * cost); // приращение координат            
         } while ((xx < 0) || (xx > getmaxx())); // отслеживание координат < области окна
        do //перемещение 2
        { 
             yy = yy + round(((rand() % 2) - 0.5) * cost); // приращение координат              
        } while ((yy < 0) || (yy > getmaxy())); // отслеживание координат < области окна
        // создание эффекта моргания/перемещения
        Hide();
        x = xx; y = yy; // обновляем координаты класса
        Show();
        std::cout << "Координаты объекта: x=" << xx << " y = " << yy << "\n";
        delay(300);
        in = getch();
    } while (in!=27);    
}
void Krug::Show()
{
    setcolor(cvet); // установка цвета
    setfillstyle(1, cvet); // цвет заливки и текстура
    pieslice(x, y, 0, 320, radius); // сектор круговой диаграммы на 0-320
}
void Krug::Hide()
{
    setcolor(getbkcolor()); // установка цвета - цвет фона
    setfillstyle(1, getbkcolor()); // цвет заливки и текстура
    pieslice(x, y, 0, 320, radius); // сектор круговой диаграммы на 0-320
}
void Ring::Show()
{
    Krug::Show(); //вызываем функцию прородителя класса
    setfillstyle(10, getbkcolor()); // цвет заливки и текстура
    pieslice(x, y, 0, 320, radius-width); // сектор круговой диаграммы на 0-320
}