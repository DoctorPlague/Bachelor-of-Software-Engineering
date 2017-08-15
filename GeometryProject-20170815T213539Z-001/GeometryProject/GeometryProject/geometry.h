//
//    Bachelor of Software Engineering
//    Media Design School
//    Auckland
//    New Zealand
//
//    (c) 2005 - 2015 Media Design School
//
//    File Name: geometry.h
//    Description: prototypes of functions
//    Author: Jasper Lyons
//    Mail: Jasper.Lyo7552@mediadesignschool.co.nz
//

#pragma once
enum EIntersections
{
	INTERSECTION_NONE,
	INTERSECTION_ONE,
	INTERSECTION_TWO
};

struct TVector2
{
	float m_fX;
	float m_fY;
};

struct TTriangle2
{
	TVector2 m_v2p1;
	TVector2 m_v2p2;
	TVector2 m_v2p3;
};

struct TRectangle
{
	TVector2 m_v2p1;
	TVector2 m_v2p2;
};

struct TVector3
{
	float m_fX;
	float m_fY;
	float m_fZ;
};

struct TTriangle3
{
	TVector3 m_v3p1;
	TVector3 m_v3p2;
	TVector3 m_v3p3;
};

struct T3DLine
{
	TVector3 m_v3q; //point on the line
	TVector3 m_v3v; //direction vector along the line
};

struct TCircle
{
	TVector2 m_v2center;
	float m_fRadius;
};

struct TPlane
{
	TVector3 m_v3normal;
	TVector3 m_v3point;
};

struct TSphere
{
	TVector3 m_v3center;
	float m_fRadius;
};

/***********************
* Equals: Check if two 3D vectors are equal.
* @author: Jasper Lyons.
* @parameter: Two 3D Vectors.
* @return: Returns a bool.
********************/
bool Equals(const TVector3& _krA, const TVector3& _krB);

/***********************
* Equals: Check if two 2D vectors are equal.
* @author: Jasper Lyons.
* @parameter: Two 2D Vectors.
* @return: Returns a bool.
********************/
bool Equals2D(const TVector2& _krA, const TVector2& _krB);


/***********************
* Add: Adds two 3D vectors and return the result.
* @author: Jasper Lyons
* @parameter: Three 3D vectors. Two for input and one for the result.
* @return: Returns the resulting 3D vector.
********************/
TVector3& Add(const TVector3& _krA,
	const TVector3& _krB,
	TVector3& _rResultant);

/***********************
* Add2D: Adds two 2D vectors and return the result.
* @author: Jasper Lyons
* @parameter: Three 2D vectors. Two for input and one for the result.
* @return: Returns the resulting 2D vector.
********************/
TVector2& Add2D(const TVector2& _krA,
	const TVector2& _krB,
	TVector2& _rResultant);

/***********************
* Subtract: Subtracts two 3D vectors and return the result.
* @author: Jasper Lyons
* @parameter: Three 3D vectors. Two for input and one for the result.
* @return: Returns the resulting 3D vector.
********************/
TVector3& Subtract(const TVector3& _krA,
	const TVector3& _krB,
	TVector3& _rResultant);

/***********************
* Subtract2D: Subtracts two 2D vectors and return the result.
* @author: Jasper Lyons
* @parameter: Three 2D vectors. Two for input and one for the result.
* @return: Returns the resulting 2D vector.
********************/
TVector2& Subtract2D(const TVector2& _krA,
	const TVector2& _krB,
	TVector2& _rResultant);

/***********************
* ScaleVector: Multiplies a vector by a float value and return the result.
* @author: Jasper Lyons
* @parameter: Two 3D vectors, one for input and one for the result, and a float value to multiply the vector by.
* @return: Returns the resulting 3D vector.
********************/
TVector3& ScaleVector(const TVector3& _krA,
	const float _kfScalar,
	TVector3& _rResultant);

/***********************
* ScaleVector2D: Multiplies a vector by a float value and return the result.
* @author: Jasper Lyons
* @parameter: Two 2D vectors, one for input and one for the result, and a float value to multiply the vector by.
* @return: Returns the resulting 2D vector.
********************/
TVector2& ScaleVector2D(const TVector2& _krA,
	const float _kfScalar,
	TVector2& _rResultant);

/***********************
* Magnitude: Finds the magnitude of a 3D vector and returns a float value.
* @author: Jasper Lyons
* @parameter: One 3D vector.
* @return: Returns a float value.
********************/
float Magnitude(const TVector3& _krA);

/***********************
* Magnitude2D: Finds the magnitude of a 2D vector and returns a float value.
* @author: Jasper Lyons
* @parameter: One 2D vector.
* @return: Returns a float value.
********************/
float Magnitude2D(const TVector2& _krA);

/***********************
* DotProduct: Finds the dot product of two 3D vectors and returns a float value.
* @author: Jasper Lyons
* @parameter: Two 3D vectors.
* @return: Returns a float value.
********************/
float DotProduct(const TVector3& _krA, const TVector3& _krB);

/***********************
* DotProduct2D: Finds the dot product of two 2D vectors and returns a float value.
* @author: Jasper Lyons
* @parameter: Two 2D vectors.
* @return: Returns a float value.
********************/
float DotProduct2D(const TVector2& _krA, const TVector2& _krB);

/***********************
* CrossProduct: Finds the cross product of two 3D vectors and returns a float value.
* @author: Jasper Lyons
* @parameter: Two 3D vectors and a resultant 3D vector.
* @return: Returns a float value.
********************/
TVector3& CrossProduct(const TVector3& _krA,
	const TVector3& _krB,
	TVector3& _rResultant);

/***********************
* Normalise: Normalises a 3D vector.
* @author: Jasper Lyons
* @parameter: Two 3D vectors, one for input one for the resultant 3D vector.
* @return: Returns a resultant 3D vector.
********************/
TVector3& Normalise(const TVector3& _krA, TVector3& _rResultant);

/***********************
* Normalise2D: Normalises a 2D vector.
* @author: Jasper Lyons
* @parameter: Two 2D vectors, one for input one for the resultant 2D vector.
* @return: Returns a resultant 2D vector.
********************/
TVector2& Normalise2D(const TVector2& _krA, TVector2& _rResultant);

/***********************
* Projection: Projects a 3D vector onto another 3D vector and returns a resultant 3D vector.
* @author: Jasper Lyons
* @parameter: Two 3D vectors, one for input one for the resultant 3D vector.
* @return: Returns a resultant 3D vector.
********************/
TVector3& Projection(const TVector3& _krA,
	const TVector3& _krB,
	TVector3& _rResultant);

/***********************
* ComputeAngleBetween: Computes the angle between two 2D vectors.
* @author: Jasper Lyons
* @parameter: Two 2D vectors.
* @return: Returns a float value.
********************/
float ComputeAngleBetween(const TVector2& _krA,
	const TVector2& _krB);

/***********************
* ComputeAngleBetween: Computes the angle between two 3D vectors.
* @author: Jasper Lyons
* @parameter: Two 3D vectors.
* @return: Returns a float value.
********************/
float ComputeAngleBetween(const TVector3& _krA,
	const TVector3& _krB);

/***********************
* ComputeDistancePointToLine: Computes the distance between a point and a line.
* @author: Jasper Lyons
* @parameter: A 3D line and a 3D vector
* @return: Returns a float value.
********************/
float ComputeDistancePointToLine(const T3DLine& _krLine,
	const TVector3& _krPoint);

/***********************
* ComputeDistancePointToPlane: Computes the distance between a point and a plane.
* @author: Jasper Lyons
* @parameter: A 3D plane and a 3D vector
* @return: Returns a float value.
********************/
float ComputeDistancePointToPlane(const TPlane& _krPlane,
	const TVector3& _krPoint);

/***********************
* ComputeDistancePointToSphere: Computes the distance between a point and a sphere.
* @author: Jasper Lyons
* @parameter: A Sphere and a 3D vector
* @return: Returns a float value.
********************/
float ComputeDistancePointToSphere(const TSphere& _krSphere,
	const TVector3& _krPoint);

/***********************
* ComputeDistanceCircleToCircle: Computes the distance between the center points of two circles
* @author: Jasper Lyons
* @parameter: Two 2D circles.
* @return: Returns a float value.
********************/
float ComputeDistanceCircleToCircle(const TCircle& _krCircle1,
	const TCircle& _krCircle2);

/***********************
* ComputeDistanceCircleToTriangle: Computes the distance between the center of a triangle and a circle.
* @author: Jasper Lyons
* @parameter: A 2D triangle and circle
* @return: Returns a float value.
********************/
float ComputeDistanceCircleToTriangle(const TCircle& _krCircle,
	const TTriangle2& _krTriangle);

/***********************
* ComputeLineSphereIntersection: Computes the number of intersections between a line and sphere and the points of intersection.
* @author: Jasper Lyons
* @parameter: A 3D line, sphere and two resultant 3D vectors for intersection points
* @return: Returns an enum based on the number of intersections.
********************/
EIntersections ComputeLineSphereIntersection(const T3DLine& _krLine,
	const TSphere& _krSphere,
	TVector3& _rv3IntersectionPoint1,
	TVector3& _rv3IntersectionPoint2);

/***********************
* IsLinePlaneIntersection: Computes the whether or not a line and a plane intersect and the intersection point if they do.
* @author: Jasper Lyons
* @parameter: A 3D line, plane and a 3D vector for the potential intersection point.
* @return: Returns a bool for if there is an intersection.
********************/
bool IsLinePlaneIntersection(const T3DLine& _krLine,
	const TPlane& _krPlane,
	TVector3& _rv3IntersectionPoint);

/***********************
* IsIntersection: Computes if two 3D lines intersect.
* @author: Jasper Lyons
* @parameter: Two 3D lines.
* @return: Returns a bool for if there is an intersection.
********************/
bool IsIntersection(const T3DLine& _krLine1,
	const T3DLine& _krLine2);

/***********************
* ComputeIntersectionBetweenLines: Computes where two 3D lines intersect.
* @author: Jasper Lyons
* @parameter: Two 3D lines and a resultant 3D vector for the intersection point
* @return: Returns a resultant 3D vector containing any intersection point.
********************/
TVector3& ComputeIntersectionBetweenLines(const T3DLine& _krLine1,
	const T3DLine& _krLine2,
	TVector3& _rIntersectionPoint);

/***********************
* IsInFieldOfView: Computes if an object is within a cameras field of view.
* @author: Jasper Lyons
* @parameter: Camera position and direction, field of view in radians and the position of an object.
* @return: Returns a bool for if the object is within the field of view.
********************/
bool IsInFieldOfView(const TVector2& _krCameraPosition,
	const TVector2& _krCameraDirection,
	const float _kfFieldOfViewInRadians,
	const TVector2& _krObjectPosition);

/***********************
* FindTriangleNormal: Computes the normal of a triangle.
* @author: Jasper Lyons
* @parameter: A 3D triangle and a vector
* @return: Returns a 3D vector containing the normal of an input triangle.
********************/
TVector3& FindTriangleNormal(const TTriangle3& _krTriangle,
	TVector3& _rNormal);

/***********************
* IsSurfaceLit: Computes whether or not a point on a surface is lit.
* @author: Jasper Lyons
* @parameter: Two 3D vectors and a 3D Triangle.
* @return: Returns a bool containing if the point on the surface is lit.
********************/
bool IsSurfaceLit(const TVector3& _krPointOnSurface,
	const TVector3& _krLightSourcePosition,
	const TTriangle3& _krSurface);

/***********************
* RotateTriangleAroundPoint: Computes the location of a triangle after being rotated around a point.
* @author: Jasper Lyons
* @parameter: Two 2D Triangles, a float and a 2D vector.
* @return: Returns a 2D vector containing the coordinates of the rotated triangle.
********************/
TTriangle2& RotateTriangleAroundPoint(const TTriangle2& _krTriangle,
	const float _kfRotAngleInRadians,
	const TVector2& _krRotAroundPoint,
	TTriangle2& _rRotatedTriangle);
