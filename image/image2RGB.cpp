/*!
 * \file image2RGB.cpp
 * \brief Implémentations fonctions Image2RGB
 * \author Ibis Ibrahim
 */

#include "image2RGB.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;


void Image2RGB::save(std::string p)
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
            for ( int k = 0 ; k < 2 ; k++)
            {
            if( (*this)(i,j)[k] > gray)
                gray = (*this)(i,j)[k];
            }
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
                for ( int k = 0 ; k < 2 ; k++)
                {
                file << (int)(*this)(i,j)[k] << " ";
                }

            }
        }
        file << endl;

        file.close();
    }
    else

        cout << "Erreur sauvegarde" << endl;

}

Image2RGB Image2RGB::load(std::string p)
{

    cout << "Chargement de l'image "<< p << endl;
    int row = 0, col = 0, numrows = 0, numcols = 0, grey = 0;
    ifstream infile(p);
    stringstream ss;
    string inputLine = "";

    getline(infile,inputLine);
    if(inputLine.compare("P3") != 0) cerr << "Version error" << endl;

    getline(infile,inputLine);

    ss << infile.rdbuf();
    ss >> numcols >> numrows >> grey;

    int nb;
    Image2RGB image(numrows,numcols);

    for(row = 0; row < numrows; ++row)
    {
        for (col = 0; col < numcols; ++col)
        {
            for ( int k = 0 ; k < 2 ; k++)
            {
                ss >> nb;
                image(row,col)[k] = nb;
            }

        }
    }

    infile.close();

    return image;

}

