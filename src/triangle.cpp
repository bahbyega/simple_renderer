#include "triangle.h"


/* draw /\ type of triangle */
void drawBottomFlatTriangle(Vec2i point0, Vec2i point1, Vec2i point2,
			    TGAColor color, TGAImage &image)
{
  float left_sloap = (float)(point2.x - point1.x) / (point2.y - point1.y); 
  float right_sloap = (float)(point2.x - point0.x) / (point2.y - point0.y);

  if (left_sloap < right_sloap) {
    std::swap(left_sloap, right_sloap);
  }
  
  float current_leftedge_x = point2.x;
  float current_rightedge_x = point2.x;
  
  for(int y = point2.y; y > point1.y; y--) { 
    fill_pixel_line((int)current_leftedge_x, (int)current_rightedge_x, y, color, image);
    current_leftedge_x -= left_sloap;
    current_rightedge_x -= right_sloap;
    }
  
}

/* draw \/ type of triangle */
void drawTopFlatTriangle(Vec2i point0, Vec2i point1, Vec2i point2,
			 TGAColor color, TGAImage &image)
{
  float left_sloap = (float)(point0.x - point1.x) / (point0.y - point1.y); 
  float right_sloap = (float)(point0.x - point2.x) / (point0.y - point2.y);
  
  if (left_sloap > right_sloap) {
    std::swap(left_sloap, right_sloap);
  }

  float current_leftedge_x = point0.x;
  float current_rightedge_x = point0.x;
  
  for(int y = point0.y; y <= point1.y; y++) {
    fill_pixel_line((int)current_leftedge_x, (int)current_rightedge_x, y, color, image);
  current_leftedge_x += left_sloap;
  current_rightedge_x += right_sloap;
  }
}


/* Standard method of drawing triangles:
   we think of a triangle as two flat 
   bottom  triangles and draw each one.  */
void fill_triangle(Vec2i point0, Vec2i point1, Vec2i point2,
		   TGAColor color, TGAImage &image)
{
  // sort vertices by y coordinat,
  // so that point0.y < point1.y < point2.y 
  if (point0.y > point2.y) std::swap(point0, point2);
  if (point1.y > point2.y) std::swap(point1, point2);
  if (point0.y > point1.y) std::swap(point0, point1);

  // speed up the proccess for trivial cases
  if (point1.y == point0.y) { // bottom flat triangle
    drawBottomFlatTriangle(point0, point1, point2, color, image);
  } else if (point1.y == point2.y) { // top flat triangle
    drawTopFlatTriangle(point0, point1, point2, color, image);
  } else { 
    drawBottomFlatTriangle(point0, point1, point2, color, image);
    drawTopFlatTriangle(point0, point1, point2, color, image);
  }
}

/* This func draws pixel line parallel to the ground */
void fill_pixel_line(int x0,  int x1, int y,
		     TGAColor color, TGAImage &image)
{
  for(int x = x0; x <= x1; x++)
    image.set(x, y, color);
}
