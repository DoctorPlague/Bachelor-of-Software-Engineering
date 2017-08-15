//
//    Bachelor of Software Engineering
//    Media Design School
//    Auckland
//    New Zealand
//
//    (c) 2005 - 2015 Media Design School
//
//    File Name: geometry.cpp
//    Description: definitions of functions
//    Author: Jasper Lyons
//    Mail: Jasper.Lyo7552@mediadesignschool.co.nz
//

#include "geometry.h"
#include <math.h>
#include <cmath>

using namespace std;

bool Equals(const TVector3 & _krA, const TVector3 & _krB)
{	
	if (_krA.m_fX == _krB.m_fX
	 && _krA.m_fY == _krB.m_fY
	 && _krA.m_fZ == _krB.m_fZ)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Equals2D(const TVector2 & _krA, const TVector2 & _krB)
{
	if (_krA.m_fX == _krB.m_fX
		&& _krA.m_fY == _krB.m_fY)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float RadianToDegree(float radians)
{
	return (radians / (4 * atan(1))) * 180;
}

TVector3 & Add(const TVector3 & _krA, const TVector3 & _krB, TVector3 & _rResultant)
{
	_rResultant = { _krA.m_fX + _krB.m_fX, _krA.m_fY + _krB.m_fY, _krA.m_fZ + _krB.m_fZ };
	return _rResultant;	
}

TVector2 & Add2D(const TVector2 & _krA, const TVector2 & _krB, TVector2 & _rResultant)
{
	_rResultant = { _krA.m_fX + _krB.m_fX, _krA.m_fY + _krB.m_fY };
	return _rResultant;
}

TVector3 & Subtract(const TVector3 & _krA, const TVector3 & _krB, TVector3 & _rResultant)
{
	_rResultant = { _krA.m_fX - _krB.m_fX, _krA.m_fY - _krB.m_fY, _krA.m_fZ - _krB.m_fZ };
	return _rResultant;
}

TVector2 & Subtract2D(const TVector2 & _krA, const TVector2 & _krB, TVector2 & _rResultant)
{
	_rResultant = { _krA.m_fX - _krB.m_fX, _krA.m_fY - _krB.m_fY };
	return _rResultant;
}

TVector3 & ScaleVector(const TVector3 & _krA, const float _kfScalar, TVector3 & _rResultant)
{
	_rResultant = { _krA.m_fX * _kfScalar, _krA.m_fY * _kfScalar, _krA.m_fZ * _kfScalar };
	return _rResultant;
}

TVector2 & ScaleVector2D(const TVector2 & _krA, const float _kfScalar, TVector2 & _rResultant)
{
	_rResultant = { _krA.m_fX * _kfScalar, _krA.m_fY * _kfScalar };
	return _rResultant;
}

float Magnitude(const TVector3 & _krA)
{	
	return (float) sqrt(((_krA.m_fX * _krA.m_fX) + (_krA.m_fY * _krA.m_fY) + (_krA.m_fZ * _krA.m_fZ)));
}

float Magnitude2D(const TVector2 & _krA)
{
	return sqrt(((_krA.m_fX * _krA.m_fX) + (_krA.m_fY * _krA.m_fY)));
}

float DotProduct(const TVector3 & _krA, const TVector3 & _krB)
{
	return (_krA.m_fX * _krB.m_fX) + (_krA.m_fY * _krB.m_fY) + (_krA.m_fZ * _krB.m_fZ);
}

float DotProduct2D(const TVector2 & _krA, const TVector2 & _krB)
{
	return (_krA.m_fX * _krB.m_fX) + (_krA.m_fY * _krB.m_fY);
}

TVector3 & CrossProduct(const TVector3 & _krA, const TVector3 & _krB, TVector3 & _rResultant)
{
	_rResultant = { ((_krA.m_fY * _krB.m_fZ) - (_krA.m_fZ * _krB.m_fY)),
				   ((_krA.m_fZ * _krB.m_fX) - (_krA.m_fX * _krB.m_fZ)),
				   ((_krA.m_fX * _krB.m_fY) - (_krA.m_fY * _krB.m_fX))
	};
	return _rResultant;
}

TVector3 & Normalise(const TVector3 & _krA, TVector3 & _rResultant)
{
	float fMag = sqrt(((_krA.m_fX * _krA.m_fX) + (_krA.m_fY * _krA.m_fY) + (_krA.m_fZ * _krA.m_fZ)));
	_rResultant = { _krA.m_fX / fMag, _krA.m_fY / fMag, _krA.m_fZ / fMag };
	return _rResultant;
}

TVector2 & Normalise2D(const TVector2 & _krA, TVector2 & _rResultant)
{
	_rResultant = { _krA.m_fX / Magnitude2D(_krA), _krA.m_fY / Magnitude2D(_krA) };
	return _rResultant;
}

TVector3 & Projection(const TVector3 & _krA, const TVector3 & _krB, TVector3 & _rResultant)
{
	float fTemp = DotProduct(_krA, _krB) / (Magnitude(_krB) * Magnitude(_krB));
	_rResultant = { (fTemp * _krB.m_fX), (fTemp * _krB.m_fY), (fTemp * _krB.m_fZ) };
	return _rResultant;
}

float ComputeAngleBetween(const TVector2 & _krA, const TVector2 & _krB)
{
	float fTemp = DotProduct2D(_krA, _krB) / (Magnitude2D(_krA) * Magnitude2D(_krB));
	return acos(fTemp);
}

float ComputeAngleBetween(const TVector3 & _krA, const TVector3 & _krB)
{
	float fTemp = DotProduct(_krA, _krB) / (Magnitude(_krA) * Magnitude(_krB));
	return acos(fTemp);
}

float ComputeDistancePointToLine(const T3DLine & _krLine, const TVector3 & _krPoint)
{
	TVector3 pQVector = Subtract(_krPoint, _krLine.m_v3q, pQVector);
	TVector3 pQUCrossProduct = CrossProduct(pQVector, _krLine.m_v3v, pQUCrossProduct);
	if (Equals(pQUCrossProduct, { (0.0f,0.0f,0.0f) }) == true)
	{
		return 0.0f;
	}
	return (Magnitude(pQUCrossProduct) / Magnitude(_krLine.m_v3v));
}

float ComputeDistancePointToPlane(const TPlane & _krPlane, const TVector3 & _krPoint) 
{
	float fNormalMagnitude = Magnitude(_krPlane.m_v3normal);
	TVector3 NormalizedNormal = { _krPlane.m_v3normal.m_fX / fNormalMagnitude, _krPlane.m_v3normal.m_fY / fNormalMagnitude, _krPlane.m_v3normal.m_fZ / fNormalMagnitude, };
	TVector3 DistanceVector = Subtract(_krPoint, _krPlane.m_v3point, DistanceVector);
	return DotProduct(DistanceVector, NormalizedNormal);	
}

float ComputeDistancePointToSphere(const TSphere & _krSphere, const TVector3 & _krPoint)
{
	return sqrt((_krPoint.m_fX - _krSphere.m_v3center.m_fX) * (_krPoint.m_fX - _krSphere.m_v3center.m_fX)
		+ (_krPoint.m_fY - _krSphere.m_v3center.m_fY) * (_krPoint.m_fY - _krSphere.m_v3center.m_fY)
		+ (_krPoint.m_fZ - _krSphere.m_v3center.m_fZ) * (_krPoint.m_fZ - _krSphere.m_v3center.m_fZ));
}

float ComputeDistanceCircleToCircle(const TCircle & _krCircle1, const TCircle & _krCircle2)
{
	return sqrt((_krCircle2.m_v2center.m_fX - _krCircle1.m_v2center.m_fX) * (_krCircle2.m_v2center.m_fX - _krCircle1.m_v2center.m_fX)
		+ (_krCircle2.m_v2center.m_fY - _krCircle1.m_v2center.m_fY) * (_krCircle2.m_v2center.m_fY - _krCircle1.m_v2center.m_fY));
}

float ComputeDistanceCircleToTriangle(const TCircle & _krCircle, const TTriangle2 & _krTriangle)
{
	TVector2 Centroid = { ((_krTriangle.m_v2p1.m_fX + _krTriangle.m_v2p2.m_fX + _krTriangle.m_v2p1.m_fX) / 3), 
		((_krTriangle.m_v2p1.m_fY + _krTriangle.m_v2p2.m_fY + _krTriangle.m_v2p1.m_fY) / 3) };	
	return sqrt((Centroid.m_fX - _krCircle.m_v2center.m_fX) * (Centroid.m_fX - _krCircle.m_v2center.m_fX)
		+ (Centroid.m_fY - _krCircle.m_v2center.m_fY) * (Centroid.m_fY - _krCircle.m_v2center.m_fY));
}

EIntersections ComputeLineSphereIntersection(const T3DLine & _krLine, const TSphere & _krSphere, TVector3 & _rv3IntersectionPoint1, TVector3 & _rv3IntersectionPoint2)
{
	double dA = (_krLine.m_v3q.m_fX - _krLine.m_v3v.m_fX) * (_krLine.m_v3q.m_fX - _krLine.m_v3v.m_fX) // x1, y1, z1 = The point on the line
		+ (_krLine.m_v3q.m_fY - _krLine.m_v3v.m_fY) * (_krLine.m_v3q.m_fY - _krLine.m_v3v.m_fY) // x0, y0, z0 = The direction of the line
		+ (_krLine.m_v3q.m_fZ - _krLine.m_v3v.m_fZ) * (_krLine.m_v3q.m_fZ - _krLine.m_v3v.m_fZ); // h, k, j = the vector of the center of the sphere

	double dB = 2 * ((_krLine.m_v3q.m_fX - _krLine.m_v3v.m_fX) * (_krLine.m_v3v.m_fX - _krSphere.m_v3center.m_fX)
		+ (_krLine.m_v3q.m_fY - _krLine.m_v3v.m_fY) * (_krLine.m_v3v.m_fY - _krSphere.m_v3center.m_fY)
		+ (_krLine.m_v3q.m_fZ - _krLine.m_v3v.m_fZ) * (_krLine.m_v3v.m_fZ - _krSphere.m_v3center.m_fZ));

	double dC = (_krSphere.m_v3center.m_fX) * (_krSphere.m_v3center.m_fX) // h^2
		+ (_krSphere.m_v3center.m_fY) * (_krSphere.m_v3center.m_fY) // k^2
		+ (_krSphere.m_v3center.m_fZ) * (_krSphere.m_v3center.m_fZ) // j^2
		+ (_krLine.m_v3v.m_fX) * (_krLine.m_v3v.m_fX) // x0^2
		+ (_krLine.m_v3v.m_fY) * (_krLine.m_v3v.m_fY) // y0^2
		+ (_krLine.m_v3v.m_fZ) * (_krLine.m_v3v.m_fZ) // z0^2
		- 2 * (((_krSphere.m_v3center.m_fX) * (_krLine.m_v3v.m_fX)) // hx0
			+ ((_krSphere.m_v3center.m_fY) * (_krLine.m_v3v.m_fY))   // ky0
			+ ((_krSphere.m_v3center.m_fZ) * (_krLine.m_v3v.m_fZ)))  // jz0 
		- ((_krSphere.m_fRadius) * (_krSphere.m_fRadius));	     // r^2

	double dResultant = (dB * dB) - (4 * (dA) * (dC)); // discriminant

	double dnegBDivide2A = -dB / (2 * dA); // Left side of quadratic equation
	double dDiscrimDivide2A = sqrt(dResultant) / (2 * dA); // Right side of quadratic equation
	float dTTwo = dnegBDivide2A + dDiscrimDivide2A; // t2
	float dTOne = dnegBDivide2A - dDiscrimDivide2A; // t1
	
	if (dResultant > 0)
	{
		_rv3IntersectionPoint1 = { dTOne * (_krLine.m_v3q.m_fX - _krLine.m_v3v.m_fX) + _krLine.m_v3v.m_fX,
								   dTOne * (_krLine.m_v3q.m_fY - _krLine.m_v3v.m_fY) + _krLine.m_v3v.m_fY,
								   dTOne * (_krLine.m_v3q.m_fZ - _krLine.m_v3v.m_fZ) + _krLine.m_v3v.m_fZ };
		_rv3IntersectionPoint2 = { dTTwo * (_krLine.m_v3q.m_fX - _krLine.m_v3v.m_fX) + _krLine.m_v3v.m_fX,
								   dTTwo * (_krLine.m_v3q.m_fY - _krLine.m_v3v.m_fY) + _krLine.m_v3v.m_fY,
								   dTTwo * (_krLine.m_v3q.m_fZ - _krLine.m_v3v.m_fZ) + _krLine.m_v3v.m_fZ };
		return EIntersections(INTERSECTION_TWO);
	}
	else if (dResultant == 0)
	{
		_rv3IntersectionPoint1 = { dTOne * (_krLine.m_v3q.m_fX - _krLine.m_v3v.m_fX) + _krLine.m_v3v.m_fX,
								   dTOne * (_krLine.m_v3q.m_fY - _krLine.m_v3v.m_fY) + _krLine.m_v3v.m_fY,
							       dTOne * (_krLine.m_v3q.m_fZ - _krLine.m_v3v.m_fZ) + _krLine.m_v3v.m_fZ };
		return EIntersections(INTERSECTION_ONE);		
	}
	else if (dResultant < 0)
	{		
		return EIntersections(INTERSECTION_NONE);
	}	
}

bool IsLinePlaneIntersection(const T3DLine & _krLine, const TPlane & _krPlane, TVector3 & _rv3IntersectionPoint)
{
	TVector3 v = _krLine.m_v3v;
	TVector3 w = Subtract(_krPlane.m_v3point, _krLine.m_v3q, w);

	float fK = DotProduct(w, _krPlane.m_v3normal) / DotProduct(v, _krPlane.m_v3normal);

	if (fK == 0)
	{
		return false;		
	}
	else
	{
		TVector3 kTimesV = ScaleVector(v, fK, kTimesV);
		_rv3IntersectionPoint = Add(_krLine.m_v3q, kTimesV, _rv3IntersectionPoint);
		return true;
	}
	//return fK >= 0 && fK <= 1;	
}

bool IsIntersection(const T3DLine & _krLine1, const T3DLine & _krLine2)
{	
	if (Equals(_krLine1.m_v3q, _krLine2.m_v3q) == true)
	{
		return true;
	}	
	
	TVector3 V1XV2 = CrossProduct(_krLine1.m_v3v, _krLine2.m_v3v, V1XV2); // Left side of equation
	TVector3 P2minusP1 = Subtract(_krLine2.m_v3q, _krLine1.m_v3q, P2minusP1); 
	TVector3 P2minusP1XV2 = CrossProduct(P2minusP1, _krLine2.m_v3v, P2minusP1XV2); // Right side of equation

	if (Equals(V1XV2, { 0, 0, 0 }) == true) // If the cross product of V1 and V2 equals zero vector, there is no intersection
	{
		return false;
	}

	TVector3 Normalise1 = Normalise(V1XV2, Normalise1);
	TVector3 Normalise2 = Normalise(P2minusP1XV2, Normalise2);

	float fAngleBetween = ComputeAngleBetween(Normalise1, Normalise2);

	if (fAngleBetween == 0) // If two lines are parallel, the angle between them must be 0
	{
		if (Equals(Normalise1, Normalise2) == false)
		{
			float fA = -(Magnitude(V1XV2) / Magnitude(P2minusP1XV2));
			if (fA > 1 || fA < 0)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			float fA = (Magnitude(V1XV2) / Magnitude(P2minusP1XV2));
			if (fA > 1 || fA < 0)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	else
	{
		return false;
	}

	// L1 = _krLine1.m_v3q + a _krLine1.m_v3v = P1 + a V1
	// L2 = _krLine2.m_v3q + b _krLine2.m_v3v = P2 + b V2

	// P1 + a V1 = P2 + b V2
	// REWRITE
	// a V1 = (P2 - P1) + b V2
	// REWRITE
	// a (V1 X V2) = (P2 - P1) X V2

	//If the lines intersect at a single point, then the resultant vectors on each side of this equation must be parallel
	//and the left side must not be the zero vector. We should check to make sure that this is true

	// Check if V1 X V2 == <0, 0, 0> If this is true there is no intersection.

	//Once we have checked this, we can solve for 'a' by taking the
	//magnitude of each side and dividing.	

	// (V1 X V2) / Magnitude(V1 X V2) and (P2 - P1) X V2 / Magnitude((P2 - P1) X V2)
	// REWRITE
	// Normalise(V1 X V2) and Normalise((P2 - P1) X V2)

	//If the resultant vectors are
	//parallel, but in opposite directions, then 'a' is the negative of the
	//ratio of magnitudes.
	
	//a = -( Magnitude(V1 X V2) / Magnitude((P2 - P1) X V2) )
	
	//Once we have 'a' we can go back to the equation
	//for L1 to find the intersection point.
		
	// L1 = _krLine1.m_v3q + (a * _krLine1.m_v3v)  INTERSECTION POINT
	
	
}

TVector3 & ComputeIntersectionBetweenLines(const T3DLine & _krLine1, const T3DLine & _krLine2, TVector3 & _rIntersectionPoint)
{
	if (Equals(_krLine1.m_v3q, _krLine2.m_v3q) == true)
	{
		return _rIntersectionPoint = {_krLine1.m_v3q};
	}

	TVector3 V1XV2 = CrossProduct(_krLine1.m_v3v, _krLine2.m_v3v, V1XV2); // Left side of equation
	TVector3 P2minusP1 = Subtract(_krLine2.m_v3q, _krLine1.m_v3q, P2minusP1);
	TVector3 P2minusP1XV2 = CrossProduct(P2minusP1, _krLine2.m_v3v, P2minusP1XV2); // Right side of equation

	if (Equals(V1XV2, { 0, 0, 0 }) == true) // If the cross product of V1 and V2 equals zero vector, there is no intersection
	{
		return _rIntersectionPoint;
	}

	TVector3 Normalise1 = Normalise(V1XV2, Normalise1);
	TVector3 Normalise2 = Normalise(P2minusP1XV2, Normalise2);

	float fAngleBetween = ComputeAngleBetween(Normalise1, Normalise2);

	if (fAngleBetween == 0) // If two lines are parallel, the angle between them must be 0
	{
		if (Equals(Normalise1, Normalise2) == false)
		{
			float fA = -(Magnitude(V1XV2) / Magnitude(P2minusP1XV2));
			if (fA > 1 || fA < 0)
			{
				return _rIntersectionPoint;
			}
			else
			{
				TVector3 aMultiplyL1V = ScaleVector(_krLine1.m_v3v, fA, aMultiplyL1V);
				return _rIntersectionPoint = Add(_krLine1.m_v3q, aMultiplyL1V, _rIntersectionPoint);
				// L1 = _krLine1.m_v3q + (a * _krLine1.m_v3v)  INTERSECTION POINT
			}
		}
		else
		{
			float fA = (Magnitude(V1XV2) / Magnitude(P2minusP1XV2));
			if (fA > 1 || fA < 0)
			{
				return _rIntersectionPoint;
			}
			else
			{
				TVector3 aMultiplyL1V = ScaleVector(_krLine1.m_v3v, fA, aMultiplyL1V);
				return _rIntersectionPoint = Add(_krLine1.m_v3q, aMultiplyL1V, _rIntersectionPoint);
				// L1 = _krLine1.m_v3q + (a * _krLine1.m_v3v)  INTERSECTION POINT
			}
		}
	}
	else
	{
		return _rIntersectionPoint;
	}

	// L1 = _krLine1.m_v3q + a _krLine1.m_v3v = P1 + a V1
	// L2 = _krLine2.m_v3q + b _krLine2.m_v3v = P2 + b V2

	// P1 + a V1 = P2 + b V2
	// REWRITE
	// a V1 = (P2 - P1) + b V2
	// REWRITE
	// a (V1 X V2) = (P2 - P1) X V2

	//If the lines intersect at a single point, then the resultant vectors on each side of this equation must be parallel
	//and the left side must not be the zero vector. We should check to make sure that this is true

	// Check if V1 X V2 == <0, 0, 0> If this is true there is no intersection.

	//Once we have checked this, we can solve for 'a' by taking the
	//magnitude of each side and dividing.	

	// (V1 X V2) / Magnitude(V1 X V2) and (P2 - P1) X V2 / Magnitude((P2 - P1) X V2)
	// REWRITE
	// Normalise(V1 X V2) and Normalise((P2 - P1) X V2)

	//If the resultant vectors are
	//parallel, but in opposite directions, then 'a' is the negative of the
	//ratio of magnitudes.

	//a = -( Magnitude(V1 X V2) / Magnitude((P2 - P1) X V2) )

	//Once we have 'a' we can go back to the equation
	//for L1 to find the intersection point.

	// L1 = _krLine1.m_v3q + (a * _krLine1.m_v3v)  INTERSECTION POINT


}

bool IsInFieldOfView(const TVector2 & _krCameraPosition, const TVector2 & _krCameraDirection, const float _kfFieldOfViewInRadians, const TVector2 & _krObjectPosition)
{
	TVector2 V = Subtract2D(_krObjectPosition, _krCameraPosition, V); // Object position vector - Camera position vector
	TVector2 VNormal = Normalise2D(V, VNormal);
	TVector2 DNormal = Normalise2D(_krCameraDirection, DNormal);
	float fDDotV = DotProduct2D(DNormal, VNormal);
	float fRadians = acosf(fDDotV);
	float fDegrees = RadianToDegree(fRadians);
	float fFoVDegrees = RadianToDegree(_kfFieldOfViewInRadians);

	if (fDegrees <= (fFoVDegrees / 2))
	{
		return true;
	}
	else
	{
		return false;
	}		
}

TVector3 & FindTriangleNormal(const TTriangle3 & _krTriangle, TVector3 & _rNormal)
{
	TVector3 P1 = _krTriangle.m_v3p1;
	TVector3 P2 = _krTriangle.m_v3p2;
	TVector3 P3 = _krTriangle.m_v3p3;
	TVector3 P2SubP1 = Subtract(P2, P1, P2SubP1);
	TVector3 P3SubP1 = Subtract(P3, P1, P3SubP1);
	return _rNormal = CrossProduct(P2SubP1, P3SubP1, _rNormal);
}

bool IsSurfaceLit(const TVector3 & _krPointOnSurface, const TVector3 & _krLightSourcePosition, const TTriangle3 & _krSurface)
{
	TVector3 SurfaceNormal = FindTriangleNormal(_krSurface, SurfaceNormal);
	float fAngleLightandSurfaceNormal = ComputeAngleBetween(SurfaceNormal, _krLightSourcePosition);
	if (fAngleLightandSurfaceNormal < 1.5708)
	{
		return true;
	}
	else
	{
		return false;
	}
}

TTriangle2 & RotateTriangleAroundPoint(const TTriangle2 & _krTriangle, const float _kfRotAngleInRadians, const TVector2 & _krRotAroundPoint, TTriangle2 & _rRotatedTriangle)
{		
	// Rotate Point 1
	float fXMinusPointX1 = _krTriangle.m_v2p1.m_fX - _krRotAroundPoint.m_fX;
	float fYMinusPointY1 = _krTriangle.m_v2p1.m_fY - _krRotAroundPoint.m_fY;
	TVector2 RotatedPoint1 = { (RotatedPoint1.m_fX = cos(_kfRotAngleInRadians) * fXMinusPointX1 - sin(_kfRotAngleInRadians) * fYMinusPointY1) + _krRotAroundPoint.m_fX,
							   (RotatedPoint1.m_fY = sin(_kfRotAngleInRadians) * fXMinusPointX1 + cos(_kfRotAngleInRadians) * fYMinusPointY1) + _krRotAroundPoint.m_fY };

	// Rotate Point 2
	float fXMinusPointX2 = _krTriangle.m_v2p2.m_fX - _krRotAroundPoint.m_fX;
	float fYMinusPointY2 = _krTriangle.m_v2p2.m_fY - _krRotAroundPoint.m_fY;
	TVector2 RotatedPoint2 = { (RotatedPoint2.m_fX = cos(_kfRotAngleInRadians) * fXMinusPointX2 - sin(_kfRotAngleInRadians) * fYMinusPointY2) + _krRotAroundPoint.m_fX,
							   (RotatedPoint2.m_fY = sin(_kfRotAngleInRadians) * fXMinusPointX2 + cos(_kfRotAngleInRadians) * fYMinusPointY2) + _krRotAroundPoint.m_fY };

	// Rotate Point 3
	float fXMinusPointX3 = _krTriangle.m_v2p3.m_fX - _krRotAroundPoint.m_fX;
	float fYMinusPointY3 = _krTriangle.m_v2p3.m_fY - _krRotAroundPoint.m_fY;
	TVector2 RotatedPoint3 = { (RotatedPoint3.m_fX = cos(_kfRotAngleInRadians) * fXMinusPointX3 - sin(_kfRotAngleInRadians) * fYMinusPointY3) + _krRotAroundPoint.m_fX,
							   (RotatedPoint3.m_fY = sin(_kfRotAngleInRadians) * fXMinusPointX3 + cos(_kfRotAngleInRadians) * fYMinusPointY3) + _krRotAroundPoint.m_fY };


	// Setting the rotated triangle points to the points we just calculated
	_rRotatedTriangle.m_v2p1.m_fX = RotatedPoint1.m_fX;
	_rRotatedTriangle.m_v2p1.m_fY = RotatedPoint1.m_fY;
	_rRotatedTriangle.m_v2p2.m_fX = RotatedPoint2.m_fX;
	_rRotatedTriangle.m_v2p2.m_fY = RotatedPoint2.m_fY;
	_rRotatedTriangle.m_v2p3.m_fX = RotatedPoint3.m_fX;
	_rRotatedTriangle.m_v2p3.m_fY = RotatedPoint3.m_fY;

	/*_rRotatedTriangle.m_v2p1.m_fX = static_cast<float>(floor(_rRotatedTriangle.m_v2p1.m_fX * 10) / 10);
	_rRotatedTriangle.m_v2p1.m_fY = static_cast<float>(floor(_rRotatedTriangle.m_v2p1.m_fY * 10) / 10);
	_rRotatedTriangle.m_v2p2.m_fX = static_cast<float>(floor(_rRotatedTriangle.m_v2p2.m_fX * 10) / 10);
	_rRotatedTriangle.m_v2p2.m_fY = static_cast<float>(floor(_rRotatedTriangle.m_v2p2.m_fY * 10) / 10);
	_rRotatedTriangle.m_v2p3.m_fX = static_cast<float>(floor(_rRotatedTriangle.m_v2p3.m_fX * 10) / 10);
	_rRotatedTriangle.m_v2p3.m_fY = static_cast<float>(floor(_rRotatedTriangle.m_v2p3.m_fY * 10) / 10);*/



	// Return the rotated triangle
	return _rRotatedTriangle;		
}


