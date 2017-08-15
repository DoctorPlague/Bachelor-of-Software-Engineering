//
//    Bachelor of Software Engineering
//    Media Design School
//    Auckland
//    New Zealand
//
//    (c) 2005 - 2015 Media Design School
//
//    File Name: main.cpp
//    Description: main file
//    Author: Jasper Lyons
//    Mail: Jasper.Lyo7552@mediadesignschool.co.nz
//

#include <iostream>
#include <conio.h>
#include <iomanip>
#include "geometry.h"
#include "test.h"

using namespace std;

int main()
{
	// Equals Function Test
	cout << " - Equals Function Test - " << endl;
	TVector3 A = { 1.0f, 2.0f, 3.0f };
	TVector3 B = { 1.0f, 2.0f, 3.0f };
	bool bResult;

	bResult = Equals(A, B);
	cout << "Are ";
	Output3DVector(A);
	cout << " and ";
	Output3DVector(B);
	cout << " equal? - " << boolalpha << bResult << endl;
	TestEquals(true, bResult);

	// Add Function Test
	cout << endl << " - Add Function Test - " << endl;	
	TVector3 result;

	result = Add(A, B, result);
	cout << "Addition of ";
	Output3DVector(A);
	cout << " and ";
	Output3DVector(B);
	cout << " is "; 
	Output3DVector(result);
	cout << endl;
	TestAdd({2, 4, 6}, result);


	// Subtract Function Test
	cout << endl << " - Subtract Function Test - " << endl;

	result = Subtract(A, B, result);
	cout << "Subtraction of ";
	Output3DVector(A);
	cout << " and ";
	Output3DVector(B);
	cout << " is ";
	Output3DVector(result);
	cout << endl;
	TestSubtract({ 0, 0, 0 }, result);

	// ScaleVector Function Test
	cout << endl << " - ScaleVector Function Test - " << endl;
	float fTwo = 3.0f;

	result = ScaleVector(A, fTwo, result);
	cout << "Scaling of ";
	Output3DVector(A);
	cout << " by 3 is ";
	Output3DVector(result);
	cout << endl;
	TestScaleVector({ 3, 6, 9 }, result);

	// Magnitude Function Test
	cout << endl << " - Magnitude Function Test - " << endl;
	float fMagnitude;

	fMagnitude = Magnitude(A);
	cout << "The magnitude of ";
	Output3DVector(A);	
	cout << " is " << fMagnitude;
	cout << endl;
	TestMagnitude((float) sqrt(14), fMagnitude);

	// DotProduct Function Test
	cout << endl << " - DotProduct Function Test - " << endl;
	float fDotProduct;

	fDotProduct = DotProduct(A, B);
	cout << "The dot product of ";
	Output3DVector(A);
	cout << " and ";
	Output3DVector(B);
	cout << " is " << fDotProduct;
	cout << endl;
	TestDotProduct(14, fDotProduct);

	// CrossProduct Function Test
	cout << endl << " - CrossProduct Function Test - " << endl;
	TVector3 C = { 2.0f, 3.0f, 4.0f };

	result = CrossProduct(A, C, result);
	cout << "CrossProduct of ";
	Output3DVector(A);
	cout << " and ";
	Output3DVector(C);
	cout << " is ";
	Output3DVector(result);
	cout << endl;
	TestCrossProduct({ -1, 2, -1 }, result);

	// Normalise Function Test
	cout << endl << " - Normalise Function Test - " << endl;
	
	result = Normalise(C, result);
	cout << "Normalising ";
	Output3DVector(C);
	cout << " equals ";	
	Output3DVector(result);
	cout << endl;
	
	TVector3 TestVector = { static_cast<float>(0.3713906763541037), static_cast<float>(0.5570860145311556), static_cast<float>(0.7427813527082075) };
	TestVector.m_fX = static_cast<float>(floor(TestVector.m_fX * 100000) / 100000);
	TestVector.m_fY = static_cast<float>(floor(TestVector.m_fY * 100000) / 100000);
	TestVector.m_fZ = static_cast<float>(floor(TestVector.m_fZ * 100000) / 100000);
	result.m_fX = static_cast<float>(floor(result.m_fX * 100000) / 100000);
	result.m_fY = static_cast<float>(floor(result.m_fY * 100000) / 100000);
	result.m_fZ = static_cast<float>(floor(result.m_fZ * 100000) / 100000);
	TestNormalise(TestVector, result);		

	// Projection Function Test
	cout << endl << " - Projection Function Test - " << endl;

	result = Projection(A, C, result);
	cout << "Projection of ";
	Output3DVector(A);
	cout << " onto ";
	Output3DVector(C);
	cout << " is ";
	Output3DVector(result);
	cout << endl;
	TestProjection({ static_cast<float>(1.3793103448275862), static_cast<float>(2.0689655172413793), static_cast<float>(2.7586206896551724) }, result);

	// ComputeAngleBetween Function Test
	cout << endl << " - ComputeAngleBetween Function Test - " << endl;
	float fAngle;

	fAngle = ComputeAngleBetween(A, A);
	fAngle = static_cast<float>(floor(fAngle * 100) / 100);
	cout << "The angle between ";
	Output3DVector(A);
	cout << " and ";
	Output3DVector(A);
	cout << " is " << fAngle;	
	cout << endl;
	TestComputeAngleBetween(0, fAngle);

	// ComputeDistancePointToLine Function Test
	cout << endl << " - ComputeDistancePointToLine Function Test - " << endl;
	float fDistance;
	T3DLine LineA = {(1,2,3),(0,0,0)};
	T3DLine LineB = { (1,2,3),(0,0,0) };

	fDistance = ComputeDistancePointToLine(LineA, A);
	cout << "The distance between ";
	Output3DVector(LineA.m_v3q);
	cout << " and ";
	Output3DVector(A);
	cout << " is " << fDistance;	
	cout << endl;
	TestComputeDistancePointToLine(0, fDistance);

	// ComputeDistancePointToPlane Function Test
	cout << endl << " - ComputeDistancePointToPlane Function Test - " << endl;
	TPlane PlaneA;
	PlaneA.m_v3normal = { (0.0f,0.0f,1.0f) };
	PlaneA.m_v3point.m_fX = 1.0f;
	PlaneA.m_v3point.m_fY = 2.0f;
	PlaneA.m_v3point.m_fZ = 3.0f;

	fDistance = ComputeDistancePointToPlane(PlaneA, A);
	cout << "Distance between ";
	Output3DVector(PlaneA.m_v3point);
	cout << " and  ";
	Output3DVector(A);
	cout << " is " << fDistance;
	cout << endl;
	TestComputeDistancePointToPlane(0, fDistance);

	// ComputeDistancePointToSphere Function Test
	cout << endl << " - ComputeDistancePointToSphere Function Test - " << endl;
	TSphere SphereA;
	SphereA.m_v3center.m_fX = 1.0f;
	SphereA.m_v3center.m_fY = 2.0f;
	SphereA.m_v3center.m_fZ = 3.0f;
	SphereA.m_fRadius = 5.0f;

	fDistance = ComputeDistancePointToSphere(SphereA, A);
	cout << "Distance between ";
	Output3DVector(SphereA.m_v3center);
	cout << " and ";
	Output3DVector(A);
	cout << " is " << fDistance;
	cout << endl;
	TestComputeDistancePointToSphere(0, fDistance);

	// ComputeDistanceCircleToCircle Function Test
	cout << endl << " - ComputeDistanceCircleToCircle Function Test - " << endl;
	TCircle CircleA;
	CircleA.m_v2center.m_fX = 1.0f;
	CircleA.m_v2center.m_fY = 2.0f;
	CircleA.m_fRadius = 5.0f;

	TCircle CircleB;
	CircleB.m_v2center.m_fX = 1.0f;
	CircleB.m_v2center.m_fY = 2.0f;
	CircleB.m_fRadius = 5.0f;

	fDistance = ComputeDistanceCircleToCircle(CircleA, CircleB);
	cout << "Distance between ";
	Output2DVector(CircleA.m_v2center);
	cout << " and ";
	Output2DVector(CircleB.m_v2center);
	cout << " is " << fDistance;
	cout << endl;
	TestComputeDistanceCircleToCircle(0, fDistance);


	// ComputeDistanceCircleToTriangle Function Test
	cout << endl << " - ComputeDistanceCircleToTriangle Function Test - " << endl;
	TTriangle2 TriangleA = {(0,1), (1,3), (2,1)};
	TVector2 Centroid = { ((TriangleA.m_v2p1.m_fX + TriangleA.m_v2p2.m_fX + TriangleA.m_v2p1.m_fX) / 3), ((TriangleA.m_v2p1.m_fY + TriangleA.m_v2p2.m_fY + TriangleA.m_v2p1.m_fY) / 3) };	

	fDistance = ComputeDistanceCircleToTriangle(CircleA, TriangleA);
	cout << "Distance between ";
	Output2DVector(CircleA.m_v2center);
	cout << " and the center of the triangle is " << fDistance;
	cout << endl;
	TestComputeDistanceCircleToTriangle(0, fDistance);

	// ComputeLineSphereIntersection Function Test
	cout << endl << " - ComputeLineSphereIntersection Function Test - " << endl;

	TSphere SphereB;
	SphereB.m_v3center.m_fX = 0.0f;
	SphereB.m_v3center.m_fY = 0.0f;
	SphereB.m_v3center.m_fZ = 1.0f;
	SphereB.m_fRadius = 5.0f;

	TVector3 intersection1;
	TVector3 intersection2;
	T3DLine LineC;
	LineC.m_v3q.m_fX = 0.0f;
	LineC.m_v3q.m_fY = 0.0f;
	LineC.m_v3q.m_fZ = 1.0f;
	LineC.m_v3v.m_fX = 1.0f;
	LineC.m_v3v.m_fY = 0.0f;
	LineC.m_v3v.m_fZ = 1.0f;

	short sNumIntersection = ComputeLineSphereIntersection(LineC, SphereB, intersection1, intersection2);	
	
	TestComputeLineSphereIntersection(2, sNumIntersection);

	// IsLinePlaneIntersection Function Test
	cout << endl << " - IsLinePlaneIntersection Function Test - " << endl;

	bResult = IsLinePlaneIntersection(LineA, PlaneA, intersection1);
	
	
	TestIsLinePlaneIntersection(1, bResult);

	// IsIntersection Function Test
	cout << endl << " - IsIntersection Function Test - " << endl;

	bResult = IsIntersection(LineA, LineB);
	
	TestIsIntersection(1, bResult);

	// ComputeIntersectionBetweenLines Function Test
	cout << endl << " - ComputeIntersectionBetweenLines Function Test - " << endl;	

	result = ComputeIntersectionBetweenLines(LineA, LineB, intersection1);
	
	TestComputeIntersectionBetweenLines({ (1.0f,2.0f,3.0f) }, result);

	// IsInFieldOfView Function Test
	cout << endl << " - IsInFieldOfView Function Test - " << endl;
	TVector2 CameraPosition = { 0.0f,0.0f };
	TVector2 CameraDirection = { 1.0f,0.0f };
	TVector2 ObjectPosition = { 2.0f,0.0f };
	float fFoVInRadians = 3.14159;

	bResult = IsInFieldOfView(CameraPosition, CameraDirection, fFoVInRadians, ObjectPosition);
	
	TestIsInFieldOfView(1, bResult);

	// FindTriangleNormal Function Test
	cout << endl << " - FindTriangleNormal Function Test - " << endl;
	TTriangle3 TriangleB = { (0.0f,0.0f,1.0f), (0.0f,0.0f,3.0f), (3.0f,0.0f,2.0f) };

	result = FindTriangleNormal(TriangleB, result);
	
	TestFindTriangleNormal({0.0f,0.0f,0.0f }, result);

	// IsSurfaceLit Function Test
	cout << endl << " - IsSurfaceLit Function Test - " << endl;
	TVector3 PointOnSurface = {0,0,0};
	TVector3 LightSourcePosition = {3,9,1};
	TTriangle3 Surface;
	Surface.m_v3p1.m_fX = 5.0f;
	Surface.m_v3p1.m_fY = 5.0f;
	Surface.m_v3p1.m_fZ = 0.0f;
	Surface.m_v3p2.m_fX = 3.0f;
	Surface.m_v3p2.m_fY = 5.0f;
	Surface.m_v3p2.m_fZ = 0.0f;
	Surface.m_v3p3.m_fX = 5.0f;
	Surface.m_v3p3.m_fY = 3.0f;
	Surface.m_v3p3.m_fZ = 0.0f;		

	bResult = IsSurfaceLit(PointOnSurface, LightSourcePosition, Surface);
	
	TestIsSurfaceLit(1, bResult);

	// RotateTriangleAroundPoint Function Test
	cout << endl << " - RotateTriangleAroundPoint Function Test - " << endl;
	TTriangle2 Triangle;
	Triangle.m_v2p1 = { -4, 4 };
	Triangle.m_v2p2 = { -12, 2 };
	Triangle.m_v2p3 = { -8, 9 };
	TTriangle2 DesiredTriangle;
	DesiredTriangle.m_v2p1 = {-4,0};
	DesiredTriangle.m_v2p2 = { 4,2 };
	DesiredTriangle.m_v2p3 = { 0,-5 };
	float fAngleInRadians = 3.14159;
	TVector2 Point = { -4, 2 };
	TTriangle2 RotatedTriangle = RotateTriangleAroundPoint(Triangle, fAngleInRadians, Point, RotatedTriangle);
	RotatedTriangle.m_v2p1.m_fX = round(RotatedTriangle.m_v2p1.m_fX);
	RotatedTriangle.m_v2p1.m_fY = round(RotatedTriangle.m_v2p1.m_fY);
	RotatedTriangle.m_v2p2.m_fX = round(RotatedTriangle.m_v2p2.m_fX);
	RotatedTriangle.m_v2p2.m_fY = round(RotatedTriangle.m_v2p2.m_fY);
	RotatedTriangle.m_v2p3.m_fX = round(RotatedTriangle.m_v2p3.m_fX);
	RotatedTriangle.m_v2p3.m_fY = round(RotatedTriangle.m_v2p3.m_fY);
	TestRotateTriangleAroundPoint(RotatedTriangle.m_v2p1, DesiredTriangle.m_v2p1);
	TestRotateTriangleAroundPoint(RotatedTriangle.m_v2p2, DesiredTriangle.m_v2p2);
	TestRotateTriangleAroundPoint(RotatedTriangle.m_v2p3, DesiredTriangle.m_v2p3);

	_getch();
	return(0);
}


