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
				

filec = open('in.c','r')
symbolt1= [] 
symbolt2 = []
symbolt3 = []		

for line in filec : 
	if "int " in line or "char " in line or "float " in line or  "long " in line or "short " in line  or "double " in line or "signed " in line or "unsigned " in line: 
		process(line) 
		


		
#print symbolt1
#print symbolt2
START_ADDRESS= 2000	
for k in symbolt2 : 
	symbolt3.append(START_ADDRESS)
	START_ADDRESS = START_ADDRESS + k

for one_row in range(len(symbolt1)):
	print str(symbolt1[one_row]) + "  "+str(symbolt2[one_row])+ "  "+ str(symbolt3[one_row])
