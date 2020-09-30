#! /usr/bin/python
import argparse

examples = """examples
"""

parser = argparse.ArgumentParser(
        description="Toggle sched_feat",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=examples)
parser.add_argument("-i", "--index", default=-1, help="toggle based on index")
args = parser.parse_args()

def read_parse_schedfeat():
    fd = open("/sys/kernel/debug/sched_features","r")
    p = fd.read()
    fd.close()
    return p

def show_menu(l):
    l = l.split(" ")
    counter = 0
    for i in l:
        features_var = i
        print (counter, features_var)
        counter += 1

def toggle(index, l):
    fd = open("/sys/kernel/debug/sched_features","w")
    features_var = l.split(" ")[index]
    features_var = features_var.split("NO_")
    isno = not (features_var[-1] == features_var[0])
    if isno:
        fd.write(features_var[-1])
	print("Turned on ", features_var[-1])
    else:
        fd.write("NO_"+features_var[-1])
	print("Turned off ",features_var[-1])

    fd.close()

# Read sched features parsed from above
p = read_parse_schedfeat()

if args.index >= 0:
	toggle(int(args.index), p)
else:
	show_menu(p)
	toggle(int(raw_input()), p)
