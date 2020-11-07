#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <bitset>
#include <array>

using namespace std;

class Component;
class Entity;

#pragma region CreateID

//ComponentID = size_t means ComponentID is coping the size_t format
using ComponentID = size_t;


//put funcion automatically
inline ComponentID getComponentTypeID()
{
	//Remenber last Id
	static ComponentID lastID = 0;
	//Give next id
	return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

#pragma endregion

#pragma region Component
//constexpr means const
//Max components an entety can have
constexpr  size_t maxComponents = 32;

//Geting the format bitset with the maxComponents size
//compare components
using ComponentBitSet = bitset<maxComponents>;

//Geting the format array with the maxComponents size
//array of components
using ComponentArray = array<Component*, maxComponents>;


//Coponent Format template
class Component 
{
public:
	//Reference to his owner
	Entity* entity;

	virtual void init() {};
	virtual void update() {};
	virtual void draw() {};
	virtual ~Component() {};
};
#pragma endregion

#pragma region Entity
//Queps a list of components
class Entity
{
private:

	//detect if etity is active
	bool active = true;

	//List of Components
	vector<unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;


public:

	void update()
	{
		//Go through out the Compunets in "components" and call update
		for (auto& c : components) c->update();
	}

	void draw() 
	{		
		//Go through out the Compunets in "components" and call draw
		for (auto& c : components) c->draw();
	}

	bool isActive()const { return active; }
	void destroy() { active = false; }

	//check components
	template<typename T>bool hasComponent() const
	{
		return componentBitSet[getComponentTypeID<T>()];
	}


	//Add a new component to the entity
	template <typename T, typename... TArgs> T& addComponent(TArgs&&... mArgs)
	{
		//create component
		T* c(new T(forward<TArgs>(mArgs)...));

		//give reference of its owner
		c->entity = this;

		//Give them all a unique pointer adresse
		unique_ptr<Component> uPtr{ c };

		//Add the pointers to the Component list
		components.emplace_back(move(uPtr));

		//Store components in componentArray
		componentArray[getComponentTypeID<T>()] = c;

		//Store component in componentBitSet 
		componentBitSet[getComponentTypeID<T>()] = true;

		//inicialyse component
		c->init();
		
		return *c;
	}


	//give reference of the compunent
	template<typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);

		return *static_cast<T*>(ptr);
	}
};
#pragma endregion

#pragma region Manager
class Manager
{
private:
	vector<unique_ptr<Entity>> entities;

public:

	//Go through out the Entities in "entities" and call update
	void update()
	{
		for (auto& e : entities) e->update();
	}

	//Go through out the Entities in "entities" and call draw
	void draw()
	{
		for (auto& e : entities) e->draw();
	}

	//Delete disebled entitys
	void refresh()
	{
		entities.erase(remove_if(begin(entities), end(entities), [](const unique_ptr<Entity>& mEntity)
		{
			return !mEntity->isActive();
		}),
			end(entities));
	}


	Entity& addEntity()
	{
		//Create an entity pointer
		Entity* e = new Entity();

		//Give it a unique adrees
		unique_ptr<Entity> uPtr{ e };

		//Store it in "entities"
		entities.emplace_back(move(uPtr));
		return*e;
	}
};
#pragma endregion