SpellChecker
============

Simple spell checker application written in C++/Qt


# Pre-requisites:

The project depends on Qt4, Hunspell 1.3


on fedora:

```
yum install qt-devel hunspell-devel
```

# Build:

go to /build folder:
```
$ qmake-qt4 ../src/
$ make
```

# Usage:

Execute
```
./SpellChecker
```
After starting the application , Load dictionary from /dictionary folder bundled English (US) dictioanry.
You may use any hunspell format dictionary file.
