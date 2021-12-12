# YGOPro2/YGOmobile deck format transform

## Usage
```
./bin/ygodeck [source_file] [dest_file]

```
Program can identify format automatically. If ```source_file``` is ygopro2 format, then ```dest_file``` will be in ygomobile format, vice versa.

```
./bin/test [source_file] [dest_file]
```
test if ```[source_file]``` and ```[dest_file]``` are the same. Result is shown
in stdout.

## Compile
First clone into local folder.
```
mkdir build
mkdir bin
cd build
cmake ..
make
```
Program is compiled in ```bin``` folder.
