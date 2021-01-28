#ifndef UTILITY_H
#define UTILITY_H

#include "../image/image.h"
#include <sstream>
#include <math.h>

class utility
{
	public:
		utility();
		virtual ~utility();
		static std::string intToString(int number);
		static int checkValue(int value);
		static void copy_image(image& src, image& tgt);
		static void copy_colorimage(image& src, image& tgt);
		static void addGrey(image &src, image &tgt, int x, int y, int sx, int sy, int value);
		static void binarize(image& src, image& tgt, int x, int y, int sx, int sy, int threshold);
		static void roiregion(image& src, image& tgt, int x, int y, int sx, int sy, int t1, int t2);
		static void smoothing(image& src, image& tgt, int x, int y, int sx, int sy, int ws);
		static void Adapsmoothing(image& src, image& tgt, int x, int y, int sx, int sy, int ws);
		static void ColorBrgt(image& src, image& tgt, int x, int y, int sx, int sy, int cr, int cg, int cb);
		static void ColorBin(image& src, image& tgt, int x, int y, int sx, int sy, int cred, int cgreen, int cblue, int tc);
		static void scale(image& src, image& tgt, float ratio);

};

#endif

