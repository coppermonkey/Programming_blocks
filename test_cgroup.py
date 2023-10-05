// This file tests chnages for memory pressure in cgroup

import subprocess as sb

print("deleting existing cgroups")
process = sb.Popen(['rmdir', '/sys/fs/cgroup/memory/nn'], stdout=sb.PIPE)
out, err = process.communicate()

print("creating new cgroup")
process = sb.Popen(['mkdir', '-p', '/sys/fs/cgroup/memory/nn'], stdout=sb.PIPE)
out, err = process.communicate()

f = open('/sys/fs/cgroup/memory/nn/memory.limit_in_bytes', 'w')
f.write('65536')
f.close()

process = sb.Popen(['echo', '$$>/sys/fs/cgroup/memory/nn/tasks'], stdout=sb.PIPE)
out, err = process.communicate()
process = sb.Popen(['dd','if=/dev/urandom','of=./ff', 'oflag=direct', 'count=10000'], stdout=sb.PIPE)
out, err = process.communicate()

print(out)
print(err)
