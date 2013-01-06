
#
# Parameter definitions per owners manuals.
#
# FILE_NAME is the resulting file name of the patch - .pd extesion is appended later
# FX_NAME is the name of the effect (as it will be displayed in the patch)
# PARAMETERNAMEX is the parameter name for parameter X (as it will be displayed in the patch)
# PARAMETERNOX is the parameter number used to map correctly in the SysEx message
# 3000X is for mapping the correct valuespace for the sliders
#	* there are two different valuespaces: 
#		* bipolar 0x4000 (most negative) to 0x8000 (zero) to 0xBFFF (most positive)
#		* unipolar 0x8000 (zero) to 0xBFFF (most positive) 
#	* 3000X maps the lower bound of the valuespaces to either bipolar or unipolar for parameter X
# fxList lists all patches to be generated
#
# PS: no whitespaces in strings!
#
# 2012 Even Brenden
#


# Template fields

templateFile = 'patch_template.pd'

uniPolar = '32768'
biPolar = '16384'

keyList = ['FILE_NAME',
	   'FX_NAME',
	   'PARAMETERNAME1', 
	   'PARAMETERNO1', 
	   '30001',
	   'PARAMETERNAME2', 
	   'PARAMETERNO2', 
	   '30002',
	   'PARAMETERNAME3', 
	   'PARAMETERNO3', 
	   '30003',
	   'PARAMETERNAME4', 
	   'PARAMETERNO4', 
	   '30004',
	   'PARAMETERNAME5', 
	   'PARAMETERNO5', 
	   '30005',
	   'PARAMETERNAME6', 
	   'PARAMETERNO6', 
	   '30006',
	   'PARAMETERNAME7', 
	   'PARAMETERNO7', 
	   '30007',
	   'PARAMETERNAME8', 
	   'PARAMETERNO8', 
	   '30008']	   


# Effects

delay1 = dict({		'FILE_NAME':	  'lxp-1_delay_1',
			'FX_NAME':    	  'LXP-1:DELAY1',
			'PARAMETERNAME1': 'group_delay', 
			'PARAMETERNO1'	: '1',
			'30001'	:  	   uniPolar,
			'PARAMETERNAME2': 'effects_level', 
			'PARAMETERNO2'	: '2',
			'30002'	:  	   uniPolar, 
			'PARAMETERNAME3': 'high_cut', 
			'PARAMETERNO3'	: '3',
			'30003'	:  	   uniPolar,
			'PARAMETERNAME4': 'delay_2_spread', 
			'PARAMETERNO4'	: '4',
			'30004'	:  	   uniPolar,
			'PARAMETERNAME5': 'delay_3_spread', 
			'PARAMETERNO5'	: '5',
			'30005'	:  	   uniPolar,
			'PARAMETERNAME6': 'delay_3_feedback', 
			'PARAMETERNO6'	: '6',
			'30006'	:  	   biPolar,
			'PARAMETERNAME7': 'diffusion', 
			'PARAMETERNO7'	: '7',
			'30007'	:  	   uniPolar,
			'PARAMETERNAME8': 'rate', 
			'PARAMETERNO8'	: '8',
			'30008'	:  	   uniPolar})

delay2 = dict({		'FILE_NAME':	  'lxp-1_delay_2',
			'FX_NAME':    	  'LXP-1:DELAY2',
			'PARAMETERNAME1': 'positive_feedback', 
			'PARAMETERNO1'	: '0',
			'30001'	:  	   uniPolar,
			'PARAMETERNAME2': 'ganged_delay', 
			'PARAMETERNO2'	: '1',
			'30002'	:  	   uniPolar, 
			'PARAMETERNAME3': 'effects_level', 
			'PARAMETERNO3'	: '2',
			'30003'	:  	   uniPolar,
			'PARAMETERNAME4': 'feedback', 
			'PARAMETERNO4'	: '3',
			'30004'	:  	   biPolar,
			'PARAMETERNAME5': 'left_delay', 
			'PARAMETERNO5'	: '4',
			'30005'	:  	   uniPolar,
			'PARAMETERNAME6': 'right_delay', 
			'PARAMETERNO6'	: '5',
			'30006'	:  	   uniPolar,
			'PARAMETERNAME7': 'high_freq_cut', 
			'PARAMETERNO7'	: '7',
			'30007'	:  	   uniPolar,
			'PARAMETERNAME8': 'diffusion', 
			'PARAMETERNO8'	: '8',
			'30008'	:  	   uniPolar})


# Effects must be listed in fxList to be generated

fxList = [	delay1, 
		delay2]