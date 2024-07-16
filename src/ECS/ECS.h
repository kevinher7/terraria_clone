#ifndef ECS_H
#define ECS_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

constexpr std::size_t maxComponents{32};

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component *, maxComponents>;

inline ComponentID getComponentTypeID()
{
    static ComponentID lastID{0};
    return lastID++;
}

template <typename T>
inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID typeID{getComponentTypeID()};
    return typeID;
}

class Component
{
public:
    Component() : entity{nullptr} {}
    Component(const Component &) : entity{nullptr} {};
    Component &operator=(const Component &) = delete;
    Component(Component &&) = delete;
    Component &operator=(Component &&) = delete;
    virtual ~Component() = default;

    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}

    Entity *entity;
};
class Entity
{
public:
    Entity() : m_active{true}, m_components{}, m_componentArray{}, m_componentBitSet{} {}
    ~Entity()
    {
        for (auto &componentPointer : m_componentArray)
        {
            if (componentPointer)
            {
                delete componentPointer;
                componentPointer = nullptr;
            }
        }
    }

    void update()
    {
        for (auto &component : m_components)
            component->update();
    }

    void draw()
    {
        for (auto &component : m_components)
            component->draw();
    }

    bool isActive() const { return m_active; }
    void destroy() { m_active = false; }

    template <typename T>
    bool hasComponent() const
    {
        return m_componentBitSet[getComponentTypeID<T>()];
    }

    template <typename T, typename... TArgs>
    void addComponent(TArgs &&...mArgs)
    {
        T *component(new T(std::forward<TArgs>(mArgs)...));
        component->entity = this;

        std::unique_ptr<Component> uPtrComponent{component}; // add std::make_unique?
        m_components.emplace_back(std::move(uPtrComponent));

        m_componentArray[getComponentTypeID<T>()] = component;
        m_componentBitSet[getComponentTypeID<T>()] = true;

        component->init();
    }

    template <typename T>
    T &getComponent() const
    {
        auto componentPointer(m_componentArray[getComponentTypeID<T>()]);
        return *static_cast<T *>(componentPointer);
    }

private:
    bool m_active;
    std::vector<std::unique_ptr<Component>> m_components;

    ComponentArray m_componentArray;
    ComponentBitSet m_componentBitSet;
};

class Manager
{
public:
    Manager() : m_gameEntities{} {}
    void update()
    {
        for (auto &entity : m_gameEntities)
            entity->update();
    }

    void draw()
    {
        for (auto &entity : m_gameEntities)
            entity->draw();
    }

    void refresh()
    {
        m_gameEntities.erase(
            std::remove_if(
                std::begin(m_gameEntities),
                std::end(m_gameEntities),
                [](const std::unique_ptr<Entity> &mEntity)
                {
                    return !mEntity->isActive();
                }),
            std::end(m_gameEntities));
    }

    Entity &addEntity()
    {
        Entity *entity = new Entity{};
        std::unique_ptr<Entity> uPtrEntity{entity};
        m_gameEntities.emplace_back(std::move(uPtrEntity));
        return *entity;
    }

private:
    std::vector<std::unique_ptr<Entity>> m_gameEntities;
};

#endif
