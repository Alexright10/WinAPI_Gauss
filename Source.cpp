#include "Header.h"
#pragma warning(suppress : 4996);

using namespace std;

extern TCHAR str1[200];
extern TCHAR str2[200];
extern TCHAR str3[200];
extern TCHAR str4[100];
extern TCHAR vectrresh[15];
extern TCHAR vyvodnevyaz[30];
extern TCHAR normvecnev[100];
extern TCHAR vecnevDouble[100];
extern TCHAR pog[100];
extern TCHAR Gaussvec[30];
extern HWND hWnd;

void Matrix::set()
{
	N = 4;
	mass1[0] = 1; mass1[1] = -2; mass1[2] = 3; mass1[3] = 2;
	mass2[0] = 4; mass2[1] = -1; mass2[2] = 5; mass2[3] = 15;
	mass3[0] = 6; mass3[1] = -8; mass3[2] = 7; mass3[3] = 9;
	m1[0] = 6.4;  m2[0] = 4.4;  m3[0] = 1.0;
	m1[1] = -8.3; m2[1] = -1.0; m3[1] = -2.3;
	m1[2] = 7.1;  m2[2] = 5.4;  m3[2] = 3.0;
	m1[3] = 9.0;  m2[3] = 15.0; m3[3] = 2.5;

	for (int i = 0; i < N; ++i)                                              // сохранение матрицы
	{
		masscopy1[i] = mass1[i];
		masscopy2[i] = mass2[i];
		masscopy3[i] = mass3[i];
	}
	for (int i = 0; i < N; ++i)                                              // сохранение матрицы
	{
		Doublecopy1[i] = m1[i];
		Doublecopy2[i] = m2[i];
		Doublecopy3[i] = m3[i];
	}
}

void Matrix::get()
{
	TCHAR der1[100];
	
	for (int i = 0; i < N; ++i) 
	{
		//mass1[i] < 0 ? wcscat_s(str1, _T("-")) : wcscat_s(str1, _T(" "));            // закидываем mass в str для вывода по TextOut()
		_itow_s(mass1[i], der1, 10);
		wcscat_s(str1, der1);
		wcscat_s(str1, _T("  "));
	}
	wcscat_s(str1, _T("    "));
	/*_itow_s(mass2[0], der1, 10);
	wcscat_s(str2, der1);
	_itow_s(mass2[1], der1, 10);
	wcscat_s(str2, der1);*/
	for (int i = 0; i < N; ++i)
	{
	//	mass2[i] < 0 ? wcscat_s(str2, _T("-")) : wcscat_s(str2, _T(" "));
		_itow_s(mass2[i], der1, 10);
		wcscat_s(str2, der1);
		wcscat_s(str2, _T("  "));
	}
	wcscat_s(str2, _T("    "));
	for (int i = 0; i < N; ++i)
	{
	//	mass3[i] < 0 ? wcscat_s(str3, _T("-")) : wcscat_s(str3, _T(" "));
		_itow_s(mass3[i], der1, 10);
		wcscat_s(str3, der1);
		wcscat_s(str3, _T("  "));
	}
	wcscat_s(str3, _T("    "));
	//_tcscat(str1,der);
    //wcscat_s(str1, _itot(mass1[0], der ,10));
	InvalidateRect(hWnd, NULL, TRUE);


}

//void Matrix::function13(int c)
//{
//	TCHAR ser[5] = _T(" ");
//	int fal;
//	//int teg = mass1[c] ;
//	/*_itow_s(teg, ser, 10);
//	MessageBox(NULL, ser, _T("TEST"), MB_OK);*/
//	(abs(mass1[c]) - abs(mass3[c])) < 0 ? fal = abs(mass3[c]) : fal = abs(mass1[c]);
//	int con = fal;
//
//	while (con % mass1[c] || con % mass3[c])
//	{
//		con += fal;
//	}
//	nok = con;
//	_itow_s(nok, ser, 10);
//	MessageBox(NULL, ser, _T("TEST1"), MB_OK);
//	if (mass1[c] == 1 || mass3[c] > 0 || mass1[c] > 0)
//	{
//		for (int i = 0; i < N; ++i)
//			mass1[i] *= nok;
//	}
//	TCHAR der[10];
//	TCHAR buf[10] = _T(" ");
//	for (int i = 0; i < N; ++i)
//	{
//		_itow_s(mass1[i], der, 10);
//		wcscat_s(str1, der);
//	}
//	
//}
//
//void Matrix::function12(int c)
//{
//	TCHAR ser[5] = _T(" ");
//	int fal;
//	//int teg = mass1[c] ;
//	/*_itow_s(teg, ser, 10);
//	MessageBox(NULL, ser, _T("TEST"), MB_OK);*/
//	(abs(mass1[c]) - abs(mass2[c])) < 0 ? fal = abs(mass2[c]) : fal = abs(mass1[c]);
//	int con = fal;
//
//	while (con % mass1[c] || con % mass2[c])
//	{
//		con += fal;
//	}
//	nok = con;
//	_itow_s(nok, ser, 10);
//	MessageBox(NULL, ser, _T("TEST2"), MB_OK);
//
//}
//void Matrix::function23(int c)
//{
//	TCHAR ser[5] = _T(" ");
//	int fal;
//	//int teg = mass1[c] ;
//	/*_itow_s(teg, ser, 10);
//	MessageBox(NULL, ser, _T("TEST"), MB_OK);*/
//	(abs(mass2[c]) - abs(mass3[c])) < 0 ? fal = abs(mass3[c]) : fal = abs(mass2[c]);
//	int con = fal;
//
//	while (con % mass2[c] || con % mass3[c])
//	{
//		con += fal;
//	}
//	nok = con;
//	_itow_s(nok, ser, 10);
//	MessageBox(NULL, ser, _T("TEST3"), MB_OK);
//
//}
void Matrix::ravno13()
{
	p1 = mass1;
	p2 = mass3;
}
void Matrix::ravno12()
{
	p1 = mass1;
	p2 = mass2;
}
void Matrix::ravno23()
{
	p1 = mass2;
	p2 = mass3;
}
void Matrix::function(int c)                              // nok
{
	TCHAR ser[5] = _T(" ");
	int fal;
	(abs(*( p1 + c)) - abs(*(p2+c))) < 0 ? fal = abs(*(p2 + c)) : fal = abs(*(p1 + c));
	int con = fal;

	while (con % *(p1 + c) || con % *(p2 + c))
	{
		con += fal;
	}
	nok = con;
	_itow_s(nok, ser, 10);
	MessageBox(NULL, ser, _T("TEST1"), MB_OK);
	


}
//void Matrix::gauss12(int c)
//{
//	int kof1;
//	int kof2;
//	kof1 = nok / (*(p1 + c));
//	kof2 = nok / (*(p2 + c));
//	for (int i = 0; i < N; ++i)
//		*(p2 + c) = *(p2 + c) * kof2 - *(p1 + c)*kof1;
//
//}
//void Matrix::gauss23(int c)
//{
//	int kof1;
//	int kof2;
//	kof1 = nok / (*(p1 + c));
//	kof2 = nok / (*(p2 + c));
//	for (int i = 0; i < N; ++i)
//		*(p2 + c) = *(p2 + c) * kof2 - *(p1 + c) * kof1;
//
//}
void Matrix::gauss(int c)
{
	int kof1;
	int kof2;
	kof1 = nok / (*(p1 + c));
	kof2 = nok / (*(p2 + c));
	for (int i = 0; i < N; ++i)
		*(p2 + i) = ( * (p2 + i)) * kof2 - (*(p1 + i)) * kof1;

}
void Matrix::resheniexyz()
{
	TCHAR resh[40] = _T(" ");
	int x, y, z;
	z = p2[3] / p2[2];
	y = (p1[3] - z * p1[2])/p1[1];
	x = mass1[3] - y*mass1[1] - z*mass1[2];
	reshen[0] = x;
	reshen[1] = y;
	reshen[2] = z;

	_itow_s(x, resh, 10);
	wcscat_s(vectrresh, resh);
	wcscat_s(vectrresh, _T(" "));
	_itow_s(y, resh, 10);
	wcscat_s(vectrresh, resh);
	wcscat_s(vectrresh, _T(" "));
	_itow_s(z, resh, 10);
	wcscat_s(vectrresh, resh);

	

	InvalidateRect(hWnd, NULL, TRUE);
}
void Matrix::vectornevyazky()
{
	TCHAR vecnevyazk[30] = _T(" ");
	int x = 0 , y =0, z = 0, n;
	
	for (int i = 0; i < 3; ++i)
	{
		n = masscopy1[i] * reshen[i];
		x += n;
	}
	for (int i = 0; i < 3; ++i)
	{
		n = masscopy2[i] * reshen[i];
		y += n;
	}
	for (int i = 0; i < 3; ++i)
	{
		n = masscopy3[i] * reshen[i];
		z += n;
	}
	vecnev[0] = x - masscopy1[3] ;
	vecnev[1] = y - masscopy2[3];
	vecnev[2] = z - masscopy3[3];

	//vecnev[0] = x;
	//vecnev[1] = y;                                                       // сохраним в int массив 
	//vecnev[2] = z;
	
	
	_itow_s(vecnev[0], vecnevyazk, 10);
	wcscat_s(vyvodnevyaz, vecnevyazk);
	wcscat_s(vyvodnevyaz, _T(" "));
	_itow_s(vecnev[1], vecnevyazk, 10);
	wcscat_s(vyvodnevyaz, vecnevyazk);
	wcscat_s(vyvodnevyaz, _T(" "));
	_itow_s(vecnev[2], vecnevyazk, 10);
	wcscat_s(vyvodnevyaz, vecnevyazk);

	InvalidateRect(hWnd, NULL, TRUE);
}
void Matrix::norma()
{
	TCHAR normvector[30] = _T(" ");
	double length = 1  , n ;
	for (int i = 0; i < 3; ++i)
	{
		n = vecnev[i] * vecnev[i];
		length += n;
	}

	length = sqrt(length);
	for (int i = 0; i < 3; ++i)
		normvec[i] =(double)( vecnev[i] / length);

	/*_itow_s(normvec[0], normvector, 10);
	wcscat_s(normvecnev, normvector);
	wcscat_s(normvecnev, _T(" "));
	_itow_s(normvec[1], normvector, 10);
	wcscat_s(normvecnev, normvector);
	wcscat_s(normvecnev, _T(" "));
	_itow_s(normvec[2], normvector, 10);
	wcscat_s(normvecnev, normvector);*/



	//InvalidateRect(hWnd, NULL, TRUE);
}
void Matrix::convert(TCHAR st[])
{

	TCHAR s[30] = _T(" ");
	TCHAR stt[30] = _T(" ");
	int n;
	double d;
	
	for (int j = 0; j < 3; ++j)
	{
		d = normvec[j];
		n = (int)d;
		_itow_s(n, s, 10);
		wcscat_s(stt, s);
		wcscat_s(stt, _T("."));                       // заносит в stt целую часть исходной координаты 
		d -= n;
		for (int i = 0; i < 5; ++i)
		{
			d *= 10;
			n = (int)d;                                     // заносит дробную часть числа в stt 
			_itow_s(n, s, 10);
			wcscat_s(stt, s);
			d -= n;
		}
		for (int i = 0; i < _tcsclen(stt); ++i)
			st[i] = stt[i];
		wcscat_s(stt, _T("  "));
	}

	
	//InvalidateRect(hWnd, NULL, TRUE);
	
}
void Matrix::convert2_1(TCHAR st[])
{

	TCHAR s[40] = _T(" ");
	TCHAR stt[100] = _T(" ");
	int n;
	double d;

	for (int j = 0; j < 4; ++j)
	{
		d = m1[j];
		d < 0 ? wcscat_s(stt, _T("-")) : wcscat_s(stt, _T(" "));
		d = abs(d);
		n = (int)d;
		_itow_s(n, s, 10);
		wcscat_s(stt, s);
		wcscat_s(stt, _T("."));                       // заносит в stt целую часть исходной координаты 
		d = abs(d - n);
		for (int i = 0; i < 5; ++i)
		{
			d *= 10;
			n = (int)d;                                     // заносит дробную часть числа в stt 
			_itow_s(n, s, 10);
			wcscat_s(stt, s);
			d = d - n;
		}
		for (int i = 0; i < _tcsclen(stt); ++i)
			st[i] = stt[i];
		wcscat_s(stt, _T("  "));
	}


	//InvalidateRect(hWnd, NULL, TRUE);

}
void Matrix::convert2_2(TCHAR st[])
{

	TCHAR s[30] = _T(" ");
	TCHAR stt[100] = _T(" ");
	int n;
	double d;

	for (int j = 0; j < 4; ++j)
	{
		d = m2[j];
		d < 0 ? wcscat_s(stt, _T("-")) : wcscat_s(stt, _T(" "));
		d = abs(d);
		n = (int)d;
		_itow_s(n, s, 10);
		wcscat_s(stt, s);
		wcscat_s(stt, _T("."));                       // заносит в stt целую часть исходной координаты 
		d = abs(d - n);
		for (int i = 0; i < 5; ++i)
		{
			d *= 10;
			n = (int)d;                                     // заносит дробную часть числа в stt 
			_itow_s(n, s, 10);
			wcscat_s(stt, s);
			d -= n;
		}
		for (int i = 0; i < _tcsclen(stt); ++i)
			st[i] = stt[i];
		wcscat_s(stt, _T("  "));
	}


	//InvalidateRect(hWnd, NULL, TRUE);

}
void Matrix::convert2_3(TCHAR st[])
{

	TCHAR s[30] = _T(" ");
	TCHAR stt[100] = _T(" ");
	int n;
	double d;

	for (int j = 0; j < 4; ++j)
	{
		d = m3[j];
		d < 0 ? wcscat_s(stt, _T("-")) : wcscat_s(stt, _T(" "));
		d = abs(d);
		n = (int)d;
		_itow_s(n, s, 10);
		wcscat_s(stt, s);
		wcscat_s(stt, _T("."));                       // заносит в stt целую часть исходной координаты 
		d = abs(d - n);
		for (int i = 0; i < 5; ++i)
		{
			d *= 10;
			n = (int)d;                                     // заносит дробную часть числа в stt 
			_itow_s(n, s, 10);
			wcscat_s(stt, s);
			d -= n;
		}
		for (int i = 0; i < _tcsclen(stt); ++i)
			st[i] = stt[i];
		wcscat_s(stt, _T("  "));
	}


	//InvalidateRect(hWnd, NULL, TRUE);

}
void Matrix::convert_resh(TCHAR st[])
{

	TCHAR s[30] = _T(" ");
	TCHAR stt[100] = _T(" ");
	int n;
	double d;

	for (int j = 0; j < 3; ++j)
	{
		d = resh[j];
		d < 0 ? wcscat_s(stt, _T("-")) : wcscat_s(stt, _T(" "));
		d = abs(d);
		n = (int)d;
		_itow_s(n, s, 10);
		wcscat_s(stt, s);
		wcscat_s(stt, _T("."));                       // заносит в stt целую часть исходной координаты 
		d = abs(d - n);
		for (int i = 0; i < 5; ++i)
		{
			d *= 10;
			n = (int)d;                                     // заносит дробную часть числа в stt 
			_itow_s(n, s, 10);
			wcscat_s(stt, s);
			d =  abs(d - n);
		}
		for (int i = 0; i < _tcsclen(stt); ++i)
			st[i] = stt[i];
		wcscat_s(stt, _T("  "));

		for (int i = 0; i < _tcsclen(stt); ++i)
			reshDouble[i] = stt[i];

	}


	//InvalidateRect(hWnd, NULL, TRUE);

}
void Matrix::resh_double()
{
	resh[2] = m3[3] / m3[2];
	resh[1] = (m2[3] - resh[2] * m2[2]) / m2[1];
	resh[0] = (m1[3] - resh[1] * m1[1] - resh[2] * m1[2]) / m1[0];
	

}
void Matrix::Gauss()
{
	TCHAR Buffer[30] = _T(" ");

	double k21 = m2[0] / m1[0];
	double k31 = m3[0] / m1[0];
	for (int i = 0; i < 4; ++i)
	{
		m2[i] = m2[i] - k21 * m1[i];
		m3[i] = m3[i] - k31 * m1[i];
	}
	double k32 = m3[1] / m2[1];
	for (int i = 0; i < 4; ++i)
		m3[i] = m3[i] - k32 * m2[i];

	
}
void Matrix::vectornevyazkyDouble(TCHAR st[], TCHAR pog[])
{
	TCHAR s[30] = _T(" ");
	TCHAR stt[100] = _T(" ");
	TCHAR STTR[100] = _T(" ");
	
	TCHAR vecnevyazky[30] = _T(" ");
	double d;
	double x = 0, y = 0, z = 0, n;
	resh2[0] = 1.97;
	resh2[1] = 1.70;
	resh2[2] = 1.48;


	for (int i = 0; i < 3; ++i)
	{
		n = Doublecopy1[i] * resh2[i];
		x += n;
	}
	for (int i = 0; i < 3; ++i)
	{
		n = Doublecopy2[i] * resh2[i];
		y += n;
	}
	for (int i = 0; i < 3; ++i)
	{
		n = Doublecopy3[i] * resh2[i];
		z += n;
	}
	vectorn[0] = x - Doublecopy1[3];
	vectorn[1] = y - Doublecopy2[3];
	vectorn[2] = z - Doublecopy3[3];
	double x1, y1, z1;
	
	x1 = (resh2[0] - resh[0]);
	y1 = resh2[1] - resh[1];
	z1 = resh2[2] - resh[2];
	pogresh = (x1 * x1 + y1 * y1 + z1 * z1) / (resh[0] * resh[0] + resh[1] * resh[1] + resh[2] * resh[2]);
	pogresh = sqrt(pogresh);



	//vectorn в stt
	for (int j = 0; j < 3; ++j)                                  // vectorn
	{
		d = vectorn[j];
		d < 0 ? wcscat_s(stt, _T("-")) : wcscat_s(stt, _T(" "));
		d = abs(d);
		n = (int)d;
		_itow_s(n, s, 10);
		wcscat_s(stt, s);
		wcscat_s(stt, _T("."));                       // заносит в stt целую часть исходной координаты 
		d = d - n;
		for (int i = 0; i < 5; ++i)
		{
			d *= 10;
			n = (int)d;                                     // заносит дробную часть числа в stt 
			_itow_s(n, s, 10);
			wcscat_s(stt, s);
			d = d - n;
		}
		for (int i = 0; i < _tcsclen(stt); ++i)
			st[i] = stt[i];
		wcscat_s(stt, _T("  "));
	}
	
	


	d = pogresh;
	n = (int)d;
	_itow_s(n, s, 10);
	wcscat_s(STTR, s);
	wcscat_s(STTR, _T("."));                       // заносит в stt целую часть исходной координаты 
	d = d - n;
	for(int i=0; i<5;++i)
	{
		d *= 10;
		n = (int)d;                                     // заносит дробную часть числа в stt 
		_itow_s(n, s, 10);
		wcscat_s(STTR, s);
		d = d - n;
	}
	for (int i = 0; i < _tcsclen(STTR); ++i)
		pog[i] = STTR[i];
	wcscat_s(STTR, _T("  "));
	//for (int j = 0; j < 3; ++j)
	//{
	//	d = vectorn[j];
	//	n = (int)d;
	//	_itow_s(n, s, 10);
	//	wcscat_s(stt, s);
	//	wcscat_s(stt, _T("."));                       // заносит в stt целую часть исходной координаты 
	//	d -= n;
	//	for (int i = 0; i < 5; ++i)
	//	{
	//		d *= 10;
	//		n = (int)d;                                     // заносит дробную часть числа в stt 
	//		_itow_s(n, s, 10);
	//		wcscat_s(stt, s);
	//		d -= n;
	//	}
	//	for (int i = 0; i < _tcsclen(stt); ++i)
	//		st[i] = stt[i];
	//	wcscat_s(stt, _T("  "));
	//	for (int i = 0; i < _tcsclen(stt); ++i)
	//		reshDouble[i] = stt[i];

	//}
//
//	
//
//
//	_itow_s(vecnev[0], vecnevyazk, 10);
//	wcscat_s(vyvodnevyaz, vecnevyazk);
//	wcscat_s(vyvodnevyaz, _T(" "));
//	_itow_s(vecnev[1], vecnevyazk, 10);
//	wcscat_s(vyvodnevyaz, vecnevyazk);
//	wcscat_s(vyvodnevyaz, _T(" "));
//	_itow_s(vecnev[2], vecnevyazk, 10);
//	wcscat_s(vyvodnevyaz, vecnevyazk);
//
//	InvalidateRect(hWnd, NULL, TRUE);
}

void Matrix::space(int c )
{
	
	for (int i = 0; i < (c - _tcsclen(str1)); ++i)
		wcscat_s(str1, _T(" "));
	for (int i = 0; i < (c - _tcsclen(str2)); ++i)
		wcscat_s(str2, _T(" "));
	for (int i = 0; i < (c - _tcsclen(str3)); ++i)
		wcscat_s(str3, _T(" "));
}