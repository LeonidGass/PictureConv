/**
* BMP-related data types based on Microsoft's own.
*/
#ifndef BMP_h
#define BMP_h

#include <stdint.h>
#pragma pack (push,1)

/**
* Common Data Types
*
* The data types in this section are essentially aliases for C/C++
* primitive data types.
*
* Adapted from https://msdn.microsoft.com/en-us/library/cc230309.aspx.
* See http://en.wikipedia.org/wiki/Stdint.h for more on stdint.h.
*/
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

/**
* BITMAPFILEHEADER
*
* The BITMAPFILEHEADER structure contains information about the type, size,
* and layout of a file that contains a DIB [device-independent bitmap].
*
* Adapted from https://msdn.microsoft.com/en-us/library/dd183374(v=vs.85).aspx.
*/
typedef struct
{
	WORD bfType;
	DWORD bfSize;
	WORD bfReserved1;
	WORD bfReserved2;
	DWORD bfOffBits;
}
BITMAPFILEHEADER;

/**
* BITMAPINFOHEADER
*
* The BITMAPINFOHEADER structure contains information about the
* dimensions and color format of a DIB [device-independent bitmap].
*
* Adapted from https://msdn.microsoft.com/en-us/library/dd183376(v=vs.85).aspx.
*/
typedef struct
{
	DWORD biSize;
	LONG biWidth;
	LONG biHeight;
	WORD biPlanes;
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	LONG biXPelsPerMeter;
	LONG biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
}
BITMAPINFOHEADER;

/**
* RGBTRIPLE
*
* This structure describes a color consisting of relative intensities of
* red, green, and blue.
*
* Adapted from https://msdn.microsoft.com/en-us/library/dd162939(v=vs.85).aspx.
*/
typedef struct
{
	BYTE rgbtBlue;
	BYTE rgbtGreen;
	BYTE rgbtRed;
} 
RGBTRIPLE;


void output_file_info_headers(BITMAPFILEHEADER bmfh, BITMAPINFOHEADER bmih);
/*
	cout everything from a structures
*/

#endif // !BMP_H