#include "line.h"
#include<iostream>

struct Line {
  int x0, y0; // left vertice
  int x1, y1; // right vertice

  float len; // length of a line
};

void draw_line(int x0, int y0,
	       int x1, int y1,
	       TGAColor color, TGAImage &image) {
  if (std::abs(x1 - x0) < std::abs(y1 - y0)) {
    if (y0 > y1)
      draw_line_high(x1, y1, x0, y0, color, image);
    else
      draw_line_high(x0, y0, x1, y1, color, image);
  }
  else {
    if (x0 > x1)
      draw_line_low(x1, y1, x0, y0, color, image);
    else
      draw_line_low(x0, y0, x1, y1, color, image);
  }
  
}

void draw_line_low(int x0, int y0,
	       int x1, int y1,
	       TGAColor color, TGAImage &image) {
  int dx = x1 - x0;
  int dy = y1 - y0;

  int error = 0;
  int y = y0;

  int y_increment = 0;
  if (dy > 0)
    y_increment = 1 ;
  else {
    y_increment = -1;
    dy = -dy;
  }
  
  for(int x = x0; x <= x1; x++) {
    image.set(x, y, color);

    error += dy;
    if (2 * (error + dy)  >= dx) {
      y += y_increment;
      error -= dx;
    }
  }
}

void draw_line_high(int x0, int y0,
	       int x1, int y1,
	       TGAColor color, TGAImage &image) {
  int dx = x1 - x0;
  int dy = y1 - y0;

  int error = 0;
  int x = x0;

  int x_increment = 0;
  if (dx > 0)
    x_increment = 1 ;
  else {
    x_increment = -1;
    dx = -dx;
  }
  
  for(int y = y0; y <= y1; y++) {
    image.set(x, y, color);

    error += dx;
    if (2 * (error + dx)  >= dy) {
      x += x_increment;
      error -= dy;
    }
  }
}

float line_get_length(int x0, int y0,
		     int x1, int y1) {
  return sqrt( (x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1) );
}
