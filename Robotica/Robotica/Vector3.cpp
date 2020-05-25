#include "Vector3.h"

Vector3::Vector3(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}

Vector3::Vector3() {
	x = 0;
	y = 0;
}

Vector3::~Vector3() {

}

Vector3 Vector3::addForce(Vector3 force) {
	Vector3 acceleration = acceleration + force;
	Vector3 velocity = velocity + acceleration;
	return velocity;
}

Vector3 Vector3::moveTowards(Vector3 _start, Vector3 _target, float speed) {
	float _x = _start.x - _target.x;
	float _y = _start.y - _target.y;
	float _z = _start.z - _target.z;
	float c = this->distancePoints(_start, _target);
	return Vector3(speed * _x / c, speed * _y / c, speed * _z / c);
}

float Vector3::distancePoints(Vector3 _a, Vector3 _b) {
	//TODO: omzetten naar 3D
	float _x = _a.x - _b.x;
	float _y = _a.y - _b.y;
	return sqrt((_x * _x) + (_y * _y));
}

Vector3& Vector3::operator+=(const Vector3& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

Vector3 Vector3::operator+(const Vector3& rhs) const
{
	return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3 Vector3::operator*(const float rhs) const
{
	return Vector3(x * rhs, y * rhs, z * rhs);
}

Vector3 Vector3::operator/(const float rhs) const
{
	return Vector3(x / rhs, y / rhs, z / rhs);
}