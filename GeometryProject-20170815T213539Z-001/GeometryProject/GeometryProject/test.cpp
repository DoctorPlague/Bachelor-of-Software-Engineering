//
//    Bachelor of Software Engineering
//    Media Design School
//    Auckland
//    New Zealand
//
//    (c) 2005 - 2015 Media Design School
//
//    File Name: test.cpp
//    Description: definitions of test functions
//    Author: Jasper Lyons
//    Mail: Jasper.Lyo7552@mediadesignschool.co.nz
//

#include "test.h"
#include "geometry.h"
#include <iostream>

using namespace std;

void Output3DVector(TVector3 vector)
{
	cout << "<" << vector.m_fX << ", " << vector.m_fY << ", " << vector.m_fZ << ">";
}

void Output2DVector(TVector2 vector)
{
	cout << "<" << vector.m_fX << ", " << vector.m_fY << ">";
}

void TestEquals(bool x, bool y) {
	if (x == y) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestAdd(TVector3 x, TVector3 y) {
	if (Equals(x, y) == true) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestSubtract(TVector3 x, TVector3 y) {
	if (Equals(x, y) == true) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestScaleVector(TVector3 x, TVector3 y) {
	if (Equals(x, y) == true) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestMagnitude(float x, float y) {
	if (x == y) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestDotProduct(float x, float y) {
	if (x == y) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestCrossProduct(TVector3 x, TVector3 y) {
	if (Equals(x, y) == true) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestNormalise(TVector3 x, TVector3 y) {
	if (Equals(x, y) == true) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestProjection(TVector3 x, TVector3 y) {
	if (Equals(x, y) == true) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestComputeAngleBetween(float x, float y) {
	if (x == y) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestComputeDistancePointToLine(float x, float y) {
	if (x == y) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestComputeDistancePointToPlane(float x, float y) {
	if (x == y) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestComputeDistancePointToSphere(float x, float y) {
	if (x == y) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestComputeDistanceCircleToCircle(float x, float y) {
	if (x == y) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestComputeDistanceCircleToTriangle(float x, float y) {
	if (x == y) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestComputeLineSphereIntersection(short x, short y) {
	if (x == y) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestIsLinePlaneIntersection(bool x, bool y) {
	if (x == y) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestIsIntersection(bool x, bool y) {
	if (x == y) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestComputeIntersectionBetweenLines(TVector3 x, TVector3 y) {
	if (Equals(x, y) == true) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestIsInFieldOfView(bool x, bool y) {
	if (x == y) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestFindTriangleNormal(TVector3 x, TVector3 y) {
	if (Equals(x, y) == true) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestIsSurfaceLit(bool x, bool y) {
	if (x == y) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}

void TestRotateTriangleAroundPoint(TVector2 x, TVector2 y) {	
	if (Equals2D(x, y) == true) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
}