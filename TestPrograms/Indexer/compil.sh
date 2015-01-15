#!/bin/bash

gcc ../../FileManager/FileManager.c ../../Indexer/Indexer.c ../../Generic-stack/generic_stack.c ../../Globals.c ../../Descriptor/Sound/SoundDesc.c ../../Descriptor/BaseDesc.c Tester_Indexer.c -I ../../Generic-stack/ -I /home/rayope/SRI/FilRouge/Source-Code-RedString/ -I /home/rayope/SRI/FilRouge/Source-Code-RedString/FileManager -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Descriptor -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Descriptor/Sound -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Indexer -o Test_Indexer_Program  >& error_compil.err
if [ `echo $?`  == 0 ]
then
	echo "Compilation successed."
	echo -e "Executing test program:\n"
	./Test_Indexer_Program  2> err_exec.err

	echo -e "\n\n\tErrors shown while executing:\n"
	cat err_exec.err
else
	echo "Error from compiling:"
	cat error_compil.err
fi
