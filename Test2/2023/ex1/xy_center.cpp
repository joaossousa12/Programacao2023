#include <iostream>
#include <fstream>
#include <string>
#include "show_file.h"

using namespace std;

void xy_center(const string& input_fname, const string& output_fname){
    ifstream in(input_fname);
    ofstream out(output_fname);
    double x, y;
    double xfinal = 0, yfinal = 0;
    double counter = 0;
    while(in >> x && in >> y){
        counter++;
        xfinal += x;
        yfinal += y;
        out << '(' << fixed << setprecision(1) << x << ',' << fixed << setprecision(1) << y << ')' << endl;
    }
    out << '(' << fixed << setprecision(1) << xfinal / counter << ',' << fixed << setprecision(1) << yfinal / counter << ')' << endl;
}

int main(){
        { xy_center("xy-1.txt", "xy-1_out.txt");
    show_file("xy-1.txt"); show_file("xy-1_out.txt"); }

    { xy_center("xy-2.txt", "xy-2_out.txt");
    show_file("xy-2.txt"); show_file("xy-2_out.txt"); }

    { xy_center("xy-3.txt", "xy-3_out.txt");
    show_file("xy-3.txt"); show_file("xy-3_out.txt"); }


    { xy_center("xy-4.txt", "xy-4_out.txt");
    show_file("xy-4.txt"); show_file("xy-4_out.txt"); }
    return 0;
}