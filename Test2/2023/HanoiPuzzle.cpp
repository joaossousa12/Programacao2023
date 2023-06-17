#include "HanoiPuzzle.h"

int Tower::top() const{
    if(disks_.size() == 0) return 0;
    return disks_.back();
}

void Tower::add(int disk){
    disks_.push_back(disk);
}

void Tower::remove(){
    if(disks_.size() > 0) disks_.pop_back();
}

ostream& operator<<(ostream& os, const Tower& t){
    os << '[';
    for(auto disk : t.get_disks()){
        os << ' ' << disk;
    }
    os << " ]";
    return os;
}

void HanoiPuzzle::move(const vector<disk_move>& dmoves){
    for(auto move : dmoves){
        if((towers_[move.first].top() == 0) || (towers_[move.first].top() > towers_[move.second].top() && towers_[move.second].top() != 0)) 
            continue;
        towers_[move.second].add(towers_[move.first].top());
        towers_[move.first].remove();
    }
}

int main(){
    { // contains invalid moves (I)
        HanoiPuzzle h(3);
        h.move({ {0, 2}, {1, 2} /* I */, {0, 2} /* I */, {0, 1}, {2, 1}, {0, 2}, {1, 1} /* I */ }); 
        cout << h << endl; }
    //[ ][ 2 1 ][ 3 ]
    { // complete solution for 2 disks
    HanoiPuzzle h(2);
    h.move({ {0, 1}, {0, 2}, {1, 2} }); 
    cout << h << endl; }
    //[ ][ ][ 2 1 ]
    { // complete solution for 3 disks
    HanoiPuzzle h(3);
    h.move({ {0, 2}, {0, 1}, {2, 1}, {0, 2}, {1, 0}, {1, 2}, {0, 2} });
    cout << h << endl; }
    //[ ][ ][ 3 2 1 ]
    { HanoiPuzzle h(5);
    h.move({ {2,0}, {2,1}, {0, 2}, {0, 0}, {0, 1}, {2, 1}, {0, 2}, {1, 0}, {1, 2}, {0, 2}, {1, 2}, {2,1} });
    cout << h << endl; } 
    //[ 5 4 ][ 1 ][ 3 2 ]
    { HanoiPuzzle h(10);
    h.move({ {2,0}, {2,1}, {0, 2}, {0, 0}, {0, 1}, {2, 1}, {0, 2}, {1, 0}, {1, 2}, {0, 2}, {1,2}, {2, 0} });
    cout << h << endl; } 
    //[ 10 9 8 7 6 5 4 1 ][ ][ 3 2 ]
    return 0;
}