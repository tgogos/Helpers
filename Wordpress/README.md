# Wordpress

## how to always redirect to the `https` version of a page

`.htaccess`

```
# BEGIN WordPress
<IfModule mod_rewrite.c>
RewriteEngine On
RewriteBase /

RewriteCond %{HTTPS} !=on
RewriteRule ^ https://%{HTTP_HOST}%{REQUEST_URI} [L,R=301]

RewriteRule ^index\.php$ - [L]
RewriteCond %{REQUEST_FILENAME} !-f
RewriteCond %{REQUEST_FILENAME} !-d
RewriteRule . /index.php [L]
</IfModule>
# END WordPress
```

## Docker - Wordpress - How to mount `volumes`

 - [https://stackoverflow.com/questions/49202531/volume-mount-when-setting-up-wordpress-with-docker](https://stackoverflow.com/questions/49202531/volume-mount-when-setting-up-wordpress-with-docker)
