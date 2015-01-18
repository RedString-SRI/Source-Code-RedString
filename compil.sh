#!/bin/bash

gcc Type_Bool.h SearchEngine/SearchEngine.c Interface/interface.c FileManager/FileManager.c Descriptor/Sound/SoundDesc.c Descriptor/Picture/PictureDesc.c Configurator/Configurator.c Input/Keyboard.c Descriptor/BaseDesc.c main.c Globals.c -I . -I SearchEngine.c -I Interface -I FileManager -I Descriptor/ -I Descriptor/Sound -I Configurator -I Input -I Descriptor/Picture -pg -o test -lm  >& err_compil.err
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
