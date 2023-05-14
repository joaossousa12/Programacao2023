#include <sstream>

using namespace std;

class Piece{
    public:
        Piece(int left, int right) : left_(left), right_(right) {}
        bool can_be_left_to(const Piece& other) const;
        bool can_be_right_to(const Piece& other) const;
        int get_left() const {return left_;}
        int get_right() const {return right_;}
        string to_string() const{
            ostringstream os;
            os << left_ << ':' << right_;
            return os.str();
        }
    private:
        int left_, right_;
};