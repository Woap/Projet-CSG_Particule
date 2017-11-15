/*!
 * \file Matrix33d.h
 * \brief Définitions classe Matrix33d
 * \author Ibis Ibrahim
 */

#ifndef MATRIX33D_H
#define MATRIX33D_H

#include <vector.h>
#include <array.h>
#include <initializer_list>
#include <iostream>


/**
 * \class Matrix33d
 * \brief Matrice de taille 3 x 3 de double et implémentations des fonctions pour cette matrice
 *
 * \protectedsection
 *      \property {Array<double,3>} m_ , tableau de 3 Array<double,3>
 *
 * \publicsection
 *      {Array<double,3>}   operator [] , methode qui return l'element d'index donné
 *      {Array<double,3>&}  operator []
 *
 *      {std::ostream&}     operator<< , affichage
 *
 *      {Matrix33d}         operator = , affectation
 *      {Matrix33d}         operator *(const Matrix33d& m2) , surcharge operator multiplication avec une matrice 3x3 et pour des vecteurs
 *      {Vec3f}             operator *(const Vec2f& m2)
 *      {Vec3f}             operator *(const Vec3f& m2)
 *
 *      {Matrix33d}         identity() , methode statique renvoyant la matrice identité
 *      {Matrix33d}         creer_translation(const Vec2f& v) , methode statique renvoyant la matrice translation
 *      {Matrix33d}         creer_translation(const double& x,const double& y)
 *      {Matrix33d}         creer_rotation(double radian) , methode statique renvoyant la matrice de rotation
 *      {Matrix33d}         creer_homothetie(const Vec2f& v) , methode statique renvoyant la matrice d'homotethie
 *      {Matrix33d}         creer_homothetie(const double& x,const double& y)
 *
 *      {Matrix33d}         inverse() , methode permettant d'inverser la matrice
 *      {Matrix33d}         translate(const double& x,const double& y) , methode permettant de deplacer la matrice
 *      {Matrix33d}         rotate(double radian) , methode permettant de faire la rotation de la matrice
 *      {Matrix33d}         scale(const double& x,const double& y) , methode permetant de changer la taille de la matrice
 *      {Vec3f}             applyTransformation(const double& x,const double& y) , methode permettant d'appliquer la transformation a un point
 */
class Matrix33d
{

public:
    Matrix33d() ;
    ~Matrix33d();

    Array<double,3> operator [](const int i) const;
    Array<double,3>& operator [](const int i);

    friend std::ostream& operator<<(std::ostream &output, const Matrix33d &m);

    Matrix33d operator =(const Matrix33d& m2);
    Matrix33d operator *(const Matrix33d& m2);
    Vec3f operator *(const Vec2f& m2);
    Vec3f operator *(const Vec3f& m2);

    static Matrix33d identity();
    static Matrix33d creer_translation(const Vec2f& v);
    static Matrix33d creer_translation(const double& x,const double& y);
    static Matrix33d creer_rotation(double radian);
    static Matrix33d creer_homothetie(const Vec2f& v);
    static Matrix33d creer_homothetie(const double& x,const double& y);

    Matrix33d inverse();
    Matrix33d translate(const double& x,const double& y);
    Matrix33d rotate(double radian);
    Matrix33d scale(const double& x,const double& y);
    Vec3f applyTransformation(const double& x,const double& y);


protected:
    Array<double,3> m_[3];
};




#endif // MATRIX33D_H
