#!bin/bash

read -p "Item number: " item_number

#Opens file and updates the contents
filename="./data/$item_number.item"
if [[ -f $filename ]];
then
    read -p "Simple Name: " simple_name
    read -p "Item Name: " item_name
    read -p "Current: " current
    read -p "Qty: " quantity
    read -p "Description: " description
   
   {
    read old_simple_name item_name
    read old_current old_quantity
    read old_description
    } < $filename

    #Checks if any values are empty and saves the old info to the updated variables

    if [[ $simple_name == "" ]];
    then
        simple_name=$old_simple_name;
    fi

    if [[ $item_name == "" ]];
    then
        item_name=$old_item_name
    fi

    if [[ $current == "" ]];
    then
        current=$old_current
    fi

    if [[ $quantity == "" ]];
    then
        quantity=$old_quantity
    fi

    if [[ $description == "" ]];
    then
        description=$old_description
    fi

    #Deletes old file/ echos into file
    rm data/$item_number.item
    
    echo $simple_name $item_name >> $filename  
    echo $current $quantity >> $filename  
    echo $description >> $filename  
    
    #UPDATES into log else prints ERROR into log
    echo "UPDATED: " $simple " - " `date` >> data/queries.log
    
    elif [[ ! -f $filename ]];
    then
        echo "ERROR: item not found" 
    fi


