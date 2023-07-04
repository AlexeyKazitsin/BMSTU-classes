#include <iostream>
#include <string>
#include <windows.h>
#include <cmath>
#include <iomanip>

using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    //задача №2
    float a;
    int sum = 1;
    cin >> a;
    if (a >= 0){
        for (int i = 2; i <= 8; i+=2){
            sum *= i*i;
        }
        cout << fixed << setprecision(2) << sum - a << endl;
    } else{
        for (int i = 3; i <= 9; i+=3){
            sum *= (i-2);
        }
        cout << fixed << setprecision(2) << sum << endl;
    }
    system("pause");
    return 0;
}
