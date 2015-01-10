#!/bin/bash

gcc ../../../FileManager/FileManager.c ../../../Configurator/Configurator.c ../../../Globals.c ../../../Input/Keyboard.c ../../../Descriptor/Sound/SoundDesc.c ../../../SearchEngine/Sound/SoundSearch.c Tester_SoundSearch.c -I /home/rayope/SRI/FilRouge/Source-Code-RedString/ -I /home/rayope/SRI/FilRouge/Source-Code-RedString/FileManager -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Configurator -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Input -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Desc -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Descriptor/Sound -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Indexer -I ../../../SearchEngine/Sound -o Test_SoundSearch_Program  2> error_compil.err
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
