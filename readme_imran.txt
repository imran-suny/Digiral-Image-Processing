*** This project is built under Visual Studio 2019
[You can find the output image in output folder and histogram image in iptool folder]

This software is architectured as follows

iptool/iptool.cpp- This file includes the main function.

iptool/iptools -This folder hosts the files that are compiled into a static library. 
	image - This folder hosts the files that define an image.
	utility- this folder hosts the files that students store their implemented algorithms.



*** INSTALATION ***

On Windows

Open the project by double click iptool.sln.

*** FUNCTIONS ***

1. Histogram Stretching of grey image: histogramstch
This function is used to stretch grey level scale from the range of [c,d] to new range [0,255]. 

2. Histogram Generation: histoBefore
It gives the histogram of an image

3. Histogram after stretching: histoAfter
Histogram after stretching is generated using this function.

4.Stretching R Only: HistostchR
Red channel of RGB image is stretched only when it is applied.

5.Stretching G Only: HistostchG
GREEN channel of RGB image is stretched only when it is applied.

6.Stretching B Only: HistostchB
BLUE channel of RGB image is stretched only when it is applied.

7.Stretching R,G,B : HistostchRGB
all three channel of RGB image is stretched when it is applied.

8. Checking conversion works well: RGBtoHSI 
this function is used to check the conversion RGB-HSI-RGB is working or not

9. Stretching I: Istrech
I of HIS is stretched. 

10. Stretching I and S: StrechIS 
I and S of HIS is stretched
 
11.Stretching I,S,H: StrechHSI 
HIS is stretched in the range of [0-255] for I and S and [0-360] for H. 


*** PARAMETERS ***

The first parameter of the parameters.txt is the number of operations (lines).
There are five parameters for each operation (line):
1. the input file name;
2. the output file name;
3. the name of the function.
4. Number of ROIs to be generated[sTimes is used in C++ coding]
5. the value for ROIs(x,y,sx,sy), the intensity range from (c,d) to (0,255)

1. histogramstch 3 0 0 90 90 90 200 0 255 90 80 100 100 90 200 0 255 300 200 200 200 50 150 0 255
here[3=number of RoIs, (0 0 90 90 90->ROIs), c=90 d=200 a=0 b=255], then next ROI 
2. histoBefore 1 90 80 100 100
[histogram is generated in the ROI region of the range x=90,y=80,sx=100,sy=100]histogram image in iptool folder]
3. histoBefore 1 90 80 100 100 90 200 0 255
[histogram is generated in the ROI region of the range x=90,y=80,sx=100,sy=100, c=90,d=200,a=0,b=255][histogram image in iptool folder]
(4-11) follow the same structure

*** Run the program:

Directly debug in Visual Studio.
You can find the output image in output folder and histogram image in iptool folder


*** Important information ***

Application assumes the next format of input image (ppm/pgm) file:
line1: <version>
line2: <#columns> <#rows>
line3: <max_value>
line4-end-of-file:<pix1><pix2>...<pix_n>

if it is a grayscale image then every pixel is a char value. If it is a RGB image then every pixel is a set of 3 char values: <red><green><blue>

Thus, if you have a problem with reading image, the first thing you should check is input file format.
