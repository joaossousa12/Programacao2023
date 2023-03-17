#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int letters = 0;
    int digits = 0;
    int special = 0;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            letters++;
        } else if(c >= '0' && c <= '9'){
            digits++;
        }else{
            special++;
        }
    }
    cout << letters << " " << digits << " " << special;
    return 0;
}