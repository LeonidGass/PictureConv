/**
* Copies a BMP piece by piece, just because.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"


using namespace std;

int main(int argc, char *argv[])
{
	FILE *inptr;
	FILE *outptr;
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;

	// open input file 
	inptr = fopen("smiley.bmp", "r");

	// open output file
	outptr = fopen("outfile.bmp", "w");

	// read infile's BITMAPFILEHEADER
	fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

	// read infile's BITMAPINFOHEADER
	fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

	output_file_info_headers(bf, bi);

	// ensure infile is (likely) a 24-bit uncompressed BMP 4.0
	if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
		bi.biBitCount != 24 || bi.biCompression != 0)
	{
		fclose(outptr);
		fclose(inptr);
		fprintf(stderr, "Unsupported file format.\n");
		return 4;
	}
	

	bi.biHeight = bi.biHeight * 2;
	bi.biWidth = bi.biWidth * 2;
	
	int curr = bi.biWidth * 3;
	while (curr % 4 != 0) {
		curr++;
	}
	
	bi.biSizeImage = bi.biHeight * curr;
	bf.bfSize = bi.biSizeImage + 54;

	output_file_info_headers(bf, bi);

	// write outfile's BITMAPFILEHEADER
	fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

	// write outfile's BITMAPINFOHEADER
	fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

	//determine padding for scanlines
	/*int padding_old = 4 - ((bi.biWidth / 2 * 3) % 4);
	int padding_new = 4 - ((bi.biWidth * 3) % 4);

	cout << padding_old << endl;
	cout << padding_new << endl;*/

	int biHeight = abs(bi.biHeight);
	RGBTRIPLE * triple = new RGBTRIPLE[bi.biWidth/2];

	for (int i = 0; i < biHeight; i++) {
		fread(triple, sizeof(RGBTRIPLE)*bi.biWidth/2, 1, inptr);
		//fseek(inptr, padding_old, SEEK_CUR);

		for (int x = 0; x < 2; x++) {
			for (int j = 0; j < bi.biWidth/2; j++) {
				for (int k = 0; k < 2; k++) {
					fwrite(&(triple[j]), sizeof(RGBTRIPLE), 1, outptr);
				}
			}

			
			/*for (int k = 0; k < padding_new; k++)
			{
				fputc(0x00, outptr);
			}*/
		}
	}

	// close infile
	fclose(inptr);

	// close outfile
	fclose(outptr);

	// success
	
	system("pause");
	return 0;
}