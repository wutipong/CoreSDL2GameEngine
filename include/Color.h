#pragma once

struct Color
{
	int r, g, b;
	Color() : r(255), g(255), b(255){}
	Color(int _r, int _g, int _b) : r(_r), g(_g), b(_b){}
};

#define COLOR_WHITE Color(255, 255, 255)
#define COLOR_BLACK Color(0, 0, 0)
#define COLOR_RED Color(255, 0, 0)
#define COLOR_GREEN Color(0, 255, 0)
#define COLOR_BLUE Color(0, 0, 255)
