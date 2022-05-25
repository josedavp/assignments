#!/bin/bash

if [ ! -d $1 ];
then 
    echo "$1 does not exist"
    exit 1
fi

function readCourse() {
read dept_code dept_name
read course_name
read course_sched course_start course_end
read credit_hours
read num_students
}

#Creates directory in case $4 is not made
if [ ! -d $4 ];
then 
    mkdir $4
fi

#Loop through all crs files
for  file in $1/*.crs; do

#reads file first
readCourse < $file



#    filename="$(basename "$file")"
 #   filename="$(echo "$filename" | sed -r -e 's/\.crs//g')"
    
    
 #   if [[ ${filename} -eq 7 ]]; 
 #   then
  #      couse_num=${filename:3:4}
    
  #  elif [[ ${filename} -eq 6 ]];
  #  then
  #      course_num=${filename:2:4}
  #  fi


#Checks if the course has an enrollment greater than 50 
if [[ $num_students -gt 50 && $# -eq 4 ]];
then
    
    #create sed file to that specific course file 
    #execute it then it will need to output the template correctly

    #Do this here->

    filename="$(basename "$file")"
    filename="$(echo "$filename" | sed -r -e 's/\.crs//g')"

    #WORKS BUT CANT USE GREP
    #course_num=$(echo $file | grep -Eo '[0-9]{4}')
    #course_num=$filename
    
    #I also tried this other way
# course_num=${filename:3:4}
#didn't work

    if [[ ${#filename} -eq 7 ]]; 
    then
        extra=${filename:0:3}
        course_num=${filename:4}
    elif [[ ${#filename} -eq 6 ]];
    then
        extra=${filename:0:2}
        course_num=${filename:4}
    fi

    if [ -e $2 ];
    then
        cat > pAssign4.sed << EOF
    s|\[\[dept_code\]\]|$dept_code|g  
    s|\[\[dept_name\]\]|$dept_name|g 
    s|\[\[course_name\]\]|$course_name|g
    s|\[\[course_sched\]\]|$course_sched|g
    s|\[\[course_start\]\]|$course_start|g
    s|\[\[course_end\]\]|$course_end|g
    s|\[\[course_hours\]\]|$credit_hours|g
    s|\[\[num_students\]\]|$num_students|g
    s|\[\[course_num\]\]|$course_num|g
    s|\[\[date\]\]|$date|g
EOF

        sed  -f pAssign4.sed $2 > "$4/$filename.warn" 
 #   cp "$2" "$4/$filename.warn"
   
  #  sed -e pAssign4.sed > $4/$filename.warn
    else
        echo "Error"
    fi
            #output directory make sure its created and course name.warn
elif [[ $num_students -gt 50 && $# -eq 6 ]];
then
    d1=$5
    d2=$6

    filename="$(basename "$file")"
    filename="$(echo "$filename" | sed -r -e 's/\.crs//g')"
    
    
    if [[ ${#filename} -eq 7 ]]; 
    then
        extra=${filename:0:3}
        course_num=${filename:4}
    elif [[ ${#filename} -eq 6 ]];
    then
        extra=${filename:0:2}
        course_num=${filename:4}
    fi    
#if [[ ${filename} -eq 7 ]]; 
 #    then
  #      couse_num=${filename:0:3:4}
    
 #   elif [[ ${filename} -eq 6 ]];
  #  then
#        course_num=${filename:0:2:4}
#    fi

    if [ -e $2 ];
    then
        
        cat > pAssign4.sed << EOF
    s!${d1}dept_code${d2}!$dept_code!g  
    s!${d1}dept_name${d2}!$dept_name!g 
    s!${d1}course_name${d2}!$course_name!g
    s!${d1}course_sched${d2}!$course_sched!g
    s!${d1}course_start${d2}!$course_start!g
    s!${d1}course_end${d2}!$course_end!g
    s!${d1}course_hours${d2}!$credit_hours!g
    s!${d1}num_students${d2}!$num_students!g
    s!${d1}course_num${d2}!$course_num!g
EOF

        sed  -f pAssign4.sed $2 > "$4/$filename.warn" 
    else
        echo "Error"
    fi
fi
    rm -f pAssign4.sed
done
