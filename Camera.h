//-----------------------------------------------------------------------------
// Camera.h by Steve Jones 
// Copyright (c) 2015-2016 Game Institute. All Rights Reserved.
//
// Basic camera class including derived orbit-style and first person
// shooter (FPS) style camera support
// Modified Camera.h by Fatih Melih ÖZGÜN 
//-----------------------------------------------------------------------------
/*Copyright (C) 2018  Mehmet ÖZGÜN

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.*/
#ifndef CAMERA_H
#define CAMERA_H
#define GLM_ENABLE_EXPERIMENTAL
#define  GLM_FORCE_CTOR_INIT
#include "glm/glm.hpp"
#include "glm/gtc/constants.hpp"



class Camera
{
public:
	glm::mat4 getViewMatrix() const;

	virtual void setPosition(const glm::vec3& position) {}
	virtual void rotate(float yaw, float pitch) {} 
	virtual void move(const glm::vec3& offsetPos) {}

	const glm::vec3& getLook() const;
	const glm::vec3& getRight() const;
	const glm::vec3& getUp() const;
	const glm::vec3& getPosition() const;

	float getFOV() const { return mFOV; }
	void setFOV(float fov) { mFOV = fov; }		
	float mYaw;
	float mPitch;


	Camera();

	virtual void updateCameraVectors() {}

	glm::vec3 mPosition;
	glm::vec3 mTargetPos;
	glm::vec3 mLook;
	glm::vec3 mUp;
	glm::vec3 mRight;
	const glm::vec3 WORLD_UP;

	
	float mFOV; // degrees
};


class FPSCamera : public Camera
{
public:

	FPSCamera(); // (yaw) initial angle faces -Z

	virtual void setPosition(const glm::vec3& position);
	virtual void rotate(float yaw, float pitch);	// in degrees
	virtual void move(const glm::vec3& offsetPos);

private:

	void updateCameraVectors();
};


//--------------------------------------------------------------
// Orbit Camera Class
//--------------------------------------------------------------
class OrbitCamera : public Camera
{
public:

	OrbitCamera();

	virtual void rotate(float yaw, float pitch);    // in degrees

													// Camera Controls
	void setLookAt(const glm::vec3& target);
	void setRadius(float radius);

private:

	void updateCameraVectors();

	// Camera parameters
	float mRadius;
};
#endif //CAMERA_H
