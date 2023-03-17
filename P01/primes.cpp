#include <iostream>

using namespace std;

int main(){
    cin >> n;
    int flag = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 2; j < i;j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0) cout << i << " ";
        else flag=0;
    }
    return 0;
}