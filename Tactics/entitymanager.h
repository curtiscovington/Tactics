#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>
#include <array>

class Entity;

class EntityManager {
public:
    Entity& addEntity();
    void addToGroup(Entity* e, std::size_t group);
    std::vector<Entity*>& getEntitiesByGroup(std::size_t group);
    void refresh();
private:
    std::vector<std::unique_ptr<Entity>> mEntities;
    std::array<std::vector<Entity*>, 32> mGroupedEntities;
};
#endif