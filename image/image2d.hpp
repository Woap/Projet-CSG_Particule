/*!
 * \file image2d.hpp
 * \brief Implémentations fonctions Image2D
 * \author Ibis Ibrahim
 */

#ifndef IMAGE2D_HPP
#define IMAGE2D_HPP

#include "../vectorMatrix/vector.h"
#include <iostream>
#include "image2d.h"
#include <algorithm>

template<typename T>
Image2D<T>::Image2D(int w, int h):w_(w),h_(h)
{
    pixels_ = new T[w*h];
}

template<typename T>
Image2D<T>::Image2D()
{

}


template<typename T>
Image2D<T>::~Image2D()
{
    delete[] pixels_;
}

template<typename T>
Image2D<T> Image2D<T>::operator=(const Image2D& a) {
    for(int i=0 ; i< w_ ;i++)
    {
        for(int j=0;j< h_ ;j++)
        {
            (*this)(i,j) = a(i,j);
        }
    }

    return *this;
}

template<typename T>
void Image2D<T>::show() const {
    std::cout << "Weight : " << w_ << " Height : "<< h_  << std::endl;

    for(int i=0 ; i< w_ ;i++)
    {
        for(int j=0;j< h_ ;j++)
        {
            std::cout << (int)(*this)(i,j) << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
int Image2D<T>::get_file_size(std::string filename)
{
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}


template<typename T>
int Image2D<T>::width() const {return w_;}

template<typename T>
int Image2D<T>::height() const {return h_;}

template<typename T>
T* Image2D<T>::data_pix() { return pixels_;}

template<typename T>
T& Image2D<T>::operator ()(int i,int j) { return pixels_[i+j*w_];}

template<typename T>
const T& Image2D<T>::operator ()(int i,int j) const { return pixels_[i+j*w_];}

template<typename T>
void Image2D<T>::swap_pixels(Image2D<T>& im)
{
    assert(im.width()==this->width() && im.height()==this->height());
    std::swap(im.pixels_,this->pixels_);
}

template<typename T>
void Image2D<T>::convol3x3(const double* m)
{
    Image2D<T> im(w_,h_);

    for(int j=1;j<h_-1;j++)
        for(int i=1;i<w_-1;i++)
        {
            double v = 0;
            const double* p = m;
            for(int l=-1;l<2;l++)
                for(int k=-1;k<2;k++)
                    v += (*this)(i+k,j+l)*(*p++);
            im(i,j) = T(v);
        }

    // copie du bord
    for(int j=0;j<h_;j++)
    {
        im(0,j) = (*this)(0,j);
        im(w_-1,j) = (*this)(w_-1,j);
    }

    for(int i=0;i<w_;i++)
    {
        im(i,0) = (*this)(i,0);
        im(i,h_-1) = (*this)(i,h_-1);
    }

    swap_pixels(im);
}



template<typename T>
Image2D<T> Image2D<T>::crop(int x1, int y1, int x2, int y2)
{

    Image2D<T> cropped(x2-x1+1,y2-y1+1);

    for(int i=x1;i<x2+1;i++)
    {
        for(int j=y1;j<y2+1;j++)
        {
            cropped(i-x1,j-y1) = (*this)(i,j);
        }
    }


    return cropped;

}


#endif


