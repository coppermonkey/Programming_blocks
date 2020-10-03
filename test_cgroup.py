import subprocess as sb

process = sb.Popen(['rmdir', '/sys/fs/cgroup/memory/nn'], stdout=sb.PIPE)
out, err = process.communicate()
process = sb.Popen(['mkdir', '-p', '/sys/fs/cgroup/memory/nn'], stdout=sb.PIPE)
out, err = process.communicate()

f = open('/sys/fs/cgroup/memory/nn/memory.limit_in_bytes', 'w')
f.write('65536')
f.close()

process = sb.Popen(['echo', '$$>/sys/fs/cgroup/memory/nn/tasks'], stdout=sb.PIPE)
out, err = process.communicate()
process = sb.Popen(['dd','if=/dev/zero','of=./ff', 'oflag=direct', 'count=10000'], stdout=sb.PIPE)
out, err = process.communicate()

print(out)
print(err)
