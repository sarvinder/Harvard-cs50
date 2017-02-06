/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }
    
    //the number to shift with
    int numbertoshift=atoi(argv[3])  ;
    
    //check if the input is positive INTEGER and less than 100
    if(numbertoshift<0||numbertoshift>100)
    {
        printf("the input should be positive and less than 100\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    //old values of the width and the height and the paddding
    int oldbiWidth=bi.biwidth;
    int oldbiHeight=abs(bi.biHeight);
    int oldpadding = (4 - (oldbiWidth *sizeof(RGBTRIPLE)) % 4) % 4;

    //here we need to compute the new biwidth,biheight,bisizeImage,bf.bfsize,padding
    bi.biwidth*=n;
    bi.biHeight*=n;
   
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth *sizeof(RGBTRIPLE)) % 4) % 4;


   // int newpadding=(4 - (bi.biWidth *(numbertoshift*sizeof(RGBTRIPLE))) % 4) % 4;

    //the size of the image in bytes including padding
    bi.biSizeImage=((sizeof(RGBTRIPLE)*bi.biWidth)+padding)*abs(bi.biHeight);
    printf("%i\n",bi.biSizeImage);
    
    //the total size of the image
    bf.bfSize=bi.biSizeImage+sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(oldbiHeight); i < biHeight; i++)
    {
        RGBTRIPLE currrow[oldWidth];
        
        fread(&currrow,sizeof(RGBTRIPLE),oldWidth,inptr);
        // iterate over pixels in scanline
        for (int j = 0; j < oldbiWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            for(int k=0;k<n;k++)
            {
            // write RGB triple to outfile
            fwrite(&currrow[k], sizeof(RGBTRIPLE), 1, outptr);    
            }
            
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
