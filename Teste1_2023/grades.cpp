#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n >= 0 && n <= 20){
        if(n >= 0 && n <= 9) cout << 'D';
        else if(n >= 10 && n <= 14) cout << 'C';
        else if(n >= 15 && n <= 18) cout << 'B';
        else cout << 'A';
    } else cout << '?';
    return 0;
}