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
  static void   cleanup(struct Block*, size_t);
  static size_t getFileSize(std::ifstream*);
  static int    getNextBlock(char*, size_t, std::ifstream*, size_t);
  static size_t linearSegment(std::ifstream*, size_t, struct Block*&);
	static void   merge(struct Block*&, struct Block*);	
};

#endif
