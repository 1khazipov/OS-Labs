echo "Albert" > ../week01/file.txt
rm -f _ex2.txt
link ../week01/file.txt _ex2.txt
inodenumber=$(ls -i ../week01/file.txt | cut -d " " -f1)
find . -inum $inodenumber > ex2.txt
find . -inum $inodenumber -exec rm {} \; >> ex2.txt
find / -inum $inodenumber >> ex2.txt
