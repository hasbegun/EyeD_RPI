
#include "UIComponents.h"


UIComponents::UIComponents() {
    BORDER = 8;
}
UIComponents::~UIComponents() {}

void UIComponents::setBorderValue(int border) {
    if (border < 8) border = 8;
    BORDER = border;
}

int UIComponents::getBorderValue() {
    return BORDER;
}

Rect UIComponents::drawButton(Mat img, string text, Point coord, int minWidth)
{
    Point textCoord = Point(coord.x + BORDER, coord.y + BORDER);
    // Get the bounding box around the text.
    Rect rcText = drawString(img, text, textCoord, CV_RGB(0,0,0));
    // Draw a filled rectangle around the text.
    Rect rcButton = Rect(rcText.x - BORDER, rcText.y - BORDER, rcText.width + 2*BORDER, rcText.height + 2*BORDER);
    // Set a minimum button width.
    if (rcButton.width < minWidth)
        rcButton.width = minWidth;
    // Make a semi-transparent white rectangle.
    Mat matButton = img(rcButton);
    matButton += CV_RGB(90, 90, 90);
    // Draw a non-transparent white border.
    rectangle(img, rcButton, CV_RGB(200,200,200), 1, CV_AA);
    
    // Draw the actual text that will be displayed, using anti-aliasing.
    drawString(img, text, textCoord, CV_RGB(10,55,20));
    
    return rcButton;
}

// Draw text into an image. Defaults to top-left-justified text, but you can give negative x coords for right-justified text,
// and/or negative y coords for bottom-justified text.
// Returns the bounding rect around the drawn text.
Rect UIComponents::drawString(Mat img, string text, Point coord, Scalar color,
                float fontScale, int thickness, int fontFace)
{
    // Get the text size & baseline.
    int baseline=0;
    Size textSize = getTextSize(text, fontFace, fontScale, thickness, &baseline);
    baseline += thickness;
    
    // Adjust the coords for left/right-justified or top/bottom-justified.
    if (coord.y >= 0) {
        // Coordinates are for the top-left corner of the text from the top-left of the image, so move down by one row.
        coord.y += textSize.height;
    }
    else {
        // Coordinates are for the bottom-left corner of the text from the bottom-left of the image, so come up from the bottom.
        coord.y += img.rows - baseline + 1;
    }
    // Become right-justified if desired.
    if (coord.x < 0) {
        coord.x += img.cols - textSize.width + 1;
    }
    
    // Get the bounding box around the text.
    Rect boundingRect = Rect(coord.x, coord.y - textSize.height, textSize.width, baseline + textSize.height);
    
    // Draw anti-aliased text.
    putText(img, text, coord, fontFace, fontScale, color, thickness, CV_AA);
    
    // Let the user know how big their text is, in case they want to arrange things.
    return boundingRect;
}

bool UIComponents::isPointInRect(const Point pt, const Rect rc)
{
    if (pt.x >= rc.x && pt.x <= (rc.x + rc.width - 1))
        if (pt.y >= rc.y && pt.y <= (rc.y + rc.height - 1))
            return true;
    
    return false;
}
