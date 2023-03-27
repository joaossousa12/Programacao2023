#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int count(const string& fname, const string& word) {
    ifstream in(fname);
    int counter = 0;
    int flag = 0;
    string x;
    while(in >> x){
        for(long unsigned int i = 0; i < word.length(); i++){
            if(x.length() != word.length()){
                flag = 1;
                break;
            }
            if(x[i] == word[i] || x[i] == toupper(word[i]) || x[i] == tolower(word[i])) continue;
            else{
                flag = 1;
                break;
            }
        }
        if(flag == 0) counter++;
        flag = 0;
    }
    return counter;
}

int main(){
    cout << count("p1_test_a.txt", "THE") << '\n';
    //4
    cout << count("p1_test_a.txt", "0") << '\n';
    //1
    cout << count("p1_test_a.txt", "code") << '\n';
    //0
    cout << count("p1_test_b.txt", "Collider") << '\n';
    //6
    cout << count("p1_test_b.txt", "you") << '\n';
    //21
    return 0;
}