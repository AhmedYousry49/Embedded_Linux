AdminLinux Task3
=======

# Section 1:

## 1. Bash script

```bash
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
```
 





# Section 2:
## 1. Create a supplementary 
```bash

sudo groupadd -g 30000 pgroup

```




## 2.  Lock any user
```bash

sudo passwd -l username

```




## 3. Delete user 
```bash

sudo userdel username

```



## 4. Delete group
```bash

sudo groupdel groupname

```


## 5. State the difference between adduser and useradd with example shown.
### Key Differences between `adduser` and `useradd`:

| Feature            | `adduser`                                      | `useradd`                                      |
|--------------------|------------------------------------------------|------------------------------------------------|
| **Type of Command** | High-level utility (script)                   | Low-level command                              |
| **User Interaction**| Provides a more interactive and guided setup  | Requires more manual configuration            |
| **Configuration**   | Automatically creates a home directory, sets default shell, and prompts for user details (e.g., password, full name) | Requires manual specification of parameters like home directory, shell, and group |
| **Default Settings**| Uses default system settings and configurations (e.g., `/etc/skel` for skeleton files) | Does not automatically use all default configurations unless specified |
| **Distribution**    | Primarily available in Debian-based systems (e.g., Ubuntu) | Available in most Linux distributions (including Debian, RedHat, Fedora, etc.) |
| **Ease of Use**     | Easier to use with less configuration needed   | More flexible and customizable, but requires more knowledge and configuration |



```bash
sudo adduser newuser
```





```bash
sudo useradd -m -s /bin/bash -G sudo newuser
```
