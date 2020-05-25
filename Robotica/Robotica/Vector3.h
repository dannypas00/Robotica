#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

class Vector3
{
public:
	Vector3(float _x, float _y, float _z);
	Vector3();

	virtual ~Vector3();

	Vector3 moveTowards(Vector3 _from, Vector3 _to, float _speed);
	Vector3 addForce(Vector3 force);
	float distancePoints(Vector3 _a, Vector3 _b);

	float x;
	float y;
	float z;

	Vector3& operator+=(const Vector3& rhs);
	Vector3 operator+(const Vector3& rhs) const;
	Vector3 operator*(const float rhs) const;
	Vector3 operator/(const float rhs) const;
	Vector3& operator-=(const Vector3& rhs);

private:
};

#endif