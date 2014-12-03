#!/bin/bash

gcc ../../Input/Keyboard.c Tester_Keyboard.c -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Input -o Test_Keyboard_Program  >& error_compil.err
if [ `echo $?`  == 0 ]
then
	echo "Compilation successed."
	echo -e "Executing test program:\n"
	./Test_Keyboard_Program & >& err_exec.err
	wait

	echo -e "\n\n\tErrors shown while executing:\n"
	cat err_exec.err
else
	echo "Error from compiling:"
	cat error_compil.err
fi
