#ifndef PERSON_H
#define PERSON_H

class Person {
public:
  Person(const string& name, const string& address, const string& phone);
  string get_name() const;
  string get_address() const;
  string get_phone() const;
private:
  string name_;    // Name
  string address_; // Address
  string phone_;   // Phone
};

void show_persons_data(const vector<Person>& persons)
{
  cout << "[\n";
  for (const auto& p : persons)
  {
    cout << "  "  << p.get_name() 
         << " : " << p.get_address() 
         << " : " << p.get_phone() << '\n';
  }
  cout << "]\n";
}

#endif