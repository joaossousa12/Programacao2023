#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <sstream>

using namespace std;

template <typename Itr> 
string to_string(Itr start, Itr end){
    ostringstream oss;
    oss << "[ ";
    while(start != end){
        oss << *start << " ";
        start++;
    }
    oss << "]";
    string result = oss.str();
    return result;
}

template <typename Itr, typename T> 
int replace(Itr start, Itr end, const T& a, const T& b){
    int count = 0;
    while(start != end){
        if(*start == a){
            *start = b;
            count++;
        }
        start++;
    }
    return count;
}

int main(){
    { vector<int> v;
    cout << replace(v.begin(), v.end(), 0, 1) << ' ' << to_string(v.cbegin(), v.cend()) << '\n'; }
    //0 [ ]
    { vector<int> v { 1, 2, 3, 3, 4 };
    cout << replace(v.begin(), v.end(), 3, 0) << ' ' << to_string(v.cbegin(), v.cend()) << '\n'; }
    //2 [ 1 2 0 0 4 ]
    { vector<int> v { 5, 1, 2, 3, 4, 5 };
    cout << replace(v.begin() + 1, v.end() - 1, 5, 0) << ' ' << to_string(v.cbegin(), v.cend()) << '\n'; }
    //0 [ 5 1 2 3 4 5 ]
    { list<string> l { "C++", "Java", "C++", "Python", "Rust", "C" } ;
    cout << replace(l.begin(), l.end(), string("C++"), string("Rust")) << ' ' << replace(l.begin(), l.end(), string("C"), string("Rust")) << ' '
    << to_string(l.cbegin(), l.cend()) << '\n'; }
    //2 1 [ Rust Java Rust Python Rust Rust ]
    { string s = "Hello world";
    cout << replace(s.begin(), s.end(), 'l', 'L') << ' '
    << to_string(s.cbegin(), s.cend()) << ' ' 
    << replace(s.rbegin(), s.rend(), 'o', 'O') << ' '
    << to_string(s.crbegin(), s.crend()) <<  ' '
    << to_string(s.cbegin(), s.cend()) << '\n'; }
    //3 [ H e L L o   w o r L d ] 2 [ d L r O w   O L L e H ] [ H e L L O   w O r L d ]
    return 0;
}