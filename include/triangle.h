#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "geometry.h"
#include "tgaimage.h"

void draw_triangle(Vec2i, Vec2i, Vec2i, TGAColor, TGAImage &);
void fill_pixel_line(int, int, int, TGAColor, TGAImage &);


#endif /* __TRIANGLE_H__ */
