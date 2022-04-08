#include <iostream>
//RU
#include <locale.h>
#include <windows.h>
//
#include "graphics.h"
#include <stdio.h>

class Point  // ������� �����
{
public:
    //����������� ������ - ���������� � ����
    int x, y;
    WORD cvet;
    //����������� � �����������
    Point(int xn, int yn, WORD color) : x(xn), y(yn), cvet(color)
    {
        x = xn; y = yn; cvet = color;
    }
    // ����������� �������
    virtual void Show();
    virtual void Hide();
    // ������
    void Locat(int&, int&);
    void Fly(int cost);
};
class Krug : public Point // ����������� ����� �� Point
{
public:
    // �������� ������ - ������
    WORD radius;
    // ������������ ������������ � ����������
    Krug(int xn, int yn, WORD color, WORD r) : Point(xn, yn, color), radius(r) 
    {
        Point(xn, yn, color);
        radius = r;
        Show();
    }
    // ����������� �������
    virtual void Show();
    virtual void Hide();
};
class Ring : public Krug // ����������� ����� �� Krug
{
 public:
     // �������� ������ - ������
    WORD width;
    // ������������ ������������ � ����������
    Ring(int xn, int yn, WORD color, WORD r, WORD wid) : Krug(xn, yn, color, r), width(wid) 
    {
        width = wid;
        Krug(xn, yn, color, r);
    }
    //����������� �������
    virtual void Show();
};


int main()
{
    //��� ������ � ������� ������
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //
    std::cout << "������� ������������ �� ������ ��� ������� ����� ������� ����� ESC \n";
    std::cout << "���������� �������� �������� ����������� ��������� ����� \n";
    std::cout << "��� ������� ESC ��������� ����������� ������... \n";
    // ������������� ������������ ����
    initwindow(500, 500);
    std::cout << "����������� ���� �������! �������� ��� �������� ��� ������... \n";
    setbkcolor(0); // ��������� ����� ����
    // ������� ������� � ���������� �����������
    Krug TestKrug(150, 40, 15, 10);
    Ring TestRing(450, 80, 90, 50, 10);
    // ����������� �������� � ������� �� ���������
    std::cout << "--> ����������� 1-�� �������! \n";
    TestKrug.Fly(100);
    std::cout << "--> 1-� ������ ����! \n";
    std::cout << "--> ����������� 2-�� �������! \n";
    TestRing.Fly(60);
    std::cout << "--> 2-� ������ ����! \n";
    std::cout << "--> ����������� 1-�� �������! \n";
    TestKrug.Fly(60);
    std::cout << "--> 2-� ������ ����! \n";
    getch();
    std::cout << "--> ������ �������! \n";
    // ������ ������� � �����
    TestKrug.Hide();
    TestRing.Hide();
    getch();
    // ��������� ����������� ����
    closegraph();
    std::cout << "����������� ���� �������! \n";
    system("pause");
    
}
void Point::Show()
{
    // ����������� �������
}
void Point::Hide()
{
    // ����������� �������
}
void Point::Locat(int& xl, int& yl)
{
    // ������ ��������� ������ ������
    xl = x; yl = y;
}
void Point::Fly(int cost)
{
    int xx, yy;
    Show();
    //��������� ��������� �����
    srand(time(0)); // �������������� ������������ r=1 + rand() % 10; ��� 1 - ������, 10 - ������ ���������
    int in;
    do 
    {
        Locat(xx, yy); // ������ ������� ���������, � 1-� ��� �� ������������
         do //����������� 1
        {
            xx = xx + round(((rand() % 2) - 0.5) * cost); // ���������� ���������            
         } while ((xx < 0) || (xx > getmaxx())); // ������������ ��������� < ������� ����
        do //����������� 2
        { 
             yy = yy + round(((rand() % 2) - 0.5) * cost); // ���������� ���������              
        } while ((yy < 0) || (yy > getmaxy())); // ������������ ��������� < ������� ����
        // �������� ������� ��������/�����������
        Hide();
        x = xx; y = yy; // ��������� ���������� ������
        Show();
        std::cout << "���������� �������: x=" << xx << " y = " << yy << "\n";
        delay(300);
        in = getch();
    } while (in!=27);    
}
void Krug::Show()
{
    setcolor(cvet); // ��������� �����
    setfillstyle(1, cvet); // ���� ������� � ��������
    pieslice(x, y, 0, 320, radius); // ������ �������� ��������� �� 0-320
}
void Krug::Hide()
{
    setcolor(getbkcolor()); // ��������� ����� - ���� ����
    setfillstyle(1, getbkcolor()); // ���� ������� � ��������
    pieslice(x, y, 0, 320, radius); // ������ �������� ��������� �� 0-320
}
void Ring::Show()
{
    Krug::Show(); //�������� ������� ����������� ������
    setfillstyle(10, getbkcolor()); // ���� ������� � ��������
    pieslice(x, y, 0, 320, radius-width); // ������ �������� ��������� �� 0-320
}