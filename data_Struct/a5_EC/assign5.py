#!/usr/bin/env python3

import os
import sys
import glob

#checks if the first argument is a directory
if not os.path.isdir(sys.argv[1]):
    print(sys.argv[1] + " is not a directory ")
    sys.exit(1)
#IF NOT IT MAKES DIRECTORY
if not os.path.isdir(sys.argv[4]):
    os.mkdir(sys.argv[4])

#sys.argv[1] that will contain the .crs
crs_files = glob.glob(sys.argv[1] + "/*.crs")
print(crs_files)
#Meant to look into the file and read each file in a listed array one at a time
for arrFile in crs_files:
    try:
 #       print("arrFile = " + arrFile)
        with open(arrFile, 'r') as infile:
        #Used to read the crs file then get each word into an array
            date = sys.argv[3]
            i = 0
            for line in infile.readlines():
                line = line.rstrip()
                if i == 0:
                    (dept_code, dept_name) = line.split(" ", 1)
                elif i == 1:
                    course_name = line
                elif i == 2: 
        #MAY NOT BE INCLUDED COURSE_SCHED
                    course_sched, course_start, course_end = line.split(" ")
                elif i == 3:
                    credit_hours = line
                elif i == 4:
                    num_students = line
                i += 1
        #Checks if greater than 30 and if arg is equal to 5
            if int(num_students) > 30 and len(sys.argv) == 5:
                fileExtra = os.path.basename(arrFile)
                filename = fileExtra[:-4]
                course_num = filename[-4:]
#                print("CourseNUM= " + course_num)
 #               print("First if/ filename =  " + filename)
#Used to check if its an actual file template then assigning filename_warn to the new file + .warn extension
                if os.path.isfile(sys.argv[2]):
                    if not ".warn" in filename:
                        filename_warn = filename + ".warn"
  #                      print("Inside filename_warn= " + filename_warn)
#Opening template to read each line,and filename to write into
                    with open(sys.argv[2], 'r') as template_file:
                        with open(sys.argv[4] + "/" + filename_warn, 'w') as outputFile:
                            for line in template_file.readlines():
                                line = line.replace("[[dept_code]]", dept_code)
                                line = line.replace("[[dept_name]]", dept_name) 
                                line = line.replace("[[course_name]]", course_name) 
                                line = line.replace("[[course_start]]", course_start)
                                line = line.replace("[[course_end]]", course_end)
                                line = line.replace("[[credit_hours]]", credit_hours)
                                line = line.replace("[[num_students]]", num_students)
                                line = line.replace("[[course_num]]", course_num)
                                line = line.replace("[[date]]", date)
                                outputFile.write(line)
#EXTRA CREDIT
            if int(num_students) > 30 and len(sys.argv) == 7:
                d1 = sys.argv[5]
                d2 = sys.argv[6]
                fileExtra = os.path.basename(arrFile)
                filename = fileExtra[:-4]
                course_num = filename[-4:]
   #             print("CourseNUM= " + course_num)
    #            print("First if/ filename =  " + filename)
#Used to check if its an actual file template then assigning filename_warn to the new file + .warn extension
                if os.path.isfile(sys.argv[2]):
                    if not ".warn" in filename:
                        filename_warn = filename + ".warn"
     #                   print("Inside filename_warn= " + filename_warn)
#Opening template to read each line,and filename to write into
                    with open(sys.argv[2], 'r') as template_file:
                        with open(sys.argv[4] + "/" + filename_warn, 'w') as outputFile:
                            for line in template_file.readlines():
                                #read and then replace
                                dept_code_key = d1 + "dept_code" + d2
                                dept_name_key = d1 + "dept_name"+ d2
                                course_name_key = d1 + "course_name"+ d2
                                course_start_key = d1 + "course_start"+ d2
                                course_end_key = d1 + "course_end" + d2
                                credit_hours_key = d1 + "credit_hours" + d2
                                num_students_key = d1 + "num_students" + d2
                                course_num_key = d1 + "course_num" + d2
                                date_key = d1 + "date" + d2
                                #Assign and Replace
                                line = line.replace(dept_code_key, dept_code)
                                line = line.replace(dept_name_key, dept_name) 
                                line = line.replace(course_name_key, course_name) 
                                line = line.replace(course_start_key, course_start)
                                line = line.replace(course_end_key, course_end)
                                line = line.replace(credit_hours_key, credit_hours)
                                line = line.replace(num_students_key, num_students)
                                line = line.replace(course_num_key, course_num)
                                line = line.replace(date_key, date)
                                outputFile.write(line)
    except IOError:
        print("Could not read from file =  " + err.filename)
