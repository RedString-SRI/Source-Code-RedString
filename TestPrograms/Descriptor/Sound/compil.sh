#!/bin/bash

gcc ../../../FileManager/FileManager.c ../../../Descriptor/Sound/SoundDescriptor.c Tester_SoundDescriptor.c ../../../Globals.c -I /home/rayope/SRI/FilRouge/Source-Code-RedString/ -I /home/rayope/SRI/FilRouge/Source-Code-RedString/FileManager -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Descriptor/ -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Descriptor/Sound -pg -o Test_SoundDescriptor_Program  >& error_compil.err
if [ `echo $?`  == 0 ]
then
	echo "Compilation successed."
	echo -e "Executing test program:\n"
	./Test_SoundDescriptor_Program  2> err_exec.err
	#wait

	echo -e "\n\n\tErrors shown while executing:\n"
	cat err_exec.err
else
	echo "Error from compiling:"
	cat error_compil.err
fi
