#include <iostream>
#include <gd.h>
#include <stdio.h>
#include <stdlib.h>

void save_png(gdImagePtr im, const char *filename)
{

  FILE *fp;

  fp = fopen(filename, "wb");
  if (!fp) {
    fprintf(stderr, "Can't save png image %s\n", filename);
    return;
  }

  gdImagePng(im, fp);

  fclose(fp);

}

int main() {

  gdImagePtr im;

  im = gdImageCreateTrueColor(1920, 1080);

  if (!im) {
    fprintf(stderr, "Can't create 400x400 TC image\n");
    return 1;
  }

  int brect[8];
  char buf[60];
  int fc = gdImageColorAllocate(im, 255, 255, 255);
  gdImageStringFT(im, brect, 0 - fc, "fonts/HelveticaNeue-CondensedBold.ttf", 50, 0.0, 250, 250, "THIS IS V4C");

  gdImageCropAuto(im, GD_CROP_SIDES);

  if (im) {
    save_png(im, "test.png");
  }

}