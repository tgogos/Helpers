# Apache

## Setting Up Virtual Hosts

Source: [How To Install the Apache Web Server on Ubuntu 18.04 [Quickstart]](https://www.digitalocean.com/community/tutorials/how-to-install-the-apache-web-server-on-ubuntu-18-04-quickstart)

When using the Apache web server, you can use *virtual hosts* (similar to server blocks in Nginx) to encapsulate configuration details and host more than one domain from a single server. 

1. Create the directory for `your_domain`:

        sudo mkdir /var/www/your_domain


2. Assign ownership of the directory:

        sudo chown -R $USER:$USER /var/www/your_domain

3. The permissions of your web roots should be correct if you haven't modified your `unmask` value, but you can make sure by typing:

        sudo chmod -R 755 /var/www/your_domain


4. Create a sample `index.html` page using `nano` or your favorite editor:

        nano /var/www/your_domain/index.html


5. Make a new virtual host file at `/etc/apache2/sites-available/your_domain.conf`:

        sudo nano /etc/apache2/sites-available/your_domain.conf

```
<VirtualHost *:80>
    ServerAdmin webmaster@localhost
    ServerName your_domain
    ServerAlias your_domain
    DocumentRoot /var/www/your_domain
    ErrorLog ${APACHE_LOG_DIR}/error.log
    CustomLog ${APACHE_LOG_DIR}/access.log combined
</VirtualHost>

```

6. Enable the file with `a2ensite`:

        sudo a2ensite your_domain.conf


7. Disable the default site defined in `000-default.conf`:

        sudo a2dissite 000-default.conf

8. Test for configuration errors (you should see `OutputSyntax OK`):

        sudo apache2ctl configtest


9. Restart Apache to implement your changes:

        sudo systemctl restart apache2
