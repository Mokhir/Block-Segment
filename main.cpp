/* Name: main.cpp
 * Author: Waleed Qawasmi
 * Used to test implementation of segment and hasher.
 */

#include <iostream>
#include "hasher.h"
#include "segment.h"

int main(int argc, char **argv) {
  if( argc < 2 ) {
    std::cout << "Not enough arguments.\n" << argv[0] << " <file>" << std::endl;
    return -1;
  }

  std::cout << "Running.\n" << std::endl;

  /*
  std::string message = "hello!";
  std::cout << message << std::endl;
  byte *digest = NULL;
  getMD5Hash((byte *)message.c_str(), message.length(), digest);
  */

  std::ifstream file (argv[1], std::ios::binary);

  // Request block of memory within range of file
  Segment::Block* blocks = NULL;
  size_t numBlocks = Segment::linearSegment(&file, 10, blocks);
  Segment::cleanup(blocks, numBlocks);
  file.close();
}
