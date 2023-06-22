#include "XPM2.hpp"
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

namespace prog {
    Image* loadFromXPM2(const std::string& file) {
        string line;
        ifstream in(file);
        getline(in, line); // to skip the first line with the xpm header

        getline(in, line); // get the line with width, height and num of colors (char per color can be ignored because it is always 1)
        istringstream iss(line);
        int width, height, n;
        iss >> width >> height >> n;

        map<char, Color> mapCharToColor; // created a map that will map a character to a color
        for(int i = 0; i < n; i++){ // iterate through all the colors
            getline(in, line);
            char symbol, c;
            string hexaColor;
            istringstream iss(line);
            iss >> symbol >> c >> hexaColor;
            vector<int> rgb; // will store red, green, blue values as rgb[0], rgb[1] and rgb[2]

            for(size_t j = 1; j < hexaColor.length() - 1; j += 2){ // ignore first char in hexaColor because it is the '#'
                int tmp = 0;

                if(tolower(hexaColor[j]) >= 'a' && tolower(hexaColor[j]) <= 'f') tmp += (tolower(hexaColor[j]) - 'a' + 10) * 16;
                else tmp += (hexaColor[j] - '0') * 16;

                if(tolower(hexaColor[j + 1]) >= 'a' && tolower(hexaColor[j + 1]) <= 'f') tmp += (tolower(hexaColor[j + 1]) - 'a' + 10);
                else tmp += (hexaColor[j + 1] - '0');

                rgb.push_back(tmp);
            }

            mapCharToColor.insert({symbol, {(rgb_value) rgb[0], (rgb_value) rgb[1], (rgb_value) rgb[2]}});
        }

        Image* xpmImage = new Image(width, height); // create the new image with the xpm width and height
        for(int h = 0; h < height; h++){
            getline(in, line);
            istringstream iss(line);
            char symbol;
            for(int w = 0; w < width; w++){
                iss >> symbol;
                for(auto m : mapCharToColor){
                    if(m.first == symbol){
                        xpmImage->at(w, h) = m.second;
                    }
                }
            }
        }

        return xpmImage;
    }

    string rgbValueToHexa(rgb_value val){
        // function to transform each rgb_value in a string of 2 chars in hexa
        string res = "";
        rgb_value tmp = val / 16;

        if(tmp > 9) res += 'a' + tmp - 10;
        else res += '0' + tmp;

        tmp = val - tmp * 16;

        if(tmp > 9) res += 'a' + tmp - 10;
        else res += '0' + tmp;

        return res;
    }

    void saveToXPM2(const std::string& file, const Image* image) {
        ofstream of(file);
        of << "! XPM2" << endl << image->width() << ' ' << image->height() << ' '; // Write the first line in the file and the height and width of the image in the second line
        int diffColors = 0;
        vector<Color> colors; // create a vector to put all the colors that exist in the image
        int flag = 0;

        for(int w = 0; w < image->width(); w++){ // iterates through all the pixels in the image and save their color
            for(int h = 0; h < image->height(); h++){
                for(Color rgb : colors){
                    if(rgb.blue() == image->at(w, h).blue() && rgb.green() == image->at(w, h).green() && rgb.red() == image->at(w, h).red()){ // if the color already exists in the vector ignores the color setting flag to 1
                        flag = 1;
                        break;
                    } else flag = 0;
                }
                if(flag == 0){ // if flag == 0 means the color is not in the vector yet, if it is continue 
                    diffColors++;
                    colors.push_back(image->at(w, h));
                    flag = 1;
                }
            }
        }

        of << diffColors << ' ' << 1 << endl; // print the rest of the second line (diffColors: colors existent in the image, 1 = number of chars per color)
        map<char, Color> map; // created a map that will map a char to a hexadecimal color
        
        for(int i = 0; i < diffColors; i++){ // for every color print the symbol associated with it and the hexadecimal value of that color
            char symbol = '*' + i;
            map.insert({symbol, colors[i]});
            string hexa = "#";
            hexa += rgbValueToHexa(colors[i].red());
            hexa += rgbValueToHexa(colors[i].green());
            hexa += rgbValueToHexa(colors[i].blue());
            of << symbol << " c " << hexa << endl; 
        }

        for(int h = 0; h < image->height(); h++){ // iterates through all the pixels in the image and print the symbol associated with the color of that pixel
            for(int w = 0; w < image->width(); w++){
                for(auto m : map){
                    if(m.second.blue() == image->at(w, h).blue() && m.second.green() == image->at(w, h).green() && m.second.red() == image->at(w, h).red()){
                        of << m.first;
                    }
                }
            }
            of << endl;
        }
    }
}
