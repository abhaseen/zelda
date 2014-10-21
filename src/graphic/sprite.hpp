#include <GL/gl.h>
#include "../math/vec2.hpp"
#include "hitmap.hpp"

#pragma once

class Sprite {
public:
    Sprite(GLuint texture, int width, int height, float tex_x, float tex_y, float tex_width, float tex_height);
    Sprite(GLuint texture, int width, int height, float tex_x, float tex_y, float tex_width, float tex_height,
            Hitmap* hitmap);

    float width() const;
    float height() const;
    Hitmap* hitmap() const;

    void Render(const vec2f& position) const;

private:
    GLuint texture_;
    int width_;
    int height_;
    float tex_x_;
    float tex_y_;
    float tex_width_;
    float tex_height_;
    Hitmap* hitmap_;
};
