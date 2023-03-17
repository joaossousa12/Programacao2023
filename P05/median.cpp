#include <algorithm>
#include <iostream>

using namespace std;

int median(const int a[], int n){
    int* tmp = new int[n];
    for(int i = 0; i < n; i++) tmp[i] = a[i];
    sort(tmp, tmp + n);
    int result;
    if(n % 2 == 0) result = (tmp[ n / 2 - 1] + tmp[ n / 2]) / 2;
    else result = tmp[n / 2];
    delete [] tmp;
    return result;
}

int main(){
    { const int n = 5; 
    int a[n] { 10, -10, 0, 12, 11 };
    cout << median(a, n) << '\n'; }
    //10
    { const int n = 6; 
    int a[n] { 30, 10, 0, -20, 14, 20 };
    cout << median(a, n) << '\n'; }
    //12
    { const int n = 1; 
    int a[n] { 99 };
    cout << median(a, n) << '\n'; }
    //99
    { const int n = 2; 
    int a[n] { 101, 99 };
    cout << median(a, n) << '\n'; }
    //100
    return 0;
}