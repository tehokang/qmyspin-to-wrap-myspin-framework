mkdir -p build
cd build
cmake ../ -DCMAKE_TOOLCHAIN_FILE=../cmake/cross-general-arm-gcc-4.8.1.cmake
make
make install
