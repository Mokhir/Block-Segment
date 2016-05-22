/* Name: fileinfo.h
 * Author: Waleed Qawasmi
 * Description: Parent class for all Blocks (linear/tree). Direct instances of
 * FileInfo aren't meant to be created.
 */

#ifndef FILEINFO_H
#define FILEINFO_H

#include <iostream>
#include <fstream>

class FileInfo {
protected:
  std::ifstream *m_file;
  size_t m_fileSize;

public:
  FileInfo(std::ifstream*);
  static size_t getFileSize(std::ifstream*);

  // Getters
  std::ifstream* file();
  size_t fileSize();
};

#endif
