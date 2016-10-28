/* Name: linearblock.cpp
 * Author: Waleed Qawasmi
 * Description: Class that represents a linear segmentation of a file
 * given a block size.
 */

#include "linearsegment.h"

typedef LinearSegment::blockNode blockNode;

// Intialize members and calculate number of blocks
LinearSegment::LinearSegment(std::ifstream* file, size_t blockSize) : FileInfo(file) {
  m_blockSize = blockSize;
  m_numBlocks = ceil( (float)m_fileSize / blockSize );
  m_head = NULL;
}

// free's list
LinearSegment::~LinearSegment() {
  freeList();
}

// MARK: Segmentation functions

/* Reads in block of data from file and calculates MD5
 * Returns number of bytes read, -1 on error */
int LinearSegment::readBlock(char** dataP) {
  if( !m_file->is_open() || m_file->fail() || m_blockSize <= 0 || dataP == NULL ) return -1;
  // Number of bytes to read and the data pointer
  size_t numBytes = m_blockSize;
  if( *dataP == NULL ) *dataP = (char*)malloc( sizeof(char)*m_blockSize );
  char* data = *dataP;
  // Resize numBytes if blocksize is larger than remaining data
  size_t diff = m_fileSize - m_file->tellg();
  if( diff < m_blockSize ) {
    memset(data, 0, m_blockSize);
    numBytes = diff;
  }

  // Read block of memory and move the stream position up
  m_file->read(data, numBytes);
  if( m_file->fail() ) return -1;
  m_file->seekg( 0, std::ios::cur );

  return numBytes;
}

/* Segments the attached file linearly. Returns resultant linked List
 * which is placed in m_head and accessible via head() */
blockNode* LinearSegment::segment() {
  if( m_file == NULL || m_blockSize == 0 ) return NULL;
  if( m_head != NULL ) {
    std::cerr << "segment() call: File already segmented!" << std::endl;
    return NULL;
  }

  // Allocate memory for segmentation and fill it with blocks
  m_head = (blockNode*)malloc( sizeof(blockNode)*m_numBlocks );
  for (size_t i = 0; i < m_numBlocks; i++) {
    m_head[i].data = NULL;
    m_head[i].digest = NULL;

    // Read block from file
    int numBytes;
    if( (numBytes = readBlock(&m_head[i].data)) != -1 ) {
      // Construct block
      std::cout << "Read " << numBytes << " bytes on block " << i << std::endl;
      m_head[i].digest = getMD5Hash((byte*)m_head[i].data, m_blockSize, NULL);
      (i + 1 < m_numBlocks ) ? m_head[i].next = &m_head[i+1] : m_head[i].next = NULL;
    }
  }

  return m_head;
}

// MARK: Linked List functions
blockNode* LinearSegment::addBlock(blockNode*) {
  return NULL;
}

blockNode* LinearSegment::removeBlock(blockNode*) {
  return NULL;
}

blockNode* LinearSegment::replaceBlock(blockNode*) {
  return NULL;
}

void LinearSegment::freeList() {
  for (size_t i = 0; i < m_numBlocks; i++) {
    free(m_head[i].data);
    free(m_head[i].digest);
  }
  free(m_head);
}

// MARK: Getters
size_t LinearSegment::blockSize() {
  return m_blockSize;
}

size_t LinearSegment::numBlocks() {
  return m_numBlocks;
}

blockNode* LinearSegment::head() {
  return m_head;
}
