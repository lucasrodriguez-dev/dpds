# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/workspaces/dpds/build/_deps/crow-src"
  "/workspaces/dpds/build/_deps/crow-build"
  "/workspaces/dpds/build/_deps/crow-subbuild/crow-populate-prefix"
  "/workspaces/dpds/build/_deps/crow-subbuild/crow-populate-prefix/tmp"
  "/workspaces/dpds/build/_deps/crow-subbuild/crow-populate-prefix/src/crow-populate-stamp"
  "/workspaces/dpds/build/_deps/crow-subbuild/crow-populate-prefix/src"
  "/workspaces/dpds/build/_deps/crow-subbuild/crow-populate-prefix/src/crow-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/workspaces/dpds/build/_deps/crow-subbuild/crow-populate-prefix/src/crow-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/workspaces/dpds/build/_deps/crow-subbuild/crow-populate-prefix/src/crow-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
