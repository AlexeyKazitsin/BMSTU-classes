#include <iostream>
#include <windows.h>

using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int h, m; //h - часы, m - минуты
    cin >> h >> m;
    if ((m <= 59) && (0 <= m) && (h <= 24) && (0 <= h)){ //проверка на правильность введенных данных
        int one_last_digit = m % 10; //отделяем последнюю цифру от кол-ва минут (для определения окончания)
        if ((h == 12) && (m == 0)){ //проверка на время суток
            cout << "полдень" << endl;
        } else if ((h == 24) || (h == 0)){ //отдельная проверка на полночь
            if (m == 0){
                cout << "полночь" << endl;
            } else {
                cout << "введены недопустимые данные" << endl;
            }
        } else if ((h >= 0) && (h < 5)){
            if (h > 12){ //перевод времени в 12 часовую систему
                h = h - 12;
                cout << h;
            } else {
                cout << h;
            }
            if (h == 1){ //выбор правильного окончания слова у часов
                cout << " час ";
            } else if ((h >= 2) && (h <= 4)){
                cout << " часа ";
            } else {
                cout << " часов ";
            }
            if (m >= 5 && m <= 20) { //выбор правильного окончания у минут
                cout << m << " минут ";
            } else if (one_last_digit > 1 && one_last_digit < 5) {
                cout << m << " минуты ";
            } else if (one_last_digit == 1) {
                cout << m << " минута ";
            } else if (m != 0){
                cout << m << " минут ";
            }
            cout << "ночи";
            if (m == 0){ //если 0 минут, то нужно вывести слово "ровно"
                cout << " ровно";
            }
            cout << endl;
        } else if ((h >= 5) && (h < 12)){
            if (h > 12){
                h = h - 12;
                cout << h;
            } else {
                cout << h;
            }
            if (h == 1){
                cout << " час ";
            } else if ((h >= 2) && (h <= 4)){
                cout << " часа ";
            } else {
                cout << " часов ";
            }

            if (m >= 5 && m <= 20) { //выбор правильного окончания у минут
                cout << m << " минут ";
            } else if (one_last_digit > 1 && one_last_digit < 5) {
                cout << m << " минуты ";
            } else if (one_last_digit == 1) {
                cout << m << " минута ";
            } else if (m != 0){
                cout << m << " минут ";
            }
            cout << "утра";
            if (m == 0){
                cout << " ровно";
            }
            cout << endl;
        } else if ((h >= 12) && (h < 18)){
            if (h > 12){
                h = h - 12;
                cout << h;
            } else {
                cout << h;
            }
            if (h == 1){
                cout << " час ";
            } else if ((h >= 2) && (h <= 4)){
                cout << " часа ";
            } else {
                cout << " часов ";
            }
            if (m >= 5 && m <= 20) { //выбор правильного окончания у минут
                cout << m << " минут ";
            } else if (one_last_digit > 1 && one_last_digit < 5) {
                cout << m << " минуты ";
            } else if (one_last_digit == 1) {
                cout << m << " минута ";
            } else if (m != 0){
                cout << m << " минут ";
            }
            cout << "дня";
            if (m == 0){
                cout << " ровно";
            }
            cout << endl;
        } else if ((h >= 18) && (h <= 23)){
            if (h > 12){
                h = h - 12;
                cout << h;
            } else {
                cout << h;
            }
            if (h == 1){
                cout << " час ";
            } else if ((h >= 2) && (h <= 4)){
                cout << " часа ";
            } else {
                cout << " часов ";
            }
            if (m >= 5 && m <= 20) { //выбор правильного окончания у минут
                cout << m << " минут ";
            } else if (one_last_digit > 1 && one_last_digit < 5) {
                cout << m << " минуты ";
            } else if (one_last_digit == 1) {
                cout << m << " минута ";
            } else if (m != 0){
                cout << m << " минут ";
            }
            cout << "вечера";
            if (m == 0){
                cout << " ровно";
            }
            cout << endl;
        }
    } else {
        cout << "введены недопустимые данные" << endl;
    }
    system("pause");
    return 0;
}
