/* Name: segment.cpp
 * Author: Waleed Qawasmi
 */

#include "segment.h"

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
size_t Segment::getNextBlock(char *block, std::ifstream *file, size_t blockSize) {
  if( !file->is_open() || file->fail() || blockSize <= 0 ) return -1;

  size_t fileSize = getFileSize(file);
  // std::cout << "File size: " << fileSize << std::endl;

  // Adjust blocksize if necessary
  size_t diff = fileSize - file->tellg();
  if( diff < blockSize ) blockSize = diff;

  // Read block of memory and move the stream position up
  file->read(block, blockSize);
  if( file->fail() ) return -1;
  file->seekg( 0, std::ios::cur );

  return blockSize;
}