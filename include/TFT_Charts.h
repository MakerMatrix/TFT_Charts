/*
Copyright 2021, Jarrod Smith (MakerMatrix)

Licensed under the Apache License
https://www.apache.org/licenses/LICENSE-2.0.txt

Inspired by (and bits borrowed from) Kris Kasprzak's Graph() function:
https://github.com/KrisKasprzak/GraphingFunction/blob/master/Graph.ino
*/

#include <Adafruit_GFX.h>
#include <TFT_ILI9341.h>
#include <TFT_Colors.h>

class ChartXY
{
public:
    // Default colors
    uint16_t tftBGColor = BLACK;
    uint16_t chartBGColor = BLACK;
    uint16_t axesColor = RED;
    uint16_t titleColor = WHITE;
    uint16_t labelColor = RED;
    uint16_t tickColor = BLUE;
    uint16_t lineColor = YELLOW;
    uint16_t pointColor = GREEN;
    boolean isScrolling=false;
    
    // Instantiates the class, taking a pointer to an ILI9341 TFT object
    //ChartXY(TFT_ILI9341 &tft);

    // Instantiates the class, taking a pointer to an ILI9341 TFT object
    void begin(TFT_ILI9341 &tft);

    // Returns diagnostic information about the object
    void tftInfo();

    // Set the chart region in pixels (top left -> bottom right)
    void setChartRegion(unsigned short xp0, unsigned short yp0,
                        unsigned short xp1, unsigned short yp1);

    void setAxisLimitsX(float xMin, float xMax, float xIncr);

    void setAxisLimitsY(float yMin, float yMax, float yIncr);

    void eraseChartRegion(TFT_ILI9341 &tft);
    
    // Draws the Title
    void drawTitle(TFT_ILI9341 &tft, String chartTitle);
    
    // Draws the X axis
    void drawAxisX(TFT_ILI9341 &tft, int tickLen);

    // Draws the Y axis
    void drawAxisY(TFT_ILI9341 &tft, int tickLen);

    // Draws the X tick labels
    void drawLabelsX(TFT_ILI9341 &tft);

    // Draws the X tick labels
    void drawLabelsY(TFT_ILI9341 &tft);

    // Draw a point
    void drawPoint(TFT_ILI9341 &tft, float x, float y, uint16_t ptSize);

    // Erase a point
    void erasePoint(TFT_ILI9341 &tft, float x, float y, uint16_t ptSize);

    // Draw a line
    void drawLine(TFT_ILI9341 &tft, float x0, float y0, float x1, float y1);

    // Erase a line
    void eraseLine(TFT_ILI9341 &tft, float x0, float y0, float x1, float y1);

private:
    // Private variables
    uint16_t tftResX; // Number of pixels in the X direction
    uint16_t tftResY; // Number of pixels in the Y direction
    uint16_t xPxLo;   // X pixel for upper left chart corner
    uint16_t yPxLo;   // Y pixel for upper left chart corner
    uint16_t xPxHi;   // X pixel for lower right chart corner
    uint16_t yPxHi;   // Y pixels for lower right chart corner
    uint16_t xPxSize; // Size of the X axis in pixels
    uint16_t yPxSize; // Size of the Y axis in pixels
    float xMin;
    float xMax;
    float yMin;
    float yMax;
    float xIncr;
    float yIncr;
    float xPxPerX;
    float yPxPerY;
    



    // Compute the width of a number in pixels
    uint16_t pixelWidth(int label);

};
