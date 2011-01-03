#pragma once
//-------------------------------------------------------------------------------------------------
// <copyright file="thmutil.h" company="Microsoft">
//    Copyright (c) Microsoft Corporation.  All rights reserved.
//    
//    The use and distribution terms for this software are covered by the
//    Common Public License 1.0 (http://opensource.org/licenses/cpl.php)
//    which can be found in the file CPL.TXT at the root of this distribution.
//    By using this software in any fashion, you are agreeing to be bound by
//    the terms of this license.
//    
//    You must not remove this notice, or any other, from this software.
// </copyright>
// 
// <summary>
//  Theme helper functions.
// </summary>
//-------------------------------------------------------------------------------------------------


#ifdef __cplusplus
extern "C" {
#endif

enum THEME_CONTROL_DATA
{
    THEME_CONTROL_DATA_HOVER = 1,
};

enum THEME_CONTROL_TYPE
{
    THEME_CONTROL_TYPE_UNKNOWN,
    THEME_CONTROL_TYPE_HYPERLINK,
    THEME_CONTROL_TYPE_BUTTON,
    THEME_CONTROL_TYPE_PROGRESSBAR,
    THEME_CONTROL_TYPE_TEXT,
};

struct THEME_CONTROL
{
    THEME_CONTROL_TYPE type;

    LPWSTR wzText;
    int nX;
    int nY;
    int nHeight;
    int nWidth;
    int nSourceX;
    int nSourceY;

    DWORD dwFontId;
    DWORD dwFontHoverId;
    DWORD dwFontSelectedId;
    HWND hWnd;
};


struct THEME_FONT
{
    HFONT hFont;
    COLORREF crForeground;
    HBRUSH hForeground;
    COLORREF crBackground;
    HBRUSH hBackground;
};


struct THEME
{
    DWORD dwStyle;
    DWORD dwFontId;
    HICON hIcon;
    LPWSTR wzCaption;
    int nHeight;
    int nWidth;
    int nSourceX;
    int nSourceY;

    Gdiplus::Image* pImage;

    DWORD cFonts;
    THEME_FONT* rgFonts;

    DWORD cControls;
    THEME_CONTROL* rgControls;

    // state variables that should be ignored
    HWND hwndHover; // currently 
};


HRESULT DAPI ThemeInitialize();

void DAPI ThemeUninitialize();

HRESULT DAPI ThemeLoadFromResource(
    __in_opt HMODULE hModule,
    __in LPCSTR szResource,
    __out THEME** ppTheme
    );

void DAPI ThemeFree(
    __in THEME* pTheme
    );

HRESULT DAPI ThemeLoadControls(
    __in THEME* pTheme,
    __in HWND hwndParent
    );

HRESULT DAPI ThemeDrawBackground(
    __in THEME* pTheme,
    __in PAINTSTRUCT* pps
    );

HRESULT DAPI ThemeDrawControl(
    __in THEME* pTheme,
    __in DRAWITEMSTRUCT* pdis
    );

void DAPI ThemeHoverControl(
    __in THEME* pTheme,
    __in HWND hwndParent,
    __in HWND hwndControl
    );

BOOL DAPI ThemeSetControlColor(
    __in THEME* pTheme,
    __in HDC hdc,
    __in HWND hWnd,
    __out HBRUSH* phBackgroundBrush
    );

HRESULT DAPI ThemeSetProgressControl(
    __in THEME* pTheme,
    __in DWORD dwControl,
    __in DWORD dwProgressPercentage
    );

HRESULT DAPI ThemeSetTextControl(
    __in THEME* pTheme,
    __in DWORD dwControl,
    __in_z LPCWSTR wzText
    );

#ifdef __cplusplus
}
#endif
