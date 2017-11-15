/*!
 * \file Image2RGB.h
 * \brief Définitions classe Image2RGB
 * \author Ibis Ibrahim
 */

#ifndef IMAGE2RGB_H
#define IMAGE2RGB_H


#include "image2d.h"
#include "../vectorMatrix/vector.h"


class Image2RGB : public Image2D<Vec3uc>
{
protected:
    Vec3uc * pixels_;
    int w_;
    int h_;

public:
    Image2RGB() : Image2D<Vec3uc>(){}
    Image2RGB(int w, int h) : Image2D<Vec3uc>(w,h){}
    ~Image2RGB(){}

    void save(std::string p);
    static Image2RGB load(std::string p);

};



#endif



