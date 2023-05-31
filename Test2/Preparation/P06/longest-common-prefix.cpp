#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longest_prefix(const vector<string>& v){
    string common = "";
    size_t i = 0;
    while(i < v[0].size()){
        common += v[0][i];
        for(auto c : v){
            if(i >= c.size()){
                common.pop_back();
                return common;
            }
            if(c[i] != common.back()){
                common.pop_back();
                return common;
            }
        }
        i++;
    }
    return common;

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