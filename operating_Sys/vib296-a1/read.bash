#!bin/bash

    #Selects the item number file and assigns it to a variable
    echo "Enter an item number: " 
    read item

    filename="./data/$item.item"


    if [ ! -r $filename ];
    then
        echo "ERROR: item not found"
        exit 1;
    else
        #read the file
        function readItem() {

            read simple_name item_name
            echo "Simple Name: " $simple_name
            echo "Item Name: " $item_name
            read current_quantity max_quantity
            echo "Qty: " $current_quantity $max_quantity
            read description
            echo "Description: " $description
    
        } 
        readItem < $filename
    fi
