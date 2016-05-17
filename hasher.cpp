/* Name: hasher.cpp
 * Author: Waleed Qawasmi
 */

#include "hasher.h"

// Returns MD5 checksum of a given block of data
byte *getMD5Hash(byte *data, size_t size, byte *digest) {
	// Digest to place newly created hash in
	if( digest == NULL)
		digest = (byte *)(malloc( sizeof(byte) * CryptoPP::Weak::MD5::DIGESTSIZE ));

	// Create hashing object and calculate digest
	CryptoPP::Weak::MD5 hash;
	hash.CalculateDigest( digest, data, size );

	// Save digest into a hex encoded string
	CryptoPP::HexEncoder encoder;
	std::string output;

	encoder.Attach( new CryptoPP::StringSink( output ) );
	encoder.Put( digest, sizeof(digest) );
	encoder.MessageEnd();

	std::cout << "Hex Encoded MD5: " << output << std::endl;
	return digest;
}
