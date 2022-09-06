date
sleep 3
mkdir folderRoot
date
sleep 3
mkdir folderHome
cd folderRoot
ls -t -r /
date
sleep 3
ls -t -r / > root.txt
cd ../folderHome
ls -t -r ~
date
sleep 3
ls -t -r ~ > home.txt
cd ..
ls folderRoot
ls folderHome
