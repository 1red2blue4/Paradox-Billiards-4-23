#ifndef __CAMERA_H_
#define __CAMERA_H_

#include "RE\ReEngAppClass.h"
#include <SFML\Graphics.hpp>

using namespace ReEng;

class Camera
{
private:
	matrix4 m_m4Projection;
	//matrix4 m_m4Orthographic;
	matrix4 m_m4View;

	vector3 center;

	float movedForward;
	float movedRight;
	float movedUp;

	quaternion orientation;

public:

	vector3 up;
	vector3 right;
	vector3 forward;

	float pitch;
	float yaw;
	float roll;


	Camera();
	~Camera();

	///<summary>
	///Should get the View Matrix
	///</summary>
	matrix4 GetView(); 
	///<summary>
	///Should get the Projection Matrix, choose between Orthographic and Perspective with the bool
	///</summary>
	matrix4 GetProjection(bool bOrthographic); 
	///<summary>
	///Sets the Position of the Camera
	///</summary>
	void SetPosition(vector3 v3Position);
	///<summary>
	///Sets the Target of the Camera
	///</summary>
	void SetTarget(vector3 v3Target);
	///<summary>
	///Sets the Up Vector of the Camera
	///</summary>
	void SetUp(vector3 v3Up);
	///<summary>
	///Move the camera forward
	///</summary>
	void MoveForward(float fIncrement);
	///<summary>
	///Move the camera sideways based upon the "right" vector depending on the "view" vector
	///</summary>
	void MoveSideways(float fIncrement);
	///<summary>
	///Move the camera up or down
	///</summary>
	void MoveVertical(float fIncrement);
	///<summary>
	///Orient your Camera by rotating about its x
	///</summary>
	void ChangePitch(float fIncrement);
	///<summary>
	///Orient your Camera by rotating about its z
	///</summary>
	void ChangeRoll(float fIncrement);
	///<summary>
	///Orient your Camera by rotating about its y
	///</summary>
	void ChangeYaw(float fIncrement);
};

#endif //__CAMERA_H_