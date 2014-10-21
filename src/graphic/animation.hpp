#include "../math/vec2.hpp"
#include "sprite.hpp"
#include "hitmap.hpp"
#include <vector>

#pragma once

class Animation {
public:
    Animation(const std::vector<Sprite*>& sprites, int idle_index, int interval);
    Animation(const std::vector<Sprite*>& sprites, int idle_index, int interval, vec2f position);

    int current_frame() const;
    bool IsFinished() const;
    vec2f position() const;
    float width();
    float height();
    Hitmap* CurrentHitmap() const;

    void set_current_frame(int frame);
    void set_ping_pong(bool ping_pong);
    void Reset();
    void Update(double delta);
    void Render(vec2f position) const;

private:
    std::vector<Sprite*> sprites_;
    float width_;
    float height_;
    vec2f position_;
    int idle_index_;
    int interval_;
    int current_frame_;
    int accum_;
    bool ping_pong_;
    bool ascending_;
    bool finished_;
};
