#ifndef COMPONENT_H
#define COMPONENT_H


//struct Component;
class Entity;

struct Component {
    Entity* entity;
};

struct Drawable : Component {
    float r, g, b;
    
    Drawable() = default;
    Drawable(float red, float green, float blue) :
    r(red), g(green), b(blue)
    {};
};

namespace Components {
    
    
    using ID = std::size_t;
    
    namespace Internal {
            template <typename T>
        inline ID getUniqueTypeID() noexcept {
            static ID id{0u};
            return id++;
        }
    }
    
    template <typename T>
    inline ID getComponentTypeID() noexcept {
        static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component.");
        static ID id{Internal::getUniqueTypeID<T>()};
        return id;
    }
    
    template <typename T>
    inline ID getComponentTypeMask() noexcept {
        return 1 << getComponentTypeID<T>();
    }

    
    
}

#endif
