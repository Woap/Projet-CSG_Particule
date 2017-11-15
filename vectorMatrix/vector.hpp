/*!
 * \file Vector.hpp
 * \brief Implémentations fonctions Vector
 * \author Ibis Ibrahim
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector.h"
#include "assert.h"


template<typename T, int N>
Vector<T, N> Vector<T, N>::operator -(Vector<T, N> const& v_right)
{
    Vector* res_p = new Vector<T,N>;
    Vector res = *res_p;
    for(int i= 0; i<N; i++)
        res[i]=  (*this)[i] - v_right[i];
    return res;
}

template<typename T, int N>
Vector<T, N> Vector<T, N>::operator +(Vector<T, N> const& v_right)
{
    Vector* res_p = new Vector<T,N>;
    Vector res = *res_p;
    for(int i= 0; i<N; i++)
        res[i]=  (*this)[i] + v_right[i];
    return res;
}

template <typename T, int N>
Vector<T, N> Vector<T, N>::operator +=(Vector<T, N> const& v_right)
{
    for(int i= 0; i<N; i++)
        (*this)[i]=  (*this)[i] + v_right[i];
    return *this;
}

template <typename T, int N>
Vector<T, N> Vector<T, N>::operator -=(Vector<T, N> const& v_right)
{
    for(int i= 0; i<N; i++)
        (*this)[i]=  (*this)[i] - v_right[i];
    return *this;
}

template <typename T, int N>//Produit scalaire
T Vector<T, N>::operator *(Vector<T, N> const& v_right)
{
    T res = T(0);
    for(int i= 0; i<N; i++)
        res+=  (*this)[i] * v_right[i];
    return res;

}

template <typename T, int N>//Produit scalaire
Vector<T, N> Vector<T, N>::operator *(const T& value)
{

    Vector* res_p = new Vector<T,N>;
    Vector res = *res_p;
    for(int i= 0; i<N; i++)
        res[i]=  (*this)[i] * value;
    return res;
}

template <typename T, int N>//Produit scalaire
Vector<T, N> Vector<T, N>::operator *=(const T& value)
{

    for(int i= 0; i<N; i++)
        (*this)[i]=  (*this)[i] * value;
    return *this;
}

template <typename T, int N>
Vector<T, N> Vector<T, N>::operator /(const T& value)
{

    Vector* res_p = new Vector<T,N>;
    Vector res = *res_p;
    for(int i= 0; i<N; i++)
        res[i]=  (*this)[i] / value;
    return res;
}

template <typename T, int N>//Produit scalaire
Vector<T, N> Vector<T, N>::operator /=(const T& value)
{
    for(int i= 0; i<N; i++)
        (*this)[i]=  (*this)[i] / value;
    return *this;
}

template <typename T, int N>
Vector<T, N> Vector<T, N>::produit_vectoriel(const Vector& v_right)
{
    Vector* res_p = new Vector<T,N>;
    Vector res = *res_p;
    if(N == 3){
        res[0]=(*this)[1]*v_right[2]-(*this)[2]*v_right[1];
        res[1]=(*this)[2]*v_right[0]-(*this)[0]*v_right[2];
        res[2]=(*this)[0]*v_right[1]-(*this)[1]*v_right[0];
    }
    return res;
}

#endif
