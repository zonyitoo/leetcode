# Read from the file file.txt and output all valid phone numbers to stdout.

egrep '(\(\d{3}\) \d{3}-\d{4})|(\d{3}-\d{3}-\d{4})' file.txt
