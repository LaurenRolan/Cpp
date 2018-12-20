/** -*- mode: c++ ; c-basic-offset: 3 -*-
 * @file   RGBImage.h
 * @date   Dec 2018
 *
 * @brief  Simple Image class with PPM input/output
 *
 * @author Sebastien Fourey
 *
 * @copyright Copyright 2018-2019 Sebastien Fourey
 * This file is owned by Sebastien Fourey.
 * It is provided to ENSICAEN students for the purpose
 * of a lab exercise. No portion of this document may be
 * reproduced, copied or revised without written
 * permission of the author.
 */
#ifndef _ENSICAEN_RGBIMAGE_H_
#define _ENSICAEN_RGBIMAGE_H_

#include <string>
#include <vector>

/**
 *  The Image class.
 */
class RGBImage {

public:
  RGBImage();
  RGBImage(int width, int height);
  RGBImage(const RGBImage &) = default;
  RGBImage(RGBImage &&);
  RGBImage & operator=(const RGBImage &) = default;
  RGBImage & operator=(RGBImage &&);

  inline int width() const;
  inline int height() const;

  void resize(int width, int height);

  /*
   * Pixel values accessors
   */
  inline unsigned char & red(int x, int y);
  inline unsigned char & green(int x, int y);
  inline unsigned char & blue(int x, int y);

  /**
   * @brief Fill the image with a given color
   * @param r
   * @param g
   * @param b
   */
  void fill(unsigned char r, unsigned char g, unsigned char b);

  /**
   * @brief Fill the image with a gray level
   * @param gray
   */
  void fill(unsigned char gray);

  /**
   * @brief Check if a pixel coordinate belongs to the image
   * @param x Column of the pixel
   * @param y Row of the pixel
   * @return true if the position belongs to the image, otherwise false
   */
  inline bool contains(int x, int y) const;

  void drawCircle(int x, int y, int radius, unsigned char r, unsigned char g, unsigned char b);

  void fillCircle(int x, int y, int radius, unsigned char r, unsigned char g, unsigned char b, unsigned char opacity = 255);

  void loadPPM(const std::string & filename);

  void savePPM(const std::string & filename);

private:
  int _width;
  int _height;
  std::vector<unsigned char> _pixels;
  static bool inDisk(int xCenter, int yCenter, int radius, int x, int y);
};

/*
 * Definition of inline methods
 */

int RGBImage::width() const
{
  return _width;
}

int RGBImage::height() const
{
  return _height;
}

unsigned char & RGBImage::red(int x, int y)
{
  return _pixels[static_cast<unsigned int>(3 * y * _width + 3 * x)];
}

unsigned char & RGBImage::green(int x, int y)
{
  return _pixels[static_cast<unsigned int>(3 * y * _width + 3 * x + 1)];
}

unsigned char & RGBImage::blue(int x, int y)
{
  return _pixels[static_cast<unsigned int>(3 * y * _width + 3 * x + 2)];
}

bool RGBImage::contains(int x, int y) const
{
  return x >= 0 && y >= 0 && x < static_cast<int>(_width) && y < static_cast<int>(_height);
}

#endif // _ENSICAEN_RGBIMAGE_H_
