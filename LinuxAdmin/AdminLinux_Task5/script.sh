#!/bin/bash

# Define variables
USER_NAME="yourName"
GROUP_NAME="FamilyName"

# Check if the group exists
if getent group "$GROUP_NAME" > /dev/null; then
    echo "Group '$GROUP_NAME' exists."
else
    echo "Group '$GROUP_NAME' does not exist. Creating group '$GROUP_NAME'."
    sudo groupadd "$GROUP_NAME"
fi

# Check if the user exists
if id "$USER_NAME" &>/dev/null; then
    echo "User '$USER_NAME' already exists."
else
    echo "User '$USER_NAME' does not exist. Creating user '$USER_NAME'."
    sudo useradd -m -g "$GROUP_NAME" "$USER_NAME"
    echo "User '$USER_NAME' created and added to group '$GROUP_NAME'."
fi

# Display the user and group information
echo "User information:"
id "$USER_NAME"
echo "Group information:"
getent group "$GROUP_NAME"