#include <iostream>
#include <string>
#include <windows.h>
#include <cmath>
#include <iomanip>
using namespace std;

void myfunc(double x, double n){
    double y = 1.0;
    double a = 1.0;
    for (int i = 1; i <= n; i++){
        a *= -1 * (x * (((2*i) + 3)/(double)(2*i)));
        y += a;

        if ((i == 3) || (i == 5) || (i == 10)) cout << "промежуточное значение " << i << " слагаемого = " << setprecision(6) << fixed << y << "\n";
    }
    cout << setprecision(6) << fixed << y << endl;
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    char s1 = 'y';
    double x, n;
    while (s1 == 'y'){
        cin >> x;
        cin >> n;
        myfunc(x, n);
        cout << "Продолжить работу? (y/n)" << endl;
        cin >> s1;
    }
    system("pause");
    return 0;
}
