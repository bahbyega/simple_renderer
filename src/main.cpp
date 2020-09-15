#include "line.h"
#include "triangle.h"

const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor orange = TGAColor(255,102,0,1);
const TGAColor yellow = TGAColor(255,255,0,1);
const TGAColor green  = TGAColor(51,255,0,1);
const TGAColor blue = TGAColor(51,204,255,1);
const TGAColor dark_blue = TGAColor(0,102,204,1);
const TGAColor purple = TGAColor(102,0,102,1);
const TGAColor white = TGAColor(255, 255, 255, 255);

int main() {
  TGAImage image(1024, 1024, TGAImage::RGB);

  /*
  draw_line(590, 550, 1000, 700, red, image);      // low 1
  draw_line(590, 460, 1000, 300, orange, image);    // low 4
  draw_line(537, 410, 700, 24, yellow, image);    // high 4
  draw_line(470, 410, 300, 24, green, image);     // high 3
  draw_line(410, 470, 24, 300, blue, image);      // low 3
  draw_line(410, 537, 24, 700, dark_blue, image); // low 2
  draw_line(470, 590, 300, 1000, purple, image);    // high 2
  draw_line(537, 590, 700, 1000, white, image);     // high 1
  */

  fill_triangle(Vec2i(240, 340), Vec2i(350, 700), Vec2i(700, 100), green, image);
  //fill_triangle(Vec2i(140, 100), Vec2i(450, 600), Vec2i(700, 240), blue, image);
  
  image.flip_vertically(); // changes origin to left bottom corner
  image.write_tga_file("../output/output.tga");

  return 0;
}
