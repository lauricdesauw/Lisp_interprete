make
echo
echo Write quit to quit the interpretor
echo Press enter to continue
read x

./cpplisp demo.lsp

echo
echo We will now show you the effect of the garbage collector
echo Press enter to continue
read x

valgrind --leak-check=summary ./cpplisp

make clean
