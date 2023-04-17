#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T1, typename T2>
class Pair{
    public:
        Pair(T1 first, T2 second);
        T1 get_first() const;
        T2 get_second() const;
        void show() const;
    private:
        T1 first_;
        T2 second_;
};

template <typename T1, typename T2>
Pair<T1, T2>::Pair(T1 first, T2 second){
    first_ = first;
    second_ = second;
}


template <typename T1, typename T2>
T1 Pair<T1, T2>::get_first() const{
    return first_;
}

template <typename T1, typename T2>
T2 Pair<T1, T2>::get_second() const{
    return second_;
}

template <typename T1, typename T2>
void Pair<T1, T2>::show() const{
    cout << "{" << first_ << "," << second_ << "}";
}

bool compare_first(Pair<string, int> i, Pair<string, int> j){
    return i.get_first() < j.get_first();
}

bool compare_second(Pair<string, int> i, Pair<string, int> j){
    return i.get_second() < j.get_second();
}

void sort_by_first(vector<Pair<string,int>>& v){
    sort(v.begin(), v.end(), compare_first);
}

void sort_by_second(vector<Pair<string,int>>& v){
    sort(v.begin(), v.end(), compare_second);
}

void show(vector<Pair<string,int>> v){
    cout << "{";
    for(auto v1 : v){
        v1.show();
    }
    cout << "}";
}

int main(){
    { vector<Pair<string, int>> persons = { {"Maria",17},{"Ana",21},{"Pedro",19} };
    sort_by_first(persons);
    show(persons); cout << '\n'; }
    //{{Ana,21}{Maria,17}{Pedro,19}}
    { vector<Pair<string, int>> persons = { {"Ana",19},{"Rui",16} };
    sort_by_second(persons);
    show(persons); cout << '\n'; }
    //{{Rui,16}{Ana,19}}
    { vector<Pair<string, int>> teams = { {"Porto",91},{"Benfica",74},{"Sporting",85} };
    sort_by_first(teams);
    show(teams); cout << '\n'; }
    //{{Benfica,74}{Porto,91}{Sporting,85}}
    { vector<Pair<string, int>> teams = { {"Porto",91},{"Benfica",74},{"Sporting",85} };
    sort_by_second(teams);
    show(teams); cout << '\n'; }
    //{{Benfica,74}{Sporting,85}{Porto,91}}
    { vector<Pair<string, int>> calories = { {"orange",37},{"egg",146},{"apple",56},{"yogurt",51} };
    sort_by_second(calories);
    show(calories); cout << '\n'; }
    //{{orange,37}{yogurt,51}{apple,56}{egg,146}}
    return 0;
}
