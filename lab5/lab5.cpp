#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;


int iRandom(int a, int b) {
    return a + (b - a + 1) * rand() / RAND_MAX;
}

double dRandom(int a, int b){
    return a + (b - a) * rand() / (double)RAND_MAX;
}

void bubble_vozr(int a[], int n, int* ksravn, int* kper) {
    *ksravn = 0;
    *kper = 0;
    bool sorted = 0;
    for (int i = 0; i < n && sorted != 1; i++) {
        sorted = 1;
        for (int j = 0; j < n - i - 1; j++) {
            (*ksravn)++;
            if (a[j] > a[j + 1]){
                sorted = 0;
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                (*kper)++;
            }
        }
    }
}

void bubble_ub(int a[], int n, int* ksravn, int* kper) {
    *ksravn = 0;
    *kper = 0;
    bool sorted = 0;
    for (int i = 0; i < n && sorted != 1; i++) {
        sorted = 1;
        for (int j = 0; j < n - i - 1; j++) {
            (*ksravn)++;
            if (a[j] < a[j + 1]){
                sorted = 0;
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                (*kper)++;
            }
        }
    }
}

void vybor_vozr(int a[], int n, int* ksravn, int* kper) {
    *ksravn = 0;
    *kper = 0;
    int z;
    int min;
    for (int i = 0; i < n; i++) {
        z = i;
        for (int j = i + 1; j < n; j++) {
            (*ksravn)++;
            if (a[j] < a[z]) {
                z = j;
            }
        }
        if (z != i) {
            (*kper)++;
            min = a[z];
            a[z] = a[i];
            a[i] = min;
        }
    }
}

void vybor_ub(int a[], int n, int* ksravn, int* kper) {
    *ksravn = 0;
    *kper = 0;
    int z;
    int max;
    for (int i = 0; i < n; i++) {
        z = i;
        for (int j = i + 1; j < n; j++) {
            (*ksravn)++;
            if (a[j] > a[z]) {
                z = j;
            }
        }
        (*kper)++;
        max = a[z];
        a[z] = a[i];
        a[i] = max;
    }
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int ksravn = 0;
    int kper = 0;
    srand((unsigned int)time(NULL));
    rand();
    int n;
    cout << "Введите длину массива:\n";
    cin >> n;
    cout << endl << endl << "---------------------------ПЕРВАЯ ЧАСТЬ---------------------------" << endl << endl;

    int* a = new int[n];
    for (int i = 0; i < n; i++){
        a[i] = iRandom(1, 9);
        cout << "a[" << i << "]=" << a[i] << endl;
    }
    int* b = new int[n];
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    cout << endl;
    vybor_vozr(a, n, &ksravn, &kper);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "1)Метод выбора(не отсортированный): " << endl << "Количество сравнений — " << ksravn << endl << "Количество перестановок — " << kper << endl << endl;

    bubble_vozr(b, n, &ksravn, &kper);

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    cout << "1)Метод пузырька(не отсортированный): " << endl << "Количество сравнений - " << ksravn << endl << "Количество перестановок - " << kper << endl << endl;

    vybor_vozr(a, n, &ksravn, &kper);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "2)Метод выбора(отсортированный): " << endl << "Количество сравнений — " << ksravn << endl << "Количество перестановок — " << kper << endl << endl;

    bubble_vozr(b, n, &ksravn, &kper);

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    cout << "2)Метод пузырька(отсортированный): " << endl << "Количество сравнений - " << ksravn << endl << "Количество перестановок - " << kper << endl << endl;

    vybor_ub(a, n, &ksravn, &kper);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "3)Метод выбора(отсортированный в обратном порядке): " << endl << "Количество сравнений — " << ksravn << endl << "Количество перестановок — " << kper << endl << endl;

    bubble_ub(b, n, &ksravn, &kper);
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    cout << "3)Метод пузырька(отсортированный в обратном порядке): " << endl << "Количество сравнений — " << ksravn << endl << "Количество перестановок — " << kper << endl << endl;

    delete[] a;
    delete[] b;
    cout << endl << endl << endl << "----------------------------ВТОРАЯ ЧАСТЬ---------------------------" << endl;
    cout <<                         "-----Исследование зависимости быстродействия от размера массива----" << endl << endl;

    int* x;
    int* y;
    int size = 5;
    cout << right << setw(29) << "Сравнения" << setw(32) << "Перестановки" << endl;
    while (size <= 500) {
        x = new int[size];
        y = new int[size];
        for (int i = 0; i < size; i++)
        {
            x[i] = iRandom(1, 100);
        }
        for (int i = 0; i < size; i++) {
            y[i] = x[i];
        }
        bubble_vozr(x, size, &ksravn, &kper);
        cout << endl << size << " элементов: " << endl << setw(20) << left << "Пузырек: " << setw(29) << ksravn << left << setw(29) << kper << endl;
        vybor_vozr(y, size, &ksravn, &kper);
        cout << setw(20) << left << "Выбор: " << setw(29) << ksravn << left << setw(29) << kper << endl;
        delete[] x;
        delete[] y;
        size *= 10;
    }
    system("pause");
    return 0;
}
