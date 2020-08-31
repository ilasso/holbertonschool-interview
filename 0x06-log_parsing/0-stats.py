#!/usr/bin/python3
"""
0-stats.py: script that reads stdin line by line and computes metrics
Input format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
After every 10 lines and/or a keyboard interruption (CTRL + C),
print these statistics from the beginning:
- Total file size: File size: <total size>
- where <total size> is the sum of all previous <file size>
  (see input format above)
- Number of lines by status code:
  possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
  if a status code doesn’t appear, don’t print anything for this status code
  format: <status code>: <number>
  status codes should be printed in ascending order
"""

import sys
totalsize = 0
dictstatus = {"200": 0, "301": 0, "400": 0, "401": 0,
              "403": 0, "404": 0, "405": 0, "500": 0}
count = 0
try:
    for sti in sys.stdin:
        count += 1
        spl = sti.split()
        totalsize += int(spl[8])
        codestatus = spl[7]
        if codestatus in dictstatus:
            dictstatus[codestatus] = int(dictstatus[codestatus]) + 1
        if count % 10 == 0:
            print("File size: {}".format(totalsize))
            for i, j in dictstatus.items():
                if j != 0:
                    print("{}: {}".format(i, j))
except KeyboardInterrupt:
    print("File size: {}".format(totalsize))
    for i, j in sorted(dictstatus.items()):
        if j != 0:
            print("{}: {}".format(i, j))
    raise
