% ECE2524: Midterm
%
% October 10, 2012
<!--
To view these instructions in glorious color, run the 'viewme' command in the same directory 
e.g. If $ is your prompt: 
$ ./viewme 
-->

## Part 0

*Introduction*

**To view the instructions with formatting and color added using the `viewme` script you will need to have `markdown` and `lynx` installed.  However, these are not required to complete the exam.  If you can not run the `viewme` command, simply view the `README.md` file directly with `less`**

**All file names used in this document that are not explicitly relative 
to the system root (`/`) or the current user's home directory (`~/`)
are relative to the base directory of the archive which this file is a 
part of (i.e. `ece2524midterm`). This `README.md` file is in the base directory of the archive.**

*If you can't come up with a command that gives exactly what is asked, get as close as you can*

*Some questions ask you to build commands off of the answers to previous questions.  If you were unable to find a working solution for a command that is used as a starting point, just answer the question assuming what you did have is correct, and build from there. The final output may not be correct, but for grading purposes I will be looking at the modified portion only (i.e. I won't "double count" points deducted for the first part)*

*For sections that ask you to record a transcript using the `script` command, only run line-oriented commands (pretty much anything except `man` or `nano`) in the terminal window you are recording in.  Run interactive utilities like `man` or `nano` in a different terminal window. This will help keep the transcript files more legible.
*

*If you have `lynx` installed and are using the `viewme` script to view the instructions you may notice that each of the section headers are links back to the table of contents*  Also, you can search within the text in `lynx` the same as you would in `vim` or `man`*

Please paste the command you want to be used for your answer to each question after the '>>' prompt in your RESONSE file.  Do not remove the '>>' 
For example, from the practice exam:

3.1) Generate a *long* directory listing of *all* the files in the directory `sample`
>> ls -al sample

When I provide examples of commands entered to the terminal I will use '$' to indicate the bash command prompt. Your actual command prompt may be different.

## Table of Contents
- <a id="toc1">[Part 1](#part1)
- <a id="toc2">[Part 2](#part2)
- <a id="toc3">[Part 3](#part3)
- <a id="toc4">[Part 4](#part4)
- <a id="toc5">[Part 5](#part5)
- <a id="toc6">[Part 6](#part6)

_____

## Part 1

(9 points)

*Setup*

**For this part record a session transcript called `part1` using the `script` command:**

    $ script -t part1 2>part1.time

**you do not need to paste any commands into your RESPONSE file for this section, the session transcript `part1` is all that is needed.**

1. Confirm that your current working directory is `ece2524midterm`
2. Create a new directory called `output`
3. *copy* the file `README.md` to a new file called `RESPONSE.md` in the `output` directory.  Record the answers to questions contained in this exam in that file. Do *not* modify the original `README.md` file.
4. **Stop recording this session by pressing 'Ctrl+D'**

_____

## Part 2

(8 points)

*History and philosophy*

**Answer the following questions in your RESPONSE.md file right after the >> prompt**

1. Unix was originally developed at

    A. Apple Inc.
    
	B. Microsoft
    
	C. AT&T/Bell Labs
    
	D. Texas Instruments
    
	E. None of the above
    >>
	
2. The Unix shell serves as an interface between
    
	A. System hardware and the kernel
    
	B. System hardware and the user
    
	C. The user and the kernel
    
	D. None of the above
	>>

3. Which of the following is *not* one of the 'Basics of the Unix Philosophy' listed in [Raymond], Chapter 1

    A. Rule of Separation

    B. Rule of Transparency

    C. Rule of Complexity

    D. Rule of Diversity
    >>

4. What is "The Unix Philosophy in One Lesson"?
>>

_____

## Part 3

(9 points)

*Filesystem*

**write or paste your answers after the `>>` prompt in your `RESPONSE.md` file.**

1. Write a command that finds all _hidden_ files *or* directories in the `sample` directory.  The output should list only the hidden files or directories, nothing else. **Hint:** the command should output 4 lines 
>>

2. Modify the previous command to *only* print hidden "regular files". 
    **Hint:** The command line argument to `find` to filter by `type` is not suprisingly `-type`. There should be only three lines of output.
>>

3. Create a symbolic link to the file `files/moby.txt` in the `output` directory.
>>

_____

## Part 4

(24 points)

*grep, sed and regular expressions*

**record a transcript of this section with the script command, call it `part4`**

    $ test -t part4 2>part4.time

**In addition, write or paste your final answers after the `>>` prompt in your `RESPONSE.md` file.**

1. Write a command that searches the lines of all hidden files in the `sample` directory for the word 'secrets', printing out any lines found. 
    **Hints:** Start with the command you wrote for 3.1 or 3.2 and pipe the output to another command.  `xargs` can be used to convert a list on standard input to a set of command line arguments. See the EXAMPLES section in the `xargs` man page.
>>

2. Using the file `files/testdata` as input, write a command that prints the number of *characters* of output produced by the previous command.
>>

3. Using the file `files/testdata` as input, write a command that replaces whole words ending in 'le' (that's a lower case 'L' 'e') on *each* line of input with the digit '0'
>>

4. Using the file `files/moby.txt` as input, write a command which prints the line number and the line itself on which the phrase
"Samuel Enderby is the name" occurs on.
>>

5. Amend the previous command so the the final output is the number of *words* on the line containing the phrase "My wrist is sprained".  Run that command.
>>

6. Run the previous command again, but direct the output to a file called `output/the.answer`
>>

**Press Ctrl+D to stop recording.**

_____

## Part 5

(20 points) +10 extra credit

*bash and python scripts* 

**Complete 2 out of the following 3 problems.  Complete the third for up to 10 points extra credit**

**for any scripts that you create, set the permission bits on the
files so that they are executable by the owner**

1. The script `viewme` in the base directory of this archive displays this README file with color highlighting.  It does this by processing the file with the `markdown` utility and then piping the output to the `lynx` web browser.  If you open up the `viewme` script you will see that the `cat` command is used to add a header and footer to the output generated by markdown.  This is because the `markdown` utility does not generate a complete HTML document.  
The `pandoc` command is a general-purpose converter capable of converting from many different input formats to many supported output formats.  To convert a file from markdown to html using `pandoc` the command would be 

        $ pandoc -f markdown -t html -s [file]
	
    The `-s` option tells pandoc to generate 'standalone' output, meaning it will include appropriate headers and footers for HTML output.
Modify the `viewme` script to use `pandoc` with the 'standalone' option instead of `markdown`. Remember, concatenating the header and footer with the generated output will be unnecessary.

2. The file `bin/myprog.py` has some errors and does not run.  Correct the errors so that it 
runs correctly.  You may overwrite the original file and keep the corrected version in the 
`bin` directory. (If you want to test the output use `file/account` directed to the standard input of `bin/myprog.py`. You do not need to record this command or the output, it is for your purposes only.)

3. Take a look at the file `files/grades.csv`.  It contains numeric grades for some imaginary students.  Each line in the file represents one student and contains a field for an alphanumeric ID string, last name, first name and grade (4 fields per line).  Fields are separated by commas. Spaces may occur in either the first or last name field.

    Write a python script called `change_grade.py` that will take two command line arguments: a string and a number, and read input formatted like `files/grades.csv` from standard input.  If the string supplied on the command line is found anywhere on a line of input, then the grade on that line should be changed to that number and the modified line printed to standard out.  Lines that do not match the string should be printed back to standard out unchanged. Here's an example usage (assuming you are running the command from within the `bin` directory):

        $ ./change_grade.py Nye 80 <../files/grades.csv
        #grades for Super Awesome Demonstration

        jshmoe,Shmoe,Joe,87
        djane,Doe,Jane,98
        skapors,Kaporski,Sam,92
        bnye,Nye,Bill,80
        bted,And Ted,Bill,83
        $

    Notice the grade for Bill Nye has been changed from a 72 to an 80

    Note that you do not need to do anything fancy with the string matching, i.e. it doesn't matter if the string given matches the first name, last name, or a combination, e.g. this is fine:

        $ ./change_grade.py oe,Joe 20 <../files/grades.csv
        #grades for Super Awesome Demonstration

        jshmoe,Shmoe,Joe,20
        djane,Doe,Jane,98
        skapors,Kaporski,Sam,92
        bnye,Nye,Bill,72
        bted,And Ted,Bill,83
        $

    No special checking need be performed on the value of the grade, but it should be converted to a valid number (integer or float).
    **Hint:** Consider using a copied version of your fixed `bin/myprog.py` and the modifying that.
	
	**Move your `change_grade.py` script into the `bin` directory, if it isn't already there**
_____

## Part 6

(10 points)

*Wrap up*

1. Create a directory called `transcripts` in the base directory.  

2. Move `part1`, `part1.timeing`, `part4` and `part4.timeing` into the `transcripts` directory.  You should be able to do that in a single command.  Paste the command you used here:
>>

    Your directory structure should now look like (`\-` denotes a subdirectory)
	
	    ece2524midterm
		    \-bin
			\-files
			\-output
            \-sample
			\-transcripts

    Your `RESPONSE.md` file and any redirected output files should be in `output`, any Python scripts should be in `bin` and any transcript files should be in `transcripts`. Keep modified source code (`viewme` and `myprog.py`) in the same location as the original.  
	
3. Create a *new* archive called `midterm.tar.gz` of the `ece2524midterm` directory which contains all the files you created and modified.  Do *not* remove any other files.  Your completed archive should contain *everything* in the original archive, plus any files you added. Assuming you are in the parent directory of `ece2524midterm` the command to create a compressed tar archive of that directory *without* preserving file permissions is:

        $ tar -czf midterm.tar.gz ece2524midterm/
	
    When you run the command, add the necessary option to *preserve* the permissions of the files. I recommend running a test extraction of your new archive to an empty temporary directory to double check that all files are included before uploading your submission.**  You do not need to paste the command you used here.

	
4. Upload `midterm.tar.gz` to scholar as your submission to the assessment.

