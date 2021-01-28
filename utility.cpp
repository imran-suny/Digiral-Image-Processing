#include "utility.h"

#define MAXRGB 255
#define MINRGB 0

std::string utility::intToString(int number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int utility::checkValue(int value)
{
	if (value > MAXRGB)
		return MAXRGB;
	if (value < MINRGB)
		return MINRGB;
	return value;
}


void utility::copy_image(image& src, image& tgt) {
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{
			tgt.setPixel(i, j, src.getPixel(i, j));

		}
	}
}

void utility::copy_colorimage(image& src, image& tgt) {
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{

			tgt.setPixel(i, j, RED, (src.getPixel(i, j, RED)));
			tgt.setPixel(i, j, GREEN, (src.getPixel(i, j, GREEN)));
			tgt.setPixel(i, j, BLUE, (src.getPixel(i, j, BLUE)));

		}
	}
}


/*-----------------------------------------------------------------------**/
void utility::addGrey(image& src, image& tgt, int x, int y, int sx, int sy, int value)
{

	for (int i = x; i < x + sx; i++)
	{
		for (int j = y; j < y + sy; j++)
		{
			tgt.setPixel(i, j, checkValue(src.getPixel(i, j) + value));
		}
	}
}

/*-----------------------------------------------------------------------**/


void utility::binarize(image& src, image& tgt, int x, int y, int sx, int sy, int threshold)
{
	cout << src.getNumberOfRows() << " " << src.getNumberOfColumns() << endl;

	for (int i = x; i < x + sx; i++)
	{
		for (int j = y; j < y + sy; j++)
		{
			if (src.getPixel(i, j) < threshold)
				tgt.setPixel(i, j, MINRGB);
			else
				tgt.setPixel(i, j, MAXRGB);
		}
	}

}


/*-----------------------------------------------------------------------**/
void utility::scale(image &src, image &tgt, float ratio)
{
	int rows = (int)((float)src.getNumberOfRows() * ratio);
	int cols  = (int)((float)src.getNumberOfColumns() * ratio);
	tgt.resize(rows, cols);
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{	
			/* Map the pixel of new image back to original image */
			int i2 = (int)floor((float)i/ratio);
			int j2 = (int)floor((float)j/ratio);
			if (ratio == 2) {
				/* Directly copy the value */
				tgt.setPixel(i,j,checkValue(src.getPixel(i2,j2)));
			}

			if (ratio == 0.5) {
				/* Average the values of four pixels */
				int value = src.getPixel(i2,j2) + src.getPixel(i2,j2+1) + src.getPixel(i2+1,j2) + src.getPixel(i2+1,j2+1);
				tgt.setPixel(i,j,checkValue(value/4));
			}
		}
	}
}



void utility::roiregion(image& src, image& tgt, int x, int y, int sx, int sy, int t1, int t2)
{
	cout << src.getNumberOfRows() << " " << src.getNumberOfColumns() << endl;
	cout << x << " " << y << " " << sx << " " << sy<< " " << t1 << " " << t2 << endl;

	for (int i = x; i < x + sx; i++)
	{
		for (int j = y; j < y + sy; j++)
		{
			if (src.getPixel(i, j) >= t1 && src.getPixel(i, j) <= t2)
				tgt.setPixel(i, j, MAXRGB);
			else
				tgt.setPixel(i, j, MINRGB);
		}
	}

}

void utility::smoothing(image& src, image& tgt, int x, int y, int sx, int sy, int ws)
{
	cout << src.getNumberOfRows() << " " << src.getNumberOfColumns() << endl;
	
	for (int j = y; j < y + sy; j++)
	{
		for (int i = x; i < x + sx; i++)
		{
			int sum = 0;
			for(int si= (i-(ws/2)); si <= (i + (ws / 2)); ++si)
			{
				
				for (int sj = (j - (ws / 2)); sj <= (j + (ws / 2)); ++sj) {	 
						
					sum = sum + src.getPixel(si, sj);
				}
			}
			int average = sum / (ws * ws);
		tgt.setPixel(i, j, average);
		}
	}

}


void utility::Adapsmoothing(image& src, image& tgt, int x, int y, int sx, int sy, int ws)
{
	cout << src.getNumberOfRows() << " " << src.getNumberOfColumns() << endl;

	for (int j = y; j < y + sy; j++)
	{
		for (int i = x; i < x + sx; i++)
		{
			int sum = 0;
			int cnt = 0;
			for (int si = (i - (ws / 2)); si <= (i + (ws / 2)); ++si)
			{

				for (int sj = (j - (ws / 2)); sj <= (j + (ws / 2)); ++sj) {

					if (si >= x && si < x + sx && sj >= y && sj < y + sy) {
						cnt += 1;
						sum += src.getPixel(si, sj);
					}


				}
			}
			
			int average = sum / ( cnt);
			tgt.setPixel(i, j, average);
		}
	}

}





void utility::ColorBrgt(image& src, image& tgt, int x, int y, int sx, int sy, int cr, int cg, int cb)
{
	for (int i = x; i < x + sx; i++)
	{
		for (int j = y; j < y + sy; j++)
		{

			tgt.setPixel(i, j, RED, checkValue(src.getPixel(i, j, RED) + cr));
			tgt.setPixel(i, j, GREEN, checkValue(src.getPixel(i, j, GREEN) + cg));
			tgt.setPixel(i, j, BLUE, checkValue(src.getPixel(i, j, BLUE) + cb));


		}
	}
}

/************************************************************************************/
void utility::ColorBin(image& src, image& tgt, int x, int y, int sx, int sy, int cred, int cgreen, int cblue, int tc)
{
	int D;
	for (int i = x; i < x + sx; i++)
	{
		for (int j = y; j < y + sy; j++)
		{
			D = sqrt(pow(src.getPixel(i, j, RED) - cred, 2) + pow(src.getPixel(i, j, GREEN) - cgreen, 2) + pow(src.getPixel(i, j, BLUE) - cblue, 2));


			if (D <= tc) {
				tgt.setPixel(i, j, RED, 255);
				tgt.setPixel(i, j, GREEN, 0);
				tgt.setPixel(i, j, BLUE, 0);
			}
			else {
				tgt.setPixel(i, j, RED, MAXRGB);
				tgt.setPixel(i, j, GREEN, MAXRGB);
				tgt.setPixel(i, j, BLUE, MAXRGB);
			}


		}
	}
}