#include "Camera.h"


Camera::Camera()
{
	m_m4Projection = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
	m_m4View = matrix4();

	up = vector3(0.0f, 1.0f, 0.0f);
	right = vector3(1.0f, 0.0f, 0.0f);
	forward = vector3(0.0f, 0.0f, -1.0f);

	center = vector3(0.0f, 0.0f, 1.0f);

	pitch = 0;
	yaw = 0;
	roll = 0;

	movedRight = 0;
	movedUp = 0;
	movedForward = 0;

	orientation = quaternion();
}

Camera::~Camera()
{
	
}

matrix4 Camera::GetView()
{
	up = vector3(-sin(roll), cos(roll)*cos(pitch), sin(pitch));
	right = vector3(cos(roll)*cos(yaw), sin(roll), -sin(yaw));
	forward = vector3(sin(yaw), -sin(pitch), cos(yaw)*cos(pitch));

	orientation = quaternion(vector3(pitch, yaw, roll));
	m_m4View = ToMatrix4(orientation);
	m_m4View = glm::translate(m_m4View, vector3(movedRight, movedUp, -movedForward));



	return m_m4View;
}

matrix4 Camera::GetProjection(bool bOrthographic)
{
	if (bOrthographic)
	{
		m_m4Projection = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
	
	}
	else
	{
		m_m4Projection = glm::ortho(-10.0f, 10.0f, -5.0f, 5.0f, 0.01f, 1000.0f);
	}

	return m_m4Projection;
}

void Camera::SetPosition(vector3 v3Position)
{
	/*
	matrix4 tempPosition = m_m4View;
	vector3 oldPosition = vector3(m_m4View[3][0], m_m4View[3][1], m_m4View[3][2]);
	m_m4View[3][0] = 0;
	m_m4View[3][1] = 0;
	m_m4View[3][2] = 0;
	*/

	m_m4View = glm::translate(IDENTITY_M4, -v3Position);
}

void Camera::SetTarget(vector3 v3Target)
{
	center = v3Target;
	//matrix4 target = glm::lookAt(vector3(m_m4View[3][0], m_m4View[3][1], m_m4View[3][2]), vector3(m_m4View[3][0] + v3Target.x, m_m4View[3][1] + v3Target.y, m_m4View[3][2] + v3Target.z), up);
	//m_m4Projection = target;
}

void Camera::SetUp(vector3 v3Up)
{
	up = v3Up;
}

void Camera::MoveForward(float fIncrement)
{
	movedForward -= fIncrement*forward.z;
	movedRight -= fIncrement*forward.x;
	movedUp -= fIncrement*forward.y;

	/*
	vector3 savedPosition = vector3(m_m4View[3][0], m_m4View[3][1], m_m4View[3][2]);
	vector3 savedRotationsR1 = vector3(m_m4View[0][0], m_m4View[0][1], m_m4View[0][2]);
	vector3 savedRotationsR2 = vector3(m_m4View[1][0], m_m4View[1][1], m_m4View[1][2]);
	vector3 savedRotationsR3 = vector3(m_m4View[2][0], m_m4View[2][1], m_m4View[2][2]);
	matrix4 rotationMatrix = matrix4(m_m4View[0][0], m_m4View[0][1], m_m4View[0][2], 0,
		m_m4View[1][0], m_m4View[1][1], m_m4View[1][2], 0,
		m_m4View[2][0], m_m4View[2][1], m_m4View[2][2], 0,
		0, 0, 0, 1);
	m_m4View = glm::translate(IDENTITY_M4, vector3(0.0f, 0.0f, fIncrement));
	m_m4View = glm::translate(m_m4View, savedPosition);
	m_m4View = m_m4View * rotationMatrix;
	*/

	//m_m4View = glm::translate(m_m4View, fIncrement*forward);
}

void Camera::MoveSideways(float fIncrement)
{
	movedRight -= fIncrement*right.x;
	movedForward -= fIncrement*right.z;
	movedUp -= fIncrement*right.y;

	/*
	vector3 savedPosition = vector3(m_m4View[3][0], m_m4View[3][1], m_m4View[3][2]);
	vector3 savedRotationsR1 = vector3(m_m4View[0][0], m_m4View[0][1], m_m4View[0][2]);
	vector3 savedRotationsR2 = vector3(m_m4View[1][0], m_m4View[1][1], m_m4View[1][2]);
	vector3 savedRotationsR3 = vector3(m_m4View[2][0], m_m4View[2][1], m_m4View[2][2]);
	matrix4 rotationMatrix = matrix4(m_m4View[0][0], m_m4View[0][1], m_m4View[0][2], 0,
		m_m4View[1][0], m_m4View[1][1], m_m4View[1][2], 0,
		m_m4View[2][0], m_m4View[2][1], m_m4View[2][2], 0,
		0, 0, 0, 1);
	m_m4View = glm::translate(IDENTITY_M4, vector3(-fIncrement, 0.0f, 0.0f));
	m_m4View = glm::translate(m_m4View, savedPosition);
	m_m4View = m_m4View * rotationMatrix;
	*/

	//m_m4View = glm::translate(m_m4View, fIncrement*right);
}

void Camera::MoveVertical(float fIncrement)
{
	movedUp -= fIncrement*up.y;
	movedRight -= fIncrement*up.x;
	movedForward -= fIncrement*up.z;

	/*
	vector3 savedPosition = vector3(m_m4View[3][0], m_m4View[3][1], m_m4View[3][2]);
	vector3 savedRotationsR1 = vector3(m_m4View[0][0], m_m4View[0][1], m_m4View[0][2]);
	vector3 savedRotationsR2 = vector3(m_m4View[1][0], m_m4View[1][1], m_m4View[1][2]);
	vector3 savedRotationsR3 = vector3(m_m4View[2][0], m_m4View[2][1], m_m4View[2][2]);
	matrix4 rotationMatrix = matrix4(m_m4View[0][0], m_m4View[0][1], m_m4View[0][2], 0,
		m_m4View[1][0], m_m4View[1][1], m_m4View[1][2], 0,
		m_m4View[2][0], m_m4View[2][1], m_m4View[2][2], 0,
		0, 0, 0, 1);
	m_m4View = rotationMatrix;
	m_m4View = glm::translate(m_m4View, vector3(0.0f, -fIncrement, 0.0f));
	m_m4View = glm::translate(m_m4View, savedPosition);
	*/
	
	//m_m4View = glm::translate(m_m4View, fIncrement*up);
}

void Camera::ChangePitch(float fIncrement)
{
	pitch += fIncrement;


	/*
	quaternion rotation = glm::angleAxis(fIncrement, forward);
	vector3 savedPosition = vector3(m_m4View[3][0], m_m4View[3][1], m_m4View[3][2]);
	
	
	
	m_m4View = ToMatrix4(rotation);
	m_m4View = glm::translate(m_m4View, savedPosition);
	*/
	//forward = rotation * forward;
	//right = rotation * right;
	//up = rotation * up;
}

void Camera::ChangeRoll(float fIncrement)
{
	roll += fIncrement;
	/*
	quaternion rotation = glm::angleAxis(fIncrement, right);
	vector3 savedPosition = vector3(m_m4View[3][0], m_m4View[3][1], m_m4View[3][2]);

	
	m_m4View = ToMatrix4(rotation);
	m_m4View = glm::translate(m_m4View, savedPosition);
	*/
	//forward = rotation * forward;
	//right = rotation * right;
	//up = rotation * up;
}

void Camera::ChangeYaw(float fIncrement)
{
	yaw += fIncrement;
	/*
	quaternion rotation = glm::angleAxis(fIncrement, up);
	vector3 savedPosition = vector3(m_m4View[3][0], m_m4View[3][1], m_m4View[3][2]);

	
	m_m4View = ToMatrix4(rotation);
	m_m4View = glm::translate(m_m4View, savedPosition);
	*/
	//forward = rotation * forward;
	//right = rotation * right;
	//up = rotation * up;
}