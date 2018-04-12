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

void add_centered_text(gdImagePtr im, int x1, int y1, int x2, int y2, const char *text)
{
  double size = 50.;

  // For sizing
  int brect[8];
  gdImageStringFT(NULL, &brect[0], 0, (char *)"fonts/HelveticaNeue-CondensedBold.ttf", size, 0., 0, 0, (char *)text);

  int white = gdImageColorAllocate(im, 255, 255, 255);
  int x = (1920 / 2) - (brect[2] / 2);
  int y = (1080 / 2) - (brect[3] / 2);
  gdImageStringFT(im, &brect[0], white, (char *)"fonts/HelveticaNeue-CondensedBold.ttf", size, 0., x, y, (char *)text);
}

int main() {

  gdImagePtr im;

  im = gdImageCreateTrueColor(1920, 1080);

  if (!im) {
    fprintf(stderr, "Can't create 400x400 TC image\n");
    return 1;
  }

  int black = gdImageColorAllocate(im, 0, 0, 0);
  gdImageFilledRectangle(im, 0, 0, 1920, 1080, black);

  add_centered_text(im, 0, 0, 1920, 1080, "[ THIS IS V4C ]");

  gdImageCropAuto(im, GD_CROP_SIDES);

  if (im) {
    save_png(im, "test.png");
  }

}