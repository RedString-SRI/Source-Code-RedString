#!/bin/bash

gcc ../../../FileManager/FileManager.c ../../../Descriptor/Sound/SoundDesc.c ../../../Descriptor/BaseDesc.c test.c ../../../Globals.c -I ../../../ -I ../../../FileManager -I ../../../Descriptor/ -I ../../../Descriptor/Sound -pg -o test  >& err_compil.err
if [ `echo $?`  == 0 ]
then
	echo "Compilation successed."
	echo -e "Executing test program:\n"
	./test  2> err_exec.err
	#wait

	echo -e "\n\n\tErrors shown while executing:\n"
	cat err_exec.err
else
	echo "Error from compiling:"
	cat err_compil.err
fi
