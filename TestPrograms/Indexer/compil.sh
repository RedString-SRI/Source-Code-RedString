#!/bin/bash

gcc ../../FileManager/FileManager.c ../../Indexer/Indexer.c ../../Globals.c ../../Desc/Sound/SoundDesc.c Tester_Indexer.c -I /home/rayope/SRI/FilRouge/Source-Code-RedString/ -I /home/rayope/SRI/FilRouge/Source-Code-RedString/FileManager -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Desc -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Desc/Sound -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Indexer -o Test_Indexer_Program  >& error_compil.err
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
