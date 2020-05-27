#!/bin/bash

echo "Compilando OpenMp..."
gcc -o compf cannonOpenMPF.c -fopenmp -lm
echo "Compilado :3"

echo "Compilando mpi"
mpicc cannonMPIF.c -o cmpif -lm
echo "Compilado :3"

echo "\n\n Ejecutando OpenMP"

for (( j=0; j<10; j++ ))
do
    for k in 2 4 8 16
    do
        echo ""
        echo "<-$k->"
        for (( i=16; i<=2048; i=i*2 ))
        do
            ./compf $i $k
        done
    done
    echo "<--------------------------------->"
done

echo "\n\n Ejecutando mpi"

for (( j=0; j<10; j++ ))
do
    for k in 2 4 8 16
    do
        echo ""
        echo "<-$k->"
        for (( i=16; i<=2048; i=i*2 ))
        do
            ./cmpif $i $k
        done
    done
    echo "<--------------------------------->"
done