#!/usr/bin/env bash

if [ `uname` == 'Darwin' ]; then
  # since Apple doesn't care enough to provide its users with OpenMP-supporting compiler by default, so do we
  export NO_OPENMP=1
fi

make -j4 && cp PFG $PREFIX/bin/PFG
