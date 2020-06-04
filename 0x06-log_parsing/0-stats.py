#!/usr/bin/python3
'Log Parsing'
import sys

status_list = [200, 301, 400, 401, 403, 404, 405, 500]
try:
    total_status = 0
    total_size = 0
    final_list = []
    for index, line in enumerate(sys.stdin, 1):
        if line:
            line_split = line.split()
            if len(line_split) > 1:
                if line_split[-1].isnumeric() and line_split[-2].isnumeric():
                    size = line_split[-1]
                    status = line_split[-2]
            if len(status) > 0 and int(status) in status_list:
                final_list.append(int(status))
            total_size += int(size)
            size = 0
        if index % 10 == 0:
            print('File size: {}'.format(str(total_size)))
            for i in status_list:
                if i in final_list:
                    status_count = final_list.count(i)
                    print(str(i)+": "+str(status_count))
    print('File size: '+str(total_size))
    for i in status_list:
        if i in final_list:
            status_count = final_list.count(i)
            print("{}: {}".format(str(i), str(status_count)))
except Exception:
    print(Exception)
