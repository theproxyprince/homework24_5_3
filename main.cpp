#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <ctime>

int main() {
    std::time_t t = std::time(nullptr);
    std::tm* time = std::localtime(&t);

    std::cout << "Enter time: ";
    std::cin >> std::get_time(time, "%M:%S");


    while (true) {
        std::cout << std::put_time(time, "%M:%S") << std::endl;
        if (!time->tm_sec && time->tm_min > 0) {
            time->tm_sec = 60;
            time->tm_min -= 1;
        } else if (!time->tm_sec && !time->tm_min) {
            std::cout << "DING! DING! DING!" << std::endl;
            break;
        }

        time->tm_sec -= 1;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
