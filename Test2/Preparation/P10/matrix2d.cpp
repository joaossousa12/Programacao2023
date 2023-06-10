#include <vector>
#include <iostream>

using namespace std;

void show_vector(const vector<vector<int>>& v) {
  cout << "{";
  for (const auto& line : v) {
    cout << "{ ";
    for (const auto& elem : line)
      cout << elem << ' ';
    cout << "}";
  }
  cout << "}";
}

bool max_filter(vector<vector<int>> &v, int n){
    if(n % 2 == 0) return false;
    size_t n1 = (size_t) n;
    if(v.size() < n1) return false; // check vertical size of matrix
    for(auto v1 : v){
        if(v1.size() < n1) return false; // check horizontal size of matrix
    }
    vector<vector<int>> tmpvec = v;
    for(size_t i = 0; i < v.size(); i++){
      for(size_t j = 0; j < v[0].size(); j++){
        for(size_t k = 0; k < v.size(); k++){
          for(size_t l = 0; l < v[0].size(); l++){
            int i1, j1, k1, l1;
            i1 = (int) i;
            j1 = (int) j;
            k1 = (int) k;
            l1 = (int) l;
            if((k1 + n / 2 >= i1 && k1 - n / 2 <= i1) && (l1 + n / 2 >= j1 && l1 - n / 2 <= j1)){
              if(v[k][l] > tmpvec[i][j]) tmpvec[i][j] = v[k][l];
            }
          }
        }
      }
    }
    v = tmpvec;
    return true;
}

int main(){
    { vector<vector<int>> v = { {1,2,3}, 
                                {4,5,6}, 
                                {7,8,9} };
    bool b = max_filter(v, 3); 
    cout << boolalpha << b;
    show_vector(v); cout << endl << endl; }
    //true{{ 5 6 6 }{ 8 9 9 }{ 8 9 9 }}
    { vector<vector<int>> v ={ { 8,5,4,2,1 },
                               { 1,2,4,5,9 },
                               { 3,6,3,7,3 },
                               { 5,7,8,1,4 },
                               { 9,1,2,6,5 } };
    bool b = max_filter(v, 3); 
    cout << boolalpha << b;
    show_vector(v); cout << endl << endl; }
    //true{{ 8 8 5 9 9 }{ 8 8 7 9 9 }{ 7 8 8 9 9 }{ 9 9 8 8 7 }{ 9 9 8 8 6 }}
    { vector<vector<int>> v = { { 8,5,4,2,1 }, { 9,1,2,6,5 } };
    bool b = max_filter(v, 3); 
    cout << boolalpha << b;
    show_vector(v); 
    cout << endl << endl; }
    //false{{ 8 5 4 2 1 }{ 9 1 2 6 5 }}
    { vector<vector<int>> v = { { -8,-5,4,2,1,-1,7 },
                                { -1,-2,4,5,9,0,4 },
                                { -3,6,-3,-7,3,-10,-7 },
                                { 5,7,8,1,4,-2,-31 },
                                { -9,1,-2,6,5,-5,-16 } };
    bool b = max_filter(v, 3); 
    cout << boolalpha << b;
    show_vector(v); 
    cout << endl << endl; }
    //true{{ -1 4 5 9 9 9 7 }{ 6 6 6 9 9 9 7 }{ 7 8 8 9 9 9 4 }{ 7 8 8 8 6 5 -2 }{ 7 8 8 8 6 5 -2 }}
    { vector<vector<int>> v = { { -8,-5,4,2,1,-1,7 },
                                { -1,-2,4,5,9,0,4 },
                                { -3,6,-3,-7,3,-10,-7 },
                                { 5,7,8,1,4,-2,-31 },
                                { -9,1,-2,6,5,-5,-16 } };
    bool b = max_filter(v, 5); 
    cout << boolalpha << b;
    show_vector(v); 
    cout << endl << endl; }
    //true{{ 6 6 9 9 9 9 9 }{ 8 8 9 9 9 9 9 }{ 8 8 9 9 9 9 9 }{ 8 8 9 9 9 9 9 }{ 8 8 8 8 8 6 5 }}
    return 0;
}
