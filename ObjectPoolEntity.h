#pragma once
class Entity
{
public:
	Entity();
	~Entity();

	void SetActive(bool bActive);
	bool GetActive();


private:
	bool m_bActive;
};

