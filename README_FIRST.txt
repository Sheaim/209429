Compilation process is begun by setting up the enviroment for the compiler.
In case of Code::Blocks' mingw32 this is accomplished by running 
mingwvars.bat in MinGW folder (see \build\setup.bat for an example)

Next step is running cmake to generate appropriate makefile.
Afterwards the project is compiled using mingw32-make.exe command and run using ctest commant
(see \QuicksortBenchmark\setupAndTest.bat for an example)

To compile different version of the project (e.g. the worse version of quicksort) you need to exchange the names of CMakeLists files 
so that the version you want to run is named CMakeLists. This has to be done by hand as there is no .bat file to automate this process.

CAUTION: QuicksortBenchmark is dependent on quicksort. Also - versions of the programs that do not use templates have their functions/members defined 
in additional .cpp files, while those that do use them are contained in a single header file.

WARNING: common folder HAS to be built first, as it generates a library which most other programs reference to!

These files are composed specifically for my machines and may need tweaking if you're using a different compiler.
Consult cmake manual for further details.
