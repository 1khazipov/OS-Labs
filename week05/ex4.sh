gcc -o comp ex4.c -pthread
(time ./comp 10000000 1) 2>&1 | cat > ex4.txt
echo "" >> ex4.txt
(time ./comp 10000000 2) 2>&1 | cat >> ex4.txt
echo "" >> ex4.txt
(time ./comp 10000000 4) 2>&1 | cat >> ex4.txt
echo "" >> ex4.txt
(time ./comp 10000000 10) 2>&1 | cat >> ex4.txt
echo "" >> ex4.txt
(time ./comp 10000000 100) 2>&1 | cat >> ex4.txt
