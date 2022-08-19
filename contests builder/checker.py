import sys

_, output_arq, answer_arq = sys.argv[1:] 

out = open(output_arq, 'r').readline()
aws = open(answer_arq, 'r').readline()

if out == aws:
    exit(0)
else:
    exit(1)