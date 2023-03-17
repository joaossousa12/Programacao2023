#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    int distance = 0;
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    for(int i = 1; i < n; i++){
        cin >> x2 >> y2;
        distance += abs(x1-x2) + abs(y1-y2);
        x1 = x2;
        y1 = y2;
    }
    cout << distance;
    return 0;
}