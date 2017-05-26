/*
	I affirm that this is my original work and not the work of anyone else.
	
	Darien Quinn Morrison

	COP4338

	Example of command line parsing via getopt
	usage: minicalc [-a num] [-d num] [-m num] [-s num] [e] value
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	extern char *optarg;	// Command line argument
	extern int optind;	// Command line argument's index
	int c, err = 0; 
	int eflag=0, mflag=0, dflag = 0, aflag=0, sflag=0;	// Flags for each option
	int mnum = 0, dnum = 0, anum = 0, snum = 0;		// integer variables for the options
	float value;
	static char usage[] = "usage: minicalc [-a num] [-d num] [-m num] [-s num] [e] value \n";	// Usage
	
	/* Set the flags and num values for each case */
	while ((c = getopt(argc, argv, "em:d:a:s:")) != -1)
		switch (c) {
		case 'e':
			eflag = 1;
			break;
		case 'm':
			mflag = 1;
			mnum = atoi(optarg);
			break;
		case 'd':
			dflag = 1;
			dnum = atoi(optarg);
			break;
		case 'a':
			aflag = 1;
			anum = atoi(optarg);
			break;
		case 's':
			sflag = 1;
         		snum = atoi(optarg);
			break;
		case '?':
			err = 1;
			break;
		}

	// Need at least one argument (change +1 to +2 for two, etc. as needeed)
	if ((optind+1) > argc) 
	{
		printf("optind = %d, argc = %d\n", optind, argc);
		fprintf(stderr, "%s: missing name\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} 
	else if (err) 
	{
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}

	// Set value to the last argument from the command line	
	value = atof(argv[argc-1]);
	
	// If value is greater than 99 or less than 1 then print an error and exit the program
	if(value > 99 || value < 1)
	{
		printf("Sorry, starting value must be between 1 and 99.\n%s", usage);
		exit(0);
	}

	
	/* Print which flags were set and what the arguments to the options are */
	printf("eflag = %d\n", eflag);
	printf("mflag = %d, %d\n", mflag, mnum);
	printf("dflag = %d, %d\n", dflag, dnum);
	printf("aflag = %d, %d\n", aflag, anum);
	printf("sflag = %d, %d\n", sflag, snum);
	
	// If statements to execute the operations we want to do (addition, multiplication, etc.)
	if(eflag == 1)
		value *= value;
	if(mflag == 1)
		value *= mnum;
	if(dflag == 1)
		value /= dnum;
	if(aflag == 1)
		value += anum;
	if(sflag == 1)
		value -= snum;

	// These are the arguments after the command line options
	if (optind < argc)
		for (; optind < argc; optind++)
			printf("Starting Value: \"%s\"\n", argv[optind]);
	else {
		printf("no arguments left to process\n");
	}
	
	// Print the result
	printf("Result : %.2f\n\n", value);

	exit(0);

}
