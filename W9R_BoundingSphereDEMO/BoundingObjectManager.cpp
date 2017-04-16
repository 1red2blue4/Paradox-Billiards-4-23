#include "BoundingObjectManager.h"

BoundingObjectManager* BoundingObjectManager::boMngr = nullptr;

BoundingObjectManager::BoundingObjectManager()
{
	numBoundingObjects = 0;
	allBoundingObjects = {};
	shouldRender = {};
}

BoundingObjectManager::BoundingObjectManager(BoundingObjectManager const& other)
{
	numBoundingObjects = other.numBoundingObjects;
	allBoundingObjects = other.allBoundingObjects;
	shouldRender = other.shouldRender;
}

BoundingObjectManager& BoundingObjectManager::operator=(BoundingObjectManager const& other)
{
	if (this != &other)
	{
		numBoundingObjects = other.numBoundingObjects;
		allBoundingObjects = other.allBoundingObjects;
		shouldRender = other.shouldRender;
	}

	return *this;
}

BoundingObjectManager* BoundingObjectManager::GetInstance()
{
	if (boMngr == nullptr)
	{
		boMngr = new BoundingObjectManager();
	}
	return boMngr;
}

void BoundingObjectManager::ReleaseInstance()
{
	if (boMngr != nullptr)
	{
		delete boMngr;
		boMngr = nullptr;
	}
}

void BoundingObjectManager::MakeNewBoundingObject(std::vector<vector3> vertexList)
{
	MyBoundingObjectClass* myBO = new MyBoundingObjectClass(vertexList);
	shouldRender[numBoundingObjects] = true;
	numBoundingObjects++;
	allBoundingObjects.push_back(myBO);
	delete myBO;
}

void BoundingObjectManager::ToggleBoxVisibility(MyBoundingObjectClass* toToggle)
{
	toToggle->ToggleBoxVisibility();
}

void BoundingObjectManager::SetVisibility(MyBoundingObjectClass* toSet, bool set)
{
	toSet->SetVisibility(set);
}

void BoundingObjectManager::SetColor(MyBoundingObjectClass* toColor, vector3 color)
{
	toColor->SetBoxColor(color);
}

void BoundingObjectManager::RenderAll()
{
	for (int i = 0; i < numBoundingObjects; i++)
	{
		allBoundingObjects[i]->Render();
	}
}

void BoundingObjectManager::Render(MyBoundingObjectClass* toRender)
{
	toRender->Render();
}

void BoundingObjectManager::CheckAllCollisions()
{
	for (int i = 0; i < numBoundingObjects; i++)
	{
		allBoundingObjects[i]->SetBoxColor(REGREEN);
		allBoundingObjects[i]->SetBoxColor(REGREEN);
	}

	for (int i = 0; i < numBoundingObjects; i++)
	{
		for (int j = 0; j < numBoundingObjects; j++)
		{
			if (i != j && allBoundingObjects[i]->IsBoxColliding(allBoundingObjects[j]->GetBoundingBox()))
			{
				allBoundingObjects[i]->SetBoxColor(RERED);
				allBoundingObjects[j]->SetBoxColor(RERED);
			}
			if (i != j && allBoundingObjects[i]->IsSphereColliding(allBoundingObjects[j]->GetBoundingSphere()))
			{
				allBoundingObjects[i]->SetBoxColor(RERED);
				allBoundingObjects[j]->SetBoxColor(RERED);
			}
		}
	}
}

int BoundingObjectManager::GetNumBO() { return numBoundingObjects; }
std::vector<MyBoundingObjectClass*> BoundingObjectManager::GetAllBO() { return allBoundingObjects; }