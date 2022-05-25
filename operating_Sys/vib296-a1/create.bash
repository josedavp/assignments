#!/bin/bash

#reads file 
    read -p "Item number: " item

    read -p "Simple name: " simple

    read -p "Current quantity: " current

    read -p "Maximum quantity: " quantity

    read -p "Description: " descriptions

#checks for item.item in directory
    if [ ! -f ./data/$item.item ]; 
    then

        echo $simple $item >> data/$item.item
        echo $current $quantity>> data/$item.item
        echo $descriptions >> data/$item.item

        echo "CREATED: " $simple " - " `date` >> data/queries.log
    
    elif [ -f ./data/$item.item ];
    then
        echo "ERROR: item already exists" >> data/queries.log
    fi


