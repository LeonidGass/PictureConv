#include <iostream>
#include "bmp.h"

using namespace std;

void output_file_info_headers(BITMAPFILEHEADER bmfh, BITMAPINFOHEADER bmih) {
	cout << "BITMAPFILEHEADER:" << endl << endl;

	cout << bmfh.bfType << endl;
	cout << bmfh.bfSize << endl;
	cout << bmfh.bfReserved1 << endl;
	cout << bmfh.bfReserved2 << endl;
	cout << bmfh.bfOffBits << endl;

	cout << "BITMAPINFOHEADER: " << endl << endl;

	cout << bmih.biSize << endl;
	cout << bmih.biWidth << endl;
	cout << bmih.biHeight << endl;
	cout << bmih.biPlanes << endl;
	cout << bmih.biBitCount << endl;
	cout << bmih.biCompression << endl;
	cout << bmih.biSizeImage << endl;
	cout << bmih.biXPelsPerMeter << endl;
	cout << bmih.biYPelsPerMeter << endl;
	cout << bmih.biClrUsed << endl;
	cout << bmih.biClrImportant << endl;

	cout << endl << endl;
}