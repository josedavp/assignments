#!/bin/bash

#Asks for the item number
read -p "Enter an item number: " item_number

#Assigns to filename and find the file path
filename="./data/$item_number.item"

#If the file is found then removes the file otherwise it will echo out an error
if [[ -f $filename ]];
then


    
    rm data/$item_number.item

    echo $item_number "was successfully deleted." 
    echo "DELETED: " $item_number " - " `date` >> data/queries.log
    #echo $simple_name "was successfully deleted." 
elif [[ ! -f $filename ]];
then 
    echo "ERROR: item was found"
fi

