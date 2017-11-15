/*!
     * \file testMattrix.cpp
     * \brief Test des methodes de matrix33d
     * \author Ibis Ibrahim
     */

#include <iostream>
#include "matrix33d.h"


void testMatrix(){
    Matrix33d m = Matrix33d();
    m[0][0] = 2;
    m[0][1] = 5;
    m[0][2] = 8;
    m[1][0] = 4;
    m[1][1] = 6;
    m[1][2] = 8;
    m[2][0] = 7;
    m[2][1] = 2;
    m[2][2] = 5;

    Matrix33d m2 = m.inverse();
    std::cout << "test inverse ok "<<  std::endl;

    Matrix33d m3 = m * m2;

    assert(m3[0][0] == 1);
    assert(m3[0][1] == 0);
    assert(m3[0][2] == 0);
    assert(m3[1][0] == 0);
    assert(m3[1][1] == 1);
    assert(m3[1][2] == 0);
    assert(m3[2][0] == 0);
    assert(m3[2][1] == 0);
    assert(m3[2][2] == 1);

    std::cout << "Matrix ok "<<  std::endl;

}

int main()
{

    Matrix33d m1 = Matrix33d::identity();
    std::cout << "test identity ok "<<  std::endl;

    std::cout << "translate(3.5f,2.4f) "<<  std::endl;
    m1.translate(3.5f,2.4f);
    std::cout << "test translate ok "<<  std::endl;

    std::cout << m1 <<  std::endl;

    double x = 0.0;
    double y = 0.0;

    Vec3f v = m1.applyTransformation(x,y);
    std::cout << "0,0 => "<< v[0] << "," << v[1] << std::endl;
    std::cout << "test transformation ok "<<  std::endl;

    m1.rotate(0.4);
    std::cout << "test rotate ok "<<  std::endl;

    Matrix33d m2 = m1.inverse();

    std::cout << m1 << std::endl<<"*"<< std::endl<<m2<< "=" << std::endl<< m1*m2 << std::endl;

    testMatrix();


    return 0;
}
