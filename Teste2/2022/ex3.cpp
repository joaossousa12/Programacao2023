#include "Deck.h"
#include "Tile.h"

bool Tile::compatible_with(const Tile& t) const{
    if(s1_ == t.s1_ || s1_ == t.s2_ || s2_ == t.s1_ || s2_ == t.s2_) return true;
    return false;
}

int Deck::remove_all_compatible_with(const Tile& t){
    int counter = 0;
    for(int i = 0; i < tiles_.size();){
        if(t.compatible_with(tiles_[i])){
            tiles_.erase(tiles_.begin() + i);
            counter++;
        }
        else i++;
    }
    return counter;
}

int main(){
    Tile t(1, 2);
    Deck d({{1, 2}, {3, 4}, {3, 2}, {1, 5}, {5, 6}, {6, 6}});
    cout << d.remove_all_compatible_with(t) << ' ';
    d.show();
    return 0;
}