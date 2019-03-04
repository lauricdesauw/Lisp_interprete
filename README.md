# C++Lisp Interpreter

This interpreter was developed as a project for the prog1 class of the ENS Rennes.

## Build Status

This project is over. Final version was to be released by 04/03/2019 at 13h45 CEST.
The sources are given within the archive.

## Requirements

Latest version of C++ libraries and compiler are required (works with g++ and clang++).
Make is also required to compile all the sources together.

## Demo instructions

- Unzip the archive BegueBastideCoudrayDesauw.zip
- Run `$ sh demo.sh` in the unzipped directory

## Build instructions

- Unzip the archive BastideCoudrayDuronPiau.zip
- Run `$ make` in the unziped directory
- Execute `$ ./cpplisp`
> **Note :**  You can directly load a file using its path by executing `$ ./raytracer path`

## Features of the interpreter

This interpreter implements various features :

- Basic Lisp language interpretation
- load function to load files to the interpreter
- A stat mode to have data on created object
- A garbage collector to avoid memory leaks


## Credits

This project was develloped by **Clara Begue**,**Paul Bastide**, **Alex Coudray** and **Lauric Desauw**  based on an idea from Luc Bougé, teacher at the ENS Rennes.
You can also find our project repository on [Github](https://github.com/lauricdesauw/Lisp_interprete.git)
