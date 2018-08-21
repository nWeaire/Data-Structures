#pragma once

class Entity;

class ObjectPool
{
public:
	ObjectPool(int nMaxSize);
	~ObjectPool();

	Entity* Allocate();
	void Deallocate(Entity* object);

private:
	Entity** m_pPool;
	int m_nMaxSize;

};