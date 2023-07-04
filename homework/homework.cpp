#include <iostream>
//#include <string>
#include <windows.h>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <new>

using namespace std;

int main(){
    //SetConsoleCP(65001);
    //SetConsoleOutputCP(65001);
    setlocale(0, "russian");
    cout <<"Введите слова текста из малых латинских букв не менее чем через один пробел\n";
    char **tekst, q= '0';
    int ctrok= 100, bukv= 100;
    cin.unsetf(ios::skipws);

//---------------------------------------------------------Создание массива строк(такста)----------------------------------------------------------------------
    tekst= new char * [ctrok];
    for(int i= 0; (i < ctrok) && (q != '.'); i++){
        tekst[i]= new char [bukv];
        q= '0';
        for(int j= 0; (i < bukv) && (q != ' ') && (q != '.'); j++){
            cin >>q;
            tekst[i][j]= q;
        }
    }
    cout <<"\n\n";

//-----------------------------------------------------------------Преобразование------------------------------------------------------------------------------
//    q= '0';
//    for(int i= 0; q != '.'; i++){
//        q= '0';
//        int j;
//        for(j= 0; (q != ' ') && (q != '.'); j++){
//            q= tekst[i][j];
//        }
//        if(j ==  6){
//            q= tekst[i][2];
//            if(q == 'z'){
//                tekst[i][0]= 'x';
//                tekst[i][1]= 'x';
//                tekst[i][2]= 'x';
//                tekst[i][3]= tekst[i][5];
//            }
//            q= tekst[i][3];
//        }
//    }
//    cout <<"\n\n";

//------------------------------------------------------------------Вывод текста------------------------------------------------------------------------------
    q= '0';
    for(int i= 0; q != '.'; i++){
        q = '0';
        for(int j= 0; (q != ' ') && (q != '.'); j++){
            q= tekst[i][j];
            cout <<tekst[i][j];
        }
    }
    cout <<"\n\n";

//--------------------------------------------------------------------The End-----------------------------------------------------------------------------------
    system("Pause");
    for(int i= 0; (i < ctrok) && (q != '.'); i++){
        delete [] tekst[i];
    }
    delete [] tekst;
    return 0;
}

