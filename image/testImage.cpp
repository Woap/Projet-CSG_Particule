/*!
     * \file testImage.cpp
     * \brief Test des methodes des images
     * \author Ibis Ibrahim
     */


#include <iostream>
#include "image2d.h"
#include "image2Grey.h"
#include "image2RGB.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

void testImage(){
    

    Image2Grey image(10,10);

    image(0, 0) = 10;
    image(0, 1) = 11;
    image(1, 0) = 12;
    image(1, 1) = 13;

    std::cout << "Crop image"  << std::endl;

    Image2Grey image2 = image.crop(0,0,2,2);

    assert(image2(0, 0) == 10);
    assert(image2(0, 1) == 11);
    assert(image2(1, 0) == 12);
    assert(image2(1, 1) == 13);

    Image2Grey imageGrey(10,10);

    Image2Grey charger = Image2Grey::load("lena.pgm");

    std::cout << "Seuillage"  << std::endl;
    Image2Grey seuil2 = charger.seuillage(120);
    seuil2.save("seuil.pgm");

    std::cout << "Echantillonnage"  << std::endl;
    Image2Grey scale = charger.echantillonnage();
    scale.save("scale.pgm");

    std::cout << "Lissage"  << std::endl;
    Image2Grey liss = charger.lissage(5);
    liss.save("lissage.pgm");


}

int main()
{

    testImage();
    return 0;
}
