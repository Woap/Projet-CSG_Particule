#ifndef IMAGE_H
#define IMAGE_H

template <typename T>
class Image
{
public:
    Image(int l, int h);
    ~Image();

protected:
    int largeur;
    int hauteur;
    T * data;
    int getSize();
    T getData();
//    T operator ()(int i, int j) {return data[calcul incroyable ici pour trouver i j];}

private: // pour interdire la copie
    Image(Image const &);// pas de définition !
    Image& operator=(Image const &);// pas de définition !
};

#endif // IMAGE_H
