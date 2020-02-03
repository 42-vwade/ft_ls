
# ft_ls

42 school project. Recreation of the "ls" Unix command.

#### Installation
```sh
$ git clone
$ make
```
-  `make` (this generates the binary as **"ft_ls"**)
- run ft_ls as `./ft_ls *flags* *files and folders*` as you would run the real ls

#### Usage
```sh
$ ./ft_ls {options} {directories}
```

## Features:
- the check for ACL's and extended attributes is implemented - `@` and `+` are displayed at the end of file permissions column if required]
- special file permissions are also implemented [`sStT`]
- ft_ls checks if the output is a terminal and displays stats accordingly, using the right format as real ls does
- correct display of minor, major or filesize depending on file's type
- flags that can be used with ft_ls: **`-1AGSRaglort`** *(See the manual for the real ls for more details)*
- all features necessary for the accurate display of stats with the right format using any of the flags that ft_ls is able to use are implemented

## Examples

**normal use of ft_ls:**
![preview](https://i.imgur.com/nqGrKfe.png)

**using bad flags:**
![preview](https://i.imgur.com/8RydKke.png)

**using the -l flag:**
![preview](https://i.imgur.com/7EdxO8T.png)

**using the -l flag on multiple files and folders some which do not exist or don't have read permissions available:**
![preview](https://i.imgur.com/QWWs5p4.png)

**using the -a flag:**
![preview](https://i.imgur.com/2eoDSuB.png)

**using the -S flag:**
![preview](https://i.imgur.com/4FpeG0n.png)

**using the -S flag combined with -r:**
![preview](https://i.imgur.com/93qh3Cg.png)

**using ft_ls on the /dev directory:**
![preview](https://i.imgur.com/F7033TH.png)

**using the -G flag:**
![preview](https://i.imgur.com/RR3EjIl.png)

**using the -R flag:**
![preview](https://i.imgur.com/T38Ikpy.png)