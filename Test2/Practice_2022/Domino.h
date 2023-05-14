#include "Piece.h"
#include <list>

class Domino{
    public:
        Domino(const list<Piece>& initial) : pieces_(initial) { }
        const Piece& left() const;
        const Piece& right() const;
        bool place_left(const Piece& p);
        bool place_right(const Piece& p);
        string to_string() const{
            string s("[");
            for(auto p: pieces_) s.append(" ").append(p.to_string());
            s.append(" ]");
            return s;
        }
    private:
        list<Piece> pieces_;
};