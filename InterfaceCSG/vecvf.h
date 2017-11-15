#include "array.h"
#include "vec2.h"

#ifndef VECVF_H
#define VECVF_H

//Dériver Array en Vector (toujours template):
//• opérateurs entre vecteurs: + - += -=
//• opérateurs avec un scalaire * / *= /=
//• Comment faire pour pouvoir écrire V = 0.5f * V ?
//• produit scalaire (*)
//• définir le produit vectoriel pour les dimensions ou il est calculable

// Définir les types VecDT pour D : 2,3,4 et T :int,float
//§§using Vec2i=Vector<2,int>;

// static fonction matrix
// translation identite + tx ty a droite
//  id (rotation) j'enleve derniere ligne et colonne
// id et remplace hx hy

// composition -> overload multipli

//Vec2i nouveau = Ve2i();

class VecVf: public Vec2<float>
{
protected:
    Array<float,2> vitesse_;

public:
    inline VecVf()
    {
        float dx = float(std::rand())/RAND_MAX;
        float dy = float(std::rand())/RAND_MAX;
        vitesse_[0]=(dx-0.5f) / 50;
        vitesse_[1]=(dy-0.5f) / 50;
    }

    inline void avance(float Ox=0, float Oy=0)
    {
        data_[0] += vitesse_[0];
        data_[1] += vitesse_[1];

        if (norm()>1.414f)
        {
            data_[0] = Ox;
            data_[1] = Oy;
        }
    }
};

#endif // VECVF_H
