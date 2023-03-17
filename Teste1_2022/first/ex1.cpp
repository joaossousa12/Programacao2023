#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    if(a == b && a == c) cout << "equilateral";
    else if(a != b && b != c && a != c) cout << "scalene";
    else cout << "isosceles";
    return 0;
}