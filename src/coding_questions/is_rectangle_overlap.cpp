// dexterity
// product operations intern
// live (with engineer)

#include <iostream>

struct Point
{
    int x, y;
};

bool isRectangleOverlap(Point& bottom_left1, Point& top_right1,
                        Point& bottom_left2, Point& top_right2)
{
    bool overlap{true};

    if (bottom_left1.x > top_right2.x || bottom_left2.x > top_right1.x)
    {
        // std::cout << "1\n";
        overlap = false;
    }

    if (top_right1.y < bottom_left2.y || bottom_left1.y > top_right2.y)
    {
        // std::cout << "2\n";
        overlap = false;
    }

    return overlap;
}

int main()
{
    Point bottom_left1;
    Point top_right1;
    Point bottom_left2;
    Point top_right2;

    // overlapping
    bottom_left1 = {0, 0};
    top_right1 = {4, 4};
    bottom_left2 = {2, 2};
    top_right2 = {5, 5};

    std::cout << isRectangleOverlap(bottom_left1, top_right1, bottom_left2, top_right2) << '\n';

    // not overlapping
    bottom_left1 = {0, 0};
    top_right1 = {1, 1};
    bottom_left2 = {2, 2};
    top_right2 = {3, 3};
    
    std::cout << isRectangleOverlap(bottom_left1, top_right1, bottom_left2, top_right2) << '\n';

    // not overlapping
    bottom_left1 = {5, 5};
    top_right1 = {10, 10};
    bottom_left2 = {2, 2};
    top_right2 = {3, 3};
    
    std::cout << isRectangleOverlap(bottom_left1, top_right1, bottom_left2, top_right2) << '\n';
    
    // not overlapping
    bottom_left1 = {0, 0};
    top_right1 = {2, 2};
    bottom_left2 = {-3, 0};
    top_right2 = {-1, -1};

    std::cout << isRectangleOverlap(bottom_left1, top_right1, bottom_left2, top_right2) << '\n';

    // overlapping on bottom edge
    // bottom_left1 = {0, 0};
    // top_right1 = {4, 4};
    // bottom_left2 = {2, 2};
    // top_right2 = {5, 5};

    // std::cout << isRectangleOverlap(bottom_left1, top_right1, bottom_left2, top_right2) << '\n';

    // // overlapping on top edge
    // bottom_left1 = {0, 0};
    // top_right1 = {4, 4};
    // bottom_left2 = {2, 2};
    // top_right2 = {5, 5};

    // std::cout << isRectangleOverlap(bottom_left1, top_right1, bottom_left2, top_right2) << '\n';

    // // overlapping on left edge
    // bottom_left1 = {0, 0};
    // top_right1 = {4, 4};
    // bottom_left2 = {2, 2};
    // top_right2 = {5, 5};

    // std::cout << isRectangleOverlap(bottom_left1, top_right1, bottom_left2, top_right2) << '\n';


    // // overlapping on right edge
    // bottom_left1 = {0, 0};
    // top_right1 = {4, 4};
    // bottom_left2 = {2, 2};
    // top_right2 = {5, 5};

    // std::cout << isRectangleOverlap(bottom_left1, top_right1, bottom_left2, top_right2) << '\n';

    // // overlapping on vertex
    // bottom_left1 = {0, 0};
    // top_right1 = {4, 4};
    // bottom_left2 = {2, 2};
    // top_right2 = {5, 5};

    // std::cout << isRectangleOverlap(bottom_left1, top_right1, bottom_left2, top_right2) << '\n';
    
    return 0;
}
