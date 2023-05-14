#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void show_file(const string& file){
    ifstream in(file);
    cout << "==> " << file << " <==\n";
    for(string line; getline(in, line);) cout << line << '\n';
}

bool average(const string& input_fname, const string& output_fname){
    ifstream in(input_fname);
    if(in.fail()) return false;
    ofstream out(output_fname);
    int lines = 0;
    for(string line; getline(in, line);){
        istringstream iss(line);
        double avg = 0;
        double val;
        vector<double> vec;
        while(iss >> val){
            vec.push_back(val);
        }
        for(auto v : vec) avg += v;
        avg = avg / vec.size();
        out << fixed << setprecision(3) << avg << endl;
        lines++;
    }
    out << "lines=" << lines;
    return true;
}