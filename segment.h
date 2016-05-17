/* Name: segment.h
 * Author: Waleed Qawasmi
 */

#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

class Segment {
public:
  static size_t getFileSize(std::ifstream*);
  static size_t getNextBlock(char*, std::ifstream*, size_t);
};

#endif
