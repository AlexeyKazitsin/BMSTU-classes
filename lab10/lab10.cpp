#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>
using namespace std;

double **obrat(double **mat, int n, int tip);
void umnog(double **mat1, double **mat2, int n);
void umnog(double **mat1, double *mat2, int n);
void slau();
bool flag = true;

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;

    double **mat = new double *[n];
    for (int i = 0; i < n; i++)
        mat[i] = new double [n];

//---------------------Ввод матрицы-------------------------
    cout << "\nВведите элементы матрицы:\n";
    for (int i= 0; i < n; i++)
        for(int j= 0; j < n; j++)
            cin >> mat[i][j];

//------------------Нахождение обратной матрицы----------------------
    double **mat_ob = obrat(mat,n, 0);
    if (flag == false){
        cout << "Обратная матрица не существует." << endl;
        flag = true;
    }else{
        cout <<" Обратная матрица: \n";
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                cout << setw(8) << fixed << setprecision(3) << mat_ob[i][j] << "   ";
            cout <<"\n";
        }

        umnog(mat,mat_ob,n); // Проверка умножением
    }


//-------------------------Решение СЛАУ----------------------------
    cout << "\nРешение системы уравнений.\n";
    slau();
    system("pause");
    return 0;
}

double **obrat(double **mat, int n, int tip){
    double a,b,c;
    double *mas= new double[2*n];

    // Создание единичной матрицы
    double **mat_ed= new double *[n];
    for(int i= 0; i < n;i++)
        mat_ed[i]= new double [n];
    for(int i= 0; i < n; i++)
        for(int j= 0; j < n; j++){
            if(i == j) mat_ed[i][j] = 1;
            else mat_ed[i][j] = 0;
        }

    // Создание вспомогательной матрицы
    double **mat_help= new double *[n];
    for(int i= 0; i < n; i++)
        mat_help[i]= new double [2*n];

    for(int i= 0; i < n; i++)
        for(int j= 0; j < (2*n); j++){
            if(j < n)
                mat_help[i][j] = mat[i][j];
            else mat_help[i][j] = mat_ed[i][j-n];
        }

    // Прямой ход, в конце цикла получается верхняя треугольная матрица
    for(int k= 0; k < n; k++){
        if (mat_help[k][k] == 0){  //проверка диагональных элементов на равенство нулю (существует ли обратная матрица)
            flag = false;
            for(int i= k+1; i < n; i++){
                if(mat_help[i][k] != 0){
                    flag = true;
                    for(int j= 0; j < n*2; j++){
                        c= mat_help[i][j];
                        mat_help[i][j] = mat_help[k][j];
                        mat_help[k][j] = c;
                    }
                    break;
                }
            }
        }
        if (flag == false){
            break;
        }
        for(int i= k; i < n; i++){
            if(i == k){
                for(int j= 0; j < 2*n; j++)
                    mas[j] = mat_help[i][j];
            }

            for(int j= k; j < 2*n; j++){
                if(i == k){
                    if(j == k) a = mat_help[k][k];
                    mat_help[i][j]= mat_help[i][j]/a;
                }else{
                    if(j == k) b = mat_help[i][j];
                    mat_help[i][j] = mat_help[i][j]-mas[j]*b/a;
                }
            }
        }
    }
    if (flag == false){
        return 0;
    }else{
        if (tip == 0){
            //Промежуточный вывод прямого хода
            cout << "Прямой ход  (промежуточный результат):" << endl;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++)
                    cout << setw(8) << fixed << setprecision(3) << mat_help[i][j] << "   ";
                cout <<"\n";
            }
            cout << endl;
        }
        // Обратный ход (прямой ход, только зануляем правые верхние элементы)
        for (int k = n-1; k >= 0; k--)
            for(int i = k; i >= 0; i--){
                if(i == k){
                    for(int j = 0; j < 2*n; j++)
                        mas[j] = mat_help[i][j];
                }

                for(int j = k; j < 2*n; j++){
                    if(i == k){
                        if(j == k) a = mat_help[k][k];
                        mat_help[i][j] = mat_help[i][j]/a;
                    }else{
                        if(j == k) b = mat_help[i][j];
                        mat_help[i][j] = mat_help[i][j]-mas[j]*b/a;
                    }
                }
            }

        double **mat_ob = new double*[n];
        for (int i = 0; i < n; i++)
            mat_ob[i] = new double [n];
        for (int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mat_ob[i][j] = mat_help[i][j+n];

        if (tip == 0){
            //Промежуточный вывод обратного хода
            cout << "Обратный ход (промежуточный результат):" << endl;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++)
                    cout << setw(8) << fixed << setprecision(3) << mat_ob[i][j] << "   ";
                cout <<"\n";
            }
            cout << endl << endl;
        }
        return mat_ob;
    }
}

void umnog(double **mat1, double **mat2, int n){
    double s;
    double **mat = new double *[n];
    for(int i = 0; i < n; i++)
        mat[i] = new double [n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            s= 0;
            for(int k = 0; k < n; k++)
                s = s+mat1[i][k]*mat2[k][j];
            if(i == j)mat[i][j] = 1;else
             mat[i][j] = s;

        }

    }

    cout <<" Умножение обратной на исходную: \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << setw(8) << fixed << setprecision(3) << abs(mat[i][j]) << "   ";
        cout <<"\n";
    }
}

void umnog(double **mat1, double *mat2, int n){
    double s;
    double *mat = new double[n];
    for (int i = 0; i < n; i++){
        s= 0;
        for (int j = 0; j < n; j++){
            s = s+mat1[i][j]*mat2[j];
        }
        mat[i]= s;
    }

    cout << "\nРезультат:\n";
    for (int i = 0; i < n; i++)
        cout << "x" << i+1 << " = " << mat[i] << "\n";
}


void slau(){
    int n;
    cout << "Введите количество уравнений в системе - ";
    cin >> n;
    double **mat= new double *[n];
    for (int i=0; i<n;i++)
        mat[i]= new double [n];

    for (int i = 0; i < n; i++){
        cout << "Введите коэффициенты уравнения: "  <<i+1 <<"\n";
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
    double **mat_ob = obrat(mat,n, 1);
    double *svob = new double [n];
    cout << "Введите свободные члены уравнений:\n";
    for(int j = 0; j < n; j++)
        cin >> svob[j];
    umnog(mat_ob, svob, n);
}
