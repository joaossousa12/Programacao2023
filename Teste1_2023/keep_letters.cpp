#include <iostream>

using namespace std;

void keep_letters(char s[]){
    int i = 0;
    int counter = 0;
    while(s[i] != '\0'){
        if((s[i]>='a' && s[i] <= 'z') || (s[i]>='A' && s[i] <= 'Z')){
            s[counter] = s[i];
            counter++;
        }
        i++;
    }
    s[counter] = '\0';
}

int main(){
    { char s[] = "x";
    cout << "\"" << s << "\" --> ";
    keep_letters(s);
    cout << "\"" << s << "\"\n"; }

        

    //"x" --> "x"

    { char s[] = "09";
    cout << "\"" << s << "\" --> ";
    keep_letters(s);
    cout << "\"" << s << "\"\n"; }

        

    //"09" --> ""

    { char s[] = "";
    cout << "\"" << s << "\" --> ";
    keep_letters(s);
    cout << "\"" << s << "\"\n"; }

        

    //"" --> ""

    { char s[] = "0a1b2c3d4e5f6g7h8i9";
    cout << "\"" << s << "\" --> ";
    keep_letters(s);
    cout << "\"" << s << "\"\n"; }

        

    //"0a1b2c3d4e5f6g7h8i9" --> "abcdefghi"

    { char s[] = "a98b23cd45ef67gh01i";
    cout << "\"" << s << "\" --> ";
    keep_letters(s);
    cout << "\"" << s << "\"\n"; }

        

    //"a98b23cd45ef67gh01i" --> "abcdefghi"

    { char s[] = "2023-03-18 9:00 and 11:30";
    cout << "\"" << s << "\" --> ";
    keep_letters(s);
    cout << "\"" << s << "\"\n"; }

        

    //"2023-03-18 9:00 and 11:30" --> "and"

    return 0;
}