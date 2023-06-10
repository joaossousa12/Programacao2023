#include "Stack.h"
#include <string>

using namespace std;

template <typename T>
Stack<T>::Stack(){
    size_ = 0;
    top_ = nullptr;
}

template <typename T>
Stack<T>::~Stack(){
    while(top_ != nullptr){
        node<T>* tmp = top_->next;
        delete top_;
        top_ = tmp;
    }
}

template<typename T>
size_t Stack<T>::size() const{
    return size_;
}

template<typename T>
bool Stack<T>::peek(T& elem) const{
    if(size_ == 0) 
        return false;
    elem = top_->value;
    return true;
}

template<typename T>
bool Stack<T>::pop(T& elem) {
    if(size_ == 0) 
        return false;
    elem = top_->value;
    node<T>* tmp = top_->next;
    delete top_;
    top_ = tmp;
    size_--;
    return true;
}

template<typename T>
void Stack<T>::push(const T& elem){
    node<T>* tmp = new node<T>{elem, top_};
    size_++;
    top_ = tmp;
}

int main(){
    { Stack<int> s;
    const Stack<int>& r = s;
    int v = -1;
    cout << r.size()  << ' ' << boolalpha
    << r.peek(v) << ' ' << v << ' '
    << s.pop(v)  << ' ' << v << ' '
    << s.size() << '\n'; }
    //0 false -1 false -1 0
    { Stack<int> s;
    int v = -1;
    s.push(123);
    cout << s.size()  << ' ' << boolalpha
    << s.peek(v) << ' ' << v << ' '
    << s.pop(v)  << ' ' << v << ' '
    << s.size() << '\n'; }
    //1 true 123 true 123 0
    { Stack<string> s; 
    string v;
    s.push("a"); s.push("b"); s.push("c");
    cout << s.size();
    while(s.pop(v)) cout << ' ' << v;
    cout << ' ' << s.size() << '\n'; }
    //3 c b a 0
    { Stack<int> s; int v = -1;
    s.push(111); s.push(222); s.push(333);
    cout << s.size();
    while(s.peek(v)) {
    cout << ' ' << v;
    s.pop(v);
    cout << ' ' << v;
    if (v % 2 != 0) s.push(v + 1);
    cout << ' ' << s.size(); }
    cout << '\n'; }
    //3 333 333 3 334 334 2 222 222 1 111 111 1 112 112 0
    return 0;
}