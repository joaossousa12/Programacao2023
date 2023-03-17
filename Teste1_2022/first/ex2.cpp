#include <iostream>

using namespace std;

void print(int a[], int size){
    cout << "[ ";
    for(int i = 0; i < size; i++) cout << a[i] << ' ';
    cout << "]" << endl;
}

bool is_prime(int number){
    if(number <= 1) return 0;
    for(int i = 2; i * i <= number; i++){
        if(number % i == 0) return false;
    }
    return true;
}

void keep_prime_numbers(int a[], int& size){
    int i = 0;
    int j = 0;
    while(i < size){
        if(is_prime(a[j])){
            a[i] = a[j];
            i++;
        }else size--;
        j++;
    }
}

int main(){
    int a[] = {2, 2};
    int size = sizeof(a) / sizeof(int);
    keep_prime_numbers(a, size);
    print(a,size);
    return 0;
}