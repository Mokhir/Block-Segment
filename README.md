# Block Segment

**About**

Tool that segments binary files into blocks of a given size and returns the MD5 checksum of each block.
Must have CryptoPP library installed.

## SETUP

**Clone repo:**
```
git clone https://github.com/wqawasmi/Block-Segment
```

**Setup CryptoPP (assuming you're on Debian. It's on Windows/OS X too):**
```
sudo apt-get install apt-cache pkgnames | grep -i crypto++
sudo apt-get install libcrypto++8 libcrypto++8-dbg libcrypto++-dev
```
  
 **Build project from source**
```
make
```
