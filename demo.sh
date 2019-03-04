make
echo
echo Write quit to quit the interpretor
read x

./main demo.lsp

echo
echo We will now show you the effect of the garbage collector
read x

valgrind --leak-check=summary ./main

make clean
