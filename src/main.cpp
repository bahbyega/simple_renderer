#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

int main() {
  TGAImage image(128, 128, TGAImage::RGB);
  image.set(30, 30, red);
  image.flip_vertically();
  image.write_tga_file("../output/output.tga");
  return 0;
}
