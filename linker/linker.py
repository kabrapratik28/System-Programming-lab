def no_giver_fun(c_line,striper):
	c_line  = c_line + "; "
	c_line = c_line.strip(" ")
	c_line = c_line[len(striper):]
	list_of_ele = []
	strex = "" 
	for achar in c_line :
		if achar == "," or achar == ";" : 
			strex = strex.strip(" ")
			if strex != "" :
				list_of_ele.append(strex)
			strex = ""
		else  :	
			strex = strex + achar 
	return list_of_ele
def process(line):
	global symbolt1
	global symbolt2
	global symbolt3
	line  = line.strip("\n").strip(" ").strip("\r")
	c_line_array = line.split(";")
	for c_line in c_line_array : 
		if "printf" in c_line or "scanf" in c_line :
			None 
		elif  "int " in c_line :
			no_of_var = no_giver_fun(c_line,"int ")
			for one_each in no_of_var : 
				symbolt1.append(one_each)
				symbolt2.append(2)
				
		elif "char " in c_line :
		 	no_of_var = no_giver_fun(c_line,"char ")
		 	for one_each in no_of_var : 
				symbolt1.append(one_each)
				symbolt2.append(1)
				
		elif "float " in c_line :
			no_of_var = no_giver_fun(c_line,"float ")
			for one_each in no_of_var : 
				symbolt1.append(one_each)
				symbolt2.append(4)
				
		elif "long " in c_line : 
			no_of_var = no_giver_fun(c_line,"long " )
			for one_each in no_of_var : 
				symbolt1.append(one_each)
				symbolt2.append(8)
				
		elif "short " in c_line : 
			no_of_var = no_giver_fun(c_line,"short " )
			for one_each in no_of_var : 
				symbolt1.append(one_each)
				symbolt2.append(2)
				
		elif "double " in c_line : 
			no_of_var = no_giver_fun(c_line,"double ")
			for one_each in no_of_var : 
				symbolt1.append(one_each)
				symbolt2.append(8)
				
		elif "signed " in c_line : 
			no_of_var = no_giver_fun(c_line,"signed ")
			for one_each in no_of_var : 
				symbolt1.append(one_each)
				symbolt2.append(2)
				
	
		elif "unsigned " in c_line : 
			no_of_var = no_giver_fun(c_line,"unsigned ")
			for one_each in no_of_var : 
				symbolt1.append(one_each)
				symbolt2.append(4)

		elif "extern " in c_line : 
			no_of_var = no_giver_fun(c_line,"extern ")
			for one_each in no_of_var : 
				externlt.append(one_each)
				
#  ===================== FIRST C FILE ============================
filec = open('in.c','r')
symbolt1= [] 
symbolt2 = []
symbolt3 = []		
externlt = [] 
for line in filec : 
	if "int " in line or "char " in line or "float " in line or  "long " in line or "short " in line  or "double " in line or "signed " in line or "unsigned " in line or "extern " in line: 
		process(line) 
		
firstc1 = symbolt1[:]
firstc2 = symbolt2[:]
firstc3 = symbolt3[:]
externc1 = externlt[:]
#  ===================== SECOND C FILE ============================		
filec = open('in2.c','r')
symbolt1= [] 
symbolt2 = []
symbolt3 = []		
externlt = [] 
for line in filec : 
	if "int " in line or "char " in line or "float " in line or  "long " in line or "short " in line  or "double " in line or "signed " in line or "unsigned " in line or "extern " in line: 
		process(line) 
		
secondc1 = symbolt1[:]
secondc2 = symbolt2[:]
secondc3 = symbolt3[:]		
externc2 = externlt[:]

# address in first c
START_ADDRESS= 1000	
for k in firstc2 : 
	firstc3.append(START_ADDRESS)
	START_ADDRESS = START_ADDRESS + k

		
# address in second c
START_ADDRESS= 5000	
for k in secondc2 : 
	secondc3.append(START_ADDRESS)
	START_ADDRESS = START_ADDRESS + k


##========linking process

externc1add = [] 
externc1addm = [ ]
for one_row in range(len(externc1)):
	externc1add.append(secondc3[secondc1.index(externc1[one_row])])
	externc1addm.append(secondc2[secondc1.index(externc1[one_row])])
	


externc2add = [] 
externc2addm= [] 
for one_row in range(len(externc2)):
	externc2add.append(firstc3[firstc1.index(externc2[one_row])])
	externc2addm.append(firstc2[firstc1.index(externc2[one_row])])


##========linking process ends  

print "FIRST LOCAL SYMBOL TABLE"
# print in first c
for one_row in range(len(firstc1)):
	print str(firstc1[one_row]) + "  "+str(firstc2[one_row])+ "  "+ str(firstc3[one_row])

print "EXTERN SYMBOL FIRST TABLE"
for one_row in range(len(externc1)):
	print str(externc1[one_row])+"  "+ str(externc1add[one_row])+"  "+str(externc1addm[one_row])
	
	
print "SECOND LOCAL SYMBOL TABLE"
# print in second c
for one_row in range(len(secondc1)):
	print str(secondc1[one_row]) + "  "+str(secondc2[one_row])+ "  "+ str(secondc3[one_row])

print "EXTERN SYMBOL SECOND TABLE"
for one_row in range(len(externc2)):
	print str(externc2[one_row])+"  "+ str(externc2add[one_row])+ "  "+ str(externc2addm[one_row])
	
