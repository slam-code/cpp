cpplask
=======

Flask (Python Microframework) clone in c++11. This is really just me playing, there's something very similar (and better) here: https://github.com/ipkn/crow

All code copyright Henry Slater unless otherwise stated.

Released under LGPLv3 or later

Building
--------

It doesn't have any particularly arduous requirements, just a modern g++ and make

Testing
-------

Unit tests have been written using Google Test (libgtest). On my ubuntu machine, to get them to work was:

    sudo apt-get install libgtest-dev
    cd /usr/src/gtest
    sudo cmake .
    sudo make
    sudo mv libg* /usr/lib/

and then to actually build and run the tests (so you'll want to cd back into the cpplask directory (or just `cd -`):

    make tests
