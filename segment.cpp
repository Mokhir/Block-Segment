/* Name: segment.cpp
 * Author: Waleed Qawasmi
 */

#include "segment.h"
#include "hasher.h"

// Represents a block of memory and its associated MD5 digest
struct Segment::Block {
  char *mem;
  byte *digest;
};

// Returns size of file in bytes
size_t Segment::getFileSize(std::ifstream *file) {
  std::streampos curr, begin, end;
  curr =  file->tellg();

  // Locate beginning and final stream positions
  file->seekg(0, std::ios::beg);
  begin = file->tellg();
  file->seekg(0, std::ios::end);
  end = file->tellg();

  // Reset position
  file->seekg(curr, std::ios::beg);

  // Return difference in positions (bytes)
  return end - begin;
}

// Returns size of block read or -1 on error
int Segment::getNextBlock(char *block, size_t blockSize, std::ifstream *file, size_t fileSize) {
  if( !file->is_open() || file->fail() || blockSize <= 0 ) return -1;

  if( fileSize == 0 ) fileSize = getFileSize(file);
  // std::cout << "File size: " << fileSize << std::endl;

  // Adjust block size if necessary
  size_t diff = fileSize - file->tellg();
  if( diff < blockSize ) {
    memset(block, 0, blockSize);
    blockSize = diff;
  }

  // Read block of memory and move the stream position up
  file->read(block, blockSize);
  if( file->fail() ) return -1;
  file->seekg( 0, std::ios::cur );

  return blockSize;
}

/* Returns array of Block structs.
 * The ith hash represents the MD5 of the ith block */
size_t Segment::linearSegment(std::ifstream* file, size_t blockSize, Segment::Block *& blocks) {
  if( file == NULL || blockSize == 0 ) return 0;

  // Find number of blocks in file given block size
  size_t fileSize = getFileSize(file);
  size_t numBlocks = ceil( (float)fileSize/blockSize );

  // Fill struct Block array with the blocks of memory and their checksums
  blocks = (Segment::Block*)malloc( sizeof(Segment::Block)*numBlocks );
  for (size_t i = 0; i < numBlocks; i++) {
    blocks[i].mem = (char*)malloc( sizeof(char)*blockSize );
    if( getNextBlock(blocks[i].mem, fileSize, file, blockSize) == -1 ) {
      std::cerr << "Error retrieving block. Exiting..." << std::endl;
      exit(0);
    }

    blocks[i].digest = getMD5Hash((byte*)blocks[i].mem, blockSize, NULL);
  }

  std::cout << numBlocks << " blocks of size " << blockSize << std::endl;
  return numBlocks;
}

void Segment::cleanup(Segment::Block* blocks, size_t numBlocks) {
  for (size_t i = 0; i < numBlocks; i++) {
    free(blocks[i].mem);
    free(blocks[i].digest);
  }

  free(blocks);
}
