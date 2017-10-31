README FOR BITDISP 

ENVIRONMENTAL EXPECTATIONS:

- When outputting ASCII values for the BYTEs, new line characters are NOT added,
  despite them helping readability, the instructions specifically state that no
  additional whitespace is to be added

- The program defaults to -bin -acbout if no parameters are specified

- Doing the default actions (above), the program will accept special characters
  like: _ and ~

- -bin -bout outputs the original input

- -acbin -acbout outputs the original binary input
	- this will only occur if the standard conditions are specified
	  Specifically, the amount of bits must be a multiple of 8 and the
	  input must not contain non zero or non-one values.

- Users should be able to pass in a file with characters, and the program will be able to output them
  in their binary representation

- When values are output as binary, the program will display each byte from
  the most significant bit to the least significant bit, splitting each byte by
  upper nibble and lower nibble, respectively, using spaces, and separating each
  byte by a new line character

- Users should be able to pass in binary values and have them converted and displayed
  through standard output as ASCII values

- If a user inputs an invalid set of parameters / commands, the program will respond with
  a usage error

- If a user inputs an invalid input to be displayed, the program will respond accordingly
  and also output a usage error

- When based binary input (generalized), the program allows spaces and newline characters
  but removes them before conducting operations
  	- As a result of this, if ASCII values are passed in then the binary representation
	  that is output will have all the characters but not any newline or space characters
	  in their binary representations

- The instructions also indicate that we should be able to handle binary values with white space
  So the program allows white space to exist in user binary input
  	- These white space and new line characters are simply removed by the program before
	  any operations are conducted, so they make no difference in this environment

- Regardless of how a user spaces binary input, the white space removal is expected to
  take care of all white space and make it as if no spaces or line breaks were added



