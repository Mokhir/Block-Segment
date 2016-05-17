/* Name: segment.h
 * Author: Waleed Qawasmi
 */

#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

size_t getFileSize(std::ifstream*);
size_t getNextBlock(char*, std::ifstream*, size_t);

#endif
