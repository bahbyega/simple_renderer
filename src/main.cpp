#include <cstdlib>
#include "line.h"
#include "triangle.h"
#include "model.h"
#include <iostream>

const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor orange = TGAColor(255,102,0,1);
const TGAColor yellow = TGAColor(255,255,0,1);
const TGAColor green  = TGAColor(51,255,0,1);
const TGAColor blue = TGAColor(51,204,255,1);
const TGAColor dark_blue = TGAColor(0,102,204,1);
const TGAColor purple = TGAColor(102,0,102,1);
const TGAColor white = TGAColor(255, 255, 255, 255);

const TGAColor colors[] = {red, orange, yellow, green, blue, dark_blue, purple, white};

/* Generates random triangles which do not cover each other. */
void generate_triangles(TGAImage &image)
{
  int step = 100; // medial size (in pixels) of a tringle
  std::srand(time(NULL));
      
  for(int i = 10; i < image.get_width() - step; i+=step) {
    for(int j = 10; j < image.get_height() - step; j+=step) {
	int rangei = step + 1;
	int rangej = step + 1;

	Vec2i vertices[3];

	for(int k = 0; k < 3; k++) {
	  int x = std::rand() % rangei + i;
	  int y = std::rand() % rangej + j;
	  vertices[k] = Vec2i(x, y);
	}

	int color_index = rand() % (sizeof(colors) / sizeof(colors[0]));
	draw_triangle(vertices[0], vertices[1], vertices[2], colors[color_index], image);
    }
  }
}


int main()
{
  // create image
  TGAImage image(1024, 1024, TGAImage::RGB);

  generate_triangles(image);
  
  image.flip_vertically(); // changes origin to left bottom corner
  image.write_tga_file("../output/output.tga");

  return 0;
}
