#ifndef BITDISP_H
#define BITDISP_H


#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <bitset>


#define DEBUG 0
#define true 1
#define false 0
#define BYTE_MASK 0xFF
#define NYBBLE_MASK 0xFF
#define LAST_NEWLINE 0
#define MAXBYTES 16

void checkArgs(char *argv[], bool &bin, bool &bout, bool &acbin, bool &acbout);
void omitSpacing(std::string &inputs);
void acToBin(std::string inputs);
void binToAc(std::string inputs);

#endif
