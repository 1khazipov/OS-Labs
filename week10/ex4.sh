rm -fr tmp
mkdir tmp
cd tmp
touch file1
touch file2
rm -f link1
ln file1 link1
cd ..
rm -f ex4.txt
gcc ex4.c -o comp.out
./comp.out
