#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    int k;
    cin >> k;
    int d;
    cin >> d;
    double result = 0.0;
    for(int n = 0; n <= k; n++){
        result += pow(-1, n) / (2 * n + 1);
    }
    result *= 4;
    cout << fixed << setprecision(d) << result;
    return 0;
}