#include<iostream>
using namespace std;

int main () {
    int contador = 0;
    while (true){
        cout << contador << endl;
        contador++;
        if(contador > 10){
            break;
        }
    }
    
    return 0;
}