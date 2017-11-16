#ifndef VECTOR2_H
#define VECTOR2_H

#include "math.h"
#include <cstring>

class Vector2
{
public:

    float X, Y;

    inline Vector2()
    {
		X = 0.0f;
		Y = 0.0f;
    }

	~Vector2()
	{
	}

    inline Vector2(const float fX, const float fY )
        : X( fX ), Y( fY )
    {
    }

    inline explicit Vector2( const float scaler )
        : X( scaler), Y( scaler )
    {
    }

    inline explicit Vector2( const float afCoordinate[2] )
        : X( afCoordinate[0] ),
          Y( afCoordinate[1] )
    {
    }

    inline explicit Vector2( const int afCoordinate[2] )
    {
        X = (float)afCoordinate[0];
        Y = (float)afCoordinate[1];
    }

    inline explicit Vector2( float* const r )
        : X( r[0] ), Y( r[1] )
    {
    }

    inline Vector2( const Vector2& rkVector )
        : X( rkVector.X ), Y( rkVector.Y )
    {
    }

	inline float operator [] ( const size_t i ) const
    {
        return *(&X+i);
    }

	inline float& operator [] ( const size_t i )
    {
        return *(&X+i);
    }

	/// Pointer accessor for direct copying
	inline float* ptr()
	{
		return &X;
	}
	/// Pointer accessor for direct copying
	inline const float* ptr() const
	{
		return &X;
	}

    /** Assigns the value of the other vector.
        @param
            rkVector The other vector
    */
    inline Vector2& operator = ( const Vector2& rkVector )
    {
        X = rkVector.X;
        Y = rkVector.Y;

        return *this;
    }

	inline Vector2& operator = ( const float fScalar)
	{
		X = fScalar;
		Y = fScalar;

		return *this;
	}

    inline bool operator == ( const Vector2& rkVector ) const
    {
        return ( X == rkVector.X && Y == rkVector.Y );
    }

    inline bool operator != ( const Vector2& rkVector ) const
    {
        return ( X != rkVector.X || Y != rkVector.Y  );
    }

    // arithmetic operations
    inline Vector2 operator + ( const Vector2& rkVector ) const
    {
        return Vector2(
            X + rkVector.X,
            Y + rkVector.Y);
    }

    inline Vector2 operator - ( const Vector2& rkVector ) const
    {
        return Vector2(
            X - rkVector.X,
            Y - rkVector.Y);
    }

    inline Vector2 operator * ( const float fScalar ) const
    {
        return Vector2(
            X * fScalar,
            Y * fScalar);
    }

    inline Vector2 operator * ( const Vector2& rhs) const
    {
        return Vector2(
            X * rhs.X,
            Y * rhs.Y);
    }

    inline Vector2 operator / ( const float fScalar ) const
    {
        float fInv = 1 / fScalar;

        return Vector2(
            X * fInv,
            Y * fInv);
    }

    inline Vector2 operator / ( const Vector2& rhs) const
    {
        return Vector2(
            X / rhs.X,
            Y / rhs.Y);
    }

    inline const Vector2& operator + () const
    {
        return *this;
    }

    inline Vector2 operator - () const
    {
        return Vector2(-X, -Y);
    }

    // overloaded operators to help Vector2
    inline friend Vector2 operator * ( const float fScalar, const Vector2& rkVector )
    {
        return Vector2(
            fScalar * rkVector.X,
            fScalar * rkVector.Y);
    }

    inline friend Vector2 operator / ( const float fScalar, const Vector2& rkVector )
    {
        return Vector2(
            fScalar / rkVector.X,
            fScalar / rkVector.Y);
    }

    inline friend Vector2 operator + (const Vector2& lhs, const float rhs)
    {
        return Vector2(
            lhs.X + rhs,
            lhs.Y + rhs);
    }

    inline friend Vector2 operator + (const float lhs, const Vector2& rhs)
    {
        return Vector2(
            lhs + rhs.X,
            lhs + rhs.Y);
    }

    inline friend Vector2 operator - (const Vector2& lhs, const float rhs)
    {
        return Vector2(
            lhs.X - rhs,
            lhs.Y - rhs);
    }

    inline friend Vector2 operator - (const float lhs, const Vector2& rhs)
    {
        return Vector2(
            lhs - rhs.X,
            lhs - rhs.Y);
    }
    // arithmetic updates
    inline Vector2& operator += ( const Vector2& rkVector )
    {
        X += rkVector.X;
        Y += rkVector.Y;

        return *this;
    }

    inline Vector2& operator += ( const float fScaler )
    {
        X += fScaler;
        Y += fScaler;

        return *this;
    }

    inline Vector2& operator -= ( const Vector2& rkVector )
    {
        X -= rkVector.X;
        Y -= rkVector.Y;

        return *this;
    }

    inline Vector2& operator -= ( const float fScaler )
    {
        X -= fScaler;
        Y -= fScaler;

        return *this;
    }

    inline Vector2& operator *= ( const float fScalar )
    {
        X *= fScalar;
        Y *= fScalar;

        return *this;
    }

    inline Vector2& operator *= ( const Vector2& rkVector )
    {
        X *= rkVector.X;
        Y *= rkVector.Y;

        return *this;
    }

    inline Vector2& operator /= ( const float fScalar )
    {
        X /= fScalar;
        Y /= fScalar;

        return *this;
    }

    inline Vector2& operator /= ( const Vector2& rkVector )
    {
        X /= rkVector.X;
        Y /= rkVector.Y;

        return *this;
    }

	///
	static float fsqrtf(float x)
	{
	   float xhalf = 0.5f * x;
	   int i = *(int*)&x; // store floating-point bits in integer
	   i = 0x5f375a86 - (i >> 1); // initial guess for Newton's method
	   x = *(float*)&i; // convert new bits into float
	   x = x*(1.5f - xhalf*x*x); // One round of Newton's method
	   return 1.0f / x;
	}

	static float fsqrtf2(float x)
	{
	   return sqrt(x);
	}

	///
	static float fcosf(float x)
	{
		return cos(x);
	}
	
	///
	static float fsinf(float x)
	{
		return sin(x);
	}


	// special points
    static const Vector2 ZERO;
	static const Vector2 One;
    static const Vector2 UNIT_X;
    static const Vector2 UNIT_Y;
    static const Vector2 NEGATIVE_UNIT_X;
    static const Vector2 NEGATIVE_UNIT_Y;
    static const Vector2 UNIT_SCALE;

	static void DistanceSquared(Vector2 value1, Vector2 value2, float &result);
	static void Distance(Vector2 value1, Vector2 value2, float &result);
	static float Dot(Vector2 value1, Vector2 value2);
    static void Dot(Vector2 value1, Vector2 value2, float &result);
	float Length();
    float LengthSquared();
	static void Normalize( Vector2 value, Vector2 &result);
};

#endif

