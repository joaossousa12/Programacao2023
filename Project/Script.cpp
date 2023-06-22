#include <iostream>
#include <fstream>
#include <sstream>
#include "Script.hpp"
#include "PNG.hpp"
#include "XPM2.hpp"

using namespace std;

namespace prog {
    // Use to read color values from a script file.
    istream& operator>>(istream& input, Color& c) {
        int r, g, b;
        input >> r >> g >> b;
        c.red() = r;
        c.green() = g;
        c.blue() = b;
        return input;
    }

    Script::Script(const string& filename) :
            image(nullptr), input(filename) {

    }
    void Script::clear_image_if_any() {
        if (image != nullptr) {
            delete image;
            image = nullptr;
        }
    }

    Script::~Script() {
        clear_image_if_any();
    }

    void Script::run() {
        string command;
        while (input >> command) {
            cout << "Executing command '" << command << "' ..." << endl;
            if (command == "open") {
                open();
                continue;
            }
            if (command == "blank") {
                blank();
                continue;
            }
            // Other commands require an image to be previously loaded.
            if (command == "save") {
                save();
                continue;
            } 

            if (command == "invert"){
                invert();
                continue;
            }

            if (command == "to_gray_scale"){
                to_gray_scale();
                continue;
            }

            if(command == "replace"){
                // need to use ints because with unsigned chars each of these variables would be a single char in the .txt instead of the 
                // whole number
                int i_r1, i_g1, i_b1, i_r2, i_g2, i_b2;
                input >> i_r1 >> i_g1 >> i_b1 >> i_r2 >> i_g2 >> i_b2;

                // convert integers to rgb_values
                rgb_value r1, g1, b1, r2, g2, b2;
                r1 = (rgb_value) i_r1;
                g1 = (rgb_value) i_g1;
                b1 = (rgb_value) i_b1;
                r2 = (rgb_value) i_r2;
                g2 = (rgb_value) i_g2;
                b2 = (rgb_value) i_b2;
                
                replace(r1, g1, b1, r2, g2, b2);
                continue;
            }

            if(command == "fill"){
                int x, y, w, h, i_r, i_g, i_b;
                input >> x >> y >> w >> h >> i_r >> i_g >> i_b;

                rgb_value r, g, b;
                r = (rgb_value) i_r;
                g = (rgb_value) i_g;
                b = (rgb_value) i_b;

                fill(x, y, w, h, r, g, b);
                continue;
            }

            if(command == "h_mirror"){
                h_mirror();
                continue;
            }
            
            if(command == "v_mirror"){
                v_mirror();
                continue;
            }

            if(command == "add"){
                string filename;
                int x, y, i_r, i_g, i_b;
                input >> filename >> i_r >> i_g >> i_b >> x >> y;
                
                rgb_value r, g, b;
                r = (rgb_value) i_r;
                g = (rgb_value) i_g;
                b = (rgb_value) i_b;

                add(filename, x, y, r, g, b);
                continue;
            }

            if(command == "crop"){
                int x, y, w, h;
                input >> x >> y >> w >> h;

                crop(x, y, w, h);
                continue;
            }

            if(command == "rotate_left"){
                rotate_left();
                continue;
            }

            if(command == "rotate_right"){
                rotate_right();
                continue;
            }

            if(command == "median_filter"){
                int ws;
                input >> ws;
                median_filter(ws);
                continue;
            }

            if(command == "xpm2_open"){
                string filename;
                input >> filename;
                clear_image_if_any(); // need to clear memory not when we call xpm2_open but when we call xpm2_save because we need to free the memory of the blank image
                image = loadFromXPM2(filename);
                continue;
            }

            if(command == "xpm2_save"){
                string filename;
                input >> filename;
                saveToXPM2(filename, image);
                continue;
            }
        }
    }
    
    void Script::open() {
        // Replace current image (if any) with image read from PNG file.
        clear_image_if_any();
        string filename;
        input >> filename;
        image = loadFromPNG(filename);
    }
    void Script::blank() {
        // Replace current image (if any) with blank image.
        clear_image_if_any();
        int w, h;
        Color fill;
        input >> w >> h >> fill;
        image = new Image(w, h, fill);
    }
    void Script::save() {
        // Save current image to PNG file.
        string filename;
        input >> filename;
        saveToPNG(filename, image);
    }

    void Script::invert(){ // calls to invert function with image object
        image->invert();
    }

    void Script::to_gray_scale(){ // calls to to_gray_scale function with image object
        image->to_gray_scale();
    }

    void Script::replace(rgb_value r1, rgb_value g1, rgb_value b1, rgb_value r2, rgb_value g2, rgb_value b2){ // calls to replace function with image object
        image->replace(r1, g1, b1, r2, g2, b2);
    }

    void Script::fill(int x, int y, int w, int h, rgb_value r, rgb_value g, rgb_value b){ // calls to fill function with image object
        image->fill(x, y, w, h, r, g, b);
    }

    void Script::h_mirror(){ // calls to h_mirror function with image object
        image->h_mirror();
    }

    void Script::v_mirror(){ // calls to v_mirror function with image object
        image->v_mirror();
    }

    void Script::add(std::string filename, int x, int y, rgb_value r, rgb_value g, rgb_value b){
        Image *png_image = loadFromPNG(filename); // uses loadFromPNG function to assign a pointer to the image we want to copy
        image->add(png_image, x, y, r, g, b); // calls to add function with image object
        delete png_image; // free/release memory
    }

    void Script::crop(int x, int y, int w, int h){
        Image *tmp_image = new Image(w, h); // temporary image that will be the cropped version of image

        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){ // iterate through all pixels of the new image and gives the value of each pixel of the original image at that position + (x, y)
                tmp_image->at(i, j) = image->at(x + i, y + j);
            }
        }

        // free/release memory
        Image *tmp = image;
        image = tmp_image;
        delete tmp;
    }

    void Script::rotate_left(){
        Image *tmp_image = new Image(image->height(), image->width()); // temporary image with image height as its width and vice-versa
        
        // start from the last x (i) to 0 and from the first y and will put the value of the pixel of image in that position 
        // on tmp_image 
        for(int i = image->width() - 1; i >= 0; i--){
            for(int j = 0; j < image->height(); j++){
                tmp_image->at(j, image->width() - i - 1) = image->at(i , j);
            }
        }

        // free/release memory
        Image *tmp = image;
        image = tmp_image;
        delete tmp;
    }

    void Script::rotate_right(){
        Image *tmp_image = new Image(image->height(), image->width()); // temporary image with image height as its width and vice-versa

        // works the same way as rotate_left but height and width are inverted
        for(int i = 0; i < image->width(); i++){
            for(int j = image->height() - 1; j >= 0; j--){
                tmp_image->at(image->height() - j - 1, i) = image->at(i , j);
            }
        }

        // free/release memory
        Image *tmp = image;
        image = tmp_image;
        delete tmp;
    }

    void Script::median_filter(int ws){
        Image *tmp_image = new Image(image->width(), image->height()); // temporary image with the same width and height as image

        image->median_filter(ws, tmp_image); // executes median_filter function with image object

        // free/release memory
        Image* tmp = image;
        image = tmp_image;
        delete tmp;
    }


}
