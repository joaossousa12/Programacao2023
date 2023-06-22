#include "Color.hpp"

namespace prog {
    // constructors

    Color::Color() {
        red_ = 0;
        green_ = 0;
        blue_ = 0;
    }

    Color::Color(const Color& other) {
        red_ = other.red_;
        green_ = other.green_;
        blue_ = other.blue_;
    }

    Color::Color(rgb_value red, rgb_value green, rgb_value blue) {
        red_ = red;
        green_ = green;
        blue_ = blue;
    }

    // accessors

    rgb_value Color::red() const {
        return red_;
    }

    rgb_value Color::green() const {
        return green_;
    }

    rgb_value Color::blue() const {
        return blue_;
    }

    // mutators

    rgb_value& Color::red()  {
        return red_;
    }

    rgb_value& Color::green()  {
        return green_;
    }

    rgb_value& Color::blue()  {
        return blue_;
    }

    void Color::invert(){ // inverts the rgb values of the pixel in question
        red_ = 255 - red_;
        green_ = 255 - green_;
        blue_ = 255 - blue_;
    }

    void Color::to_gray_scale(){ // turns all the rgb values to the same value v that is calculated by doing (r + g + b) / 3
        rgb_value v = (red_ + green_ + blue_) / 3;
        red_ = v;
        green_ = v;
        blue_ = v;
    }

    void Color::replace(rgb_value r1, rgb_value g1, rgb_value b1, rgb_value r2, rgb_value g2, rgb_value b2){ // for each pixel checks if it is equal to (r1, g1, b1) and if it is changes it to (r2, g2, b2)
        if(red_ == r1 && green_ == g1 && blue_ == b1){
            red_ = r2;
            green_ = g2;
            blue_ = b2;
        }
    }
}
