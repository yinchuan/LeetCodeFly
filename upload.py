#!/usr/bin/python3

import sys
import subprocess
from pathlib import Path

file = Path(sys.argv[1])

process = subprocess.Popen("xclip -selection clipboard", shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                           stderr=subprocess.PIPE, text=True)

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
            process.stdin.write(line)

process.stdin.close()
