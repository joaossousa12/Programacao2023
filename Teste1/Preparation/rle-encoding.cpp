#include <iostream>

using namespace std;

void int_to_str(int n, char str[], int& pos){
    int n_array[10];
    int i = 0;
    while(n != 0){
        n_array[i++] = n % 10;
        n /= 10;
    }
    while(i > 0){
        str[pos++] = '0' + n_array[--i];
    }
}

void rle_encode(const char str[], char rle[]){
    if(rle[0] == '\0') {
        rle[0] = '\0';
        return;
    }
    int i = 0;
    int counter = 1;
    int j = 0; // current position on rle
    while(str[i] != '\0'){
        if(str[i + 1] != '\0'){
            if(str[i] == str[i + 1]) counter++;
            else{
                int_to_str(counter, rle, j);
                rle[j++] = str[i];
                counter = 1;
            }
        } else {
            int_to_str(counter, rle, j);
            rle[j++] = str[i];
        }
        i++;
    }
    rle[j] = '\0';
}

int main(){
    { char rle[1] = { -1 }; 
    rle_encode("", rle);
    cout << rle << endl; }
    //
    { char rle[2 + 1] = { -1, -1, -1 }; 
    rle_encode("a", rle);
    cout << rle << endl; }
    //1a
    { char rle[10 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; 
    rle_encode("abcde", rle);
    cout << rle << endl; }
    //1a1b1c1d1e
    { char rle[9 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; 
    rle_encode("aaaaabbbbbbbbbbbcccd", rle);
    cout << rle << endl; }
    //5a11b3c1d
    { char rle[3 + 1] = { -1, -1, -1, -1 }; 
    rle_encode("xxxxxxxxxxxxxxxxxxxx", rle);
    cout << rle << endl; }
    //20x
    return 0;
}