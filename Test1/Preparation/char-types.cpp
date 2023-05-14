#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    char c;
    int count_digits = 0, count_letters = 0, count_others = 0;

    for(int i = 0; i < n; i++){
        cin >> c;
        if(c >= '0' && c <= '9') count_digits++;
        else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) count_letters++;
        else count_others++;
    }

    cout << count_letters << ' ' << count_digits << ' ' <<count_others;

    return 0;
}