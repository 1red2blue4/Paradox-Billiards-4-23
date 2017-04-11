#include "AppClass.h"
void AppClass::ProcessKeyboard(void)
{
	//Flag for the modifier
	bool bModifier = false;

	float rotationSpeed = 0.01f;
	float moveSpeed = 0.1f;

	//ON PRESS/RELEASE
#pragma region ON PRESS/RELEASE DEFINITION
	static bool	bLastF1 = false, bLastF2 = false, bLastF3 = false, bLastF4 = false, bLastF5 = false,
				bLastF6 = false, bLastF7 = false, bLastF8 = false, bLastF9 = false, bLastF10 = false,
				bLastEscape = false;
#define ON_KEY_PRESS_RELEASE(key, pressed_action, released_action){  \
			bool pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::key);			\
			if(pressed){											\
				if(!bLast##key) pressed_action;}/*Just pressed? */\
			else if(bLast##key) released_action;/*Just released?*/\
			bLast##key = pressed; } //remember the state
#pragma endregion
	/*
	//F1 Controllers
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
	{
		m_m4Projection = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
		m_m4View = glm::lookAt(glm::vec3(0.0f, 0.0f, 15.0f), glm::vec3(0.0f, 0.0f, 14.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	//F2 Controllers
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
	{
		m_m4Projection = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
		m_m4View = glm::lookAt(glm::vec3(15.0f, 0.0f, 0.0f), glm::vec3(14.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	}

	//F3 Controllers
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
	{
		m_m4Projection = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.01f, 21.0f);
		m_m4View = glm::lookAt(glm::vec3(0.0f, 0.0f, 20.0f), glm::vec3(0.0f, 0.0f, 19.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	//F4 Controllers
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
	{
		m_m4Projection = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
		m_m4View = glm::lookAt(glm::vec3(15.0f, 0.0f, 0.0f), glm::vec3(14.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	//F5 Controllers
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
	{
		m_m4Projection = glm::ortho(-10.0f, 10.0f, -30.0f, 30.0f, 0.01f, 31.0f);
		m_m4View = glm::lookAt(glm::vec3(30.0f, 0.0f, 0.0f), glm::vec3(29.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}
	*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		myCamera.MoveForward(moveSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myCamera.MoveForward(-moveSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myCamera.MoveSideways(moveSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		myCamera.MoveSideways(-moveSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		myCamera.MoveVertical(moveSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		myCamera.MoveVertical(-moveSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		{
			myCamera.ChangePitch(-rotationSpeed);
		}
		else
		{
			myCamera.ChangePitch(rotationSpeed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		{
			myCamera.ChangeRoll(-rotationSpeed);
		}
		else
		{
			myCamera.ChangeRoll(rotationSpeed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		{
			myCamera.ChangeYaw(-rotationSpeed);
		}
		else
		{
			myCamera.ChangeYaw(rotationSpeed);
		}
	}

	//Exit the program
#pragma region Other Actions
	ON_KEY_PRESS_RELEASE(Escape, NULL, PostMessage(m_pWindow->GetHandler(), WM_QUIT, NULL, NULL))
#pragma endregion
}