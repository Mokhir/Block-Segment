/* Name: segmentcpp
 * Author: Waleed Qawasmi
 */

#include "segment.h"

// Returns size of file in bytes
size_t getFileSize(std::ifstream *file) {
  std::streampos curr, begin, end;

  curr =  file->tellg();
  std::cout<< "Curr before: " << curr << std::endl;

  file->seekg(0, std::ios::beg);
  begin = file->tellg();
  file->seekg(0, std::ios::end);
  end = file->tellg();

  std::cout << "Curr after: " << curr << std::endl;
  // Reset positions
  file->seekg(curr, std::ios::beg);

  // Return difference in positions (bytes)
  return end - begin;
}

// Returns the next block in file of size blockSize in bytes
bool getNextBlock(std::ifstream *file, size_t blockSize) {
  if( !file->is_open() || file->fail() || blockSize <= 0 ) return false;

  size_t fsize = getFileSize(file);
  std::cout << "File size: " << fsize << std::endl;
  return true;
}
