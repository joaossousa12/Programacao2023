#ifndef INC_2022_DECK_H
#define INC_2022_DECK_H

#include "Tile.h"
#include <vector>

//! Represents available tiles.
class Deck {
public:
    // Constructor
    Deck(const vector<Tile>& tiles) : tiles_(tiles) {}
    // Remove all tiles compatible with given title
    int remove_all_compatible_with(const Tile& t); //TODO IMPLEMENT
    // Show tiles in deck
    void show() const {
        cout << "[ ";
        for(auto t : tiles_) {t.show(); cout << ' ';}
        cout << "]\n";
    }
private:
    vector<Tile> tiles_;
};

#endif //INC_2022_DECK_H
