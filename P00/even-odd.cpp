#include <iostream>

using namespace std;

int main() {
    int x;         // Declares x as a variable of type int
    cin >> x;      // Reads input value for x
    if ( x % 2 == 0 ) {
        cout << x << " is even\n";
    } else {
        cout << x << " is odd\n";
    }
    return 0;
}