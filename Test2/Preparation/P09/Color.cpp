#include "Color.h"
#include <iostream>

using namespace std;

Color::Color(unsigned char red, unsigned char green, unsigned char blue) : red_(red), green_(green), blue_(blue) {}

Color::Color(const Color& c){
    red_ = c.red_;
    green_ = c.green_;
    blue_ = c.blue_;
}

unsigned char Color::red() const {
    return red_;
}

unsigned char Color::green() const {
    return green_;
}

unsigned char Color::blue() const {
    return blue_;
}

const Color Color::RED = {255, 0, 0};
const Color Color::GREEN = {0, 255, 0};
const Color Color::BLUE = {0, 0, 255};
const Color Color::BLACK = {0, 0, 0};
const Color Color::WHITE = {255, 255, 255};

bool Color::equal_to(const Color& other) const {
    if(red_ == other.red_ && green_ == other.green_ && blue_ == other.blue_) return true;
    return false;
}

void Color::invert(){
    red_ = 255 - red_;
    green_ = 255 - green_;
    blue_ = 255 - blue_;
}

int main(){
    { Color c (1, 2, 3);
    const Color& r = c;
    cout << (int) r.red() << ' '  
    << (int) r.green() << ' '  
    << (int) r.blue() << ' '
    << boolalpha << r.equal_to(r) << '\n'; }
    //1 2 3 true
    { cout << boolalpha 
    << Color::WHITE.equal_to(Color::WHITE) << ' '
    << Color::BLACK.equal_to(Color::RED) << ' '
    << Color::BLUE.equal_to(Color::GREEN) << '\n'; }
    //true false false
    { Color c(Color::WHITE); 
    cout << (int) c.red() << ' ' 
    << (int) c.green() << ' '  
    << (int) c.blue() << ' '
    << boolalpha << c.equal_to(Color::WHITE) << ' '
    << c.equal_to(Color::BLACK) << '\n'; }
    //255 255 255 true false
    { Color c(Color::WHITE); 
    c.invert();
    cout << (int) c.red() << ' '  
    << (int) c.green() << ' '  
    << (int) c.blue() << ' ' 
    << boolalpha << c.equal_to(Color::WHITE) << ' '
    << c.equal_to(Color::BLACK) << '\n'; }
    //0 0 0 false true
    { Color c(255, 128, 12); 
    c.invert();
    Color c2(c);
    c2.invert();
    cout << (int) c.red() << ' ' 
    << (int) c.green() << ' '  
    << (int) c.blue() << ' ' 
    << boolalpha << c.equal_to({ 0, 127, 243 }) << ' '
    << (int) c2.red() << ' ' 
    << (int) c2.green() << ' '  
    << (int) c2.blue() << ' ' 
    << boolalpha << c2.equal_to({ 255, 128, 12 }) << '\n'; }
    //0 127 243 true 255 128 12 true
    return 0;
}
