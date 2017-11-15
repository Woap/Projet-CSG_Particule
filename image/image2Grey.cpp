/*!
 * \file image2Grey.cpp
 * \brief Implémentations fonctions Image2Grey
 * \author Ibis Ibrahim
 */

#include "image2Grey.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;


void Image2Grey::save(std::string p)
{
    std::ofstream file(p,std::ios::out
                       |std::ios::binary
                       |std::ios::trunc
                       );

    int gray = -1;
    for(int i=0 ; i< width() ;i++)
    {
        for(int j=0;j< height() ;j++)
        {
            if( (*this)(i,j) > gray)
                gray = (*this)(i,j);
        }
    }

    if (file)
    {
        cout << "Sauvegarde de l'image " << p << endl;
        file << "P2" << endl;
        file << "# Sauvegarde de l'image "<< p << endl;
        file << width() << " " << height() << endl;
        file << gray << endl;
        for(int i=0 ; i< width() ;i++)
        {
            for(int j=0;j< height() ;j++)
            {
                file << (int)(*this)(i,j) << " ";
            }
        }
        file << endl;

        file.close();
    }
    else

        cout << "Erreur sauvegarde" << endl;



}

Image2Grey Image2Grey::load(std::string p)
{

    cout << "Chargement de l'image "<< p << endl;
    int row = 0, col = 0, numrows = 0, numcols = 0, grey = 0;
    ifstream infile(p);
    stringstream ss;
    string inputLine = "";

    getline(infile,inputLine);
    if(inputLine.compare("P2") != 0) cerr << "Version error" << endl;

    getline(infile,inputLine);

    ss << infile.rdbuf();
    ss >> numcols >> numrows >> grey;

    int nb;
    Image2Grey image(numrows,numcols);

    for(row = 0; row < numrows; ++row)
    {
        for (col = 0; col < numcols; ++col)
        {
            ss >> nb;
            image(row,col) = nb;
        }
    }



    infile.close();

    return image;

}

Image2Grey Image2Grey::echantillonnage(){

    int width = (*this).width() / 2;
    int height = (*this).height()/ 2;

    if(width % 2 != 0)
        width--;

    if(height % 2 != 0)
        height--;
     std::cout << "Taille image : " << height << "x" << width << std::endl;
    Image2Grey nouveau = Image2Grey(width, height);


    for(int i = 0; i < (*this).width(); i +=2)
    {
        for(int j = 0; j < (*this).height(); j +=2)
        {
            nouveau(i/2,j/2) = (*this)(i, j);
        }
    }

    return nouveau;

}

Image2Grey Image2Grey::lissage(int n){
    int width = (*this).width();
    int height = (*this).height();

    Image2Grey liss = Image2Grey(height, width);


    if(n > 10 || n > width || n > height){
        return liss;
    }

    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            int moyenne = 0;

            for(int x = std::max(0, i - n); x < std::min(i + n, height); x++){
                for(int y = std::max(0, j - n); y < std::min(j + n, width); y++){
                    moyenne += (*this)(x, y);
                }
            }

            moyenne /= std::pow(2*n + 1, 2);

            liss(i, j) = (unsigned char)moyenne;
        }
    }

    return liss;

}

Image2Grey Image2Grey::seuillage(int value)
{
    Image2Grey nouveau(height(),width());
    for ( int i =0 ; i < width(); i++)
    {
        for( int j=0; j<height(); j++)
        {
            if ( (*this)(i,j) >= value )
            {
                nouveau(i,j)=255;
            }
            else
            {
                nouveau(i,j)=0;
            }
        }
    }

    return nouveau;
}

Vec2f Image2Grey::gradientSobel()
{

    //x = (*this).convol5x5(m, mSobelX);
    //y = (*this).convol5x5(m, mSobelY);
    Vec2f a;
    a[0] = 0;
    a[1] = 0;

    return a;

}

Image2Grey Image2Grey::crop(int x1, int y1, int x2, int y2)
{

    Image2Grey cropped(x2-x1+1,y2-y1+1);

    for(int i=x1;i<x2+1;i++)
    {
        for(int j=y1;j<y2+1;j++)
        {
            cropped(i-x1,j-y1) = (*this)(i,j);
        }
    }


    return cropped;

}
