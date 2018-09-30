# Lib-X-SVF
A library for implementing SVF and XSVF JTAG players.

This is a copy of [libxsvf](http://www.clifford.at/libxsvf/).

Branch _trunk_ keep the original svn trunk from http://svn.clifford.at/libxsvf/trunk/, at the moment, it updated to revision 102.

## Directories

1. trunk - based on the copy from [libxsvf](http://www.clifford.at/libxsvf/).
2. lib   - C++ wrapper for libxsvf, so we can use [Google Test](https://github.com/google/googletest) to develop unit test.
3. tests - unit tests in [Google Test](https://github.com/google/googletest).

## Build
```
git clone git@github.com:decodable/Lib-X-SVF.git
cd Lib-X-SVF/
mkdir build
cd build
cmake ..
make
make test
ctest -T memcheck
```

## Docker
Compiled and tested in the docker [ubuntu_cpp_dev](https://hub.docker.com/r/codible/ubuntu_cpp_dev/).

## References
1. [SVF and XSVF File Formats for Xilinx Devices](https://www.xilinx.com/support/documentation/application_notes/xapp503.pdf)
2. [Serial Vector Format Specification](http://www.jtagtest.com/pdf/svf_specification.pdf)
3. [SPI Configuration and Flash Programming in UltraScale FPGAs](https://www.xilinx.com/support/documentation/application_notes/xapp1233-spi-config-ultrascale.pdf)

