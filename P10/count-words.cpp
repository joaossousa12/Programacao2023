#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void show_vector(const vector<pair<string, size_t>>& count) {
  cout << "[ ";
  for (const auto& e : count) {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}

bool compare_words(pair<string, size_t> a, pair<string, size_t> b){
    return a.first < b.first;
}

void count_words(const string& str, vector<pair<string, size_t>>& count){
    istringstream iss(str);
    string word;
    while(iss >> word){
        int flag = 1;
        for(auto &c : word){
            if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        }

        for(auto &p : count){
            if(p.first == word){
                p.second++;
                flag = 0;
            }
        }

        if(flag == 1) count.push_back({word, 1});
    }
    sort(count.begin(), count.end(), compare_words);
}

int main(){
    { string s = "If you want to buy  buy  if you don't want to buy  bye bye";
    vector<pair<string, size_t>> count;
    count_words(s, count);
    show_vector(count); }
    //[ buy:3 bye:2 don't:1 if:2 to:2 want:2 you:2 ]
    { string s = "You can fool some of the people all of the time and all of the people some of the time  but you cannot fool all of the people all of the time";
    vector<pair<string, size_t>> count;
    count_words(s, count);
    show_vector(count); }
    //[ all:4 and:1 but:1 can:1 cannot:1 fool:2 of:6 people:3 some:2 the:6 time:3 you:2 ]
    { string s = "A tutor who tooted the flute tried to tutor two young tooters to toot   Said the two to the tutor is it tougher to toot or to tutor two young tooters to toot";
    vector<pair<string, size_t>> count;
    count_words(s, count);
    show_vector(count); }
    //[ a:1 flute:1 is:1 it:1 or:1 said:1 the:3 to:6 toot:3 tooted:1 tooters:2 tougher:1 tried:1 tutor:4 two:3 who:1 young:2 ]
    { string s = "You do not need to turn on a night light on a clear night like tonight because in a clear night there is always a light light and tonight is a clear night";
    vector<pair<string, size_t>> count;
    count_words(s, count);
    show_vector(count); }
    //[ a:5 always:1 and:1 because:1 clear:3 do:1 in:1 is:2 light:3 like:1 need:1 night:4 not:1 on:2 there:1 to:1 tonight:2 turn:1 you:1 ]
    { string s = "If one doctor doctors another doctor  Does the doctor who doctors the doctor  Doctor the way the doctor he is doctoring doctor  Or does he doctor the doctor  The way the doctor who doctors doctor";
    vector<pair<string, size_t>> count;
    count_words(s, count);
    show_vector(count); }
    //[ another:1 doctor:11 doctoring:1 doctors:3 does:2 he:2 if:1 is:1 one:1 or:1 the:7 way:2 who:2 ]
    return 0;
}