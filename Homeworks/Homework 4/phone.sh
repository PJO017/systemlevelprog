
# Phone-Book Utility

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
chmod 600 "$database"  # Only accessible by user

clear

while [ "$option" != "6" ]
do
    firstname=""
    lastname=""
    phone=""
    address=""
    
    case "$option" in 
        1)  # Dislpay Contact
            if [ -s "$database" ]  # If database file exists
            then 
                echo "Contacts sorted by First Name"
                echo ""
                sort -t "|" -k1 "$database" | column -s : -t # Print contacts in sorted order
            else
                echo ""
                echo "No phone directory '$database' found" 
            fi
            options
            echo "Enter option >> "
            read option
            continue
            ;;

        2)  # Add contact
            # Get first name
            until [ ! -z "$firstname" ] # Asks until user inputs 
            do 
                echo -n "Enter first name: "
                read firstname

                if [ "$firstname" = "exit" ]
                then 
                    exit 0
                fi
            done

            # Get last name
            until [ ! -z "$lastname" ] # Asks until user inputs 
            do 
                echo -n "Enter last name: "
                read lastname

                if [ "$lastname" = "exit" ]
                then 
                    exit 0
                fi
            done

            while [ -z "$phone" ] # Asks until user inputs 
            do 
                echo -n "Enter phone number: "
                read phone

                if [ "$phone" = "exit" ]
                then 
                    exit 0
                fi
            done

            until [ ! -z "$address" ] # Asks until user inputs 
            do 
                echo -n "Enter address: "
                read address

                if [ "$address" = "exit" ]
                then 
                    exit 0
                fi
            done

            # Add contact in database
            echo "$firstname|$lastname|$phone|$address" >> "$database"
            echo ""
            echo "New contact added"

            options
            echo "Enter option >> "
            read option
            continue
            ;;

        3)  # Delete contact
            echo ""
            until [ ! -z "$firstname" ]
            do 
                echo -n "Enter first name: "
                read firstname

                if [ "$firstname" = "exit" ]
                then 
                    exit 0
                fi
            done

            until [ ! -z "$lastname" ]
            do 
                echo -n "Enter last name: "
                read lastname

                if [ "$lastname" = "exit" ]
                then 
                    exit 0
                fi
            done

            # Strip whitespace
            firstname=$(echo "$firstname" | tr -s " ")
            lastname=$(echo "$lastname" | tr -s " ")

            tmpfile=$(mktemp)

            # Put all non matching lines into tmpfile
            grep -iwv "$firstname|$lastname" "$database" > "$tmpfile"

            dbrowcount=$(wc -l < "$database")
            tmprowcount=$(wc -l < "$tmpfile")

            # If amount of entries in database and tempfile are the same no match was made
            if [ dbrowcount != tmprowcount ]
            then
                mv "$tmpfile" "$database"
                echo ""
                echo "Deleted phone"

                options
                echo -n "Enter a option [1-6]: "
                read option
                continue
            else  
                echo ""
                echo "No match found"

                options
                echo -n "Enter a option [1-6]: "
                read option
                continue

            fi
            ;;

        4)  # Edit contact
            if [ ! -w "$database" ]
            then 
                options
                echo "Error: You're not allowed to write into '$database'"
                echo ""

                exit 1
            fi

            echo ""

            oldfirstname=""
            oldlastname=""
            oldphone=""
            oldaddress=""

            while [ -z "$oldfirstname" ]
            do 
                echo -n "Enter old first name: "
                read oldfirstname

                if [ "$oldfirstname" = "exit" ]
                then 
                    exit 0
                fi
            done

            while [ -z "$oldlastname" ]
            do 
                echo -n "Enter old last name: "
                read oldlastname

                if [ "$oldlastname" = "exit" ]
                then 
                    exit 0
                fi
            done


            echo ""

            newfirstname=""
            newlastname=""
            newphone=""
            newaddress=""

            # ASk for new info
            while [ -z "$newfirstname" ]
            do 
                echo -n "Enter new first name: "
                read newfirstname

                if [ "$newfirstname" = "exit" ]
                then 
                    exit 0
                fi
            done

            while [ -z "$newlastname" ]
            do 
                echo -n "Enter new last name: "
                read newlastname

                if [ "$newlastname" = "exit" ]
                then 
                    exit 0
                fi
            done

            while [ -z "$newphone" ]
            do 
                echo -n "Enter new phone number: "
                read newphone

                if [ "$newphone" = "exit" ]
                then 
                    exit 0
                fi
            done

            while [ -z "$newaddress" ]
            do 
                echo -n "Enter new address: "
                read newaddress

                if [ "$newaddress" = "exit" ]
                then 
                    exit 0
                fi
            done


            oldentry=$(grep -iw "$oldfirstname|$oldlastname" "$database")
            newentry="$newfirstname|$newlastname|$newphone|$newaddress"

            if [ -z oldentry ]  # If old entry is empty
            then
                echo "No match found"

                options
                echo -n "Enter a option [1-6]: "
                read option
                continue
            else  
                sed -i "s/$oldentry/$newentry/" "$database"    # Replace old entry with new entry in database
                echo "Modified entry"
            fi

            options
            echo -n "Enter a option [1-6]: "
            read option
            continue
            ;;
            
        
        5)
            # Find contact
            if [ ! -r "$database" ]   # Check for read permission
            then 
                echo ""
                echo "Error: You're not allowed to read '$database'"
                echo ""

                exit 1
            fi

            while [ -z "$firstname" ]
            do 
                echo -n "Enter first name: "
                read firstname

                if [ "$firstname" = "exit" ]
                then 
                    exit 0
                fi
            done

            while [ -z "$lastname" ]
            do 
                echo -n "Enter last name: "
                read lastname

                if [ "$lastname" = "exit" ]
                then 
                    exit 0
                fi
            done


            firstname=$(echo "$firstname" | tr -s " ")
            lastname=$(echo "$lastname" | tr -s " ")

            echo ""
            entry=$(grep -iw "$firstname|$lastname" "$database")

            if [ -z entry ]    # Check if entry exists
            then 
                echo "No match found"

                options
                echo -n "Enter a option [1-6]: "
                read option
                continue

            else
                echo "Results: "
                echo "$entry"
            fi

            options
            echo -n "Enter a option [1-6]: "
            read option
            continue
            ;;

        
        
        6)  echo ""
            exit
            ;;

        *)  options
            echo -n "Enter a option [1-6]: "
            read option
            ;;
    esac
done
echo ""
exit


