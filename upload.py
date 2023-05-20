import sys
from pathlib import Path

file = Path(sys.argv[1])
started = False

with open(file, 'r') as f:
    while True:
        line = f.readline()
        if not line:
            break

        if line.startswith('//####'):
            if started:  # find the separator above driver code
                break
            else:
                started = True
        elif started:
            sys.stdout.write(line)
