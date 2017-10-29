#include "Transform.h"






glm::quat Transform::_rotation()
{
	return glm::quat();
}

void Transform::UpdateModelMatrix()
{
	_modelMatrix = glm::mat4_cast (_rotation);

	_modelMatrix[0] = _modelMatrix[0] * _scale.x;
	_modelMatrix[1] = _modelMatrix[1] * _scale.y;
	_modelMatrix[2] = _modelMatrix[2] * _scale.z;
	
	_modelMatrix[3][0] = _modelMatrix[3][0] * _scale.x;
	_modelMatrix[3][1] = _modelMatrix[3][1] * _scale.x;
	_modelMatrix[3][2] = _modelMatrix[3][2] * _scale.x;

}

Transform::Transform()
{
	_modelMatrix = glm::mat4(1.0f);
	_rotation() = glm::vec3(1.0f);
	_position = glm::radians(glm::vec3(0.0f, 0.0f, 0.0f));
	_scale = glm::vec3(1.0, 1.0, 1.0);

}

glm::mat4 GetModelMatrix()
{
	return glm::mat4(1.0f);

}


glm::vec3 GetPosition()
{
	return glm::vec3(0.0, 0.0,0.0);

}

glm::quat GetRotation()
{
	return glm::quat(glm::radians(glm::vec3(0.0f, 0.0f, 0.0f)));

}

glm::vec3 GetScale()
{
	return glm::vec3(1.0, 1.0, 1.0);

}


glm::quat Transform::GetRotation()
{
	return glm::quat();
}


void Transform::SetPosition(float x, float y, float z)
{
	_position=glm::vec3(x,y,z);
	UpdateModelMatrix();

}

void Transform::SetRotation(float x, float y, float z)
{
	_rotation() = glm::radians(glm::vec3(x, y, z));
	UpdateModelMatrix();

}

void Transform::SetScale(float x, float y, float z)
{
	_scale = glm::vec3(x, y, z);
	UpdateModelMatrix();

}


