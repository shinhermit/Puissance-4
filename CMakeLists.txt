cmake_minimum_required(VERSION 2.6) # In order to avoid a warning, tell the minimal version required

# Project Name
project(power4)

#Allows to generate option -Iinclude like in the makefile
include_directories(include)

#function file() gets the complete list of files
# and puts it the var that is its second argument (source_files)
file(
    GLOB_RECURSE
    source_files
    src/*.c
    include/*.h
)

# Déclaration de l'exécutable
add_executable(
    ../power4
    ${source_files}
)
