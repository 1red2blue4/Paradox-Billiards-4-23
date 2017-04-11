#include "AppClass.h"


void AppClass::InitWindow(String a_sWindowName)
{
	super::InitWindow("A08_Camera"); // Window Name
}
void AppClass::InitVariables(void)
{
	myCamera = Camera();

	cameraView = myCamera.GetView();
	cameraProjection = myCamera.GetProjection(true);

	//myCamera.SetPosition(vector3(0.0f, 0.0f, -4.0f));

	//matrix4 cameraPos = myCamera.GetView();

	//Generate the Cone
	m_pCone = new PrimitiveClass();
	m_pCone->GenerateCone(1.0f, 1.0f, 10, RERED);

	//Generate the Cylinder
	m_pCylinder = new PrimitiveClass();
	m_pCylinder->GenerateCylinder(1.0f, 1.0f, 10, REGREEN);



	//Calculate the first projections
	//notes
	//m_m4Projection = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
	//m_m4Projection = glm::ortho(-10.0f, 10.0f, -5.0f, 5.0f, 0.01f, 1000.0f);
	//m_m4View = glm::lookAt(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 0.0f, 9.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//setup
	//m_m4Projection = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);

	//m_m4View = glm::lookAt(glm::vec3(0.0f, 0.0f, 15.0f), glm::vec3(0.0f, 0.0f, 14.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

void AppClass::Update(void)
{
	//myCamera.MoveForward(-0.01);

	cameraView = myCamera.GetView();
	myCamera.SetTarget(vector3(0.0f, 0.0f, 3.0f));
	cameraProjection = myCamera.GetProjection(true);

	//Update the system's time
	m_pSystem->UpdateTime();

	//Update the mesh manager's time without updating for collision detection
	m_pMeshMngr->Update();

	//Adds all loaded instance to the render list
	m_pMeshMngr->AddInstanceToRenderList("ALL");
}

void AppClass::Display(void)
{
	//clear the screen
	ClearScreen();
	
	//Render the grid
	m_pMeshMngr->AddGridToRenderList(1.0f, REAXIS::XY);

	//Render the cone
	m_pCone->Render(myCamera.GetProjection(true), cameraView, IDENTITY_M4);

	//Render the cylinder
	m_pCylinder->Render(myCamera.GetProjection(true), cameraView, glm::translate(IDENTITY_M4, REAXISZ * -3.0f));

	m_pMeshMngr->Render(); //renders the render list
	m_pMeshMngr->ClearRenderList(); //Reset the Render list after render
	m_pGLSystem->GLSwapBuffers(); //Swaps the OpenGL buffers

	m_pMeshMngr->PrintLine("UpX: " + std::to_string(myCamera.up.x));
	m_pMeshMngr->PrintLine("UpY: " + std::to_string(myCamera.up.y));
	m_pMeshMngr->PrintLine("UpZ: " + std::to_string(myCamera.up.z));
	m_pMeshMngr->PrintLine("");
	m_pMeshMngr->PrintLine("ForwardX: " + std::to_string(myCamera.forward.x));
	m_pMeshMngr->PrintLine("ForwardY: " + std::to_string(myCamera.forward.y));
	m_pMeshMngr->PrintLine("ForwardZ: " + std::to_string(myCamera.forward.z));
	m_pMeshMngr->PrintLine("");
	m_pMeshMngr->PrintLine("RightX: " + std::to_string(myCamera.right.x));
	m_pMeshMngr->PrintLine("RightY: " + std::to_string(myCamera.right.y));
	m_pMeshMngr->PrintLine("RightZ: " + std::to_string(myCamera.right.z));
}

void AppClass::Release(void)
{
	//Release the memory of the member fields
	SafeDelete(m_pCone);
	SafeDelete(m_pCylinder);

	//Release the memory of the inherited fields
	super::Release(); 
}