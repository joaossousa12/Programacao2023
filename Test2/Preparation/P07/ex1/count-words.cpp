#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int count(const string& fname, const string& word){
    ifstream in(fname);
    int count = 0;
    string w;
    while(in >> w){
        int flag = 0;
        if(w.size() == word.size()){
            for(size_t i = 0; i < w.size(); i++){
                if(tolower(w[i]) != tolower(word[i])) flag = 1;
            }
        } else flag = 1;
        if(flag == 0) count++;
    }
    return count;
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