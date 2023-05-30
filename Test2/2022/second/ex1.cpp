#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void show_file(const string& file){
    ifstream in(file);
    cout << "==> " << file << " <==\n";
    for(string line; getline(in, line); ) cout << line << '\n';
}

void maximum(const string& input_fname, const string& output_fname){
    ifstream in(input_fname);
    ofstream out(output_fname);

    double x;
    double max = -1001;
    int counter = 0;

    while(in >> x){
        out << fixed << setprecision(3) << x << endl;
        if(x > max) max = x;
        counter++;
    }

    out << "count=" << counter << "/max=" << fixed << setprecision(3) << max;  
}

int main(){
    maximum("ex1-1.txt", "ex1-1_out.txt");
    show_file("ex1-1_out.txt");
    return 0;
}