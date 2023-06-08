#include <iostream>
#include <cmath>
using namespace std;

class Fraction{
    public:
        Fraction();
        Fraction(int num, int den);
        int gcd(int a, int b);
        void normalise();
        void write() const;
        int numerator() const;
        int denominator() const;
        Fraction sum(const Fraction& right);
        Fraction sub(const Fraction& right);
        Fraction mul(const Fraction& right);
        Fraction div(const Fraction& right);
    private:
        int numerator_, denominator_;
};

int Fraction::gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

Fraction::Fraction() : numerator_(0), denominator_(1) {}

Fraction::Fraction(int num, int den){
    numerator_ = num;
    denominator_ = den;
    normalise();
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

int Fraction::denominator() const{
    return denominator_;
}

int Fraction::numerator() const{
    return numerator_;
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