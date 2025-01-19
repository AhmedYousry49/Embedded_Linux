AdminLinux Task1
=======


![alt text](Linux_Distribution_Timeline.svg "Title")



### man command
 System-wide documentation system that provides short reference manuals (pages) for individual
 commands,API functions, concepts, configuration file syntax, file formats and is organized in sections
 (1 for user commands, 2 for system calls...). That's the traditional Unix documentation system

### Key Differences:
| Feature                  | `rm`                      | `rmdir`                   |
|--------------------------|---------------------------|---------------------------|
| **Primary Purpose**      | Remove files or directories | Remove empty directories  |
| **Directory Removal**    | Requires `-r` option      | Only removes empty directories |
| **Recursive Deletion**   | Supported with `-r`       | Not supported             |
| **Error on Non-empty**   | No (with `-r`)            | Yes                       |



### Trac Directory
#### A 
        Remove file and subdir 
#### B 
        rmdir: failed to remove 'OldFiles': No such file or directory
#### C
        /home/user/docs/mycv


###  list four ways to go to your home
        cd ~        
        cd 
        cd /home
        cd .. | cd /home/



### script [link](script.sh)
        #!/bin/bash
        cd ~
        mkdir "myDirectory"
        cd myDirectory
        mkdir "secondDirectory"
        cd secondDirectory
        touch "myNotePaper"
        cp myNotePaper ../"myOldNotePaper"

