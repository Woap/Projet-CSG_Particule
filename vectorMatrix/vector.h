/*!
 * \file Vector.h
 * \brief Définitions classe Vector
 * \author Ibis Ibrahim
 */

#ifndef VECTOR_H
#define VECTOR_H

#include "array.h"

/**
 * \class Vector
 * \brief Template de vecteur de taille N et de type T
 *
 * \publicsection
 *      {Vector}    operator + , surcharge de l'operateur plus pour les vecteurs
 *      {Vector}    operator - , surcharge de l'operateur moins pour les vecteurs
 *      {Vector}    operator +=
 *      {Vector}    operator -=
 *
 *      {Vector}    operator *(const T& value); , surcharge de l'operateur multiplication pour les vecteurs
 *      {T}         operator *(const Vector& v_right);
 *
 *      {Vector}    operator *=
 *
 *      {Vector}    operator /(const T& value); , surcharge de l'operateur division pour les vecteurs
 *      {Vector}    operator /=(const T& value);
 *
 *      {T}         produit_scalaire , methode permettant de faire le produit scalaire ente deux vecteurs
 *      {Vector}    produit_vectoriel , methode permettant de faire le produit vectoriel
 */
template <typename T, int N>
class Vector : public Array<T,N>
{

public:

    Vector operator +(const Vector& v_right);
    Vector operator -(const Vector& v_right);
    Vector operator +=(const Vector& v_right);
    Vector operator -=(const Vector& v_right);

    Vector operator *(const T& value);
    T operator *(const Vector& v_right);

    Vector operator *=(const T& value);

    Vector operator /(const T& value);
    Vector operator /=(const T& value);

    T produit_scalaire(const Vector& v_right);
    Vector produit_vectoriel(const Vector& v_right);

};

using Vec2i=Vector<int,2>;
using Vec3i=Vector<int,3>;
using Vec4i=Vector<int,4>;

using Vec2f=Vector<float,2>;
using Vec3f=Vector<float,3>;
using Vec4f=Vector<float,4>;

using Vec3uc=Vector<unsigned char,3>;



#include "vector.hpp"

#endif // ARRAY_H
