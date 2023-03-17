#include <iostream>

using namespace std;

void print(int a[], int size){
    cout << "[ ";
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << "] ";
    cout << endl;
}

bool is_prime(int number){
    if(number <= 1) return 0;
    for(int i = 2; i * i <= number; i++){
        if (number % i == 0) return false;
    }
    return true;
}

void keep_prime_numbers(int a[], int& size){
    int counter_prime = 0;
    for(int i = 0; i < size; i++){
        if(is_prime(a[i])){
            counter_prime++;
        }
    }
    int res[counter_prime];
    int j = 0;
    for(int i = 0; i < size; i++){
        if(is_prime(a[i])){
            res[j] = a[i];
            j++;
        }
    }
    size = counter_prime;
    for(int i = 0; i < counter_prime; i++){
        a[i] = res[i];
    }
}
// {1, 2, 3, 4, 5, 6}   
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(a) / sizeof(int);
    keep_prime_numbers(a, size);
    print(a, size);
    return 0;
}