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

  gdImageFilledRectangle(im, 19, 29, 390, 390, 0xFFFFFF);
  gdImageRectangle(im, 19, 29, 390, 390, 0xFF0000);
  gdImageCropAuto(im, GD_CROP_SIDES);

  if (im) {
    save_png(im, "test.png");
  }

}