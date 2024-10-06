#include <iostream>
#include <string>
#include <vector>
#include "StringData.h"
#include <chrono>
using std::cout;
using std::endl;
using std::vector;
using std::string;
vector <string> container = getStringData();
int linear_search(vector <string> container, string element) {
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}
int binary_search(vector<string> container, string element) {
    int startIndex = 0;
    int endIndex = container.size() - 1;
    while (startIndex <= endIndex) {
        int middleIndex = (startIndex + endIndex) / 2;
        if (container[middleIndex] == element) {
            return middleIndex;
        } else if (container[middleIndex] > element) {
            endIndex = middleIndex - 1;
        } else {
            startIndex = middleIndex + 1;
        }
    }
    return -1;
}
int binary_timer(vector<string> container, string element) {
    auto start_time = std::chrono::system_clock::now();
    int index = binary_search(container, element);
    auto end_time = std::chrono::system_clock::now();
    cout << "Binary search index of " << element << " is " << index << endl;
    std::chrono::duration<double, std::micro> final_time = (end_time - start_time);
    //the lab said that the times might be 0 seconds. they are if you use the typical duration type
    // but i wanted actual times so i just used microseconds as my time measurement
    double count = final_time.count();
    return count;
}
int linear_timer(vector<string> container, string element) {
    auto start_time = std::chrono::system_clock::now();
    int index = linear_search(container, element);
    auto end_time = std::chrono::system_clock::now();
    cout << "Linear search index of " << element << " is " << index << endl;
    //the lab said that the times might be 0 seconds. they are if you use the typical duration type
    // but i wanted actual times so i just used microseconds as my time measurement
    std::chrono::duration<double, std::micro> final_time = (end_time - start_time);
    double count = final_time.count();
    return count;
}
int main() {
    double notHereLinear = linear_timer(container, "not_here");
    double notHereBinary = binary_timer(container, "not_here");
    double mzzzzLinear = linear_timer(container, "mzzzz");
    double mzzzzBinary = binary_timer(container, "mzzzz");
    double aLinear = linear_timer(container, "aaaaa");
    double aBinary = binary_timer(container, "aaaaa");
    cout << "Not_here linear time: " << notHereLinear << " microseconds" << endl;
    cout << "Not_here binary time: " << notHereBinary << " microseconds" << endl;
    cout << "mzzzz linear time: " << mzzzzLinear << " microseconds" << endl;
    cout << "mzzzz binary time: " << mzzzzBinary << " microseconds" << endl;
    cout << "aaaaa linear time: " << aLinear << " microseconds" << endl;
    cout << "aaaaa binary time: " << aBinary << " microseconds" << endl;

    return 0;
}
