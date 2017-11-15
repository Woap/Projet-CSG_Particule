/*!
 * \file Image2D.h
 * \brief Définitions classe Image2D
 * \author Ibis Ibrahim
 */

#ifndef IMAGE2D_H
#define IMAGE2D_H

#include <string>



/**
 * \class Image2D
 * \brief Template des images 2 D contenant des pixels de type T
 *
 * \protectedsection
 *      \property {T*} pixels_ ( tableau de type T de pixels )
 *      \property {int} w_ ( largeur )
 *      \property {int} h_ ( hauteur )
 *
 * \publicsection
 *       {Image2D}  operator=(const Image2D& a) , assignation d'une image
 *
 *       {int}      width() , recupere la largeur
 *       {int}      height() , recupere la hauteur
 *       {T*}       data_pix() , recupere le pixel
 *       {T&}       operator ()(int i,int j) , surcharge () pour accesseur et assignation d'une valeur
 *       {T&}       operator ()(int i,int j)
 *       {void}     swap_pixels(Image2D<T>& im) , swap les pixels
 *       {void}     convol3x3(const double* m) , convolution avec une matrix 3x3
 *       {void}     convol5x5(const double* m) , convolution avec une matrice 5x5
 *       {void}     show() , affichage le contenu d'une matrice
 *       {int}      get_file_size(std::string filename), recupere la taille du fichier
 *
 *       {Image2D}  crop(int x1,int y1, int x2, int y2), crop et renvoie l'image
 */
template<typename T>
class Image2D
{
protected:
    T* pixels_;
    int w_;
    int h_;

public:
    Image2D(int w, int h);
    Image2D();
    ~Image2D();

    Image2D operator=(const Image2D& a);

    int width() const;
    int height() const;
    T* data_pix();
    T& operator ()(int i,int j);
    const T& operator ()(int i,int j) const;
    void swap_pixels(Image2D<T>& im);
    void convol3x3(const double* m);
    void convol5x5(const double* m);
    void show() const;
    int get_file_size(std::string filename);

    Image2D crop(int x1,int y1, int x2, int y2);

};



#include "image2d.hpp"

#endif // IMAGE2D_H
