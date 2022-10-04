gcc -o comp ex3.c -pthread
(time ./comp 10000000 1) 2>&1 | cat > ex3.txt
echo "" >> ex3.txt
(time ./comp 10000000 2) 2>&1 | cat >> ex3.txt
echo "" >> ex3.txt
(time ./comp 10000000 4) 2>&1 | cat >> ex3.txt
echo "" >> ex3.txt
(time ./comp 10000000 10) 2>&1 | cat >> ex3.txt
echo "" >> ex3.txt
(time ./comp 10000000 100) 2>&1 | cat >> ex3.txt
