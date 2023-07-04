#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>
using namespace std;
typedef double (*TPF)(double);
void zapoln(double** A, int str, int stolb, TPF fact);
void out(double** A, int nrow, int ncol, int n);
double fact(double x);

void zapoln(double** A, int str, int stolb, TPF fact){
    int x = 1;
    for (int i = 0; i < str; i++)
        for (int j = 0; j < stolb; j++){
            if (i == j)
                A[i][j] = 1;
            else
                if (i < j)
                    A[i][j] = pow(x, i + 1) / pow(fact(j + 1), i + 1);
                else
                    A[i][j] = pow(-x, i + 1) / pow(fact(j + 1), i + 1);
        }
}

double fact(double x){
    if (x > 0)
        return x * fact(x - 1);
    else
        if (x == 0)
            return 1;
        else return 0;
}

void out(double** A, int str, int stolb, int n){
    int size = 80 / n;
    int k = 0;
    for (int km = 0; km < (stolb / size + 1); km++){
        for (int i = 0; i < str; i++){
            for (int j = k; j < (k + size); j++){
                if (j == stolb) break;
                cout << setw(n) << A[i][j];
            }
            cout << '\n';
        }
        k += size;
        cout << '\n';
    }
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int point = 8; //количество знаков после запятой
    int n = 0; //количество символов, умещающихся в одной строке одного столбца
    cout << "Введите размер квадратной матрицы:" << '\n';
    int str, stolb;
    cin >> str;
    stolb = str;

    cout << "Научный формат:" << "\n";
    cout << scientific << setprecision(point);
    n = 10 + point;
    double** A = new double* [str];
    for (int i = 0; i < str; i++)
        A[i] = new double[stolb];
    zapoln(A, str, stolb, fact);
    out(A, str, stolb, n);


    cout << "Фиксированный формат:" << "\n";
    cout << fixed << setprecision(point);
    n = 4 + point;
    out(A, str, stolb, n);
    cout << endl << endl;


    //Вторая часть

    double B[10][10];
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            B[i][j] = i * 10 + j;
        }
    }
    double** C = new double* [10];
    for (int i = 0; i < 10; i++){
        C[i] = B[i];
    }
    cout << setprecision(0) << fixed;
    out(C, 10, 10, 3);
    cout << '\n';

    cout << B << " " << B[0] << " " << B[2] << endl;
    cout << B[0][0] << " " << **B << " " << *B[0] << endl;
    cout << *(*(B + 1)) << " " << *B[1] << endl;
    cout << *(B[0] + 1) << " " << *(*B + 1) << endl;
    cout << B[0][20] << " " << *(B[0] + 20) << " " << *B[2] << endl;

    system("pause");
    return 0;
}
