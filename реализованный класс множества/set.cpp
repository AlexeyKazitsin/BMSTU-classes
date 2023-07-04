#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Set {
private:
    char* data;
    int   maxsize;
    int   cursize;
public:
	Set(){
		cursize = 0;
		data = nullptr;
	}
    Set(int  n){
        maxsize = n;
        data = new char[maxsize];
        cursize = 0;
    }

	void SetSymbol(int index, char ch){
		data[index] = ch;
	}

	void SetData(char* arr1){
		int size = strlen(arr1);
		maxsize = size;
		cursize = maxsize;
		data = new char[maxsize+1];
		strcpy(data, arr1);
		data[maxsize] = '\0';
	}

	Set(char* arr1){
		int size = strlen(arr1);
		maxsize = size;
		cursize = maxsize;
		data = new char[maxsize+1];
		strcpy(data, arr1);
		data[maxsize] = '\0';
	}
    Set(const Set& ob){
        maxsize = ob.maxsize;
        cursize = ob.cursize;
        data    = new char[maxsize];
        for(int i = 0; i < cursize; i++)
            data[i] = ob.data[i];
    }

    ~Set(){
		if (data != nullptr){
			delete[] data;
		}
    }
	
	Set& operator=(const Set &R){//оператор равно
        if(this == &R){
            return *this;
        }
        if(maxsize != R.maxsize){
            delete []data;
            data = new char[R.maxsize];
            cursize = 0;
            maxsize = R.maxsize;
        }
        for(int i = 0; i < maxsize; i++){
            data[i] = R.data[i];
        }
        cursize = R.cursize;
        return *this;
    }

    Set& operator + (const char c){
        if(cursize >= maxsize)
            return *this;
        else if(! cursize || (c > data[cursize - 1])){
            data[cursize++] = c;
            return *this;
        }
 
        int m, f = 0, l = cursize;
        while(f < l){
            m = f + (l - f) / 2;
            if(c == data[m])
                return *this;
            else if(c < data[m])
                l = m;
            else
                f = m + 1;
        }
 
        for(int i = cursize; i > f; --i)
            data[i] = data[i - 1];
 
        data[f] = c;
        ++cursize;
        return *this;
    }

	/*Set& operator - (const char c){
        int m, f = 0, l = cursize;
        while(f < l){
            m = f + (l - f) / 2;
            if(c == data[m])
                return *this;
            else if(c < data[m])
                l = m;
            else
                f = m + 1;
        }
 
        for(int i = cursize; i > f; --i)
            data[i] = data[i - 1];
 
        data[f] = c;
        ++cursize;
        return *this;
    }*/
 
    Set operator + (const Set& ob){
        int n = 0, i = 0, j = 0;
        while((i < cursize) && (j < ob.cursize)){
            if(data[i] < ob.data[j])
                ++i;
            else if(ob.data[j] < data[i])
                ++j;
            else {
                ++n;
                ++j;
                ++i;
            }
        }
 
        Set ss(n);
        i = j = 0;
        while((i < cursize) && (j < ob.cursize)){
            if(data[i] < ob.data[j])
                ++i;
            else if(ob.data[j] < data[i])
                ++j;
            else {
                ss = ss + data[i++];
                ++j;
            }
        }
        return ss;
    }

	Set operator*(const Set &ob){//пересечение
        int k = cursize + ob.cursize;
        int r = 0;
        bool b = true;
        Set mnogestvo3(k); //объект, которому мы присвоим результат
        for (int i = 0; i < cursize; i++){
            for (int j = 0; j < ob.cursize && b; j++){
                if (data[i] = ob.data[i]){
                    mnogestvo3.data[r] = data[i];
                    r++;
                    b = false;
                }
            }
        }
        mnogestvo3.cursize = r;
        return mnogestvo3;
    }

	Set operator-(const Set &ob){//вычитание
        int k = cursize + ob.cursize;
        int r = 0;
        Set mnogestvo3(k); //объект, которому мы присвоим результат
        for (int i = 0; i < cursize; i++){
            for (int j = 0; j < ob.cursize; i++){
                if (data[i] != ob.data[i]){
                    mnogestvo3.data[r] = data[i];
                    r++;
                }
            }
        }
        for (int i = 0; i < ob.cursize; i++){
            for (int j = 0; j < cursize; i++){
                if (data[i] != ob.data[i]){
                    mnogestvo3.data[r] = data[i];
                    r++;
                }
            }
        }
        mnogestvo3.cursize = r;
        return mnogestvo3;
    }
 
    void show(){
        for(int i = 0; i < cursize; ++i)
            cout << data[i] << " ";
        cout << endl;
    }
};
 
 
int main(){
    Set A(10);
    Set B(10);
	char *ch = "lalala";
	Set D(ch);
	D.show();
	D.SetSymbol(0, 'q');
	D.show();
	D.SetData("HaHaHaHaHa");
	D.show();
 
    A = A + 'a' + 'b' + 'x' + 'c' + 'd' + 'w';
    B = B + 'e' + 'f' + 'b' + 'w' + 'a' + 'z' + 'x';
 
    A.show();
    B.show();
	
    //Set C = A - B;
    //C.show();
	Set F = A * B;
	F.show();
	Set G = F;
	G.show();
	system("pause");
    return 0;
}