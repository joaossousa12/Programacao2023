#include "print.h"

void normalise(const string& input_fname, const string& output_fname){
    ifstream in(input_fname);
    ofstream out(output_fname);
    string line;
    while(getline(in, line)){
        int flag = 1;
        int alt_flag = 1;
        string result = "";
        for(auto &c : line){
            if(c == ' ' && alt_flag == 0) result += c;
            if(c != ' '){
                alt_flag = 0;
                flag = 0;
                result += toupper(c);
            }
        }
        while(result.back() == ' ') result.pop_back();
        if(flag == 0) out << result << endl;
    }
}

int main(){
    { normalise("p3_test1.txt", "p3_test1_out.txt"); 
    print("p3_test1_out.txt"); }
    //1|WORD ONE|
    //2|WORD TWO|
    //3|WORD THREE SPACES FOLLOW|
    //4|AND ONE FINAL EMPTY LINE|
    { normalise("p3_test2.txt", "p3_test2_out.txt"); 
    print("p3_test2_out.txt"); }
    //1|C++|
    //2|LEIC UP|
    //3|PYTHON 3|
    //4|PYTHON 2|
    { normalise("p3_test3.txt", "p3_test3_out.txt"); 
    print("p3_test3_out.txt"); }
    //1|THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG|
    { normalise("p3_test4.txt", "p3_test4_out.txt"); 
    print("p3_test4_out.txt"); }
    //1|T H E|
    //2|Q U I C K  B R O W N|
    //3|F O X  J U M P S  O V E R  T H E|
    //4|L A Z Y|
    //5|D|
    //6|O|
    //7|G|
    { normalise("p3_test5.txt", "p3_test5_out.txt"); 
    print("p3_test5_out.txt"); }
    //1|ABCDEFGHIIJKLMOPQRSTUVWXYZ|
    //2|0123456789 0123456789 0123456789|
    //3|ABCDEFGHIIJKLMOPQRSTUVWXYZ|
    //4|0123456789 0123456789 0123456789|
    return 0;
}