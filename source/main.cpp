#include <iostream>
#include "Window.h"

static const uint16_t number = 4;

bool is_correct_answer (std::string answer, std::string* actions) {

    for (int i=0;i < number;++i) {
        if (answer == actions[i]) return true;
    }
    return false;
}

int main() {

    std::string actions[] = {"move","resize","display","close"};
    std::string answer;
    Window* window = new Window();

    do {
        std::cout << "\nInput one from the list of commands:" << std::endl;
        for (int i=0;i < number;++i) {
            std::cout << "-" << actions[i] << std::endl;
        }
        std::cout << ">";

        do {
            std::cin >> answer;
            if (!(is_correct_answer(answer,actions))) std::cout << "Incorrect!Repeat.\n>";
        } while (!(is_correct_answer(answer,actions)));

        if (answer == actions[0]) window->move();
        else if (answer == actions[1]) {
            window->resize();
        }
        else if (answer == actions[2]) {
            window->display();
        }
    } while (answer != "close");
    delete window;
    window = nullptr;
    return 0;
}
