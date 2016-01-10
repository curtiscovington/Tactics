#include "entity.h"
#include "component.h"

Entity::Entity(EntityManager& manager) : mManager(manager) { }

bool Entity::isAlive() const {
    return mIsAlive;
}

void Entity::destory() {
    mIsAlive = false;
}

bool Entity::hasGroup(GroupBitset g) const noexcept {
    return (mGroupBitset & g) == g;
}

