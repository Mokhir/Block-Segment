/* Name: linearblock.h
 * Author: Waleed Qawasmi
 * Description: Class that represents a linear segmentation of a file
 * given a block size.
 */

#ifndef LINEARSEG_H
#define LINEARSEG_H

#include <math.h>
#include "hasher.h"
#include "fileinfo.h"

class LinearSegment: public FileInfo {
public:
  // Constructor/deconstructor
  LinearSegment(std::ifstream*, size_t);
  ~LinearSegment();

  // Represents a memory block and its checksum
  typedef struct blockNode {
    char* data;
    byte* digest;
    struct blockNode* next;
  } blockNode;

  // Segmentation functions
  int readBlock(char**);
  blockNode* segment();

  // Linked List funtions
  blockNode* addBlock(blockNode*);
  blockNode* removeBlock(blockNode*);
  blockNode* replaceBlock(blockNode*);
  void freeList();

  // Getters
  size_t blockSize();
  size_t numBlocks();
  blockNode* head();

private:
  blockNode* m_head;
  size_t m_blockSize;
  size_t m_numBlocks;
};

#endif
