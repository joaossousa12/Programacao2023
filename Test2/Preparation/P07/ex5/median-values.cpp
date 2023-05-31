#include "show_file.h"

void calc_medians(const string& input_fname, const string& output_fname){
    ifstream in(input_fname);
    ofstream out(output_fname);
    string line;
    double x;
    while(getline(in, line)){
        if(line[0] == '#') continue;
        string id = line.substr(0, line.find_first_of(' '));
        line = line.substr(id.length() + 1, line.length());
        istringstream iss(line);
        vector<double> values;
        while(iss >> x) values.push_back(x);
        sort(values.begin(), values.end());
        if(values.size() % 2 == 0) out << id << ' ' << fixed << setprecision(1) << 0.5 * (values[ values.size() / 2 - 1] + values[ values.size() / 2]) << endl;
        else out << id << ' ' << fixed << setprecision(1) << values[values.size() / 2] << endl;
    }
}

int main(){
    { calc_medians("p5_test1.txt", "p5_test1_out.txt"); 
    show_file("p5_test1_out.txt"); }
    //==> p5_test1_out.txt <==
    //a 3.0
    { calc_medians("p5_test2.txt", "p5_test2_out.txt"); 
    show_file("p5_test2_out.txt"); }
    //==> p5_test2_out.txt <==
    //b 1.1
    //c 1.3
    //d 1.0
    { calc_medians("p5_test3.txt", "p5_test3_out.txt"); 
    show_file("p5_test3_out.txt"); }
    //==> p5_test3_out.txt <==
    //u1 1.5
    //u2 2.0
    //u3 2.0
    //u4 -0.5
    { calc_medians("p5_test4.txt", "p5_test4_out.txt"); 
    show_file("p5_test4_out.txt"); }
    /*==> p5_test4_out.txt <==
    ___a 1.0
    ___b 1.0
    ___c 0.5
    ___d 1.0*/
    { calc_medians("p5_test5.txt", "p5_test5_out.txt"); 
    show_file("p5_test5_out.txt"); }
    /*
    ==> p5_test5_out.txt <==
    ___a 1.0
    ___b 1.0
    ___c 0.5
    ___d 1.0*/
    return 0;
}