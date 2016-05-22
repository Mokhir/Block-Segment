/* Name: fileinfo.cpp
 * Author: Waleed Qawasmi
 */

#include "fileinfo.h"

FileInfo::FileInfo(std::ifstream *file) {
  m_file = file;
  m_fileSize = getFileSize(file);
}

size_t FileInfo::getFileSize(std::ifstream *file) {
  // Retrieve file size
  std::streampos curr, begin, end;
  curr =  file->tellg();

  // Locate beginning and final stream positions
  file->seekg(0, std::ios::beg);
  begin = file->tellg();
  file->seekg(0, std::ios::end);
  end = file->tellg();

  // Reset position and calculate file size
  file->seekg(curr, std::ios::beg);

  return end - begin;
}

// Getters
std::ifstream* FileInfo::file() {
  return m_file;
}

size_t FileInfo::fileSize() {
  return m_fileSize;
}
