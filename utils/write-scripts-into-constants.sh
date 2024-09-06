#!/bin/bash

outputFile="script-constants/script-constants.c"
outputHeaderFileName="script-constants.h"
outputHeaderFile="script-constants/$outputHeaderFileName"

# Clear the output files if they exists
> "$outputFile"
> "$outputHeaderFile"

# Include header in constants file
echo -e "#include \"$outputHeaderFileName\"\n" >> "$outputFile"

for inputFile in script-constants/*.ps1; do
    filename=$(basename ${inputFile})

    # Create constant with input file name
    echo -n "const char *${filename%.ps1}Script = " >> "$outputFile"
    echo "extern const char *${filename%.ps1}Script;" >> "$outputHeaderFile"

    # Iterate over each line in the input file
    while IFS= read -r line || [[ -n $line ]]; do
        # Remove the trailing newline (handle Windows-style \r\n and Unix-style \n)
        line=$(echo "$line" | sed 's/\r$//')

        # Escape backslashes
        line=$(echo "$line" | sed 's/\\/\\\\/g')

        # Escape double quotes
        line=$(echo "$line" | sed 's/"/\\"/g')

        # Append escaped line to string constant
        echo "\"$line\\n\"" >> "$outputFile"
    done < "$inputFile"

    # Finish constant definition with a semicolon and two newlines
    echo -e ";\n" >> "$outputFile"
    
    echo "Processed $inputFile -> $outputFile"
done

echo "All files processed."
