#!/bin/bash

hostname >> /var/www/html/index.html
/usr/sbin/httpd -D FOREGROUND

