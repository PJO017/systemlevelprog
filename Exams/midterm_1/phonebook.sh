#!/bin/bash
# Phone Book Utility
# Paul Ofremu Jr., pofremu1@student.gsu.edu

# Function to print menu options
options () 
{
echo ""
echo "+=====================+"
echo "| PHONE-BOOK UTILITY  |"
echo "+=====================+"
echo ""
echo "1)   Display Contacts"
echo "2)   Add Contact"
echo "3)   Delete Contact"
echo "4)   Edit Contact"
echo "5)   Find Contact"
echo "6)   Exit"
echo ""
}

# Where phone data is stored
database="phone.txt"

# Create database if not already created
touch "$database"
chmod 700 "$database"  # Only accessible by user

clear

while true; do
    case "$option" in
        1)  # Dislpay Contact
            echo ""
            echo "----------CONTACTS----------"
            sort -t"|" -k1 "$database" | column -s: -t # Print contacts in sorted order
            options
            read -p "Enter option >> " option
            continue
            ;;

        2) # Add Contact

            echo ""
            echo "Enter "exit" to exit"
            echo ""
            # Get first name
            read -p "Enter first name: " firstname

            if [ "$firstname" = "exit" ]
            then 
                exit
            fi

            # Get last name
            read -p "Enter last name: " lastname

            if [ "$lastname" = "exit" ]
            then 
                exit
            fi

            # Get phone number
            read -p "Enter phone number: " phone

            if [ "$phone" = "exit" ]
            then 
                exit
            fi

            # Get address
            read -p "Enter address: " address

            if [ "$address" = "exit" ]
            then 
                exit
            fi


            # Add contact in database
            echo "$firstname|$lastname|$phone|$address" >> "$database"
            echo ""
            echo "New contact added"

            options
            read -p "Enter option >> " option
            continue
            ;;
        3)
            # Delete contact
            echo ""
            echo "Enter "exit" to exit"
            echo ""
            # Get first name
            read -p "Enter first name: " firstname

            if [ "$firstname" = "exit" ]
            then 
                exit 0
            fi

            # Get last name
            read -p "Enter last name: " lastname

            if [ "$lastname" = "exit" ]
            then 
                exit 0
            fi

            query=$(grep -iw "$firstname|$lastname" "$database")

            if [ -z query ]
            then 
                echo ""
                echo "Contact not found"
                options
                read -p "Enter option >> " option
                continue
            else
                $(sed -i '/'$firstname\|$lastname'/Id' "$database")
                echo "Contact deleted"
            fi

            options
            read -p "Enter option >> " option
            continue
            ;;
        4)
            # Edit contact
            echo ""

            # Get first name
            read -p "Enter first name: " firstname

            if [ "$firstname" = "exit" ]
            then 
                exit 0
            fi

            # Get last name
            read -p "Enter last name: " lastname

            if [ "$lastname" = "exit" ]
            then 
                exit 0
            fi

            query=$(grep -iw "$firstname|$lastname" "$database")

            if [ -z query ]
            then 
                echo ""
                echo "Contact not found"
                options
                read -p "Enter option >> " option
                continue
            else
                echo ""
                
                # Get new first name
                read -p "Enter new first name: " newfirstname
                # Get new last name
                read -p "Enter new last name: " newlastname
                # Get new phone number
                read -p "Enter new phone number: " newphone
                # Get new address
                read -p "Enter new address: " newaddress

                newentry="$newfirstname|$newlastname|$newphone|$newaddress"

                sed -i "s/$query/$newentry/" "$database"
                echo "Contact edited"
            fi

            options
            read -p "Enter option >> " option
            continue
            ;;

        5)
            # Find contact
            echo ""

            # Get first name
            read -p "Enter first name: " firstname

            if [ "$firstname" = "exit" ]
            then 
                exit 0
            fi

            # Get last name
            read -p "Enter last name: " lastname

            if [ "$lastname" = "exit" ]
            then 
                exit 0
            fi

            query=$(grep -iw "$firstname|$lastname" "$database")

            if [ -z query ]
            then 
                echo ""
                echo "Contact not found"
                options
                read -p "Enter option >> " option
                continue
            else
                echo ""
                echo "Contact: $query"
            fi

            options
            read -p "Enter option >> " option
            continue
            ;;

        6)
            exit 
            ;;

        *)
            options
            read -p "Enter option >> " option
            continue
            ;;
    esac
done
echo ""