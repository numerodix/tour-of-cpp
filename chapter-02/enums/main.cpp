#include <iostream>
#include <cassert>

enum class Color {red, blue, green};
enum class TrafficLight {green, yellow, red};

TrafficLight& operator++(TrafficLight& t) {
    switch (t) {
        case TrafficLight::green:
            t = TrafficLight::yellow;
            break;
        case TrafficLight::yellow:
            t = TrafficLight::red;
            break;
        case TrafficLight::red:
            t = TrafficLight::green;
            break;
    }
    return t;
}


int main() {
    // different types!
    // Color::red == TrafficLight::red;

    TrafficLight light = TrafficLight::green;
    assert(light == TrafficLight::green);

    ++light;
    assert(light == TrafficLight::yellow);

    ++light;
    assert(light == TrafficLight::red);

    ++light;
    assert(light == TrafficLight::green);
}