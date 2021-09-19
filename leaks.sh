#!bin/sh

EXEC=./so_long
ARGS=map.ber
valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes --log-file=valgrin.log --track-origins=yes ./$EXEC $ARGS
grep -A1 "valgrind" valgrin.log | grep $EXEC
