#include <cmath>

#ifndef VEC2_H
#define VEC2_H

template <typename T>
class Vec2 : public Array<T,2>
{
public:
    T norm() const;
};


template <typename T>

T scalaire(const Vec2<T>& v1, const Vec2<T>& v2)
{
    return v1[0]*v2[0]+v1[1]*v2[1];
}

template <typename T>
T Vec2<T>::norm() const
{
    return std::sqrt(scalaire(*this, *this));
}

#endif // VEC2_H
