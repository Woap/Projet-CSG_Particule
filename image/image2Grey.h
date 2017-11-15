/*!
 * \file Image2Grey.h
 * \brief Définitions classe Image2Grey
 * \author Ibis Ibrahim
 */

#ifndef IMAGE2GREY_H
#define IMAGE2GREY_H


#include "image2d.h"


/**
 * \class Image2Grey
 * \brief Classe des images 2D avec un niveau de gris
 *
 * \protectedsection
 *      \property {T*} pixels_ ( tableau de type unsigned char de pixels )
 *      \property {int} w_ ( largeur )
 *      \property {int} h_ ( hauteur )
 *
 * \publicsection
 *          {void}          save(std::string p) , sauvegarde l'image dans un format pgm
 *          {Image2Grey}    load(std::string p) , lecture et renvoie l'image dans un format pgm
 *
 *          {Image2Grey}    echantillonnage() , division de la taille de l'image par 2
 *          {Image2Grey}    lissage(int n) , lissage de l'image
 *          {Image2Grey}    seuillage(int value) , application d'un seuillage sur l'image
 *          {Image2Grey}    crop(int x1, int y1, int x2, int y2) , crop de l'image
 *          {Vec2f}         gradientSobel() , calcul du gradient
 */
class Image2Grey : public Image2D<unsigned char>
{
protected:
    unsigned char * pixels_;
    int w_;
    int h_;

public:
    Image2Grey() : Image2D<unsigned char>(){}
    Image2Grey(int w, int h) : Image2D<unsigned char>(w,h){}
    ~Image2Grey(){}

    void save(std::string p);
    static Image2Grey load(std::string p);

    Image2Grey echantillonnage();
    Image2Grey lissage(int n);
    Image2Grey seuillage(int value);
    Image2Grey crop(int x1, int y1, int x2, int y2);

    Vec2f gradientSobel();

};

const int Sobel5x[25]={1,2,0,-2,-1,
                       4,8,0,-8,-4,
                       6,12,0,-12,-6,
                       4,8,0,-8,-4,
                       1,2,0,-2,-1};

const int Sobel5y[25]={1, 4, 6, 4, 1,
                       2, 8, 12, 8, 2,
                       0, 0, 0, 0, 0,
                       -2,-8,-12,-8,-2,
                       -1,-4,-6,-4,-1};


#endif



