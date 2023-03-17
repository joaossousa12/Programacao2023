#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1;
    cin >> y1;
    int res = 0;
    for(int i = 1; i < n; i++){
        cin >> x2;
        cin >> y2;
        res += abs(x1 - x2) + abs(y1 - y2);
        x1 = x2;
        y1 = y2;
    }
    cout << res;
    return 0;
}