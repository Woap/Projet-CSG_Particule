#include "image.h"

template <typename T>

Image<T>::Image(int l, int h)
{
    largeur = l;
    hauteur = h;

    data = new T[l * h];
}

template <typename T>

Image<T>::~Image()
{
    // delete le tableau
}

template <typename T>
// accesseur pour la taille
int Image<T>::getSize()
{
    return largeur * hauteur;
}

template <typename T>
// accesseur pour le pointeur sur les pixels
T Image<T>::getData()
{
    return data;
}
