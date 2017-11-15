/*!
     * \file Array.h
     * \brief Définitions classe Array
     * \author Ibis Ibrahim
     */

#ifndef ARRAY_H
#define ARRAY_H


/**
 * \class Array
 * \brief Template de tableau de taille N et de type T
 *
 * \protectedsection
 *      \property {T} data_ ( tableau de type T de taille N )
 *
 * \publicsection
 *      {T}     operator[], methode qui return l'element d'index donné
 *      {T&}    operator[]
 *      {T*}    get_ptr, return data
 *      {Array} operator= , affectation d'un array
 *      {bool}  operator== , verifie si le tableau donné est identique
 *      {bool}  operator!= , verifie si le tableau donné est différent
 *      {bool}  switchArray, echange le contenu de deux tableaux
 */
template <typename T, int N>
class Array
{
protected:
    T data_[N];

public:
    Array();
    const T* get_ptr() const;
    T operator[](const int index) const;
    T& operator[](const int index);
    Array operator=(const Array& a) ;
    bool operator==(const Array& Tab);
    bool operator!=(const Array& Tab);
    bool switchArray(Array& Tab);
};


#include "array.hpp"

#endif // ARRAY_H
