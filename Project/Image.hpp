#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__
#include "Color.hpp"

namespace prog
{
  class Image
  {
  private:
    int width_, height_;
    Color **pixels;
  public:
    Image(int w, int h, const Color &fill = {255, 255, 255}); // constructor
    ~Image(); // destructor
    int width() const; // accessor
    int height() const; // accessor
    Color &at(int x, int y); // mutator
    const Color &at(int x, int y) const; // accessor
    // table 7 functions
    void invert();
    void to_gray_scale();
    void replace(rgb_value r1, rgb_value g1, rgb_value b1, rgb_value r2, rgb_value g2, rgb_value b2);
    void fill(int x, int y, int w, int h, rgb_value r, rgb_value g, rgb_value b);
    void h_mirror();
    void v_mirror();
    void add(Image *png_image, int x, int y, rgb_value r, rgb_value g, rgb_value b);
    // advanced funcionalities
    void median_filter(int ws, Image* tmp_image);
  };
}
#endif
