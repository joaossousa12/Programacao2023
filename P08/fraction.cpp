class Fraction{
    public:
        Fraction();
        Fraction(int numerator, int denominator);
        int denominator() const;
        int numerator() const;
        Fraction sum(const Fraction& right);
        Fraction sub(const Fraction& right);
        Fraction mul(const Fraction& right);
        Fraction div(const Fraction& right);
        void normalise();
        void write() const;
    private:
        static int gcd(int a, int b);
        int denominator_, numerator_;
};

#include <iostream>
#include <cmath>
using namespace std;

//! Compute the gcd of two numbers.
int Fraction::gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

//! Normalize a fraction.
void Fraction::normalise() {
  int g = gcd(numerator_, denominator_);
  numerator_ /= g;
  denominator_ /= g;
  if (denominator_ < 0) {
    numerator_ = - numerator_;
    denominator_ = - denominator_;
  }
}

// shows fraction on the screen
void Fraction::write() const {
  cout << numerator_ << '/' << denominator_;
}

Fraction::Fraction(){
    numerator_ = 0;
    denominator_ = 1;
}

Fraction::Fraction(int numerator, int denominator){
    denominator_ = denominator;
    numerator_ = numerator;
    normalise();
}

int Fraction::denominator() const{
    return denominator_;
}

int Fraction::numerator() const{
    return numerator_;
}

Fraction Fraction::sum(const Fraction& right){
    return Fraction(numerator_ * right.denominator_ + right.numerator_ * denominator_, denominator_ * right.denominator_);
}

Fraction Fraction::sub(const Fraction& right){
    return Fraction(numerator_ * right.denominator_ - right.numerator_ * denominator_, denominator_ * right.denominator_);
}

Fraction Fraction::mul(const Fraction& right){
    return Fraction(numerator_ * right.numerator_, denominator_ * right.denominator_);
}

Fraction Fraction::div(const Fraction& right){
    return Fraction(numerator_ * right.denominator_, denominator_ * right.numerator_);
}

int main(){
    { Fraction().sum({2, 4}).write(); cout << ' ';
    Fraction(1,1).sum({2, 4}).write(); cout << ' ';
    Fraction(2,4).sum({3, 9}).write(); cout << ' ';
    Fraction(-2,4).sum({1, 2}).write(); cout << ' ';
    Fraction(3,27).sum({-27, 81}).write(); cout << '\n'; }
    //1/2 3/2 5/6 0/1 -2/9
    { Fraction().sub({2, 4}).write(); cout << ' ';
    Fraction(1,1).sub({2, 4}).write(); cout << ' ';
    Fraction(2,4).sub({3, 9}).write(); cout << ' ';
    Fraction(-2,4).sub({1, 2}).write(); cout << ' ';
    Fraction(3,27).sub({-27, 81}).write(); cout << '\n'; }
    //-1/2 1/2 1/6 -1/1 4/9
    { Fraction().mul({2, 4}).write(); cout << ' ';
    Fraction(1,1).mul({2, 4}).write(); cout << ' ';
    Fraction(2,4).mul({3, 9}).write(); cout << ' ';
    Fraction(-2,4).mul({1, 2}).write(); cout << ' ';
    Fraction(3,27).mul({-27, 81}).write(); cout << '\n'; }
    //0/1 1/2 1/6 -1/4 -1/27
    { Fraction().div({2, 4}).write(); cout << ' ';
    Fraction(1,1).div({2, 4}).write(); cout << ' ';
    Fraction(2,4).div({3, 9}).write(); cout << ' ';
    Fraction(-2,4).div({1, 2}).write(); cout << ' ';
    Fraction(3,27).div({-27, 81}).write(); cout << '\n'; }
    //0/1 2/1 3/2 -1/1 -1/3
    return 0;
}