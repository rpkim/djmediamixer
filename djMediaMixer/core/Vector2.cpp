#include "Vector2.h"

const Vector2 Vector2::ZERO( 0, 0);
const Vector2 Vector2::One( 1, 1);

const Vector2 Vector2::UNIT_X( 1, 0);
const Vector2 Vector2::UNIT_Y( 0, 1);
const Vector2 Vector2::NEGATIVE_UNIT_X( -1,  0);
const Vector2 Vector2::NEGATIVE_UNIT_Y(  0, -1);
const Vector2 Vector2::UNIT_SCALE(1, 1);

void Vector2::DistanceSquared(Vector2 value1, Vector2 value2, float &result)
{
    result = (value1.X - value2.X) * (value1.X - value2.X) + (value1.Y - value2.Y) * (value1.Y - value2.Y);
}

void Vector2::Distance(Vector2 value1, Vector2 value2, float &result)
{
    DistanceSquared(value1, value2, result);
	result = fsqrtf(result);
}

float Vector2::Dot(Vector2 value1, Vector2 value2)
{
    return value1.X * value2.X + value1.Y * value2.Y;
}

void Vector2::Dot(Vector2 value1, Vector2 value2, float &result)
{
    result = value1.X * value2.X + value1.Y * value2.Y;
}

float Vector2::Length()
{
	return fsqrtf(X*X + Y*Y);
}

float Vector2::LengthSquared()
{
    return X*X + Y*Y;
}

void Vector2::Normalize( Vector2 value, Vector2 &result)
{
    float factor;
    DistanceSquared(value, ZERO, factor);
    factor = (1.0f / fsqrtf2(factor));
    result.X = value.X * factor;
    result.Y = value.Y * factor;
}