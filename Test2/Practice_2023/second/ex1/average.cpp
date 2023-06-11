#include "show_file.h"

 bool average(const string& input_fname, const string& output_fname){
    ifstream in(input_fname);
    ofstream out(output_fname);
    if(in.fail()) 
        return false;
    string line;
    int counter = 0;
    while(getline(in, line)){
        istringstream iss(line);
        double x;
        double num = 0, den = 0;
        while(iss >> x){
            num += x;
            den++;
        }
        if(den == 0) out << fixed << setprecision(3) << 0 << endl;
        else out << fixed << setprecision(3) << num / den << endl;
        counter++;
    }
    out << "lines=" << counter;
    return true; 
}

int main(){
    { if (average("p1a-1.txt", "p1a-1_out.txt"))
    show_file("p1a-1_out.txt"); }
    { if (average("p1a-2.txt", "p1a-2_out.txt"))
    show_file("p1a-2_out.txt"); }
    { if (average("p1a-3.txt", "p1a-3_out.txt"))
    show_file("p1a-3_out.txt"); }
    { if (average("p1a-4.txt", "p1a-4_out.txt"))
    show_file("p1a-4_out.txt"); }
    return 0;
}