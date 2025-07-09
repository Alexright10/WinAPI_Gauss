// WindowsProject2.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject2.h"
#include "Header.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT2));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
HWND hWnd;
TCHAR str1[200] = _T(" ");
TCHAR str2[200] = _T(" ");
TCHAR str3[200] = _T(" ");
TCHAR str4[100] = _T(" ");
TCHAR ser[5] = _T(" ");
TCHAR vectrresh[15] = _T("");
TCHAR vyvodnevyaz[30] = _T(" ");
TCHAR normvecnev[100] = _T(" ");
TCHAR normvecnev2_1[100] = _T(" ");
TCHAR normvecnev2_2[100] = _T(" ");
TCHAR normvecnev2_3[100] = _T(" ");
TCHAR vector_resh[100] = _T(" ");
TCHAR Gaussvec[30] = _T(" ");
TCHAR vecnevDouble[30] = _T(" ");
TCHAR pog[100] = _T(" ");
Matrix obj;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_MATR:
                obj.set();
                obj.get();
                break;
            case IDM_NOK13:
                obj.ravno13();
                obj.function(0);
                obj.gauss(0);
                obj.space(40);
                obj.get();
                break;
            case IDM_NOK12:
                obj.ravno12();
                obj.function(0);
                obj.gauss(0);
                obj.space(80);
                obj.get();
                break;
            case IDM_NOK23:
                obj.ravno23();
                obj.function(1);
                obj.gauss(1);
                obj.space(100);
                obj.get();
                break;
            case IDM_RESHENIE:
                obj.resheniexyz();
                break;
            case IDM_NEVYAZ:
                obj.vectornevyazky();
                break;
            case IDM_NORMA:
                obj.norma();
                obj.convert(normvecnev);
                InvalidateRect(hWnd, NULL, TRUE);
                break;
            case IDM_DOUBL:
                obj.Gauss();
                obj.resh_double();
                obj.convert2_1(normvecnev2_1);
                obj.convert2_2(normvecnev2_2);
                obj.convert2_3(normvecnev2_3);
                obj.convert_resh(vector_resh);
                obj.vectornevyazkyDouble(vecnevDouble, pog);
                InvalidateRect(hWnd, NULL, TRUE);
                break;
            case IDM_EXIT:  
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            TextOut(hdc, 0, 0, str1, _tcsclen(str1));
            TextOut(hdc, 0, 20, str2, _tcsclen(str2));
            TextOut(hdc, 0, 40, str3, _tcsclen(str3));
            TextOut(hdc, 0, 80, vectrresh, _tcsclen(vectrresh));
            TextOut(hdc, 0, 120, vyvodnevyaz, _tcsclen(vyvodnevyaz));
            TextOut(hdc, 0, 160, normvecnev, _tcsclen(normvecnev));
            TextOut(hdc, 0, 200, normvecnev2_1, _tcsclen(normvecnev2_1));
            TextOut(hdc, 0, 220, normvecnev2_2, _tcsclen(normvecnev2_2));
            TextOut(hdc, 0, 240, normvecnev2_3, _tcsclen(normvecnev2_3));
            TextOut(hdc, 0, 280, vector_resh, _tcsclen(vector_resh));
            TextOut(hdc, 0, 320, vecnevDouble, _tcsclen(vecnevDouble));
            TextOut(hdc, 0, 360, pog, _tcsclen(pog));
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
