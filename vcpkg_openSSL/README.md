# The  OpenSSL deprecated library causes issues within vcpkg package manager 

Small test solution reproducing the compilation error that are appearing once [ **vcpkg** packages manager](https://github.com/microsoft/vcpkg/). is installed on a machine.
  - *dll4test* - DLL using CURL with OpenSSL
  - *curl_tester* - command line application calling the HelloBing() exported function of dll4test.dll

The problem is described here.