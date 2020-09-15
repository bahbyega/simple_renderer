#include <cmath>
#include "triangle.h"
#include <iostream>

/* standard method of drawing triangles 
   it splits a triangle in two flat bottom
   triangles and then draws each of them */
void fill_triangle(Vec2i point0, Vec2i point1, Vec2i point2,
		   TGAColor color, TGAImage &image) {
  // sort vertices by y coordinat,
  // so that point0.y < point1.y < point2.y 
  if (point0.y > point2.y) std::swap(point0, point2);
  if (point0.y > point1.y) std::swap(point0, point1);
  if (point1.y > point2.y) std::swap(point1, point2);

  // draw top triangle
  float left_sloap = (float)(point2.x - point1.x) / (point2.y - point1.y); 
  float right_sloap = (float)(point2.x - point0.x) / (point2.y - point0.y);

  if ((point1.x > point2.x && point0.x < point2.x) || (point1.x < point2.x && point0.x < point2.x)) {
    std::swap(left_sloap, right_sloap);
  }
  
  std::cout << "left_sloap: " << left_sloap << std::endl;
  std::cout << "right_sloap: " << right_sloap << std::endl;
  
  float current_leftedge_x = point2.x;
  float current_rightedge_x = point2.x;
  
  for(int y = point2.y; y > point1.y; y--) { 
    fill_pixel_line(current_leftedge_x, current_rightedge_x, y,
		    color, image);
    current_leftedge_x -= left_sloap;
    current_rightedge_x -= right_sloap;
    }
  
  // draw bottom triangle
  left_sloap = (float)(point0.x - point1.x) / (point0.y - point1.y); 
  right_sloap = (float)(point0.x - point2.x) / (point0.y - point2.y);

  std::cout << "left_sloap: " << left_sloap << std::endl;
  std::cout << "right_sloap: " << right_sloap << std::endl;
  current_leftedge_x = point0.x;
  current_rightedge_x = point0.x;

  if ((point1.x > point2.x && point0.x < point2.x) || (point1.x < point2.x && point0.x < point2.x)) {
    std::swap(left_sloap, right_sloap);
  }
  
  for(int y = point0.y; y <= point1.y; y++) {
  fill_pixel_line(current_leftedge_x, current_rightedge_x, y,
  		    color, image);
  current_leftedge_x += left_sloap;
  current_rightedge_x += right_sloap;
  }
}

void fill_pixel_line(int x0,  int x1, int y,
		     TGAColor color, TGAImage &image) {
  for(int x = x0; x <= x1; x++)
    image.set(x, y, color);
}
