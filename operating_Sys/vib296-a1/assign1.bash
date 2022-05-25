#!/bin/bash

if [ ! -d ./data ];
then
    mkdir ./data
fi
    

while true
do
    #Prints the menu
    echo "Enter one of the following actions or press CTRL-D to exit."
    
    echo "C - create a new item"
    echo "R - read an existing item"
    echo "U - update an existing item"
    echo "D - delete an existing item"
    #reads inputed value
    read letter   
    
    if [ $letter == "C" ] || [ $letter == "c" ];
    then
        bash ./create.bash

    elif [ $letter == "R" ] || [ $letter == "r" ];
    then
        bash ./read.bash

    elif [ $letter == "U" ] || [ $letter == "u" ];
    then
        bash ./update.bash

    elif [ $letter == "D" ] || [ $letter == "d" ];
    then 
        bash ./delete.bash
    else
        echo "ERROR: invalid option"
    fi
done
