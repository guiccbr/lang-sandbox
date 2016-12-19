# Create a symbolic link
ln -s TARGET LINK_NAME

# Find all links in a directory
ls -l | grep "^l"

# Create readonly file in user directory
touch FILE_NAME & chmod 444 FILE_NAME

# View operating system information (unix-name)
uname -a

# Run a process in background
process_name &

# Suspend a process
process_name
ctrl+z

# Put a running process in background
process_name
ctrl+z
bg

# Show all jobs that are suspended or running on background
jobs

# Disown a job so you can kill the terminal where it has been
# spawned
disown [%job_id]

# Put a process to foreground (if no job_id is given put the most
# recently suspended or run on background job foreground).
fg [job_id]

# kill a process
kill -KILL process_id

# Check if a remote is alive
ping remote_addr

# Command line history
history

# Copy a file from one host to another with scp
scp your_username@remotehost:file_name local_file_name

# Find out cpu usage
top

# Sort top output by processor/memory
Shift+P
Shift+M

# See space left in disks
df -h

# See space used by folder
du -sh

# See memory usage
free -h

# View cpuinfo
cat /proc/cpuinfo

# View for how long youre system is running
uptime
