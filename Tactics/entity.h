#ifndef ENTITY_H
#define ENTITY_H

#include <cassert>
#include <bitset>
#include <array>
#include <vector>
#include "component.h"



using ComponentBitset = std::size_t;
using GroupBitset = std::size_t;
using ComponentArray = std::array<Component*, 32>;
class EntityManager;

class Entity {
public:
    Entity(EntityManager& manager);
    bool isAlive() const;
    void destory();
    bool hasGroup(GroupBitset g) const noexcept;
    template <typename T>
    bool hasComponent() const {
        Components::ID id = Components::getComponentTypeID<T>();
        Components::ID mask = 1 << id;
        return ((mComponentBitset & mask) == mask);
    }
    template <typename T>
    T& getComponent() const {
        Components::ID id = Components::getComponentTypeID<T>();
        auto p(mComponentArray[id]);
        return *reinterpret_cast<T*>(p);
    }
    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... args) {
        
        assert(!hasComponent<T>());
        
        T* component(new T(std::forward<TArgs>(args)...));
        component->entity = this;
        std::unique_ptr<Component> p{component};
        
        mComponents.emplace_back(std::move(p));
        Components::ID id = Components::getComponentTypeID<T>();
        this->mComponentBitset |= (1 << id);
        
        mComponentArray[id] = component;
        
        return *component;
    }
private:
    EntityManager& mManager;
    bool mIsAlive{true};
    std::vector<std::unique_ptr<Component>> mComponents;
    ComponentBitset mComponentBitset;
    GroupBitset mGroupBitset;
    ComponentArray mComponentArray;
};

#endif