#include <stdio.h>
#include <iostream>

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

// Draw a GUI button into the image, using drawString().
// Can specify a minWidth if you want several buttons to all have the same width.
// Returns the bounding rect around the drawn button, allowing you to position buttons next to each other.
Rect drawButton(Mat img, string text, Point coord, int minWidth = 0);
