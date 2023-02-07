# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/media/sf_D_DRIVE/Linux/linux/rgr-rumeone-main/cmake-build-debug/_deps/googletest-src"
  "/media/sf_D_DRIVE/Linux/linux/rgr-rumeone-main/cmake-build-debug/_deps/googletest-build"
  "/media/sf_D_DRIVE/Linux/linux/rgr-rumeone-main/cmake-build-debug/external/gtest"
  "/media/sf_D_DRIVE/Linux/linux/rgr-rumeone-main/cmake-build-debug/external/gtest/tmp"
  "/media/sf_D_DRIVE/Linux/linux/rgr-rumeone-main/cmake-build-debug/external/gtest/src/googletest-populate-stamp"
  "/media/sf_D_DRIVE/Linux/linux/rgr-rumeone-main/cmake-build-debug/external/gtest/src"
  "/media/sf_D_DRIVE/Linux/linux/rgr-rumeone-main/cmake-build-debug/external/gtest/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/media/sf_D_DRIVE/Linux/linux/rgr-rumeone-main/cmake-build-debug/external/gtest/src/googletest-populate-stamp/${subDir}")
endforeach()
