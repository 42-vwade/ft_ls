#include "ft_ls.h"

static void
	check_errno(char *s)
{
	((s) && ft_printf("ft_ls: %s: %s (%i)\n", s, strerror(errno), errno));
//	|| ft_printf("ft_ls: %s: (%i) \n", strerror(errno), errno);
}

static int
	open_dir(char *name, DIR **dir)
{
	dir[0] = opendir(name);
	if (dir[0] == NULL)
		check_errno(name);
	return (!!dir[0]);
}

static void
	expose_stat(struct stat *info)
{
	size_t	i = 0;
	int		pad;
	ull_t	*info_elems;
	char	**info_type;
	char	**info_field;
	char	**info_info;

	if (!info)
		return ;
	info_elems = (ull_t[]){
		info->st_dev, info->st_ino, info->st_nlink, info->st_uid,
		info->st_gid, info->st_rdev, info->st_size, info->st_blksize,
		info->st_blocks, 0, 0, 0
	};
	info_type = (char*[]){
		"dev_t", "ino_t", "mode_t", "nlink_t", "uid_t", "gid_t", "dev_t",
		"off_t", "blksize_t", "blkcnt_t", "time_t", "time_t", "time_t"
	};
	info_field = (char*[]){
		"st_dev", "st_ino", "st_nlink", "st_uid", "st_gid", "st_rdev",
		"st_size", "st_blksize", "st_blkcnt", "st_blocks", "st_atime", "st_mtime", "st_ctime"
	};
	info_info = (char*[]){
		"/* ID of device containing file */",
		"/* inode number */",
		"/* protection */",
		"/* number of hard links */",
		"/* user ID of owner */",
		"/* group ID of owner */",
		"/* device ID (if special file) */",
		"/* total size, in bytes */",
		"/* blocksize for file system I/O */",
		"/* number of 512B blocks allocated */",
		"/* time of last access */",
		"/* time of last modification */",
		"/* time of last status change */"
	};
	while (i < 10)
	{
		pad = 32 - ft_printf("%a%s", 36, info_type[i]);
		pad = ft_printf("%a%*s%s", 117, pad < 0 ? 0 : pad, "", info_field[i]);
		pad = 32 - pad + ft_printf(" = %#a%llu", "red", info_elems[i]);
		//ft_printf("\t%i\t", pad);
		//pad = 32;
		ft_printf(";%a%*s%s\n", 65, pad < 0 ? 0 : pad, "", info_info[i]);
		i++;
	}
}

static void
	expose_dir(char *name)
{
	int				fd;
	DIR				*dir[2];
	struct dirent	*entry;
	struct stat		info;
	int				pad;

	fd = open(name, O_RDONLY);
	open_dir(name, &dir[0]);
	open_dir(name, &dir[1]);
	while ((entry = readdir(dir[0])) != NULL)
		pad = MAX(8 + ft_strlen(entry->d_name) / 4 * 4, pad);
//	rewinddir(dir[0]);
	while ((entry = readdir(dir[1])))
	{
		lstat(entry->d_name, &info);
		if ((1))
			expose_stat(&info);
		//ft_printf("[chk0] directory type: %i\t", entry->d_type);
			ft_printf("directory path: %-*s""directory type: %i\n", pad, entry->d_name, entry->d_type);
		if (entry->d_type == DT_DIR)
		{
			//if (!ft_strcmp(entry->d_name, ".") || !ft_strcmp(entry->d_name, ".."))	continue ;
		}
	}
	closedir(dir[0]);
	closedir(dir[1]);
}

int main(int n, char **v)
{
	int	i = 0;
	DIR	*ds;

	if (n > 1)
		while (++i < n)
		{
			errno = 0;
			expose_dir(v[1]);
		}
}

/*
◦ write
◦ opendir
	opens <dir>, associates with and returns pointer to [directory stream]
	returns NULL on error. check errno to verify.
◦ readdir
◦ closedir
◦ stat
◦ lstat
◦ getpwuid
◦ getgrgid
◦ listxattr
◦ getxattr
◦ time
◦ ctime
◦ readlink
◦ malloc
◦ free
◦ perror
◦ strerror
◦ exit
*/
