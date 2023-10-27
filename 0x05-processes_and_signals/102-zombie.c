#!/usr/bin/env bash
# Write Bash (init) script 101-manage_my_process that manages manage_my_process. (both files need to be pushed to git)

# Requirements:

# When passing the argument start:
# Starts manage_my_process
# Creates a file containing its PID in /var/run/my_process.pid
# Displays manage_my_process started
# When passing the argument stop:
# Stops manage_my_process
# Deletes the file /var/run/my_process.pid
# Displays manage_my_process stopped
# When passing the argument restart
# Stops manage_my_process
# Deletes the file /var/run/my_process.pid
# Starts manage_my_process
# Creates a file containing its PID in /var/run/my_process.pid
# Displays manage_my_process restarted
# Displays Usage: manage_my_process {start|stop|restart} if any other argument or no argument is passed

if [ "$1" == "start" ]
then
    ./manage_my_process &
    echo $! > /var/run/my_process.pid
    echo "manage_my_process started"
elif [ "$1" == "stop" ]
then
    kill "$(pgrep -f /manage_my_process)"
    rm /var/run/my_process.pid
    echo "manage_my_process stopped"
elif [ "$1" == "restart" ]
then
    kill "$(pgrep -f /manage_my_process)"
    rm /var/run/my_process.pid
    ./manage_my_process &
    echo $! > /var/run/my_process.pid
    echo "manage_my_process restarted"
else
    echo "Usage: manage_my_process {start|stop|restart}"
fi
