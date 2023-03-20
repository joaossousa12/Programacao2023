#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longest_prefix(const vector<string>& v){
    string res = "";
    unsigned long int min_length = v[0].length();
    for(string s: v){
        if(s.length() < min_length) min_length = s.length();
    }
    for(unsigned long int i = 0; i < min_length; i++){
        char curr_char = v[0][i];
        for(string s: v){
            if(s[i] != curr_char) return res;
        }
        res.push_back(curr_char);
    }
    return res;
}

int main(){
    cout << "\"" << longest_prefix({ "apple", "apply", "ape", "april" }) << "\"\n";
    //"ap"
    cout << "\"" << longest_prefix({ "ap", "apple", "apply", "ape", "april", "aq", "x" }) << "\"\n";
    //""
    cout << "\"" << longest_prefix({ "geezer", "geeksforgeeks", "geeks", "geek",  }) << "\"\n";
    //"gee"
    cout << "\"" << longest_prefix({ "sedatesingratiateconcomitant", "sedatesparleypoliteness", "sedateselbowsHahn", "sedatesgloweringimbecility's", "sedatesbuttershexing", "sedatesKwangju'smulch's", "sedatesunwiserN", "sedatesprepossessedboggles", "sedatesinterrelationshipdialings", "sedatesgropesNelsen's", "sedatesMayfaircondemnations" }) << "\"\n";
    //"sedates"
    cout << "\"" << longest_prefix({ "symmetricstalwartscorn'flowers", "symmetricShetland'ssuccessfully", "symmetricreceiver'shipsteed", "symmetricGrailsflown", "symmetricpromenadingoutflank", "symmetricdrugg'ingseizure", "symmetricsanctumsove'rprinting", "symmetricCitroentransgr'essed", "symmetricdissembledwinging", "symmetric'recoupingCinderella" }) << "\"\n";
    //"symmetric"
    return 0;
}