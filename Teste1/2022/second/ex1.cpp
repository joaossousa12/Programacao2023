#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a != b && b != c && a != c) cout << "scalene";
    else if(a == b && b == c) cout << "equilateral";
    else cout << "isosceles";
    return 0;
}