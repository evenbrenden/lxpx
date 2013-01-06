
#
# Script for autogenerating parameter-patches.
#
# parameterdefinitions.py holds lists with parameter definition.
#
# 2012 Even Brenden
#

from parameter_definitions import *

import fileinput
import sys
import shutil

def replaceAll(file, searchExpression, replaceExpression):
    for line in fileinput.input(file, inplace=1):
        if searchExpression in line:
            line = line.replace(searchExpression, replaceExpression)
        sys.stdout.write(line)

for fx in fxList:
	patchFile = fx['FILE_NAME'] + '.pd'	
	shutil.copy(templateFile, patchFile)
	for key in keyList:
		replaceAll(patchFile, key, fx[key])