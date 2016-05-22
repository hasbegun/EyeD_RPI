
#ifndef UI_COMPONENTS
#define UI_COMPONENTS

#include <stdio.h>
#include <iostream>

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;


class UIComponents {
public:
    UIComponents(void);
    ~UIComponents(void);
    
    // Draw a GUI button into the image, using drawString().
    // Can specify a minWidth if you want several buttons to all have the same width.
    // Returns the bounding rect around the drawn button, allowing you to position buttons next to each other.
    Rect drawButton(Mat img, string text, Point coord, int minWidth = 0);
    Rect drawString(Mat img, string text, Point coord, Scalar color,
                           float fontScale = 0.6f, int thickness = 1, int fontFace = FONT_HERSHEY_COMPLEX);
    bool isPointInRect(const Point pt, const Rect rc);

    void setBorderValue(int);
    int getBorderValue();
    
private:
    int BORDER;
};
#endif
