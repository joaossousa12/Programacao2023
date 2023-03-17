#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    int k, d;
    cin >> k;
    cin >> d;
    double res = 0;
    for(int n = 0; n <= k; n++){
        res += pow(-1, n) / (2 * n + 1);
    }
    cout << fixed << setprecision(d) << 4 * res;
    return 0;
}