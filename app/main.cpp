#include <iostream>

#include "timer.h"



int main() {
    util::Timer timer(3000, []() {std::cout << "Hello World\n";});
    std::cout << "Press 's' to start the timer, 'r' to reset, 'm' to stop, or 'q' to quit." << std::endl;

    char choice;
    while (true) {
        std::cout << "MAKE A CHOICE\n";
        std::cin >> choice;
        switch (choice) {
            case 's':
                timer.start(); // Start a 5-second timer
                break;
            case 'r':
                timer.resetTimer(); // Reset the timer
                break;
            case 'q':
                return 0; // Quit the program
            case 'm':
                timer.stop();
                break;
            default:
                std::cout << "Invalid choice. Press 's' to start, 'r' to reset, 'm' to stop, or 'q' to quit." << std::endl;
        }
    }

    return 0;
}