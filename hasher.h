/* Name: hasher.h
 * Author: Waleed Qawasmi
 */

#ifndef HASHER_H
#define HASHER_H

// Required due to MD5's security issues
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

#include <iostream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/simple.h>
#include <cryptopp/md5.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

byte *getMD5Hash(byte*, size_t size, byte *digest);

#endif
