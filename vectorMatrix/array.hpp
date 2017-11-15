/*!
 * \file Array.hpp
 * \brief Implémentations fonctions Array
 * \author Ibis Ibrahim
 */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "array.h"
#include "assert.h"


template<typename T, int N>
Array<T,N>::Array(){
    for(int i=0; i<N; i++){
        data_[i] = T(0);
    }
}


template<typename T, int N>
Array<T,N> Array<T,N>::operator=(const Array& a) {
    if(this == &a) // éviter l'autoaffectation
    {
        return *this;
    }

    /*if(size != a.size) // éviter une copie aved des tailles différentes
            {
                return *this;
            }*/

    for(int i = 0; i < N; i++)
    {
        data_[i] = a[i];
    }

    return *this;
}

/**
 * @brief   methode qui return l'element d'index donné
 * @return  {T}  element du tableau
 */
template<typename T, int N>
T Array<T,N>::operator[](const int index) const{

    return data_[index];
}


/**
 * @brief   methode qui return l'element d'index donné
 * @return  {T&} adresse de l'element du tableau
 */
template<typename T, int N>
T& Array<T,N>::operator[](const int index){
    return data_[index];
}

/**
 * @brief   methode qui return data
 * @return  {T*}
 */
template<typename T, int N>
const T* Array<T,N>::get_ptr() const{
    return data_;
}

/**
 * @brief   methode qui verifie si le tableau est identique a celui donné
 * @return  {bool}
 */
template<typename T, int N>
bool Array<T,N>::operator==(const Array& tab){

    for (int i=0; i<N; i++)
    {
        if ( tab[i] != this->data_[i] )
            return false;
    }

    return true;
}

/**
 * @brief   methode qui verifie si le tableau est différent a celui donné
 * @return  {bool}
 */
template<typename T, int N>
bool Array<T,N>::operator!=(const Array& tab){

    for (int i=0; i<N; i++)
    {
        if ( tab[i] != this->data_[i] )
            return true;
    }

    return false;
}

/**
 * @brief   methode qui echange avec le tableau donné
 * @return  {bool}, vrai si opération réussi
 */
template<typename T, int N>
bool Array<T,N>::switchArray(Array& tab){

    for(int i=0; i<N; i++)
    {
        T tmp= tab[i];
        T tmp2 = data_[i];
        tab[i] = tmp2;
        data_[i]= tmp;
    }

    // Test

    return true;
}


#endif
