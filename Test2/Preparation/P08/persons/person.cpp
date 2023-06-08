#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

#include "Person.h"

Person::Person(const string& name, const string& address, const string& phone) : name_(name), address_(address), phone_(phone) {}

string Person::get_name() const{
    return name_;
}

string Person::get_address() const{
    return address_;
}

string Person::get_phone() const{
    return phone_;
}

void read_persons_data(const string& file_name, vector<Person>& persons){
    ifstream in(file_name);
    string name, address, phone;
    while(getline(in, name)){
        getline(in, address);
        getline(in, phone);
        persons.push_back({name, address, phone});
    }
}

bool compare_name(Person a, Person b){
    return a.get_name() < b.get_name();
}

void sort_persons_by_name(vector<Person>& persons){
    sort(persons.begin(), persons.end(), compare_name);
}

int main(){
    { vector<Person> persons { Person("Pedro Miguel Faria", "Rua de Santa Catarina, 1234, Porto", "911123456"), 
    Person("Maria Roberta Fernandes", "Rua do Santo Silva, 4321, Porto", "987654321") };
    show_persons_data(persons); }
    //[ Pedro Miguel Faria : Rua de Santa Catarina, 1234, Porto : 911123456 Maria Roberta Fernandes : Rua do Santo Silva, 4321, Porto : 987654321]
    { vector<Person> persons;
    read_persons_data("persons-1.txt", persons);
    show_persons_data(persons); }
    //[Pedro Miguel Faria : Rua de Santa Catarina, 1235, Porto : 911123456 Ana Sousa : Avenida da Boavista, 7654, Porto : 987654321 Rui da Silva Santos : Avenida da Liberdade, 1234, Lisboa : 963111222]
    { vector<Person> persons;
    read_persons_data("persons-1.txt", persons);
    sort_persons_by_name(persons);
    show_persons_data(persons); }
    //[Ana Sousa : Avenida da Boavista, 7654, Porto : 987654321 Pedro Miguel Faria : Rua de Santa Catarina, 1235, Porto : 911123456 Rui da Silva Santos : Avenida da Liberdade, 1234, Lisboa : 963111222]
    { vector<Person> persons;
    read_persons_data("persons-2.txt", persons);
    sort_persons_by_name(persons);
    show_persons_data(persons); }
    //[Ana Sousa : Avenida da Boavista, 7654, Porto : 987654321 Pedro Miguel Faria : Rua de Santa Catarina, 1235, Porto : 911123456 Rui da Silva Santos : Avenida da Liberdade, 1234, Lisboa : 963111222 Sofia Alves Marques de Sousa : Rua da Sofia, 987, Coimbra : 963111222]

    return 0;
}