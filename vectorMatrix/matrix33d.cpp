/*!
 * \file Matrix33d.cpp
 * \brief Implémentations fonctions Matrix33d
 * \author Ibis Ibrahim
 */

#include "matrix33d.h"
#include <math.h>
#include <iostream>


Matrix33d::Matrix33d()
{
    for ( int i = 0 ; i < 3 ; i++)
    {
        (*this)[i] = Array<double,3>();
    }
}

Matrix33d::~Matrix33d()
{}

Array<double,3> Matrix33d::operator [](const int i) const
{
    return m_[i];
}

Array<double,3>& Matrix33d::operator [](const int i)
{
    return m_[i];
}

Matrix33d Matrix33d::operator =(const Matrix33d& m2) {
    for(int i = 0; i < 3; i++)
    {
        this->m_[i] = m2.m_[i];
    }

    return *this;
}

std::ostream& operator << (std::ostream& output, const Matrix33d& m1)
{
    output << "(" << m1[0][0] << "," << m1[0][1] << "," << m1[0][2] << ")" << std::endl;
    output << "(" << m1[1][0] << "," << m1[1][1] << "," << m1[1][2] << ")" << std::endl;
    output << "(" << m1[2][0] << "," << m1[2][1] << "," << m1[2][2] << ")" <<  std::endl;
    return output;
}

Matrix33d Matrix33d::inverse()
{

    double det = (*this)[0][0]*(*this)[1][1]*(*this)[2][2] +
            (*this)[0][1]*(*this)[1][2]*(*this)[2][0] +
            (*this)[0][2]*(*this)[1][0]*(*this)[2][1] -
            (*this)[0][2]*(*this)[1][1]*(*this)[2][0] -
            (*this)[0][0]*(*this)[1][2]*(*this)[2][1] -
            (*this)[0][1]*(*this)[1][0]*(*this)[2][2];

    if (det != 0) {
        Matrix33d res;

        res[0][0] =  ((*this)[1][1]*(*this)[2][2] - (*this)[1][2]*(*this)[2][1]) / det;
        res[1][0] = -((*this)[1][0]*(*this)[2][2] - (*this)[2][0]*(*this)[1][2]) / det;
        res[2][0] =  ((*this)[1][0]*(*this)[2][1] - (*this)[2][0]*(*this)[1][1]) / det;

        res[0][1] = -((*this)[0][1]*(*this)[2][2] - (*this)[2][1]*(*this)[0][2]) / det;
        res[1][1] =  ((*this)[0][0]*(*this)[2][2] - (*this)[2][0]*(*this)[0][2]) / det;
        res[2][1] = -((*this)[0][0]*(*this)[2][1] - (*this)[2][0]*(*this)[0][1]) / det;

        res[0][2] =  ((*this)[0][1]*(*this)[1][2] - (*this)[1][1]*(*this)[0][2]) / det;
        res[1][2] = -((*this)[0][0]*(*this)[1][2] - (*this)[1][0]*(*this)[0][2]) / det;
        res[2][2] =  ((*this)[0][0]*(*this)[1][1] - (*this)[1][0]*(*this)[0][1]) / det;

        return res;
    }

    return (*this);

}

Matrix33d Matrix33d::identity()
{
    Matrix33d t;
    t.m_[0][0] = 1;
    t.m_[0][1] = 0;
    t.m_[0][2] = 0;
    t.m_[1][0] = 0;
    t.m_[1][1] = 1;
    t.m_[1][2] = 0;
    t.m_[2][0] = 0;
    t.m_[2][1] = 0;
    t.m_[2][2] = 1;

    return t;
}

Matrix33d Matrix33d::creer_translation(const Vec2f& v)
{
    Matrix33d t;
    t.m_[0][0] = 1;
    t.m_[0][1] = 0;
    t.m_[0][2] = v[0];
    t.m_[1][0] = 0;
    t.m_[1][1] = 1;
    t.m_[1][2] = v[1];
    t.m_[2][0] = 0;
    t.m_[2][1] = 0;
    t.m_[2][2] = 1;

    return t;

}

Matrix33d Matrix33d::creer_translation(const double& x,const double& y)
{
    Matrix33d t;
    t.m_[0][0] = 1;
    t.m_[0][1] = 0;
    t.m_[0][2] = x;
    t.m_[1][0] = 0;
    t.m_[1][1] = 1;
    t.m_[1][2] = y;
    t.m_[2][0] = 0;
    t.m_[2][1] = 0;
    t.m_[2][2] = 1;

    return t;

}

Matrix33d Matrix33d::creer_rotation(double radian)
{
    Matrix33d t;

    t.m_[0][0] = 1;
    t.m_[0][1] = 0;
    t.m_[0][2] = 0;
    t.m_[1][0] = 0;
    t.m_[1][1] = cos(radian);
    t.m_[1][2] = -sin(radian);
    t.m_[2][0] = 0;
    t.m_[2][1] = sin(radian);
    t.m_[2][2] = cos(radian);
    return t;

}

Matrix33d Matrix33d::creer_homothetie(const Vec2f& v)
{
    Matrix33d t;
    t.m_[0][0] = v[0];
    t.m_[0][1] = 0;
    t.m_[0][2] = 0;
    t.m_[1][0] = 0;
    t.m_[1][1] = v[1];
    t.m_[1][2] = 0;
    t.m_[2][0] = 0;
    t.m_[2][1] = 0;
    t.m_[2][2] = 1;

    return t;

}

Matrix33d Matrix33d::creer_homothetie(const double& x,const double& y)
{
    Matrix33d t;
    t.m_[0][0] = x;
    t.m_[0][1] = 0;
    t.m_[0][2] = 0;
    t.m_[1][0] = 0;
    t.m_[1][1] = y;
    t.m_[1][2] = 0;
    t.m_[2][0] = 0;
    t.m_[2][1] = 0;
    t.m_[2][2] = 1;

    return t;

}

Matrix33d  Matrix33d::operator *(const Matrix33d& m2)
{
    Matrix33d t;
    for (int x=0; x<3; ++x)
    {
        for (int y=0; y<3; ++y)
        {
            double sum = 0;
            for (int z=0; z<3; ++z)
                sum += m_[x][z] * m2.m_[z][y];
            t.m_[x][y] = sum;
        }
    }

    return t;

}

Vec3f Matrix33d::operator *(const Vec2f& v)
{
    Vec3f v2;
    v2[0] = v[0];
    v2[1] = v[1];
    v2[2] = 1;

    v2 = (*this)*v2;

    return v2;
}

Vec3f Matrix33d::operator *(const Vec3f& v)
{
    Vec3f v2;
    Vec3f nouv;
    int i;
    for (i = 0; i < 3; i++)
    {
        int j;
        for (j = 0; j < 3; j++)
        {
            nouv[i]+=(*this)[i][j] * v[j];
        }
    }
    return nouv;
}

Matrix33d Matrix33d::translate(const double& x,const double& y)
{
    Matrix33d m2 = Matrix33d::creer_translation(x,y);
    (*this) = (*this)*m2;

    return (*this);

}

Matrix33d Matrix33d::rotate(double radian)
{
    Matrix33d m2 = Matrix33d::creer_rotation(radian);
    (*this) = m2*(*this);

    return (*this);
}

Matrix33d Matrix33d::scale(const double& x,const double& y)
{
    Matrix33d m2 = Matrix33d::creer_homothetie(x,y);
    (*this) = m2*(*this);

    return (*this);

}

Vec3f Matrix33d::applyTransformation(const double& x,const double& y)
{
    Vec2f v;
    v[0] = x;
    v[1] = y;

    return  (*this)*v;
}

