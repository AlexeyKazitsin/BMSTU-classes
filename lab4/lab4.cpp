#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>
using namespace std;

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double eps = 0.000001; //точность
    int i, cof = 1, n = 100000; // i - число шагов, cof - коэф. перед иксом, n - макс число шагов
    double x, c, a, b, x1, a1, b1;
    cout << "Введите начальный x для метода простых итераций. ";
    cin >> x1;
    cout <<"Введите границы интервала для метода половинного деления. ";
    cin >> a1 >> b1;
    while(a1 == b1){
        cout <<"Ошибка (a должно быть не равно b). Введите границы интервала для метода половинного деления. ";
        cin >> a1 >> b1;
    }

    for (int j = 1; j < 4; j++){
        if (j == 2){   //изменение изначальных данных под нужные задачи (j - номер задачи)
            eps = 0.00000001;
        } else if (j == 3){
            cof = 10;
            eps = 0.000001;
        }

        cout <<setprecision(16) <<"Нахождение корней нелинейного уравнения y=x-" << cof << "*cos(x)\n";
        cout <<"Точность вычисления = " <<eps <<"\n";

        if(b1 < a1){
            b1= b1+a1;
            a1= b1-a1;
            b1= b1-a1;
        }
        a = a1;
        b = b1;

        cout << j <<") Простая итерация.\n";
        i= 0;
        x= x1;
        do{
            if (i >= n){
                break;
            }
            i++;
            x= x-(x-cof*cos(x));
        }while (fabs(x-cof*cos(x)) > eps);
        cout << j << ") Корень уравнения= " << x <<" вычислен за " << i <<" шагов.\n\n";

        cout << j << ") Метод Ньютона.\n";
        i= 0;
        x= x1;
        do{
            if (i >= n){
                break;
            }
            i++;
            x= x-((x-cof*cos(x))/(1+cof*sin(x)));
        }while(fabs(x-cof*cos(x)) > eps);
        cout << j << ") Корень уравнения= " << x <<" вычислен за " << i << " шагов.\n\n";

        cout << j << ") Половинное деление.\n";
        i= 0;
        do{
            i++;
            c= (a+b)/2;
            if ((a-cof*cos(a))*(c-cof*cos(c)) > 0) a= c;
                else b=c;
        }while(fabs(b-a) > eps);
        x= (a+b)/2;
        cout << j << ") Корень уравнения= " << x <<" вычислен за " << i <<" шагов.\n\n";
    }

    system("Pause");
    return 0;
}
