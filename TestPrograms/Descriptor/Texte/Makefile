//RANDRIA Estelle


TextDesc.o: TextDesc.c TextDesc.h Type_Bool.h
	gcc -c -o TextDesc.o TextDesc.c

Test_TextDesc.c : Test_TextDesc.c 
	gcc -c -o Test_TextDesc.o Test_TextDesc.c

Test_TextDesc: Test_TextDesc_Program.o TextDesc.o
	gcc -o Test_TextDesc Test_TextDesc.o TextDesc.o

Test_DescTextCreation.o : Test_DescTextCreation.c
	gcc -c -o Test_DescTextCreation.o Test_DescTextCreation.c 

DescTextCreation : Test_DescTextCreation.o TextDesc.o 
	gcc -o  Test_DescTextCreation Test_DescTextCreation.o TextDesc.o
