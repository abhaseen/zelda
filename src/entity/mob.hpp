#pragma once

#include "../entity.hpp"
#include "mob/action.hpp"
#include "mob/ai.hpp"
#include "../math/vec2.hpp"
#include "../math/dir.hpp"
#include <map>
#include <string>
#include <SFML/Audio/SoundBuffer.hpp>

class Path;
class Mob : public Entity {
public:
    typedef Entity super;

    static sf::SoundBuffer* HIT_SOUND;
    static void Load();

    Mob(float x, float y, float width, float height, Action* idle_action_);
    ~Mob();

    bool CanMove() const;
    const Dir& facing() const;
    bool moving() const;
    bool IsMob() const;
    Action* action(std::string name) const;
    Sprite* CurrentSprite(vec2f& position) const;
    Sprite* CurrentSprite() const;
    Entity* SeekPlayer() const;
    Entity* SeekEnemy() const ;
    Path* FindPath(Entity* to);
    bool FollowPath(Path* path, double delta);
    bool CanCollideWith(RectangleShape* rectangle) const;
    float speed() const;

    sf::SoundBuffer* attack_sound() const;

    void set_AI(AI* ai);
    void set_facing(const Dir& dir);
    void AddAction(const std::string& name, Action* action);
    void ChangeAction(Action *action);
    bool Move(const Dir& direction, double delta);
    bool Move(const vec2f& direction, int intensity, double delta);
    void MoveTowards(Entity* entity, double delta);
    void Slide(const vec2f direction, int intensity, double delta);
    void MeleeAttack(Hitbox* hitbox);
    void Damage(Entity* from, int damage);

    void Update(double delta);
    void Draw() const;

protected:
    Action* idle_action_;
    Action* current_action_;
    float speed_;
    sf::SoundBuffer* attack_sound_;
    Dir facing_;

private:
    AI* ai_;
    std::map<std::string, Action*> actions_;
    int facing_candidate_;
    bool moving_;

    void _MoveVector(vec2f dir, double delta);
    bool _UpdatePosition(const vec2f& new_position);
};
