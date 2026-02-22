# Wheel-Of-Fortune
wheel of fortune command line game implemented in C++

## Building with CMake ⚙️

This project provides a simple CMake build setup. To compile the game:

1. Create a build directory and navigate into it:
   ```sh
   mkdir -p build && cd build
   ```
2. Run CMake to configure the project:
   ```sh
   cmake ..
   ```
3. Build the executable:
   ```sh
   cmake --build .
   ```

The resulting binary (`WheelOfFortune`) will be placed in the `build` folder.  
Because the game reads puzzle files relative to the current working directory, you have a couple of options:

* run the executable from the project root (e.g. `./build/WheelOfFortune`).
* or simply change into the build directory before launching, since CMake will copy the `puzzles/` directory there automatically:

```sh
cd build
./WheelOfFortune
```

The copy step happens automatically every time you build, courtesy of a `copy_puzzles` custom target defined in `CMakeLists.txt` which mirrors `puzzles/` into the binary tree.


(optional) install the program with:

```sh
cmake --install .
```
