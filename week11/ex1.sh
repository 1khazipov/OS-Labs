truncate -s 50M lofs.img
mkdir lofsdisk
sudo losetup -f lofs.img
sudo mkfs -t ext4 lofs.img
sudo mount -o loop lofs.img lofsdisk/
