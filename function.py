import os
def one():
	with open("record.txt") as f1: 
		with open("record2.txt", "w") as f2:
			for line in f1.readlines():
  	    			f2.write(line.strip("\n")+",name\n")
			os.remove("record.txt")
			os.rename("record2.txt", "record.txt")

