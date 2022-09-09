#! bin/bash

path=$(find /home -name "Assignment1.txt.txt")

tr -c '[:alnum:]' '[\n*]' < $path | sort | uniq -c | sort -nr | head -4 | tail -3 
