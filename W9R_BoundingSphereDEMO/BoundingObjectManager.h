#pragma once
#include "MyBoundingObjectClass.h"
#include "RE\ReEng.h"

class BoundingObjectManager
{
private:

	static int numBoundingObjects;
	static std::vector<MyBoundingObjectClass*> allBoundingObjects;
	static std::vector<bool> shouldRender;

	static BoundingObjectManager* boMngr;
	BoundingObjectManager();
	BoundingObjectManager(BoundingObjectManager const& other);
	BoundingObjectManager& operator=(BoundingObjectManager const& other);

	
	static std::vector<MyBoundingObjectClass*> GetAllBO();

public:
	static BoundingObjectManager* GetInstance(void);
	static void ReleaseInstance(void);
	static void MakeNewBoundingObject(std::vector<vector3> vertexList);
	static void ToggleBoxVisibility(MyBoundingObjectClass* toToggle);
	static int GetNumBO();
	static void SetColor(MyBoundingObjectClass* toColor, vector3 color);
	static void SetVisibility(MyBoundingObjectClass* toSet, bool set);
	static void RenderAll();
	static void Render(MyBoundingObjectClass* toRender);
	static void CheckAllCollisions();

};