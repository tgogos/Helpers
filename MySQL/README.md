MySQL
=====

Enable remote access
--------------------

### STEP 1:

```bash
$ mysql -u root -p
mysql> GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY 'your_password';
```

### STEP 2:

```bash
$ nano /etc/mysql/my.cnf
# comment out line: "bind-address           = 127.0.0.1"
$ service mysql restart
```
