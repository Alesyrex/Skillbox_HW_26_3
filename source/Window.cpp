#include <iostream>
#include "Window.h"

static const uint16_t displayWidth = 80;
static const uint16_t displayHeight = 50;

Window::Window()
{
    do
    {
        std::cout << "Enter the width of the window:";
        std::cin >> width;
        std::cout << "Enter the height of the window:";
        std::cin >> height;
        std::cout << "Enter the coordinates X Y of the upper left angle:";
        std::cin >> topLeftAngle.coordX >> topLeftAngle.coordY;
        if (!is_correct())
        {
            std::cout << "Coordinates of the upper left angle should not be less than zero and more than ";
            std::cout << displayWidth << "x" << displayHeight << "." << std::endl;
            std::cout << "Window width should not be more than " << displayWidth << ". ";
            std::cout << "Window height should not be more than " << displayHeight << "." << std::endl;
            std::cout << "Try again." << std::endl;
        }
    } while (!is_correct());
}

void Window::move()
{
    bool correct = false;
    while (!correct)
    {
        std::cout << "Enter the vector (X,Y) to move the window:";
        std::cin >> vector.coordX >> vector.coordY;
        topLeftAngle.coordX += vector.coordX;
        topLeftAngle.coordY += vector.coordY;
        if (!is_correct()) {
            std::cout << "Window extends outside the display. Try again." << std::endl;
            topLeftAngle.coordX -= vector.coordX;
            topLeftAngle.coordY -= vector.coordY;
        }
        else
        {
            std::cout << "New window coordinates (" << topLeftAngle.coordX << "," << topLeftAngle.coordY << ")" << std::endl;
            correct = true;
        }
    }
}

void Window::resize()
{
    uint16_t tmpWidth = width;
    uint16_t tmpHeight = height;
    bool correct = false;
    while (!correct)
    {
        std::cout << "Enter new window sizes. Width:";
        std::cin >> width;
        std::cout << "Height:";
        std::cin >> height;

        if (!is_correct()) {
            std::cout << "Window extends outside the display. Try again." << std::endl;
            width = tmpWidth;
            height = tmpHeight;
        }
        else
        {
            std::cout << "New window sizes " << width << "x" << height << std::endl;
            correct = true;
        }
    }
}

void Window::display()
{
    for (int i=0;i < displayHeight;++i)
    {
        for (int j=0;j < displayWidth;++j)
        {
            if (j >= topLeftAngle.coordX && i >= topLeftAngle.coordY
               && (j < width + topLeftAngle.coordX) && (i < height + topLeftAngle.coordY))
                std::cout << "1";
            else std::cout << "0";
        }
        std::cout << std::endl;
    }
}

bool Window::is_correct ()
{
    if ((topLeftAngle.coordX >= displayWidth || topLeftAngle.coordY >= displayHeight)
        || (width + topLeftAngle.coordX > displayWidth)
        || (height + topLeftAngle.coordY > displayHeight)
        || width < 0 || height < 0 || topLeftAngle.coordX < 0 || topLeftAngle.coordY < 0)
        return false;
    else return true;
}
