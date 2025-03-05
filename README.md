# Advent Of Code

Personal repository of [Advent of Code](#about-advent-of-code) solutions.

## What is Advent of Code

Directly quoted from original page:

> Advent of Code is an Advent calendar of small programming puzzles for a variety of skill levels that can be solved in any programming language you like. People use them as interview prep, company training, university coursework, practice problems, a speed contest, or to challenge each other.

## How to build

This is a C++ project and build manages by cmake.

### Build
___
```bash
mkdir build
cd build
cmake ../
make
```

There is a Cmake option to choose which inputs is using while compiling and running. By default this option is _off_ state. If it is _off_ state, make command copy files under inputs/test folder otherwise inputs/real folder.

```bash
-DREAL=ON
```

I am not going to share real inputs as stated in the Advent of Code about page. If you'd like test my code with your real input, please locate those on proper folder.

### Run
___
Build artifacts are put under related year folder. 2024 executable is under _2024/_ folder. Executable name is _AoC_. 
