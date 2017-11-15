/*!
     * \file test_vec.cpp
     * \brief Test des methodes de vecteurs
     * \author Ibis Ibrahim
     */

#include <iostream>
#include "vector.h"
#include "array.h"


void testArrayCrochet(){
    Array<int,2> array;
    array[0] = 1;
    array[1] = 2;
    Array<int,2> array1;
    array1[0] = 1;
    array1[1] = 2;
    assert(array[0] == 1);
    assert(array[1] == 2);
    assert(array == array1);

    Array<int, 2> array2;
    array2[0] = 3;
    array2[1] = 4;
    array1.switchArray(array2);
    assert(array == array2);

    Array<int,2> a;
    Array<int,2> b;
    a[0] = 1;
    a[1] = 2;
    b[0] = 2;
    b[1] = 1;
    b.switchArray(a);
    assert(b[1] == 2);
    assert(b[0] == 1);
    std::cout << "Test array ok" << std::endl;
}


void testVector(){
    Vector<int,2> a;
    Vector<int,2> b;
    Vec2i c;

    Vec2f f1;
    Vec2f f2;
    Vec2f f3;

    f1[0] = 1.5;
    f1[1] = 2;
    f2[0] = 2;
    f2[1] = 1;

    f3 = f1 + f2;

    std::cout << "Test vec2f ok " << std::endl;


    c[0] = 0;
    c[1] = 1;
    c[5] = 2;


    std::cout << "Test acces ok"  << std::endl;

    a[0] = 1;
    a[1] = 2;
    b[0] = 2;
    b[1] = 1;

    c = a+b;

    assert(c[0] == 3);
    assert(c[1] == 3);

    std::cout << "Test + ok" << std::endl;

    a[0] = 1;
    a[1] = 2;
    b[0] = 1;
    b[1] = 2;

    c = a-b;

    assert(c[0] == 0);
    assert(c[1] == 0);
    std::cout << "Test - ok" << std::endl;

    a[0] = 1;
    a[1] = 2;
    b[0] = 2;
    b[1] = 1;

    a += b;

    assert(a[0] == 3);
    assert(a[1] == 3);

    std::cout << "Test += ok" << std::endl;

    a[0] = 1;
    a[1] = 2;
    b[0] = 1;
    b[1] = 2;

    a -= b;

    assert(a[0] == 0);
    assert(a[1] == 0);
    std::cout << "Test -= ok" << std::endl;

    a[0] = 1;
    a[1] = 1;
    b[0] = 2;
    b[1] = 2;

    int resultat = a * b;

    assert(resultat == 4);
    std::cout << "Test * ( produit scalaire ) ok" << std::endl;

    a[0] = 1;
    a[1] = 2;


    c = a * 2;

    assert(c[0] == 2);
    assert(c[1] == 4);
    std::cout << "Test * ok" << std::endl;

    a[0] = 1;
    a[1] = 2;


    a *= 2.0;

    assert(a[0] == 2);
    assert(a[1] == 4);
    std::cout << "Test *= ok" << std::endl;

    a[0] = 4;
    a[1] = 2;


    c = a/2;

    assert(c[0] == 2);
    assert(c[1] == 1);

    std::cout << "Test / ok" << std::endl;

    a[0] = 5;
    a[1] = 2;


    a /= 2;

    assert(a[0] == 2);
    assert(a[1] == 1);

    std::cout << "Test /= ok" << std::endl;

    Vector<int,3> z;
    Vector<int,3> y;
    Vector<int,3> res;
    z[0] = 2;
    z[1] = 3;
    z[2] = 4;

    y[0] = 5;
    y[1] = 6;
    y[2] = 7;

    res = z.produit_vectoriel(y);

    assert(res[0] == -3);
    assert(res[1] == 6);
    assert(res[2] == -3);

    std::cout << "Test produit vectoriel ok" << std::endl;

    std::cout << "Test vector OK "<< std::endl;


}


int main()
{

    testArrayCrochet();
    testVector();

    return 0;
}


