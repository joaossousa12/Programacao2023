#include "wc.h"

wcresult wc(const string& filename){
    wcresult result = {0, 0, 0};
    ifstream in(filename);
    string line;
    while(getline(in, line)){
        string x;
        istringstream iss(line);
        result.bytes += iss.str().length() + 1;
        while(iss >> x) result.words++;
        result.lines++;
    }
    return result;
}



int main(){
    { wcresult r = wc("p2_test1.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    //1 0 1
    { wcresult r = wc("p2_test2.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    //6 13 92
    { wcresult r = wc("p2_test3.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    //1 9 44
    { wcresult r = wc("p2_test4.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    //4 9 51
    { wcresult r = wc("p2_test5.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    //39 188 1051
    return 0;
}