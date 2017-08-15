//
//    Bachelor of Software Engineering
//    Media Design School
//    Auckland
//    New Zealand
//
//    (c) 2005 - 2015 Media Design School
//
//    File Name: test.h
//    Description: prototypes of test functions
//    Author: Jasper Lyons
//    Mail: Jasper.Lyo7552@mediadesignschool.co.nz
//

#include "geometry.h"

#pragma once
void Output3DVector(TVector3);
void Output2DVector(TVector2);

// Math Functions
void TestEquals(bool, bool);
void TestAdd(TVector3, TVector3);
void TestSubtract(TVector3, TVector3);
void TestScaleVector(TVector3, TVector3);
void TestMagnitude(float, float);
void TestDotProduct(float, float);
void TestCrossProduct(TVector3, TVector3);
void TestNormalise(TVector3, TVector3);
void TestProjection(TVector3, TVector3);
void TestComputeAngleBetween(float, float);
void TestComputeDistancePointToLine(float, float);
void TestComputeDistancePointToPlane(float, float);
void TestComputeDistancePointToSphere(float, float);
void TestComputeDistanceCircleToCircle(float, float);
void TestComputeDistanceCircleToTriangle(float, float);
void TestComputeLineSphereIntersection(short, short);
void TestIsLinePlaneIntersection(bool, bool);
void TestIsIntersection(bool, bool);
void TestComputeIntersectionBetweenLines(TVector3, TVector3);
void TestIsInFieldOfView(bool, bool);
void TestFindTriangleNormal(TVector3, TVector3);
void TestIsSurfaceLit(bool, bool);
void TestRotateTriangleAroundPoint(TVector2, TVector2);