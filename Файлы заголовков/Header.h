#pragma once
#include <tchar.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>

//#include <stdlib.h>



class Matrix
{
protected:
    int mass1[4];
    int mass2[4];
    int mass3[4];
    int masscopy1[4];
    int masscopy2[4];
    int masscopy3[4];
    double Doublecopy1[4];
    double Doublecopy2[4];
    double Doublecopy3[4];                            // исходная матрицы double
    int reshen[3];
    int vecnev[3];
    double m1[4];
    double m2[4];
    double m3[4];
    double resh[3];                           // решение исходной матрицы  
    double resh2[3];
    double pogresh;
    double normvec[3];
    double reshDouble[40];
    double vectorn[3];
    int N;
    int nok;
    int* p1;
    int* p2;

public:
    
    void set();
    void get();
   /* void function13(int c);
    void function12(int c);
    void function23(int c);*/
    void ravno13();
    void ravno12();
    void ravno23();
   // void gauss12(int c);
   // void gauss23(int c);
    void gauss(int c);
    void function(int c);
    void resheniexyz();
    void vectornevyazky();
    void norma();
    void convert( TCHAR *stg);
    void convert2_1(TCHAR* stg);
    void convert2_2(TCHAR* stg);
    void convert2_3(TCHAR* stg);
    void convert_resh(TCHAR* st);
    void resh_double();
    void Gauss();
    void vectornevyazkyDouble(TCHAR st[], TCHAR pog[]);
    void space(int c);
};