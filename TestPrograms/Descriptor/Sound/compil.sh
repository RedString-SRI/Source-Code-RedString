#!/bin/bash

gcc ../../../FileManager/FileManager.c ../../../Descriptor/Sound/SoundDesc.c Tester_SoundDesc.c ../../../Globals.c -I /home/rayope/SRI/FilRouge/Source-Code-RedString/ -I /home/rayope/SRI/FilRouge/Source-Code-RedString/FileManager -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Descriptor/ -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Descriptor/Sound -pg -o Test_SoundDesc_Program  >& error_compil.err
if [ `echo $?`  == 0 ]
then
	echo "Compilation successed."
	echo -e "Executing test program:\n"
	./Test_SoundDesc_Program  2> err_exec.err
	#wait

	echo -e "\n\n\tErrors shown while executing:\n"
	cat err_exec.err
else
	echo "Error from compiling:"
	cat error_compil.err
fi
