#include "CarSale.h"

CarSale::CarSale(const string& model, double base_price) : model_(model), base_price_(base_price) { }

string CarSale::model() const{
    return model_;
}

double CarSale::base_price() const{
    return base_price_;
}

void CarSale::add(const accessory& a){
    acc_.push_back(a);
}

int CarSale::free_accessories() const{
    int count = 0;
    for(auto a : acc_){
        if(a.tax == 0) count++;
    }
    return count;
}

double CarSale::final_price() const{
    double result =  base_price_;
    for(auto a : acc_){
        result +=  (a.tax / 100.0) * base_price_;
    }
    return result;
}

int main(){
    { CarSale cs("Renault 4L", 5000);
    print(cs); }

    { CarSale cs("Renault 4L", 5000);
    cs.add({ "4x4 traction", 10 });
    print(cs); }

    { CarSale cs("Renault 4L", 5000);
    cs.add({ "Renault logo sticker", 0 });
    cs.add({ "Yellow paint", 0 });
    cs.add({ "4x4 traction", 10 });
    print(cs); }

    { CarSale cs("Tasle X-2039", 1000000.42);
    cs.add({ "Flying module", 50 });
    cs.add({ "Lunar landing module", 10 });
    cs.add({ "Elun Mosk's portrait in gold paint", 100 });
    print(cs); }

    { CarSale cs("Zuckerborg Meta-3", 42424242.42);
    cs.add({ "Metaverse immersion plugin", 50 });
    cs.add({ "Meta-something wheels", 10 } );
    cs.add({ "Fakebook plugin", 0 });
    print(cs); }
    return 0;
}