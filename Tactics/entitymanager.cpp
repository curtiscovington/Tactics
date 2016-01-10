#include "entitymanager.h"
#include "entity.h"

Entity& EntityManager::addEntity() {
    Entity* e(new Entity(*this));
    std::unique_ptr<Entity> uPtr{e};
    mEntities.emplace_back(uPtr);
    return *e;
}

void EntityManager::addToGroup(Entity* e, std::size_t group) {
    mGroupedEntities[group].emplace_back(e);
}

std::vector<Entity*>& EntityManager::getEntitiesByGroup(std::size_t group) {
    return  mGroupedEntities[group];
}

void EntityManager::refresh() {
    for (auto i(0u); i < 32u; i++) {
        auto& v(mGroupedEntities[i]);
        v.erase(std::remove_if(std::begin(v), std::end(v),
                               [i](Entity* e) {return !e->isAlive() || !e->hasGroup(i);}),
                            std::end(v));
    }
}