#!/bin/sh
DoExitAsm ()
{ echo "An error occurred while assembling $1"; exit 1; }
DoExitLink ()
{ echo "An error occurred while linking $1"; exit 1; }
echo Assembling program
as -o test.o test.s
if [ $? != 0 ]; then DoExitAsm program; fi
rm test.s
