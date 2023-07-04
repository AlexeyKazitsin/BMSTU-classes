#include <iostream>
#include <string>
#include <windows.h>
#include <cmath>
#include <iomanip>

using namespace std;

void myatan(double x, double eps){
    int n = 0;
    double a = 111;
    double sum = x;
    double b = x;
    for (int i = 1; fabs(a) > eps; i++){
        b *= -x * x;
        a = b/(2*i + 1);
        sum += a;
        n = i;
    }
    cout << "x = " << setw(3) << x
         << "     Y(x) = " << setw(8) << atan(x)
         << "     S(x) = " << setw(8) << sum
         << "     N = " << n << endl;
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double eps = 1e-6;

    cout << "x" << setw(15)
         << "Y(x)" << setw(20)
         << "S(x)" << setw(17)
         << "N" << endl;

    for (double x = 0.0; x <= 1.0; x+=0.2){
        myatan(x, eps);
    }

    return 0;
}
