#!/bin/bash

gcc ../../FileManager/FileManager.c ../../Configurator/Configurator.c ../../Globals.c ../../Input/Keyboard.c ../../Desc/Sound/SoundDesc.c Tester_Configurator.c -I /home/rayope/SRI/FilRouge/Source-Code-RedString/ -I /home/rayope/SRI/FilRouge/Source-Code-RedString/FileManager -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Configurator -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Input -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Desc -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Desc/Sound -I /home/rayope/SRI/FilRouge/Source-Code-RedString/Indexer -o Test_Configurator_Program  2> error_compil.err
if [ `echo $?`  == 0 ]
then
	echo "Compilation successed."
	echo -e "Executing test program:\n"
	./Test_Configurator_Program  2> err_exec.err

	echo -e "\n\n\tErrors shown while executing:\n"
	cat err_exec.err
else
	echo "Error from compiling:"
	cat error_compil.err
fi
