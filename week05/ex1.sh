gcc -o compp publisher.c
gcc -o comps subscriber.c

x-terminal-emulator -e ./compp $1 &

for ((i = 0 ; i < $1 ; i++)); do
  x-terminal-emulator -e ./comps $i &
done
