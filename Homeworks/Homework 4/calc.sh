#!/bin/bash
# Calculator
# Paul Ofremu Jr., pofremu1@student.gsu.edu

menu ()
{
echo "============CALCULATOR==========="
echo "Enter expressions without spaces"
echo "Enter \"clear\" to clear screen or \"cancel\" to exit"
echo ""
}

menu
while true; do
	# Get user input	
	echo "Enter an expression:"
	read expr
	
	#
	case "$expr" in
		"cancel")
			exit
			;;

		"clear")
			clear
			menu
			;;

		*)
			# If input matches regex for valid expression evaluate with bc              
			[[ $expr =~ ([0-9]+)([/%*+-])([0-9]+) ]] && echo "Answer: " && echo "$expr" | bc || echo "Invalid Expression."
			echo ""
			;;
	esac
done
