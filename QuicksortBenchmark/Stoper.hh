#ifndef STOPER_HH_INCLUDED
#define STOPER_HH_INCLUDED
#include <windows.h>
#include <ctime>
#include <fstream>

/*!
 *\file
  *\brief definicje funkcji zliczajacych czas operacji wypelnienia struktur danych
 */

/*!
 *\brief definicja funkcji StartTimer
 *Rozpoczyna pomiar czasu
 *Funkcja pobrana ze strony http://jaroslaw.mierzwa.staff.iiar.pwr.wroc.pl/
 */
LARGE_INTEGER startTimer()
{
LARGE_INTEGER start;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&start);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return start;
}

/*!
 *\brief definicja funkcji endTimer
 *Konczy pomiar czasu
 *Funkcja pobrana ze strony http://jaroslaw.mierzwa.staff.iiar.pwr.wroc.pl/
 */
LARGE_INTEGER endTimer()
{
LARGE_INTEGER stop;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&stop);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return stop;
}

/*!
 *\brief definicja funkcji benchamarkujacej licz
 *funkcja nie przeznaczona dla struktury danych Kolejka
 *\param [obiekt] struktura danych, dla ktorej zostana przeprowadzone obliczenia
 *\param [N] ilosc elementow, ktorymi zostanie wypelniona strukutra danych
 *\return czas wypelnienia struktury danych liczbami pseldolosowymi
 *Funkcja pobrana ze strony http://jaroslaw.mierzwa.staff.iiar.pwr.wroc.pl/
 */
template<typename typ>
double licz(typ obiekt, int N)
{
LARGE_INTEGER performanceCountStart,performanceCountEnd;
performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy'

for(int i=0; i<N; i++)
obiekt->push(rand()%9);

performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu

double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
return tm;
}


/*!
 *\brief definicja funkcji benchamarkujacej licz200
 *Funkcja przeznaczonadla struktury danych stos, dzialajacej
 *przy alokowaniu pamieci razy 200%.
 *Funkcja nie przeznaczona dla struktury danych Kolejka i lista
 *oraz stos dzialajacej w sposub alokowania pamieci o 1 element.
 *\param [obiekt] struktura danych, dla ktorej zostana przeprowadzone obliczenia
 *\param [N] ilosc elementow, ktorymi zostanie wypelniona strukutra danych
 *\return czas wypelnienia struktury danych liczbami pseldolosowymi
 *Funkcja pobrana ze strony http://jaroslaw.mierzwa.staff.iiar.pwr.wroc.pl/
 */
template<typename typ>
double licz200(typ obiekt, int N)
{
LARGE_INTEGER performanceCountStart,performanceCountEnd;
performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy'

for(int i=0; i<N; i++)
obiekt->push200(rand()%9);

performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu

double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
return tm;
}


/*!
 *\brief definicja funkcji liczKol
 *Funkcja Benchmarkujaca przeznaczona tylko dla struktury danych Kolejka
 *Posiada atrybuty takie same jak funkcja licz
 */
template<typename typ>
double liczKol(typ objekt, int N)
{
LARGE_INTEGER performanceCountStart,performanceCountEnd;
performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy'

for(int i=0; i<N; i++)
objekt->enqueue(rand()%9);

performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu

double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
return tm;
}

#endif // STOPER_HH_INCLUDED
