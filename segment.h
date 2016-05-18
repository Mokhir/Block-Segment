/* Name: segment.h
 * Author: Waleed Qawasmi
 */

#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

class Segment {
public:
  struct Block;
  static size_t getFileSize(std::ifstream*);
  static int    getNextBlock(char*, size_t, std::ifstream*, size_t);
  static struct Block* linearSegment(std::ifstream*, size_t);
};

#endif
