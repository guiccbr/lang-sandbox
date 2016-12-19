#include <iostream>
#include <cmath>

struct rectangle {
    float x;
    float y;
    float w;
    float h;
};

int find_intersection(rectangle a, rectangle b, rectangle& intersection) {

    // Find out if 'a' possibly intersects with 'b' horizontally
    float h_dist = b.x - (a.x + a.w);
    if (h_dist > 0 || h_dist < -b.w - a.w) {
        return -1;
    }

    // Find out if 'a' possibly intersects with 'b' vertically
    float v_dist = b.y - (a.y + a.h);
    if (v_dist > 0 || v_dist < -b.h - a.h) {
        return -1;
    }

    // Rectangles intersect. Let's find out where.
    intersection.x = fmax(a.x + a.w + h_dist, a.x);
    intersection.y = fmax(a.y + a.h + v_dist, a.y);
    intersection.w = fmin(a.w, b.w);
    intersection.w = fmin(intersection.w, h_dist + a.w + b.w);
    intersection.w = fmin(intersection.w, -h_dist);
    intersection.h = fmin(a.h, b.h);
    intersection.h = fmin(intersection.h, v_dist + a.h + b.h);
    intersection.h = fmin(intersection.h, -v_dist);

    return 0;
}

int main(void) {

    rectangle a = {0.0, 0.0, 2.0, 2.0};
    rectangle b = {1.0, 1.0, 1.0, 1.0};

    rectangle intersection = {0};

    if (find_intersection(a, b, intersection) != -1) {
        std::cout << "Intersection (x, y, w, h): " << intersection.x << ", "
                  << intersection.y << ", " << intersection.w << ", "
                  << intersection.h << std::endl;
    } else {
        std::cout << "Rectangles do not intersect" << std::endl;
    }

    std::cout << "\033[1;31mBold Red Text\033[0m\n";

    return 0;
}
