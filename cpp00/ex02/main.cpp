#include <iostream>
#include <ctime>
#include <iomanip>

std::string getCurrentTime() {
    std::time_t raw_time;
    std::tm* time_info;
    char buffer[20];

    std::time(&raw_time);
    time_info = std::localtime(&raw_time);

    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", time_info);
    return std::string(buffer);
}

int main() {
    std::string current_time = getCurrentTime();
    std::cout << "Current time: " << current_time << std::endl;

    return 0;
}
