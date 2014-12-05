#!/bin/bash

gcc  Tester_Keyboard.c -I ../../ -I ../../Input -I /home/rayope/SRI/FilRouge/Source-Code-RedString/FileManager -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Input -o Test_Keyboard_Program  >& error_compil.err
if [ `echo $?`  == 0 ]
then
	echo "Compilation successed."
	echo -e "Executing test program:\n"
	./Test_Keyboard_Program  2> err_exec.err
	#wait

	echo -e "\n\n\tErrors shown while executing:\n"
	cat err_exec.err
else
	echo "Error from compiling:"
	cat error_compil.err
fi
