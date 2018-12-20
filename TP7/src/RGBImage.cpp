/** -*- mode: c++ ; c-basic-offset: 3 -*-
 * @file   RGBImage.cpp
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
#include "RGBImage.h"
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>

RGBImage::RGBImage() : _width(0), _height(0)
{
  //
}

RGBImage::RGBImage(int width, int height) : _width(width), _height(height), _pixels(static_cast<unsigned int>(width * height * 3))
{
  //
}

RGBImage::RGBImage(RGBImage && other) : _width(other._width), _height(other.height()), _pixels(std::move(other._pixels))
{
  //
}

RGBImage & RGBImage::operator=(RGBImage && other)
{
  _width = other._width;
  _height = other._height;
  _pixels = std::move(other._pixels);
  return *this;
}

void RGBImage::resize(int width, int height)
{
  _width = width;
  _height = height;
  _pixels.assign(static_cast<unsigned int>(width * height * 3), 0);
}

void RGBImage::fill(unsigned char r, unsigned char g, unsigned char b)
{
  unsigned char * pixel = _pixels.data();
  unsigned char * limit = pixel + _width * _height * 3;
  while (pixel != limit) {
    pixel[0] = r;
    pixel[1] = g;
    pixel[2] = b;
    pixel += 3;
  }
}

void RGBImage::fill(unsigned char gray)
{
  std::memset(_pixels.data(), gray, _pixels.size());
}

void RGBImage::drawCircle(int x, int y, int radius, unsigned char r, unsigned char g, unsigned char b)
{
  const int right_x = std::min(x + radius, _width - 1);
  const int bottom_y = std::min(y + radius, _height - 1);
  for (int row = std::max(0, y - radius); row <= bottom_y; ++row) {
    for (int col = std::max(0, x - radius); col <= right_x; ++col) {
      if (inDisk(x, y, radius, col, row) && //
          !(inDisk(x, y, radius, col - 1, row) && inDisk(x, y, radius, col, row - 1) && inDisk(x, y, radius, col + 1, row) && inDisk(x, y, radius, col, row + 1))) {
        red(col, row) = r;
        green(col, row) = g;
        blue(col, row) = b;
      }
    }
  }
}

void RGBImage::fillCircle(int x, int y, int radius, unsigned char r, unsigned char g, unsigned char b, unsigned char opacity)
{
  const float a = opacity / 255.0f;
  const float ar = a * r;
  const float ag = a * g;
  const float ab = a * b;
  const float ca = 1.0f - a;
  const int right_x = std::min(x + radius, _width - 1);
  const int bottom_y = std::min(y + radius, _height - 1);
  for (int row = std::max(0, y - radius); row <= bottom_y; ++row) {
    for (int col = std::max(0, x - radius); col <= right_x; ++col) {
      if (inDisk(x, y, radius, col, row)) {
        red(col, row) = static_cast<unsigned char>(ar + ca * red(col, row) + 0.5f);
        green(col, row) = static_cast<unsigned char>(ag + ca * green(col, row) + 0.5f);
        blue(col, row) = static_cast<unsigned char>(ab + ca * blue(col, row) + 0.5f);
      }
    }
  }
}

void RGBImage::loadPPM(const std::string & filename)
{
  std::ifstream in(filename);
  std::string line;
  std::getline(in, line);
  if (line[0] != 'P' || line[1] != '6') {
    std::cerr << "Error: Cannot open PPM file. Not a P6 binary RGB pixmap.\n";
    return;
  }
  int width = -1;
  int height = -1;
  do {
    std::getline(in, line);
  } while (line[0] == '#');
  sscanf(line.c_str(), "%d %d", &width, &height);
  do {
    std::getline(in, line);
  } while (line[0] == '#');
  int maxValue = atoi(line.c_str());
  if (maxValue > 255) {
    std::cerr << "Error: Cannot open PPM file. Not an 8-bit depth format.\n";
    return;
  }
  _pixels.assign(static_cast<unsigned int>(width * height * 3), 0);
  _width = width;
  _height = height;
  in.read(reinterpret_cast<char *>(_pixels.data()), static_cast<std::streamsize>(_pixels.size()));
  if (in.gcount() != static_cast<std::streamsize>(_pixels.size())) {
    std::cerr << "Error: PPM file seems truncated.\n";
    _pixels.clear();
    _width = _height = 0;
  }
}

void RGBImage::savePPM(const std::string & filename)
{
  std::ofstream out(filename);
  out << "P6\n";
  out << "#Created by the RGBImage class (c)2018 S. Fourey\n";
  out << _width << " " << _height << "\n";
  out << "255\n";
  out.write(reinterpret_cast<char *>(_pixels.data()), _width * _height * 3);
}

bool RGBImage::inDisk(int xCenter, int yCenter, int radius, int x, int y)
{
  const long dx = std::labs(x - xCenter);
  const long dy = std::labs(y - yCenter);
  const float distance = std::hypotf(dx, dy);
  return std::round(distance) < radius;
}
