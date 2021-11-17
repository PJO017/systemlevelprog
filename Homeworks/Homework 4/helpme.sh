#!/bin/bash
# Print manual for 10 favorite commands
# Paul Ofremu Jr., pofremu1@student.gsu.edu

touch "mandatabase.txt"
mandatabase="mandatabase.txt" 

while true; do
    echo ""
    # Get user input
    echo "Enter "exit" to exit"
    read -p "Enter a command: " command

    if [ $command = "exit" ]
    then
        exit 0
    fi
    
    # Make user input all uppercase
    command=$(echo "$command" | tr [a-z] [A-Z])

    # Check for the commandname(1) at the beginning and end of a line
    if [ ! -z "$(sed -n "/^$command(1)/,/$command(1)$/p" "$mandatabase")" ]
    then
        # Print everything in between first line and last line of command 
        sed -n "/^$command(1)/,/$command(1)$/p" "$mandatabase" | more
    else
        # Command is not found
        echo "Sorry , I cannot help you"
    fi
done
