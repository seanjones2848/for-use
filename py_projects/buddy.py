import sys

name = str(raw_input("What's my name?\n"))
user = str(raw_input("What's your name?\n"))

print ("Hi " + user + ", my name is " + name + "! we are running version " + sys.version[:5] + " on " + sys.platform + "\n")
