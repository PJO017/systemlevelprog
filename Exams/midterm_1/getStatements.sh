# Count # of Statements
# Paul Ofremu Jr., pofremu1@student.gsu.edu

# Input file
myexamfile="myexamfile.txt"

# Get count of statements
count=$(grep -oc ".*\." "$myexamfile")
echo "There are $count statements in the text!" 
echo ""

statements=$(grep -o ".*\." "$myexamfile")

# Get number of words and letters for each statements
echo $(grep -o ".*\." "$myexamfile" | awk '{print "Statement: " NR " | # of words: " NF " | # of letters: " length " \\n"}')
