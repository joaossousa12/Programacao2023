#include <iostream>

using namespace std;

int main(){
    char c;
    cin >> c;
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) cout << "LETTER";
    else if(c >= '0' && c <= '9') cout << "DIGIT";
    else cout << "OTHER";
    return 0;
}

/*
z
LETTER
X
LETTER
0
DIGIT
-
OTHER
!
OTHER
*/