#include <iostream>

using namespace std;

bool is_prime(int n){
    if(n <= 1) return false;
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

bool is_pernicious(int n){
    int counter_1s = 0;
    while(n != 0){
        if(n % 2 == 1){
            counter_1s++;
        }
        n /= 2;
    }
    return is_prime(counter_1s);
}

int main(){
    int start;
    cin >> start;
    int end;
    cin >> end;
    for(int i = start; i <= end;i++){
        if(is_pernicious(i) && is_prime(i)) cout << i << ' ';
    }
    return 0;
}