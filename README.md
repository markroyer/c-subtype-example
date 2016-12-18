# c-subtype-example

This project demonstrates an object-oriented programming style in C
that has subtype polymorphism.

This project demonstrates an interesting technique for modeling C data
structures so that common object-oriented language features such as
information hiding and subtype polymorphism can be achieved.  While
this is not exactly the same inheritance that one would find in modern
object-oriented languages, it does not require any preprocessing,
macros, or modifications to the standard C compiler.

## Setup

For Debian based systems, make sure that you have the Debian
`build-essentials` package installed.  If you want to also build
Doxygen documentation, install the `doxygen` package.

## Compilation

The system can be compiled by typing

```bash
make
```

in the root directory.  This will produce an executable called
`c-subtype-example`.

If you have Doxygen installed, you can type

```bash
make docs
```

to generate the documentation files in the `docs` folder. 



## Usage

After building the program, it can be executed by typing

```bash
./c-subtype-example
```

at the command line.  The generated output should be as follows.


```
The toString() method is based on each object's subtype definition.
[ Object@0x5571d9c9d0a0, Object@0x5571d9c9d0e0, (1,2), (3,4), (5,6), (7,8), (9,10,11) ] - LinkedList pointer
[ Object@0x5571d9c9d0e0, (1,2), (3,4), (5,6), (7,8), (9,10,11) ] - Object pointer
Done!
```

## License

The project is licensed under the terms of the
[GPL3](https://www.gnu.org/licenses/gpl-3.0.en.html) license.


<!--  LocalWords:  Doxygen doxygen toString LinkedList
 -->
