#pragma once
#ifndef SKILLBOX_HW_26_3_WINDOW_H
#define SKILLBOX_HW_26_3_WINDOW_H

class Window
{
private:
    uint16_t width = 0;
    uint16_t height = 0;
    struct coord
    {
        uint16_t coordX = 0;
        uint16_t coordY = 0;
    };
public:
    Window();
    coord topLeftAngle;
    coord vector;
    void move ();
    void resize ();
    void display ();
    bool is_correct ();
};

#endif //SKILLBOX_HW_26_3_WINDOW_H
