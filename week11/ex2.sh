sudo touch lofsdisk/file1
sudo touch lofsdisk/file2
sudo echo "Albert" > sudo lofsdisk/file1
sudo echo "Khazipov" > sudo lofsdisk/file2
sudo mkdir lofsdisk/bin
sudo mkdir lofsdisk/lib
sudo cp /bin/bash ./lofsdisk/bin/bash
bdeps="$(ldd /bin/bash | egrep -o '/lib.*\.[0-9]')"
for i in $bdeps; do sudo cp -v --parents "$i" "./lofsdisk"; done
gcc ex2.c -o comp.out
sudo cp comp.out lofsdisk
sudo chroot lofsdisk/ /bin/bash -c "./comp.out > ex2.txt"
sudo sh -c "./comp.out >> lofsdisk/ex2.txt"
