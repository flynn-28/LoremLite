# LoremLite

## Contents
1. [Overview](#overview)
2. [Installation](#installation)
    2.1 [Downloading](#downloading)
    2.2 [Build from Source](#building-from-source)
3. [Include Library](#include-library)
4. [Usage](#usage)
5. [Compile and Link](#compile-and--link)
6. [Useful Resources](#useful-links)
7. [Support](#support)

## Overview
LoremLite is a C++ library that is lightweight and cross platform. It is designed for generating randomized Lorem Ipsum text based on a specified amount of words. 

## Installation
You can install LoremLite in your project by downloading a precompiled library or building it from source.
### Downloading
You can download a precompiled version of the library [here](https://github.com/flynn-28/LoremLite/releases/tag/Release). The uncompressed folders have the following structure:
```bash
LoremLite/
├── include/
│   └── LoremLite.h
└── lib/
    └── libLoremLite.a
```
### Building from Source
**1. Clone Repository and Open folder**
```bash
git clone https://github.com/flynn-28/LoremLite && cd LoremLite
```
**2. Create and open build dir**
```bash
mkdir build && cd build
```
**3. Build Library**

**Linux**:
```bash
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```
**Windows (MinGW)**:
```bash
cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
mingw32-make
```

## Include Library
**1. Include the header**
```cpp
#include <LoremLite.h>
```
**2. Link the library (assuming include and lib dirs)**

Add this to your compile comand (assuming g++):
```bash 
-Iinclude/ -Llib/ -lLoremLite
```


## Usage
Below is an example program using the library. This program prompts a user for input then genrates that many words of lorem ipsum text.
```cpp
#include "LoremLite.h" // include loremlite library
#include <iostream> // for io

int main() { // main function
    int wordCount; // declare number of words to gnerate
    
    std::cout << "Enter the number of words to generate: "; // prompt for words to generate
    std::cin >> wordCount;  // get word count from prompt

    std::string loremText = LoremLite::generate(wordCount); // generate lorem ipsum text based on input
    std::cout << "\nGenerated Lorem Ipsum Text:\n" << loremText << "\n";  // print output

    return 0;
}
```

## Compile *and*  Link
the following command assumes **include** and **lib** dirs
```bash
g++ -o example example.cpp -Iinclude/ -Llib/ -lLoremLite
```

## Useful Links
1. [lipsum.com](https://www.lipsum.com/)
2. [Lorem Ipsum wikipedia](https://en.wikipedia.org/wiki/Lorem_ipsum)

## Support
For support, email [msmc.dev@gmail.com](mailto:msmc.dev@gmail.com), or submit an issue or pull request.