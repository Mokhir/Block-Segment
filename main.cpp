/* Name: main.cpp
 * Author: Waleed Qawasmi
 */

#include <iostream>
#include "hasher.h"
#include "segment.h"

int main(int argc, char **argv) {
  std::cout << "Running.\n" << std::endl;

  /*
  std::string message = "hello!";
  std::cout << message << std::endl;
  byte *digest = NULL;
  getMD5Hash((byte *)message.c_str(), message.length(), digest);
  */

  std::ifstream file ("test.txt", std::ios::binary);
  getNextBlock(&file, 1);

}
