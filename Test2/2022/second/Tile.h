#ifndef INC_2022_TILE_H
#define INC_2022_TILE_H

#include <iostream>

using namespace std;

//! Represents a tile.
class Tile {
public:
    // Constructor
    Tile(int s1, int s2) : s1_(s1), s2_(s2) { }
    // Test if tile matches t in any of the sides
    bool compatible_with(const Tile& t) const; // TO BE IMPLEMENTED
    // Show tile
    void show() const { cout << s1_ << '-' << s2_;}
private:
    int s1_, s2_;
};

#endif //INC_2022_TILE_H
