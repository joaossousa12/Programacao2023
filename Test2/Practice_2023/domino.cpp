#include "Domino.h"
#include <iostream>

bool Piece::can_be_left_to(const Piece& other) const{
    if(right_ == other.left_)
        return true;
    return false;
}

bool Piece::can_be_right_to(const Piece& other) const{
    if(left_ == other.right_)
        return true;
    return false;
}

const Piece& Domino::left() const{
    return pieces_.front();
}

const Piece& Domino::right() const{
    return pieces_.back();
}

bool Domino::place_left(const Piece& p){
    if(p.can_be_left_to(left())){
        pieces_.push_front(p);
        return true;
    }
    return false;
}

bool Domino::place_right(const Piece& p){
    if(p.can_be_right_to(right())){
        pieces_.push_back(p);
        return true;
    }
    return false;
}



int main(){
    { Piece p (1, 2);
    cout << boolalpha 
    << p.can_be_left_to({2, 3}) << ' ' 
    << p.can_be_left_to({3, 2}) << ' ' 
    << p.can_be_right_to({3, 2}) << ' ' 
    << p.can_be_right_to({0, 1}) << '\n'; }
    //true false false true
    { Domino d( { {1,2}, {2,0}, {0,6}, {6,6} } );
    cout << d.left().to_string() << ' '
    << d.right().to_string() << ' '
    << d.to_string() << '\n'; }
    //1:2 6:6 [ 1:2 2:0 0:6 6:6 ]
    { Domino d( { {1,2}, {2,0}, {0,6}, {6,6} } );
    cout << boolalpha
    << d.place_left({6,1})  << ' '
    << d.place_right({3,6}) << ' '
    << d.to_string() << '\n'; }
    //true false [ 6:1 1:2 2:0 0:6 6:6 ]
    { Domino d( { {1,2}, {2,3}, {3,3}, {3,4} } );
    cout << boolalpha
    << d.place_left({4,3})  << ' '
    << d.place_right({4,1}) << ' '
    << d.to_string() << '\n'; }
    //false true [ 1:2 2:3 3:3 3:4 4:1 ]
    { Domino d( { {1,2}, {2,3}, {3,3}, {3,6} } );
    cout << boolalpha
    << d.place_left({1,1})  << ' '
    << d.place_right({6,6}) << ' '
    << d.to_string() << '\n'; }
    //true true [ 1:1 1:2 2:3 3:3 3:6 6:6 ]
    return 0;
}