/* Name: segment.h
 * Author: Waleed Qawasmi
 */

#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include <fstream>

size_t getFileSize(std::ifstream*);
bool getNextBlock(std::ifstream*, size_t);

#endif
