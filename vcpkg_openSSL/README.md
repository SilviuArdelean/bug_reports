# The  OpenSSL deprecated library causes issues within vcpkg package manager 

Small test solution reproducing the compilation errors that are appearing once the [ **vcpkg** packages manager](https://github.com/microsoft/vcpkg/) is installed on a machine.
  - *dll4test* - DLL using CURL with OpenSSL
  - *curl_tester* - command line application calling the HelloBing() exported function of dll4test.dll

The problem is described [here](https://silviuardelean.ro/2019/12/14/openssl-vs-vcpkg-some-strange-experiences/).
