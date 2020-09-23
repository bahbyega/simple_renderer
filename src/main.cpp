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

Model * draw_model(TGAImage &image)
{
  Model *model = new Model("african_head.obj");
  Vec3f light_dir(0,0,-1);
  std::cout << model->nfaces() << std::endl; // return 0
    for (int i=0; i<model->nfaces(); i++) {
      
        std::vector<int> face = model->face(i);
        Vec2i screen_coords[3];
        Vec3f world_coords[3];
        for (int j=0; j<3; j++) {
            Vec3f v = model->vert(face[j]);
            screen_coords[j] = Vec2i((v.x+1.)*1024/2., (v.y+1.)*1024/2.);
            world_coords[j]  = v;
        }
        Vec3f n = (world_coords[2]-world_coords[0])^(world_coords[1]-world_coords[0]);
        n.normalize();
        float intensity = n*light_dir;
        if (intensity>0) {
	  
	  draw_triangle(screen_coords[0], screen_coords[1], screen_coords[2], TGAColor(intensity*255, intensity*255, intensity*255, 255), image);
        }
    }
  return model;
}

int main()
{
  // create image
  TGAImage image(1024, 1024, TGAImage::RGB);

  //generate_triangles(image);

  Model * model = draw_model(image);
  
  image.flip_vertically(); // changes origin to left bottom corner
  image.write_tga_file("../output/output.tga");

  delete model;

  return 0;
}
