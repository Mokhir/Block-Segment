/* Name: main.cpp
 * Author: Waleed Qawasmi
 */

#include <iostream>
#include "hasher.h"

int main(int argc, char **argv) {
  std::cout << "Running." << std::endl;

  std::string message = "hello!";

  std::cout << message << std::endl;
  byte *digest = NULL;
  getMD5Hash((byte *)message.c_str(), message.length(), digest);
}
