#!/bin/bash

gcc ../../../FileManager/FileManager.c ../../../Configurator/Configurator.c ../../../Globals.c ../../../Input/Keyboard.c ../../../Descriptor/Sound/SoundDesc.c ../../../SearchEngine/Sound/SoundSearch.c Tester_SoundSearch.c -I ../../../ -I ../../../FileManager -I ../../../Configurator -I ../../../Input -I ../../../Desc -I ../../../Descriptor/Sound -I ../../../Indexer -I ../../../SearchEngine/Sound -o Test_SoundSearch_Program  2> error_compil.err
if [ `echo $?`  == 0 ]
then
	echo "Compilation successed."
	echo -e "Executing test program:\n"
	./Test_SoundSearch_Program  2> err_exec.err

	echo -e "\n\n\tErrors shown while executing:\n"
	cat err_exec.err
else
	echo "Error from compiling:"
	cat error_compil.err
fi
