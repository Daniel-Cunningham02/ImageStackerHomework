#ifndef STACKER_H
#define STACKER_H
#include <string>
#include <vector>


struct pixel {
    int red;
    int green;
    int blue;
};

class Stacker {
    private:
        std::string magic_number;
        int width;
        int height;
        int max_color;
        std::vector<pixel> pixels;
};

#endif