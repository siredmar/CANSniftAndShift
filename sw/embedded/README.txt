AVR32 Toolchain installation:
=============================
before_install:
  - wget http://www.atmel.com/Images/avr-headers.zip
  - wget http://www.atmel.com/Images/avr32-gnu-toolchain-3.4.0.332-linux.any.x86.tar.gz

install:
  - tar -xzf avr32-gnu-toolchain-3.4.0.332-linux.any.x86.tar.gz
  - mv avr32-gnu-toolchain-linux_x86 avr32-tools
  - unzip -qq avr-headers.zip && mv avr-headers/avr32 avr32-tools/avr32/include
  - export PATH=$PWD/avr32-tools/bin:$PATH
