#ifndef STOS_HH_INCLUDED
#define STOS_HH_INCLUDED

#include <windows.h>
#include <fstream>
#include <iostream>

/*!
 *\file
 *\brief definicja struktruy danych Stos
 */

/*!
 *\brief definicja klasy Stos
 * zedfiniowany za pomoca tablicy.
 * Klasa zbudowana na szablonie.
 */
template<typename typ>
class Stos {
int rozmiar; /*! rozmiar stosu */
int licznik;  /*! ilosc zapisanych danych na stosie */
typ *tab;    /*! alokowana pamiec */
public:
    Stos();
    ~Stos();
    void push(typ element);
    void push200(typ element);
    typ pop();
    int size()const;
    int size_licznik()const;
    typ* getTab();
};

template<typename typ>
typ* Stos<typ>::getTab()
{
    return tab;
}

/*!
 *\brief definicja konstruktora bezparametrycznego
 *zeruje rozmiar, przypisuje NULL do wskaznikow.
 */
template<typename typ>
Stos<typ>::Stos()
{
    rozmiar=1;
    licznik=0;
    tab=NULL;
}

/*!
 *\brief definicja destruktora
 * Zwalnia pamiec, zeruje rozmiar.
 */
template<typename typ>
Stos<typ>::~Stos()
{
    delete [] tab;
    rozmiar=0;
    licznik=rozmiar;
}

/*!
 *\brief definicja metody push
 *\param [element] dodany element na koniec stosu
 *zwieksza licznik o 1, alokuje nowa tablice, kopiuje zawartosc
 *starej do nowej, kladzie element na ostatniej pozycji,
 *realokuje  i przekopiowuje zawartosc do pierwotenj tablicy,
 *usuwa tablice pomocnicza.
 */
template<typename typ>
void Stos<typ>::push(typ element)
{
    ++licznik;
    typ *tmp=new typ[licznik];
    memcpy(tmp,tab,sizeof(typ)*(licznik-1));
    tmp[licznik-1]=element;
    delete [] tab;
    tab=new typ[licznik];
    memcpy(tab,tmp,sizeof(typ)*size());
    delete [] tmp;
    rozmiar=licznik;
}


/*!
 *\brief definicja metody push200
 *\param [element] dodawany element na koniec stosu
 *zwieksza rozmiar razy 200%, dodaje element na stos
 *zwieksza licznik ilosci elementow
 *realokuje i przekopiowywyje wartosci tablic
 */
template<typename typ>
void Stos<typ>::push200(typ element)
{
   if(licznik==rozmiar-1)
    {
        rozmiar=rozmiar*2;
        ++licznik;
        typ *tmp=new typ[rozmiar];
        memcpy(tmp,tab,sizeof(typ)*(licznik-1));
        tmp[licznik-1]=element;
        delete [] tab;
        tab=new typ[rozmiar];
        memcpy(tab,tmp,sizeof(typ)*(licznik));
        delete [] tmp;
    } else {
    tab[licznik]=element;
    ++licznik;
    }
}
/*!
 *\brief definicja metody pop
 *zmmniejsza licznik elementow o 1,
 *jesli licznik jest mniejszy od rozmiary akolkowanej pamieci 25%
 *rozmiar jest zmniejszany o te 25%
 *\return usuwany element
 *\return 0 i wyswietla komunikat, kiedy stos jest pusty.
 */
template<typename typ>
typ Stos<typ>::pop()
{
    if(licznik==0)
    {
        std::cout << "Stos jest pusty." << std::endl;
        return 0;
    } else {
    typ tmp;
    tmp=tab[licznik-1];
    licznik--;
    if(licznik<=(1/4)*rozmiar)
        rozmiar/=4;
    return tmp;
    }
}

/*!
 *\brief definicja metody size
 *\return rozmiar stosu
 */
template<typename typ>
int Stos<typ>::size()const
{
    return rozmiar;
}

/*!
 *\brief definicja metody size_licznik
 *\return licznik elementow na stosie
 */
template<typename typ>
int Stos<typ>::size_licznik()const
{
    return licznik;
}


#endif // STOS_HH_INCLUDED
