#ifndef __LINE_H__
#define __LINE_H__

#include <cstdlib>
#include <math.h>

#include "tgaimage.h"

void draw_line(int, int, int, int, TGAColor, TGAImage &);
void draw_line_low(int, int, int, int, TGAColor, TGAImage &);
void draw_line_high(int, int, int, int, TGAColor, TGAImage &);
float line_get_length(int, int, int, int);

#endif /* __LINE_H__ */
