#include "show_file.h"

 bool average(const string& input_fname, const string& output_fname){
    ifstream in(input_fname);
    ofstream out(output_fname);
    if(in.fail()) return false;
    string line;
    int line_counter = 0;
    while(getline(in, line)){
        double count = 0;
        double average = 0;
        double x;
        istringstream iss(line);
        while(iss >> x){
            average += x;
            count++;
        }
        out << fixed << setprecision(3) << average / count << endl;
        line_counter++;
    }
    out << "lines=" << line_counter;
    return true;
 }

int main(){
    { if (average("p1a-1.txt", "p1a-1_out.txt"))
    show_file("p1a-1_out.txt"); }
    /*==> p1a-1_out.txt <==
    1.629
    1.222
    1.695
    lines=3*/
    { if (average("p1a-2.txt", "p1a-2_out.txt"))
    show_file("p1a-2_out.txt"); }
    /*==> p1a-2_out.txt <==
    0.000
    26.528
    3.141
    lines=3*/
    { if (average("p1a-3.txt", "p1a-3_out.txt"))
    show_file("p1a-3_out.txt"); }
    /*==> p1a-3_out.txt <==
    0.000
    18.786
    lines=2*/
    { if (average("p1a-4.txt", "p1a-4_out.txt"))
    show_file("p1a-4_out.txt"); }
    /*==> p1a-4_out.txt <==
    1.629
    1.222
    0.848
    26.528
    3.141
    lines=5*/
    return 0;
}