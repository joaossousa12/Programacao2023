#include <iostream>

using namespace std;

bool isprime(int n){
    if(n <= 1) return false;
    for(int i = 2; i < n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

bool ispernicious(int n){
    int binary = 0, remainder, i = 1;
    while(n != 0){
        remainder = n % 2;
        binary += remainder * i;
        i *= 10;
        n /= 2;
    }
    int j = 0;
    while(binary != 0){
        if(binary % 10 == 1){
            j++;
        }
        binary /= 10;
    }
    return isprime(j);
}

int main(){
    int a;
    cin >> a;
    int b;
    cin >> b;
    while(a <= b){
        if(isprime(a) && ispernicious(a)){
            cout << a << " ";
        }
        a++;
    }
    return 0;
}