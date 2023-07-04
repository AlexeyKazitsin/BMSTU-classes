#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    //задача №1
    char s1 = 'y';
    int n, m, x;
    while (s1 == 'y'){
        int sum = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            cin >> x;
            if (((x % 5) == 0) && ((x % m) != 0)){
                sum += x;
            }
        }
        cout << sum << endl;
        cout << "Продолжить работу? (y/n)" << endl;
        cin >> s1;
    }

    system("pause");
    return 0;
}
