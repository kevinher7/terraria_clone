class Entity;

class PlayerManager
{
public:
    PlayerManager() = default;
    ~PlayerManager() = default;

    void init(Entity &playerEntity, int xpos, int ypos);
};
